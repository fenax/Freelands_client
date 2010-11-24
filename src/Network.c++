#include "Network.h"


Network::Network(std::string server, Protocol::Protocol& protocol):
		socket_(io_),
		server_(server),
		stoprequested_(false),
		protocol_(protocol)
{
}

void
Network::connect(){
	boost::asio::ip::tcp::resolver resolver(io_);
	boost::asio::ip::tcp::resolver::query query(server_);
	boost::asio::ip::tcp::resolver::iterator
		endpoint_iterator = resolver.resolve(query);
	boost::asio::ip::tcp::resolver::iterator end;

    boost::system::error_code error = boost::asio::error::host_not_found;
    while (error && endpoint_iterator != end)
    {
      socket_.close();
      socket_.connect(*endpoint_iterator++, error);
    }
    if (error)
      throw boost::system::system_error(error);
}


void
Network::thread(){
	while(!stoprequested_){
		NetworkBuffer * buff = new NetworkBuffer();

		boost::system::error_code error;

		int read =
		boost::asio::read(socket_,
				*(boost::asio::basic_streambuf< std::allocator<char> > *)buff,
				boost::asio::transfer_at_least(3));//fugly downcasting

		int type = buff->read_LE_uint8();
		int size = buff->read_LE_uint16();

		boost::asio::read(socket_,
				*(boost::asio::basic_streambuf< std::allocator<char> > *)buff,
				boost::asio::transfer_at_least(size + 2 - read));
		protocol_.parse(*buff, type);//TODO do something with received message

		delete buff;
	}
}



void
Network::start(){
    assert(!thread_);
	thread_ = boost::shared_ptr<boost::thread>(
			new boost::thread(
					boost::bind(&Network::thread, this)));
}

void
Network::stop(){
	assert(thread_);
	stoprequested_ = true;
	thread_->join();
}
