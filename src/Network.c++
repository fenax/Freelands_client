#include "Network.h"

using boost::asio::ip::tcp;
using boost::asio;





ProtocolMessage*
Network::process_message(NetworkBuffer& msg){
	std::map<int, ProtocolMessage* (*)(NetworkBuffer&)>::iterator
			it = handlers_.find(msg.read_LE_int16());
	if(it == handlers_.end()){
		throw new FatalNetworkException();
	}
	return it->second(msg);
}

Network::Network(std::string server){
	server_ = server;
	stoprequested_ = false;
}

void
Network::connect(){
    resolver resolver(io_);
    resolver::query query(server_);
    resolver::iterator endpoint_iterator = resolver.resolve(query);
    resolver::iterator end;

    socket_ = socket(io_);
    boost::system::error_code error = boost::asio::error::host_not_found;
    while (error && endpoint_iterator != end)
    {
      socket_.close();
      socket_.connect(*endpoint_iterator++, error);
    }
    if (error)
      throw boost::system::system_error(error);
}

class LimitedReader{
	int len_;
	LimitedReader(int len){
		len_ = len;
	}
	std::size_t
	completion_condition(// Result of latest read_some operation.
						const boost::system::error_code& error,

						// Number of bytes transferred so far.
						std::size_t bytes_transferred){
		//TODO errors
		return len - bytes_transferred;
	}
};


void
Network::thread(){
	while(!stoprequested_){
		NetworkBuffer size;

		NetworkBuffer buff();
		boost::system::error_code error;
		boost::asio::read(socket_,size,LimitedReader(2));
		boost::asio::read(socket_,buff,LimitedReader(size.read_LE_int16()));
		process_message(buff);//TODO do something with received message
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
