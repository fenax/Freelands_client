#ifdef HAVE_CONFIG_H
#   include "config.h"
#endif
#include <string>
#include <map>

#include "protocol_message.h"

class network{
	std::string server;
	std::map<int, protocol_message* (*)(int,char*)> handlers;

	static int LE_int32(char i[]){
		return int(i[0])<<24 | int(i[1])<<16 | int(i[2])<<8 | i[3];
	}
	static int read_LE_int32(char data[],int& index,int imax){
		int out = LE_int32(&data[index]);
		index += 4;
		return out;
	}
	static int LE_int16(char i[]){
		return int(i[2])<<8 | i[3];
	}

	//TODO list de handlers enregistrable de type de messages
};
