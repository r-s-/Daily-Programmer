#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

std::string camelCase(std::string &input)
{
  auto len = input.size();
  for (std::string::size_type i = 0; i<len; ++i)
  {
    if (input[i] == ' ')
    {
      input.erase(input.begin() + i);
      input[i] = std::toupper(input[i]);
    }
  }
  return input;
}

std::string snakeCase(std::string &input)
{
  auto len = input.size();
  for (std::string::size_type i = 0; i<len; ++i)
  {
    if (input[i] == ' ')
    {
      input[i] = '_'; 
    }
  }
  return input;
}


int main()
{
  int type;
  std::string input;
  std::cin>>type;
  std::cin.ignore(1);

  getline(std::cin, input);

  if (type == 0) input = camelCase(input);
  else if (type == 1) input = snakeCase(input);
  else if (type == 2)
  {
    input = snakeCase(input);
    std::transform(input.begin(), input.end(), input.begin(), ::toupper);
  }

  std::cout<< input <<std::endl;
}
