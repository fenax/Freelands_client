#ifndef NETWORK_H_
#define NETWORK_H_


#include <string>
#include <map>

#include <boost/asio.hpp>
#include <boost/thread.hpp>

#include "FatalNetworkException.h"
#include "Protocol/Protocol.h"
#include "NetworkBuffer.h"

class Network
{
public:
	Network(std::string server, Protocol::Protocol & protocol);


	void thread();
	void start();
    void stop();
    void connect();

protected:
    boost::asio::io_service io_;
    boost::asio::ip::tcp::socket socket_;
	boost::shared_ptr<boost::thread> thread_;

	Protocol::Protocol& protocol_;

    volatile bool stoprequested_;
	std::string server_;

};

#endif /* NETWORK_H_ */
