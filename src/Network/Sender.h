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
 * Interface for classes that can send messages to the network.
 */

#ifndef NETWORK_SENDER_H_
#define NETWORK_SENDER_H_

#include "Network/Buffer.h"

namespace Network {

    class Sender {
    public:
        virtual void send(Buffer *, int priority = 0) = 0; // zero is send at once

    };

}

#endif /* NETWORK_SENDER_H_ */
