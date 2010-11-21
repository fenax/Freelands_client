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

#include <streambuf>
#include <boost/cstdint.hpp>

class NetworkBuffer : public std::basic_streambuf<unsigned char> {
public:
	NetworkBuffer();
	virtual ~NetworkBuffer();

	boost::int32_t read_LE_int32();
	boost::int16_t read_LE_int16();
};

#endif /* NETWORK_BUFFER_H_ */
