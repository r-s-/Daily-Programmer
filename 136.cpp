#include <iostream>
#include <vector>
#include <fstream>
#include <numeric>
struct student
{
  std::string name;
  std::vector<int> grades;
  double average;
};

int main()
{
  std::ifstream data("data.txt");
  std::string line, temp_grade;
  std::vector<student> s;
  student temp;
  double sum = 0;
  while (getline(data, line))
  {
    for (std::string::const_iterator i = line.begin(); i<line.end(); ++i)
    {
      while (isalpha(*i))
      {
        temp.name += *i;
        ++i;
      }
      if (*i == ' ')
      {
        ++i;
        while (isdigit(*i))
        {
          temp_grade += *i;
          ++i;
        } --i;
        temp.grades.push_back(std::atoi(temp_grade.c_str()));
        temp_grade.erase();
      }
    }
    temp.average = std::accumulate(temp.grades.begin(), temp.grades.end(), 0.0)/temp.grades.size();
    s.push_back(temp);
    temp.name.erase();
    temp.grades.erase(temp.grades.begin(), temp.grades.end());
  }
for (auto i : s)
  {
    sum += i.average;
  }
  std::cout<<sum/s.size()<<std::endl;

for (auto i : s)
  {
    std::cout<<i.name<<" "<<i.average<<std::endl;
  }
  return 0;
}
