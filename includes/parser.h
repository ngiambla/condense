#ifndef __PARSER_H__
#define __PARSER_H__


#include "document.h"

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <vector>


class Parser {

	private:
		std::unordered_map<std::string, int> stopwords;
		std::unordered_map<std::string, int> supported_filetypes;
		Document * parseTextFile(std::string filename);
		Document * parseFileFromType(std::string filename, std::string filetype);

	public:
		Parser();
		~Parser();
		Document * parseFile(std::string filename);
	
};

#endif