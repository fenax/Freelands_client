/*
 * fatal_network_exception.cpp
 *
 *  Created on: 20 nov. 2010
 *      Author: fenax
 */

#include "FatalNetworkException.h"
#include <iostream>

/*FatalNetworkException::FatalNetworkException() {
	// TODO Auto-generated constructor stub

}

FatalNetworkException::~FatalNetworkException() {
	// TODO Auto-generated destructor stub
}*/

const char*
FatalNetworkException::what() const throw(){
	return "Fatal network exception : ";
}
