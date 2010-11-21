#ifndef PROTOCOL_MESSAGE_H_
#define PROTOCOL_MESSAGE_H_

class ProtocolMessage {
	virtual ~ProtocolMessage(){}
	virtual ProtocolMessage create(int ,char[] );
};

#endif // PROTOCOL_MESSAGE_H_
