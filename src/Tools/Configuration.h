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
 * The configuration class reads configuration from files and dispenses
 * it to the rest of the program.
 */

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

namespace Tools{


	class Configuration{

		std::vector<std::string*> readFile(const char * file_name){
			char temp[256];
			std::vector<std::string*> vect;

			std::ifstream config_file(file_name,std::ios_base::in);

		    if(!config_file) //Always test the file open.
			{
				std::cout << "Error opening file " << file_name << std::endl;
				return vect;
			}

		    while(config_file.good()){
		    	config_file.getline(temp,256);
		    	vect.push_back(new std::string(temp));
		    }
		    return vect;
		}



	public :
		std::string server;
		std::vector<std::string*> boots, hair, head, pants, shirt, skin;



		Configuration():
			server("127.0.0.1:3000")
		{
			boots = readFile("data/boots.dt");
			hair = readFile("data/hair.dt");
			head = readFile("data/head.dt");
			pants = readFile("data/pants.dt");
			shirt = readFile("data/shirt.dt");
			skin = readFile("data/skin.dt");
		}




	};

}
