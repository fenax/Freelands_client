/*
 * network_buffer.cpp
 *
 *  Created on: 20 nov. 2010
 *      Author: fenax
 */

#include <iostream>

#include "Network/Buffer.h"

namespace Network{

Buffer::Buffer() {
	// TODO Auto-generated constructor stub

}

Buffer::~Buffer() {
	// TODO Auto-generated destructor stub
}

boost::int32_t
Buffer::read_LE_int32(){
	//TODO check for end of buffer and subsequent exceptions
	boost::int32_t out = 0;
	out |= boost::int32_t (sgetc());
	sbumpc();
	out |= boost::int32_t (sgetc())<<8;
	sbumpc();
	out |= boost::int32_t (sgetc())<<16;
	sbumpc();
	out |= boost::int32_t (sgetc())<<24;
	sbumpc();
	return out;
}

void Buffer::write_LE_int32(boost::int32_t value){
	sputc((char) value&0xFF);
	sputc((char)(value >> 8)&0xFF );
	sputc((char)(value >> 16)&0xFF );
	sputc((char)(value >> 24)&0xFF );
}


boost::uint32_t
Buffer::read_LE_uint32(){
	return (unsigned)read_LE_int32();
}


boost::uint16_t
Buffer::read_LE_uint16(){
	boost::uint16_t out = 0;
	out |= static_cast<boost::uint16_t>( sgetc() );
	sbumpc();
	out |= static_cast<boost::uint16_t>( sgetc() ) << 8;
	sbumpc();
	return out;
}

void Buffer::write_LE_int16(boost::uint16_t value){
	sputc((unsigned char) value&0xFF);
	sputc((unsigned char)(value>> 8)&0xFF );
}

boost::int16_t
Buffer::read_LE_int16(){
	return static_cast<boost::uint16_t>(read_LE_uint16());
}


boost::int8_t
Buffer::read_LE_int8(){
	boost::int8_t out = sgetc();
	sbumpc();
	return out;
}

void
Buffer::write_LE_int8(boost::int8_t value){
	sputc(value);
}

boost::uint8_t
Buffer::read_LE_uint8(){
	boost::uint8_t out = sgetc();
	sbumpc();
	return out;
}

std::string
Buffer::read_c_string(){
	//TODO optimize
	std::string out = "";
	while( char c = sgetc() ){
		sbumpc();
		out.append(&c);
	}
}

void Buffer::write_c_string(std::string value){
	sputn(value.c_str(),value.size()+1);
}

void
Buffer::makeReadable(){
	size_t s = size();
	std::cout << s << std::endl;
	prepare(s);
	commit(0);
}
}
