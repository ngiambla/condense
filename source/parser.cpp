#include "parser.h"
#include "replacements.h"

Parser::Parser() {

	supported_filetypes[".txt"] = 1;
	supported_filetypes[".pdf"] = 1;	
	supported_filetypes[""] 	= 1;

}


std::string Parser::ReplaceAll(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}

Document * Parser::parsePDFFile(std::string filename) {
	std::cout << "Not implemented yet.\n";
	return NULL;
}

Document * Parser::parseTextFile(std::string filename) {
	
	size_t len 		= 0;
	char * line 	= NULL;
	std::string doc 		= "";
	Document * D 	= new Document();
	FILE * fp 		= fopen(filename.c_str(), "r");
	
	if (fp == NULL) {
		return NULL;	
	}

	while ((getline(&line, &len, fp)) != -1) {
		doc += line;
	}

	fclose(fp);	
	if(line) {
		free(line);	
	}

	for(const auto &x : word_replacement_map) {
		doc = ReplaceAll(doc, x.first, x.second);
	}
	doc = ReplaceAll(doc, "\n", " ");


	std::string t_doc = doc;

	std::regex sentencex("[A-Z]([^.?!]){3,}.?!?\??");
	std::smatch sentencematch;
	while (std::regex_search (t_doc, sentencematch, sentencex)) {
		for(auto x : sentencematch) {
			std::string pline = x.str();
			std::cout << "[S] "<< pline << "\n";


			/*	
				std::string delimiter = " ";
				size_t pos = 0;
				std::string token;
				while ((pos = s.find(delimiter)) != std::string::npos) {
					token = s.substr(0, pos);
					std::cout << token << std::endl;
					s.erase(0, pos + delimiter.length());
				}
				std::cout << s << std::endl; 
			*/

			break;
		}
		t_doc = sentencematch.suffix().str();
	}
	std::cout << t_doc << "--remaining....\n";



	std::cout << "Not implemented yet.\n";

	return NULL;
}

Document * Parser::parseFileFromType(std::string filename, std::string filetype) {
		if(".txt" == filetype)
			return parseTextFile(filename);
		if(".pdf" == filetype)
			return parsePDFFile(filename);
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