#include "parser.h"
#include "replacements.h"

Parser::Parser() {

	supported_filetypes[".txt"] = 1;
	supported_filetypes[".pdf"] = 1;	
	supported_filetypes[""] 	= 1;

	boundaries[""] = " ";
	boundaries[" "] = " ";
	boundaries[" "] = ",";
	boundaries[" "] = ".";
	boundaries[" "] = "?";
	boundaries[" "] = "!";
	boundaries[" "] = "-";

}


std::string Parser::ReplaceAll(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}

std::vector<std::string> Parser::VectorizeSentence(std::string str_org) {
	std::string str = str_org;
	std::string token;
	std::string delimiter = " ";
	std::vector<std::string> sentence;
	size_t pos = 0;

	while ((pos = str.find(delimiter)) != std::string::npos) {
		token = str.substr(0, pos);
		if (word_replacement_map.find(token) == word_replacement_map.end()) {
			sentence.push_back(token);
		}
		//std::cout << token << std::endl;
		str.erase(0, pos + delimiter.length());
	}
	if (word_replacement_map.find(str) == word_replacement_map.end()) {
		sentence.push_back(str);
	}
	//std::cout << s << std::endl;
	
	return sentence;
}

Document * Parser::parsePDFFile(std::string filename) {
	std::cout << "Not implemented yet.\n";
	return NULL;
}

Document * Parser::parseTextFile(std::string filename) {
	
	size_t len 		= 0;
	char * line 	= NULL;
	std::unordered_map<std::string, int> word_frequency_map;
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

	doc = ReplaceAll(doc, "\n", " ");

	std::string t_doc = doc;

	std::regex sentencex("[A-Z]([^.?!]){3,}.?!?\??");
	std::smatch sentencematch;
	while (std::regex_search (t_doc, sentencematch, sentencex)) {
		for (auto x : sentencematch) {
			std::string pline = x.str();
			//std::cout << pline << "\n";
			std::vector<std::string> sentence = VectorizeSentence(pline);
        	for(auto word : sentence) {
        		std::cout << word << "\n";
        	}
        	t_doc.replace(sentencematch.position(0), pline.length(), "");
			break;
		}
	}
	std::vector<std::string> sentence_last = VectorizeSentence(t_doc);

	std::cout << t_doc << "--remaining....\n";

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