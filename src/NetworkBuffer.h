/*
 * network_buffer.h
 *
 *  Created on: 20 nov. 2010
 *      Author: fenax
 */

#ifndef NETWORK_BUFFER_H_
#define NETWORK_BUFFER_H_

#ifdef HAVE_CONFIG_H
#   include "config.h"
#endif

#include <boost/cstdint.hpp>
#include <boost/asio.hpp>

class NetworkBuffer : public boost::asio::basic_streambuf< std::allocator<char> > {
public:
	NetworkBuffer();
/*	NetworkBuffer(const NetworkBuffer & network_buffer):
		std::basic_streambuf(network_buffer)
	{}*/
	virtual ~NetworkBuffer();

	boost::int32_t read_LE_int32();
	boost::int16_t read_LE_int16();
	boost::int8_t read_LE_int8();
	boost::uint32_t read_LE_uint32();
	boost::uint16_t read_LE_uint16();
	boost::uint8_t read_LE_uint8();
	std::string read_c_string();
};

#endif /* NETWORK_BUFFER_H_ */
