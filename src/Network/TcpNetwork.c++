/**
 * @file
 * @author  Guillaume Minet "Fenax" <mail@fenax.name>
 *
 * @section LICENSE
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 *
 * Tcp network client implementation.
 */


#include "TcpNetwork.h"

namespace Network{
using namespace boost::asio;
TcpNetwork::TcpNetwork(std::string server, Protocol::Protocol& protocol):
		socket_(io_),
		protocol_(protocol),
		stoprequested_(false),
		server_(server)
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
