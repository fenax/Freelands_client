#include "TcpNetwork.h"

namespace Network{
using namespace boost::asio;
TcpNetwork::TcpNetwork(std::string server, Protocol::Protocol& protocol):
		socket_(io_),
		server_(server),
		stoprequested_(false),
		protocol_(protocol)
{
	protocol_.registerNetworkSender(*this);
}

void
TcpNetwork::connect(){
	boost::asio::ip::tcp::resolver resolver(io_);
	//boost::asio::tcp::resolver::query query(tcp::v4(), host, port);
	boost::asio::ip::tcp::resolver::query query("127.0.0.1","3000");
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
TcpNetwork::send(Buffer * send_buffer,int priority){ // zero is send at once
	//TODO use priority
	//TODO user a ffff ing queue
	boost::asio::write(
			socket_,
			*static_cast<boost::asio::basic_streambuf< std::allocator<char> > *>
					(send_buffer),
			boost::asio::transfer_all());
	delete send_buffer;
}

void
TcpNetwork::thread(){
	Buffer * buff = new Buffer();
	while(!stoprequested_){

		//TODO check errors
		boost::system::error_code error;

		int to_read = protocol_.getAmountToRead() - buff->in_avail();

		if(to_read > 0){
			int red = read(socket_,
					*(basic_streambuf< std::allocator<char> > *)buff,
					transfer_at_least(to_read));//fugly downcasting
		}

		protocol_.parse(*buff);

	}
	delete buff;
}



void
TcpNetwork::start(){
    assert(!thread_);
	thread_ = boost::shared_ptr<boost::thread>(
			new boost::thread(
					boost::bind(&TcpNetwork::thread, this)));
}

void
TcpNetwork::stop(){
	assert(thread_);
	stoprequested_ = true;
	thread_->join();
}
}
