#include <iostream>
#include <functional>
#include <string>
#include <memory>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

using std::min_element;
using std::begin; 
using std::end;

class Student{
  public:
    Student(std::string n, std::vector<int> g): grades(g), name(n){}
    double get_average() const { return ave; }
    std::string get_name() const{ return name; }
    bool operator<(const Student &a) const{
      return this->get_average() < a.get_average(); }
    bool operator>(const Student &a) const{
      return this->get_average() > a.get_average(); }

  private:
    std::vector<int> grades;
    std::string name;
    double ave = calculate_average();
    double calculate_average() const {
      return std::accumulate(begin(grades), end(grades), 0) / grades.size();}
};
using SVec = std::vector<Student>;

Student process_line(std::string line){
  std::stringstream ss(line);
  std::string tmp, name, grade;
  std::vector<int> grades;
  int p = 0;
  while (ss>>tmp){
   if (p == 0){
     name = tmp; ++p;
   } else if (p == 1){
     name += " " +  tmp; ++p;
   } else if (p > 1){
     grade = tmp; ++p;
     grades.push_back(std::stoi(tmp));
   }
  }
  return Student(name, grades);
}

SVec read_data(const std::string input_filename){
  std::ifstream input_handle(input_filename);
  std::vector<Student> all_students;
  for (std::string line; std::getline(input_handle, line); ){
    all_students.push_back(process_line(line));}
  return all_students;
}

template<typename C>
Student dispatch(const SVec &students, C c)
{
  return *min_element(begin(students), end(students),c);
}

int main(){
  auto all_students = read_data("input.txt"); 
  auto highest_grade = dispatch(all_students, std::greater<Student>());
  auto lowest_grade = dispatch(all_students, std::less<Student>());
  std::cout<<"highest: " << highest_grade.get_name() << std::endl;
  std::cout<<"lowest: " << lowest_grade.get_name() << std::endl;
}
