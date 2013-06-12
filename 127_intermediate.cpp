//DailyProgrammer Challenge
//number 127

#include <iostream>     
#include <deque>     
#include <iterator>
#include <fstream>

using std::deque; using std::cin; using std::cout;

int getmaxlength(deque<deque<int> > &db)
{
  unsigned int max = 0;
  for (deque<deque<int> >::size_type i = 0; i<db.size(); ++i)
  {
    if (max < db[i].size())
      max = db[i].size()-1;
  }
  return max;
}

int function(int x, int y)
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
          ++it; ++count;
        }       
        if (!inserted)
          {
            tmp.push_back(y); tmp.push_back(x);
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
 infile>>day; infile>>x;
 
 for (int i = 0; i<x; ++i)
 {
   infile>>a>>b>>c>>d;
     if (day >= c && day < c+d)
     {
       tmp = function(a, b);
       if (max < tmp)
         max = tmp;
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
