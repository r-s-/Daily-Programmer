#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

void print_words(const std::vector<int> &check, 
		 const std::vector<std::string> &words){
    for (const auto &i : check){
	try { std::cout<< words.at(i-1)<<" "; }
	catch (const std::out_of_range& oor) {}
    }
  std::cout<<std::endl;
}

int main(){
    const std::string example = "...You...!!!@!3124131212 Hello have this is a --- string Solved !!...? to test @\n\n\n#!#@#@%$**#$@ Congratz this!!!!!!!!!!!!!!!!one ---Problem\n\n";
    const std::string allow = "abcdefghijklmnopqrstuvwxiyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const std::vector<int> check = {12,-1,1,-100,4,1000,9,-1000,16,13,17,15};
    std::vector<std::string> words;

    size_t apos = 0;
    for (auto pos = example.find_first_not_of(allow);
	 pos < example.size();
	 pos = example.find_first_not_of(allow, ++pos)){

	auto tmp = example.substr(apos, pos-apos);
	if (tmp != "") words.push_back(tmp);
	apos = pos + 1;
    }
    print_words(check, words);
}
