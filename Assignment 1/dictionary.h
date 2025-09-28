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

#ifndef SENECA_DICTIONARY_H
#define SENECA_DICTIONARY_H
#include "settings.h"

namespace seneca {

	enum class PartOfSpeech
	{
		Unknown,
		Noun,
		Pronoun,
		Adjective,
		Adverb,
		Verb,
		Preposition,
		Conjunction,
		Interjection,
	};
	struct Word
	{
		std::string m_word{};
		std::string m_definition{};
		PartOfSpeech m_pos = PartOfSpeech::Unknown;
	};
 //needs rule of 5
	class Dictionary {

		Word* m_wordArr{};
		size_t m_wordArrSize{};

	public:

		Dictionary() {};
		Dictionary(const char* filename);

		//Copy
		Dictionary(const Dictionary& src);
		Dictionary& operator=(const Dictionary& src);

		//Move
		Dictionary(Dictionary&& src);
		Dictionary& operator=(Dictionary&& src);

		void searchWord(const char* word);

		~Dictionary();

	};

	std::ostream& operator<<(std::ostream& os, const PartOfSpeech& obj);

}


#endif // !

