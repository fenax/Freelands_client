/*
 * network_buffer.cpp
 *
 *  Created on: 20 nov. 2010
 *      Author: fenax
 */

#include "NetworkBuffer.h"

NetworkBuffer::NetworkBuffer() {
	// TODO Auto-generated constructor stub

}

NetworkBuffer::~NetworkBuffer() {
	// TODO Auto-generated destructor stub
}

boost::int32_t
NetworkBuffer::read_LE_int32(){
	//TODO check for end of buffer and subsequent exceptions
	boost::int32_t out = 0;
	out |= boost::int32_t (sgetc())<<24;
	out |= boost::int32_t (sgetc())<<16;
	out |= boost::int32_t (sgetc())<<8;
	out |= boost::int32_t (sgetc());
	return out;
}

boost::int16_t
NetworkBuffer::read_LE_int16(){
	boost::int16_t out = 0;
	out |= boost::int16_t (sgetc())<<8;
	out |= boost::int16_t (sgetc());
	return out;
}