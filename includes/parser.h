#ifndef __PARSER_H__
#define __PARSER_H__

// condense-defined
#include "document.h"

// [c/c++]-std define
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <regex>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <bits/stdc++.h> 



class Parser {

	private:
		std::unordered_map<std::string, int> supported_filetypes;
		std::unordered_map<std::string, std::string> boundaries;
		// std::unordered_map<int,std::vector<std::string> > sentence_map;
		Document * parseTextFile(std::string filename);
		Document * parsePDFFile(std::string filename);
		Document * parseFileFromType(std::string filename, std::string filetype);
		std::string ReplaceAll(std::string str, const std::string& from, const std::string& to);
		std::vector<std::string> VectorizeSentence(std::string str);
	public:
		Parser();
		~Parser();
		Document * parseFile(std::string filename);
	
};

#endif