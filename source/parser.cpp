#include "parser.h"


Parser::Parser() {

	supported_filetypes[".txt"] = 1;
	supported_filetypes[""] 	= 1;

}

Document * Parser::parseTextFile(std::string filename) {
	std::cout << "Not implemented yet.\n";
	return NULL;
}

Document * Parser::parseFileFromType(std::string filename, std::string filetype) {
		if(".txt" == filetype)
			return parseTextFile(filename);
		if("" == filetype)
			return parseTextFile(filename);
	
}

Document * Parser::parseFile(std::string filename) {

	size_t pos = 0;

	for(auto key : supported_filetypes) {
		if(filename.find(key.first) != std::string::npos) {
			return parseFileFromType(filename, key.first);
		}
	}

	std::cout << "Filetype not supported.\n";
	return NULL;

}