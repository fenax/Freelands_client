/*
 * RawTextMessage.h
 *
 *  Created on: 21 nov. 2010
 *      Author: fenax
 */

#ifndef RAWTEXTMESSAGE_H_
#define RAWTEXTMESSAGE_H_

#include <string>

#include <boost/cstdint.hpp>

#include "Message.h"

namespace Protocol
{

class RawTextMessage : public Message
{
public:
	RawTextMessage();
	RawTextMessage(std::string message);
	RawTextMessage(std::string message, boost::int8_t);

	virtual ~RawTextMessage();

	boost::int8_t color_;
	std::string message_;
};

}

#endif /* RAWTEXTMESSAGE_H_ */
