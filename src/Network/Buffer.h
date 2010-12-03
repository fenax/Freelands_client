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
 * Stream buffer with accessors to read and write in little endian header.
 */

#ifndef NETWORK_BUFFER_H_
#define NETWORK_BUFFER_H_

#include <boost/cstdint.hpp>
#include <boost/asio.hpp>
#include <string>
namespace Network{
class Buffer : public boost::asio::basic_streambuf< std::allocator<char> > {
public:
	Buffer();
        Buffer(std::string filename);
	virtual ~Buffer();


	boost::int32_t read_LE_int32();
	boost::int16_t read_LE_int16();
	boost::int8_t read_LE_int8();
	boost::uint32_t read_LE_uint32();
	boost::uint16_t read_LE_uint16();
	boost::uint8_t read_LE_uint8();

        float read_float();

	std::string read_c_string();
	std::string read_string(int size);

	void write_LE_int32(boost::int32_t value);
	void write_LE_int16(boost::uint16_t value);
	void write_LE_int8(boost::int8_t value);

	void write_c_string(std::string value);

	void makeReadable();

};
}
#endif /* NETWORK_BUFFER_H_ */
