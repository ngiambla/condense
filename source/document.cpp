#include "document.h"


Document::Document(std::vector<std::vector<std::string>> sentences) {
	// Calculate Word Frequencies.
	total_word_usages = 0;
	number_of_sentences = 0;
	for(auto sentence : sentences) {
		text[number_of_sentences++] = sentence;
		for(auto word : sentence) {
			if (word_frequency_map.find(word) != word_frequency_map.end()) {
				word_frequency_map[word] += 1.0;
			} else {
				word_frequency_map[word] = 1.0;
			}
			++total_word_usages;
		}
	}


	for(auto word : word_frequency_map) {
		word_frequency_map[word.first] /= total_word_usages; 
		//std::cout << word.first << " ["<< word_frequency_map[word.first] <<"]\n";
	}

	for(auto pair: text) {
		sentence_entropy_map[pair.first] = SentenceEntropy(pair.second);	
		std::cout << "sid[" << pair.first << "] [" << sentence_entropy_map[pair.first] << "]\n";
		for(auto thing : pair.second) {
			std::cout << thing << " ";
		}
		std::cout << "\n";

	}

	//std::vector<std::pair<std::string, float>> elems(word_frequency_map.begin(), word_frequency_map.end());
	//std::sort(elems.begin(), elems.end(), [](std::pair<std::string, float> const& a, std::pair<std::string, float> const& b ) -> bool { return a.second>b.second; });	

	//for(auto elem : elems) {
	//	std::cout << elem.first << " : " << elem.second << "\n";
	//}

	std::cout << "Total Words: "<< total_word_usages << "\n";



}

float Document::SentenceEntropy(std::vector<std::string> sentence) {
	float sum = 0;
	for(auto word : sentence) {
		sum += word_frequency_map[word]*(log(word_frequency_map[word])/log(2));
	}
	return (-1*sum);
}


void Document::PrintSentence() {

}

void Document::PrintDocument() {

}

Document::~Document() {
	
}