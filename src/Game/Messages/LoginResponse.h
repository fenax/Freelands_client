/*
 * LoginResponse.h
 *
 *  Created on: 25 nov. 2010
 *      Author: fenax
 */

#ifndef LOGINRESPONSE_H_
#define LOGINRESPONSE_H_

#include <string>

#include "Game/Message.h"

namespace Game
{

namespace Messages
{

class LoginResponse: public Game::Message
{
private:
	std::string message_;
	bool is_logged_in_;
public:
	LoginResponse(bool, std::string = "");
	virtual ~LoginResponse();
	bool isLoggedIn();
	std::string getMessage();
};

}

}

#endif /* LOGINRESPONSE_H_ */
