#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <array>

std::vector<std::string> read_dictionary(const std::string filename, const size_t letters){
	std::ifstream file(filename);
	std::vector<std::string> dict;
	for (std::string word; std::getline(file, word);)
		if (word.size()-1 == letters) dict.push_back(word); 
	std::random_shuffle (std::begin(dict), std::end(dict), [] (int i){ return std::rand()%i;});
	return dict;
}

std::vector<std::string> get_words(const size_t letters, const int num, const std::vector<std::string> &dict){
	std::vector<std::string> wordlist;
	for (int i =0; i<num; ++i){
		auto word = dict[i];
		wordlist.push_back(word);
		std::transform(std::begin(word), std::end(word), std::begin(word), ::toupper);
		std::cout<<word<<std::endl;
	}
	return wordlist;
}

std::string get_secret(const std::vector<std::string> &wordlist, const size_t letters){
	auto res = wordlist[std::rand()%letters]; res.pop_back();
	return res;
}

int guess_word(const std::string word, const std::string guess){
	if (word.size() != guess.size())
		{ std::cout<<"Bad Guess"; return 0; }
	int number_correct = 0;
	for (size_t i = 0; i<word.size(); ++i)
		{ if (tolower(word[i]) == tolower(guess[i])) number_correct++; }
	return number_correct;
}

int main(){
	std::srand(unsigned(std::time(0)));
	const std::array<std::array<int,2>,5> settings = {{{4,10},{7,10},{10,10},{13,10},{15,10}}};
	std::cout<<"Difficulty (1-5)? ";
	int difficulty; std::cin>>difficulty;
	
	auto length = settings[difficulty-1][0], amount = settings[difficulty-1][1];

	auto dict = read_dictionary("enable1.txt", length);
	auto wordlist = get_words(length, amount, dict);
	auto word = get_secret(wordlist, amount);

	size_t number_correct = 0, guesses = 0;
	do { std::cout<<"Guess: ("<<4-guesses<<" left)? ";
		 std::string guess; std::cin>>guess;
		 number_correct = guess_word(word, guess); guesses++;
		 std::cout<<number_correct <<"/"<<word.size()<<" Correct" <<std::endl;
		 if (number_correct == word.size()) std::cout<<"You Win!"<<std::endl;
	} while(number_correct != word.size() && guesses < 4);
}