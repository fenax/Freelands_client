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
