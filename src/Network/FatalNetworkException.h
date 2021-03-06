/**
 * @file
 * @author  Guillaume Minet "Fenax" <mail@fenax.name>
 *
 * @section LICENSE
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @section DESCRIPTION
 *
 * Fatal network exception header.
 */

#ifndef NETWORK_FATAL_NETWORK_EXCEPTION_H_
#define NETWORK_FATAL_NETWORK_EXCEPTION_H_

#include <exception>

class FatalNetworkException: public std::exception
{
	//TODO differentiate errors.
public:

	virtual const char* what() const throw();
};

#endif /* NETWORK_FATAL_NETWORK_EXCEPTION_H_ */
