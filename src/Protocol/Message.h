#ifndef PROTOCOL_MESSAGE_H_
#define PROTOCOL_MESSAGE_H_

#include <boost/cstdint.hpp>

#include "NetworkBuffer.h"

namespace Protocol{

	class Message {
//		virtual ~Message(){}
		static Message * create(NetworkBuffer, boost::int8_t );

	};

}
#endif // PROTOCOL_MESSAGE_H_
