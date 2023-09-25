#include "../include/argumentParsing.hpp"
    
ArgumentParser::ArgumentParser(int argc, char **argv)
{
	this->argc = argc;
	this->argv = argv;
	
	diff = EASY;
	debug = true;

	Parse();
}
	
void ArgumentParser::Parse()
{
	try
	{
		if (argc < 2)
			return;

		if(argc == 2) 
			if ((strcmp(argv[1], "--help") == 0) || 
				(strcmp(argv[1], "-help") == 0) || 
				(strcmp(argv[1], "--h") == 0) || 
				(strcmp(argv[1], "-h") == 0)) 
			{
				cout << GenerateHelpString();
				exit(0);
			} else { cout << " Unrecognized option" << endl; }
		
		if(argc%2 == 0)
		{
			cout << "\nThere was an error parsing command line arguments\n";
			cout << GenerateHelpString();
			exit(0);
		}
		
			
		for(int i=1; i<argc-1; i=i+2)
		{
			
			if (strcmp(argv[i], "--diff") == 0) {
				if(strcmp(argv[i+1], "easy") == 0) {
					diff = EASY;
				} else if(strcmp(argv[i+1], "medium") == 0) {
					diff = MEDIUM;
				} else if(strcmp(argv[i+1], "hard") == 0) {
					diff = HARD;
				} else {
					cout << "\nThere was an error parsing command line argument <" << argv[i] << ">\n";
					cout << GenerateHelpString();
					exit(0);
				}
			} else if (strcmp(argv[i], "--debug") == 0) {
				debug = true;
			} else {
				cout << "\nThere was an error parsing command line argument <" << argv[i] << ">\n";
				cout << GenerateHelpString();
				exit(0);
			}
		}
	}
	catch( const std::exception& strException ) {
		std::cerr << strException.what() << "\n";
		GenerateHelpString();
		exit(0);
	}
	catch(...) {
		std::cerr << "An exception has occurred.\n";
		GenerateHelpString();
		exit(0);
	}
}

string ArgumentParser::GenerateHelpString(){
	string str = "\nRequired arguments:";
	str += "\n    [--debug]: Extra messages and verficiation (Defualt: true) E.g. --debug true";
	str += "\n    [--diff: Puzzle difficulty of easy, medium, hard, or expert with the pre-filled cells determining the difficulty (Default: easy) E.g. --diff expert";
	str += "\n\n";
	return str;
}

