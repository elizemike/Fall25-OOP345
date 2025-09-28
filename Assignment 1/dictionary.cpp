////////////////////////////////////////////////////////////////////
// Name : Elizabeth Esede
// Email : eesede@myseneca.ca
// Student ID: 120651245
// Date Completed:
//////////////////////////////////
// I declare that this submission is the result of my own work 
// and I only copied the code that my professor provided to complete
// my assignments.This submitted piece of work has not been shared 
// with any other student or 3rd party content provider.
////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include "dictionary.h"
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include "settings.h"


namespace seneca {



	Dictionary::Dictionary(const char* filename)
	{

		std::ifstream fin(filename);

		if (fin) {
			
			m_wordArrSize = 0;
			std::string x;

			while (std::getline(fin,x)){

				if (!x.empty()) {

					m_wordArrSize++;

				}	
			}

			
			fin.clear();
			fin.seekg(0);

			m_wordArr = new Word[m_wordArrSize];
			
			
			for (size_t i = 0; i < m_wordArrSize; i++) {

				std::string tempWord{};
				getline(fin, tempWord, ',');
				m_wordArr[i].m_word = tempWord;

				std::string tempPos;
				getline(fin, tempPos, ',');

				if (tempPos == "n." || tempPos == "n. pl.") {
					m_wordArr[i].m_pos = PartOfSpeech::Noun;
				}
				else if (tempPos == "adv.") {
					m_wordArr[i].m_pos = PartOfSpeech::Adverb;
				}
				else if (tempPos == "a.") {
					m_wordArr[i].m_pos = PartOfSpeech::Adjective;
				}
				else if (tempPos == "v." || tempPos == "v. i." || tempPos == "v. t." || tempPos == "v. t. & i.") {
					m_wordArr[i].m_pos = PartOfSpeech::Verb;

				}
				else if (tempPos == "prep.") {
					m_wordArr[i].m_pos = PartOfSpeech::Preposition;

				}
				else if (tempPos == "pron.") {
					m_wordArr[i].m_pos = PartOfSpeech::Pronoun;
						
				}
				else if (tempPos == "conj.") {
					m_wordArr[i].m_pos = PartOfSpeech::Conjunction;
				}
				else if (tempPos == "interj.") {
					m_wordArr[i].m_pos = PartOfSpeech::Interjection;
				}
				else {
					m_wordArr[i].m_pos = PartOfSpeech::Unknown;
				}
				
				std::string tempDef;
				getline(fin, tempDef);

				m_wordArr[i].m_definition = tempDef;

			}

		}
		else {

			delete[] m_wordArr;
			m_wordArr = nullptr;
			m_wordArrSize = 0;

		}

	}

	Dictionary::Dictionary(const Dictionary& src)
	{
		*this = src;
	}

	Dictionary& Dictionary::operator=(const Dictionary& src)
	{
		if (this != &src) {

			delete[] m_wordArr;
			m_wordArr = nullptr;
			m_wordArrSize = 0;

			if (src.m_wordArrSize > 0) {

				m_wordArrSize = src.m_wordArrSize;

				m_wordArr = new Word[src.m_wordArrSize];

				for (auto i = 0; i < m_wordArrSize; i++) {


					m_wordArr[i] = src.m_wordArr[i];

				}

			}


		}


		return *this;
	}

	Dictionary::Dictionary(Dictionary&& src)
	{

		*this = std::move(src);
	}

	Dictionary& Dictionary::operator=(Dictionary&& src)
	{
		if (this != &src) {

			delete[] m_wordArr;
			m_wordArr = nullptr;

			m_wordArr = src.m_wordArr;
			src.m_wordArr = nullptr;

			m_wordArrSize = src.m_wordArrSize;
			src.m_wordArrSize = 0;

		}

		return *this;
	}

	void Dictionary::searchWord(const char* word)
	{
	
		bool firstWord{ true };
		bool match = false; 

		for (auto i = 0; i < m_wordArrSize; i++) {

			if (m_wordArr[i].m_word == word) {

				if (firstWord) {
					std::cout << word;
					firstWord = false;
				}
				else {

					size_t len = std::strlen(word);

					for (auto j = 0; j < len; j++) {
						std::cout << ' ';
					}



				}


				std::cout << " - ";

				if (g_settings.m_verbose && m_wordArr[i].m_pos != PartOfSpeech::Unknown) {
					std::cout << "(" << m_wordArr[i].m_pos << ") ";
				}
				
				
				std::cout << m_wordArr[i].m_definition << std::endl;
				match = true;

				if (!g_settings.m_show_all) {
					return;
				}

			}

		}

		if (!match) {
			std::cout << "Word '" << word << "' was not found in the dictionary." << std::endl;
		}



	}

	Dictionary::~Dictionary()
	{
		delete[] m_wordArr;
		m_wordArr = nullptr;
		m_wordArrSize = 0;
	}

	std::ostream& operator<<(std::ostream& os, const PartOfSpeech& obj)
	{

		if (obj == PartOfSpeech::Noun) {
			os << "noun";
		}
		else if (obj == PartOfSpeech::Pronoun) {
			os << "pronoun";
		}
		else if (obj == PartOfSpeech::Adjective) {
			os << "adjective";
		}
		else if (obj == PartOfSpeech::Adverb) {
			os << "adverb";
		}
		else if (obj == PartOfSpeech::Verb) {
			os << "verb";
		}
		else if (obj == PartOfSpeech::Preposition) {
			os << "preposition";
		}
		else if (obj == PartOfSpeech::Conjunction) {
			os << "conjunction";
		}
		else if (obj == PartOfSpeech::Interjection) {
			os << "interjection";
		}
		else {
			os << "unknown";
		}


		return os;
	}

}