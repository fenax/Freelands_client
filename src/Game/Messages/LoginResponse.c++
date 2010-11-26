/*
 * LoginResponse.c++
 *
 *  Created on: 25 nov. 2010
 *      Author: fenax
 */

#include "LoginResponse.h"

namespace Game
{

namespace Messages
{

LoginResponse::LoginResponse(bool, std::string = std::string::empty()){

}
bool
LoginResponse::isLoggedIn(){
	return is_logged_in_;
}
std::string
LoginResponse::getMessage(){
	return message_;
}

}

}
