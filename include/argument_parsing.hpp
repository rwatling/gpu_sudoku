#ifndef ARGUMENT_PARSING_HPP
#define ARGUMENT_PARSING_HPP

#include "globals.hpp"

class ArgumentParser
{
private:

public:
	int argc;
	char** argv;

	Difficulty diff;
	bool debug;
	
	ArgumentParser(int argc, char **argv);
	void Parse();
	string GenerateHelpString();
	
};

#endif	//	ARGUMENT_PARSING_HPP
