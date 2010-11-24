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

void NetworkBuffer::write_LE_int32(boost::int32_t value){
	sputc((char)(value&0xFF000000) >> 24);
	sputc((char)(value&0xFF0000) >> 16);
	sputc((char)(value&0xFF00) >> 8);
	sputc((char) value&0xFF);
}


boost::uint32_t
NetworkBuffer::read_LE_uint32(){
	return (unsigned)read_LE_int32();
}


boost::int16_t
NetworkBuffer::read_LE_int16(){
	boost::int16_t out = 0;
	out |= boost::int16_t (sgetc())<<8;
	out |= boost::int16_t (sgetc());
	return out;
}

void NetworkBuffer::write_LE_int16(boost::int16_t value){
	sputc((char)(value&0xFF00) >> 8);
	sputc((char) value&0xFF);
}

boost::uint16_t
NetworkBuffer::read_LE_uint16(){
	return (unsigned)read_LE_int16();
}


boost::int8_t
NetworkBuffer::read_LE_int8(){
	return sgetc();
}

void
NetworkBuffer::write_LE_int8(boost::int8_t value){
	sputc(value);
}

boost::uint8_t
NetworkBuffer::read_LE_uint8(){
	return (unsigned)sgetc();
}

std::string
NetworkBuffer::read_c_string(){
	//TODO optimize
	std::string out = "";
	while( char c = sgetc() ){
		out.append(&c);
	}
}

void NetworkBuffer::write_c_string(std::string value){
	sputn(value.c_str(),value.size()+1);
}
