#ifndef __DOCUMENT_H__
#define __DOCUMENT_H__

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include <unordered_map>

class Document {
	private:
		
		unsigned int total_word_usages;
		unsigned int number_of_sentences;

		std::unordered_map<unsigned int, std::vector<std::string > > text;
		std::unordered_map<unsigned int, float> sentence_entropy_map;
		std::unordered_map<std::string,  float> word_frequency_map;

		float SentenceEntropy(std::vector<std::string> sentence);

	public:
		// std.
		Document(std::vector<std::vector<std::string>> sentences);
		~Document();

		//Funcs
		void PrintSentence();
		void PrintDocument();

};

#endif
