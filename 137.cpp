#include <iostream>
#include <string>
#include <vector>

int main()
{
  size_t num_strings;
  std::string tempstring;
  std::vector<std::string> allstrings;
  std::string::size_type maxlength = 0;

  std::cout<<"Enter number of strings: "<<std::endl;
  std::cin>>num_strings;

  for (size_t i = 0; i<num_strings; i++)
  {
    std::cout<<"Enter string number "<<i+1;
    std::cin>>tempstring;
    allstrings.push_back(tempstring);
    if (tempstring.length() > maxlength) maxlength = tempstring.length();
  }
  
  //print strings vertically
  for (std::string::size_type x = 0; x<maxlength; x++){
    for (size_t i = 0; i<num_strings; i++)
    {
      char t = allstrings[i][x];
      if (isalpha(t))
        std::cout<<t;
      else std::cout<<" ";  
    } 
  std::cout<<std::endl;
  }








  return 0;
}
