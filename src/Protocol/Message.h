#ifndef PROTOCOL_MESSAGE_H_
#define PROTOCOL_MESSAGE_H_
namespace Protocol{

	class ProtocolMessage {
		virtual ~ProtocolMessage(){}
		virtual ProtocolMessage create(NetworkBuffer );
	};

}
#endif // PROTOCOL_MESSAGE_H_
