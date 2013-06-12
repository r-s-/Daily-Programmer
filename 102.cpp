#include <iostream>
#include <set>
#include <fstream>

bool ncset(std::string word, unsigned int x)
{
  std::set<char> list;
  for (std::string::size_type i = 0; i<word.length(); ++i)
  {
    list.insert(word[i]);
  }
return list.size() <= x ? true : false;
}

int main()
{
  std::string word;
  int count = 0;
  std::ifstream file;
  file.open("102.txt");

  while (file>>word)
  {
  if (ncset(word, 4))
     count++;
  }
  std::cout<<"Count: "<<count;
return 0;
}