#include <iostream>
#include <vector>

int main()
{

  std::vector<std::string>::size_type num_strings;
  std::vector<std::string> all_strings;
  std::string::size_type maxlength = 0;
  std::string temp_string;

  std::cin>>num_strings;
  std::cin.ignore(1);
  for (size_t i = 0; i<num_strings; i++)
  {
    std::getline(std::cin, temp_string);
    all_strings.push_back(temp_string);
    if (temp_string.length() > maxlength)
    {
      maxlength = temp_string.length();
    }
  }
  for (size_t x = 0; x<maxlength; x++)
    for (size_t i = 0; i<num_strings; i++)
    {
      if (isprint(all_strings[i][x]))
      {
        std::cout<<all_strings[i][x];
      }
      else
      {
        std::cout<<" ";
      }
    }
  std::cout<<std::endl;
}
