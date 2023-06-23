#include "../include/argument_parsing.hpp"
    
ArgumentParser::ArgumentParser(int argc, char **argv)
{
	this->argc = argc;
	this->argv = argv;
	
	Parse();
}
	
bool ArgumentParser::Parse()
{
	try
	{
		if(argc == 1)
		{
			cout << GenerateHelpString();
			exit(0);
		}
		
		if(argc == 2) 
			if ((strcmp(argv[1], "--help") == 0) || 
				(strcmp(argv[1], "-help") == 0) || 
				(strcmp(argv[1], "--h") == 0) || 
				(strcmp(argv[1], "-h") == 0))
			{
				cout << GenerateHelpString();
				exit(0);
			}
		
		if(argc%2 == 0)
		{
			cout << "\nThere was an error parsing command line arguments\n";
			cout << GenerateHelpString();
			exit(0);
		}
		
			
		for(int i=1; i<argc-1; i=i+2)
		{
			
			if (strcmp(argv[i], "--input") == 0) {
				input = string(argv[i+1]);
				hasInput = true;
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
	str += "\n    [--input]: Input graph file. E.g., --input FacebookGraph.txt";
	str += "\n\n";
	return str;
}

