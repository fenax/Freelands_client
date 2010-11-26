/*
 * Sender.h
 *
 *  Created on: 26 nov. 2010
 *      Author: fenax
 */

#ifndef NETWORK_SENDER_H_
#define NETWORK_SENDER_H_

#include "Network/Buffer.h"

namespace Network
{

class Sender
{
public:
    virtual void send(Buffer *,int priority = 0) = 0; // zero is send at once

};

}

#endif /* NETWORK_SENDER_H_ */
