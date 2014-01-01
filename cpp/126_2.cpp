#include <iostream>
#include <cmath>

int psp(unsigned int x)
{
  unsigned int p = 32;
  std::cout<<"P: "<<p<<std::endl;

  while (p > 0)
  {
    for (int i = 1; i<=x; ++i)
    {
      if (pow(i, p)==x)
      {
        return p;
      }
    }
    p--;
  }
  std::cout<<"P: "<<p<<std::endl;
  return p;
}

int main()
{
  std::cout<<psp(25)<<std::endl;
  return 0;
}