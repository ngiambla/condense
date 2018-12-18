#ifndef __PARSER_H__
#define __PARSER_H__


#include "document.h"

#include <iostream>
#include <unordered_map>
#include <vector>

class Parser {

	private:
		std::unordered_map<std::string, int> word_freq_map;
		std::unordered_map<int, std::vector<std::string> > sentence_map;

	public:
		Parser();
		~Parser();
	
};

#endif