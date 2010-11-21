/*
 * RawTextMessage.c++
 *
 *  Created on: 21 nov. 2010
 *      Author: fenax
 */

#include "RawTextMessage.h"

namespace Protocol
{


	RawTextMessage::RawTextMessage(std::string message):
		message_(message),
		color_(0)
	{}

	RawTextMessage::RawTextMessage(std::string message, boost::int8_t color):
		message_(message),
		color_(color)
	{}

	RawTextMessage::~RawTextMessage()
	{
		// TODO Auto-generated destructor stub
	}

}
