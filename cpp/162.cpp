#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

class Encrypt{
public:
	Encrypt(const std::string filename) {
		std::ifstream file(filename);
		std::string word;
			while (std::getline(file, word))
			{ toencrypt.push_back(word); }
	}
	std::string encrypt();
	void output_dict() const;

private:
	std::vector<std::string> dict;
	std::vector<std::string> toencrypt;
	std::string enct;
	std::vector<std::string>::size_type wordnum(std::string);
};

std::string sanitize(const std::string &word){
	std::string builder;
	for (const auto &letter : word){
		if (isalpha(letter))
			builder+= std::tolower(letter);
	}
	return builder;
}

void Encrypt::output_dict() const {
	std::ofstream out("output.txt");
	out<<dict.size()<<"\n";
	for (const auto &i : dict) out<<i<<"\n";
	out<<enct;
}

std::vector<std::string>::size_type Encrypt::wordnum(const std::string word){
	for (std::vector<std::string>::size_type i = 0; i<dict.size(); ++i)
		if (dict[i] == word) { return i; }
	return 99999;
}

std::string Encrypt::encrypt(){
	bool sp = false;
	size_t elem = 0;
	for (const auto &line: toencrypt){
		std::stringstream ss(line);
		std::string word;
		while (ss>>word){
			if (std::find(dict.begin(), dict.end(), sanitize(word)) == dict.end())
			{ dict.push_back(sanitize(word)); }

			enct+= std::to_string(wordnum(sanitize(word)));			

			if (isupper(word[0])){ enct += "^"; }
			enct += " ";
			if (!isalpha(word.back())){
				enct += word.back();
				sp = true;
			}

			if (sp){
				enct += " ";
				sp = false;
			}
		}
		(++elem < toencrypt.size()) ? enct+="R " : enct+= "R E";
	}
	return enct;
}

class Decrypt{
public:
	Decrypt(const std::string filename) {
		std::ifstream file(filename);
		std::string word;

			size_t lines;
			file>>lines;
			for (size_t i = 0; i<lines; ++i){
				file>>word;
				dict.push_back(word);
			}

			for (std::string ch; file>>ch;)
				{ chunks.push_back(ch); }
	}
	std::string decrypt();

private:
	std::vector<std::string> chunks;
	std::vector<std::string> dict;
	std::string decrypted;
};

std::string Decrypt::decrypt() {
	bool sp= false;
	for (const auto &chk : chunks)
	{
		std::stringstream ss(chk);
		std::string part;

		while(ss>>part){
			if (part == "E") break;
			else if (part == "R") { decrypted+= "\n"; sp = false; }
			else if (part == "-") { decrypted+= "-"; sp = false; }
			else if (part.find_first_of(".,?!;:") == 0) { decrypted+=part; sp = true; }
			else{
				if (sp) decrypted+=" ";
				std::string word = dict[std::stoi(part)];
				char m = part[part.size() - 1];
				if (m == '^') word[0] = std::toupper(word[0]);
				else if (m == '!') for (auto &i : word) i = std::toupper(i);

				decrypted+= word;
				sp = true;
			}
		}
	}
	return decrypted;
}

int main(){
	Encrypt enc("input2.txt");
	std::cout<< enc.encrypt() <<std::endl;
	enc.output_dict(); //saves to output.txt

	Decrypt dec("output.txt");
	std::cout<< dec.decrypt() <<std::endl;
}
