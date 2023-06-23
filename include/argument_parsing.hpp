#ifndef ARGUMENT_PARSING_HPP
#define ARGUMENT_PARSING_HPP

#include "globals.hpp"

class ArgumentParser
{
private:

public:
	int argc;
	char** argv;

	bool hasInput;
	string input;
	
	ArgumentParser(int argc, char **argv);
	
	bool Parse();
	
	string GenerateHelpString();
	
};


#endif	//	ARGUMENT_PARSING_HPP
