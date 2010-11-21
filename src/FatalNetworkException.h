/*
 * fatal_network_exception.h
 *
 *  Created on: 20 nov. 2010
 *      Author: fenax
 */

#ifndef FATAL_NETWORK_EXCEPTION_H_
#define FATAL_NETWORK_EXCEPTION_H_

#include <exception>

class FatalNetworkException: public std::exception
{
	//TODO differentiate errors.
public:
//	FatalNetworkException();
//	virtual ~FatalNetworkException();

	virtual const char* what() const throw();
};

#endif /* FATAL_NETWORK_EXCEPTION_H_ */
