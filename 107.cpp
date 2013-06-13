//DailyProgrammer Challenge
//number 107
//r-s

/*
Verify the Infinite Monkey Theorem[1] .
Well that's a bit hard, so let's go with this. Using any method of your choice, generate a 
random string of space-separated words. (The simplest method would be to randomly choose, 
with equal probability, one of the 27 characters including letters and space.) Filter the 
words using a word list[2] of your choice, so that only words in the word list are actually 
output.
*/


#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <random>
#include <ctime>

void monkies(std::set<std::string> db)
{
  std::string monkey;
  while(1)
  {
    for(int i = 0; i<rand()%6+1; i++)
    {
      monkey.push_back((rand()%(122-97))+97);  
      
    }
     std::set<std::string>::iterator it;
     it = db.find(monkey);
     if (it != db.end())
     std::cout<<monkey<<" ";
     monkey.erase(monkey.begin(), monkey.end()); 
  }
}

std::set<std::string> readin(std::string input)
{
  std::set<std::string> db;
  std::string in;
  std::ifstream file;
  file.open(input.c_str());
  
  while (file>>in)
  {
    if (in.length() > 5)
      db.insert(in);
  }
  return db;  
}

int main()
{
  srand(time(0));
  monkies(readin("words107.txt"));
return 0;
}