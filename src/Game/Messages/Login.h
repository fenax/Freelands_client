/*
 * Login.h
 *
 *  Created on: 24 nov. 2010
 *      Author: fenax
 */

#ifndef LOGIN_H_
#define LOGIN_H_

#include "Message.h"
#include <string>
namespace Game
{

namespace Messages
{

class Login: public virtual Game::Message
{
private:
	string username_;
	string password_;
public:
	Login(string username, string password);
	virtual ~Login();

	string GetUsername();
	string GetPassword();
};

}

}

#endif /* LOGIN_H_ */
