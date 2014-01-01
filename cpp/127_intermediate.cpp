//DailyProgrammer Challenge
//number 127

/*
You will be given an integer N on its own line that represents the number of
 vacation schedule descriptions that follow (each on their separate line). For
 each vacation description, you will be given four integers: the first is the
 person's regular 4-digit phone number, then the 4-digit phone number they
 choose to forward to, then when the vacation starts (measured in days) and
 how long the vacation lasts (measured in days). On the final line of input,
 which is line N + 1, you will be given a day to test the properties of the
 call-forwarding system (as defined in the output description).
Note that the date/time system here is based on a day index system. 1 represents
 the first day, 2 represents the second day, etc. Days do not respect the concept
 of months or years, so expect to simulate any given schedule up to the day
 4,294,967,295. (32-bit unsigned integer max value)
Note that the input's forwarding chain will be guaranteed to not have circular
 forwarding: you can expect that Carol, in the challenge description, will never
 re-forward back to Alice while she is on vacation. As a secondary challenge, if
 you can detect such a failure, in that case simply print the chain in question
 that fails the call forwarding.

 Output Description
For the given day you want to test the system (the last integer from the input
 format), you must print both how many call forwarding are in place and the largest
 forwarding chain. A forwarding chain is the relationship as described in the challenge
 description where Alice forwards to Bob, who in turn forwards to Carol (this chain has a
 value of two, for the two call forwards).
 */

#include <iostream>
#include <deque>
#include <iterator>
#include <fstream>


using std::deque;
using std::cin;
using std::cout;

int getmaxlength(deque<deque<int> > &db)
{
  unsigned int max = 0;
  for (deque<deque<int> >::size_type i = 0; i<db.size(); ++i)
  {
    if (max < db[i].size())
    {
      max = db[i].size()-1;
    }
  }
  return max;
}

int findroutes(int x, int y)
{
  int count = 0;
  static deque<deque<int> > db;
  static deque<int> tmp;
  bool inserted;

  if (db.empty())
  {
    tmp.push_back(y);
    tmp.push_back(x);
    db.push_back(tmp);
    tmp.erase(tmp.begin(), tmp.end());
  }
  else
  {
    deque<deque<int> >::iterator it = db.begin(), end = db.end();
    count = 0;
    while (it!=end)
    {
      deque<int>::iterator it1 = it->begin();
      if (x == *it1)
      {
        tmp.push_back(y);
        std::front_insert_iterator<deque<int> > front_it(db[count]);
        std::copy (tmp.begin(), tmp.begin()+1, front_it);
        tmp.erase(tmp.begin(), tmp.end());
        inserted = true;
      }
      ++it;
      ++count;
    }
    if (!inserted)
    {
      tmp.push_back(y);
      tmp.push_back(x);
      db.push_back(tmp);
      tmp.erase(tmp.begin(), tmp.end());
    }
    inserted = false;
  }
  return getmaxlength(db);
}

void callforwarding(const std::string input)
{
  int x,a,b,c,d,day,tmp=0, max = 0;

  std::ifstream infile;
  infile.open(input.c_str());
  infile>>day;
  infile>>x;

  for (int i = 0; i<x; ++i)
  {
    infile>>a>>b>>c>>d;
    if (day >= c && day < c+d)
    {
      tmp = findroutes(a, b);
      if (max < tmp)
      {
        max = tmp;
      }
    }
  }
  cout<<x<<" call forwarding set up on day "<<day<<std::endl;
  cout<<max<<" call forwardings are the longest chain on day "<<day<<std::endl;
}

int main ()
{
  callforwarding("127.txt");
  return 0;
}
