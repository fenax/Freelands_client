#ifndef NETWORK_H_
#define NETWORK_H_


#ifdef HAVE_CONFIG_H
#   include "config.h"
#endif

#include <string>
#include <map>

#include <boost/asio.hpp>
#include <boost/thread.hpp>

#include "FatalNetworkException.h"
#include "ProtocolMessage.h"
#include "NetworkBuffer.h"

class Network
{
public:
	Network(std::string server);

	ProtocolMessage*	process_message(NetworkBuffer msg);

	void thread();
	void start();
    void stop();

protected:

	boost::shared_ptr<boost::thread> thread_;
    volatile bool stoprequested_;
	std::string server_;
	std::map<int, ProtocolMessage* (*)(NetworkBuffer&)> handlers_;

};

#endif /* NETWORK_H_ */
