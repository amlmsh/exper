/*
 * server.C
 *
 *  Created on: 11.09.2019
 *      Author: aml
 */
#include <cstdio> // standard input and output library
#include <cstdlib> // this includes functions regarding memory allocation
#include <cstring> // contains string functions
#include <cerrno> //It defines macros for reporting and retrieving error conditions through error codes
#include <ctime> //contains various functions for manipulating date and time

#include <unistd.h> //contains various constants
#include <sys/types.h> //contains a number of basic derived types that should be used whenever appropriate
#include <arpa/inet.h> // defines in_addr structure
#include <sys/socket.h> // for socket creation
#include <netinet/in.h> //contains constants and structures needed for internet domain addresses



#include <iostream>

#include "SIMPLESOCKET.H"

class MyServer : public TCPserver{

public:
	MyServer(int portNmb, int maxDataRecv) : TCPserver(portNmb, maxDataRecv){;};

protected:
	string myResponse(string input);

};


int main(){
	srand(time(nullptr));

	MyServer srv(2025,32);

	srv.run();
}


string MyServer::myResponse(string input){
	string responseStr = string("ERROR");
	int a,b,c;


	if(input.compare(0,4,"cmd(") == 0){
		sscanf(input.c_str() , "cmd(%i,%i,%i)", &a, &b, &c );

		if(a < 1){
			responseStr = string("ERROR: Wrong value for parameter a.");
			return responseStr;
		}

		responseStr = string("OK");
		return responseStr;
	}else if(input.compare(0,8,"otherCMD") == 0){
		// mache, was otherCMD triggern soll


		responseStr = string("OK");
		return responseStr;
	}


	responseStr = string("ERROR");
	return responseStr;
};


