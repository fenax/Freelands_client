#include "Network.h"

ProtocolMessage*
Network::process_message(NetworkBuffer msg){
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
Network::thread(){
	while(!stoprequested_){

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
