//DailyProgrammer Challenge
//number 127
//r-s

/*
Write a function that takes a string s and an integer n, and returns whether or not the string s contains at most n different characters.
For example, ncset("aacaabbabccc", 4) would return true, because it contains only 3 different characters, 'a', 'b', and 'c', and 3 ≤ 4.
For how many English words (yes, it's time for this dictionary again!) does ncset(word, 4) hold?
http://code.google.com/p/dotnetperls-controls/downloads/detail?name=enable1.txt
*/

#include <iostream>
#include <set>
#include <fstream>

bool ncset(std::string word, size_t x)
{
  std::set<char> list;

  for (std::string::size_type i = 0; i<word.length(); ++i)
    list.insert(word[i]);

  return list.size() <= x ? true : false;
}

int main()
{
  std::ifstream file("words107.txt");

  int count = 0;
  for (std::string word; file>>word; )
  {
    if (ncset(word, 4))
      count++;
  }
  
  std::cout << "Count: " << count <<std::endl;
}
