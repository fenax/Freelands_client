/*
 * Login.c++
 *
 *  Created on: 24 nov. 2010
 *      Author: fenax
 */

#include "Login.h"

namespace Game
{

namespace Messages
{

Login::Login(string username, string password) :
	username_(username), password_(password)
{

}

Login::~Login()
{
	// TODO Auto-generated destructor stub
}

string
Login::GetUsername()
{
	return username_;
}

string
Login::GetPassword()
{
	return password_;
}

}

}
