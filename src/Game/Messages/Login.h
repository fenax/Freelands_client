/*
 * Login.h
 *
 *  Created on: 24 nov. 2010
 *      Author: fenax
 */

#ifndef LOGIN_H_
#define LOGIN_H_

#include <string>
namespace Game
{

namespace Messages
{

class Login: public virtual Game::Message
{
private:
	std::string username_;
	std::string password_;
public:
	Login(std::string username, std::string password);
	virtual ~Login();

	std::string getUsername();
	std::string getPassword();
};

}

}

#endif /* LOGIN_H_ */
