#include <iostream>
#include <string>
#include <memory>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

class Student{
  public:
    Student(std::string n, std::vector<int> g): grades(g), name(n){}
    double get_average() const { return ave; }
    std::string get_name() const{ return name; }
  private:
    std::vector<int> grades;
    std::string name;
    double ave = calculate_average();
    double calculate_average() const {
     return std::accumulate(std::begin(grades), std::end(grades), 0) / grades.size();
    }
};

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

std::vector<Student> read_data(std::string input_filename){
  std::ifstream input_handle(input_filename);
  std::vector<Student> all_students;
  for (std::string line; std::getline(input_handle, line); ){
    all_students.push_back(process_line(line));
  }
  return all_students;
}

auto sort_students(std::vector<Student> &all_students) -> decltype(all_students){
  std::sort(std::begin(all_students), std::end(all_students),
      [] (const Student &a, const Student &b){
 	return b.get_average() < a.get_average();});
  return all_students;
}

std::vector<Student>::const_iterator lowest_grade(const std::vector<Student> all_students){
  int max = 999;

  std::vector<Student>::const_iterator sid;

  for (std::vector<Student>::const_iterator it = std::begin(all_students); it != std::end(all_students); ++it){
    if (it->get_average() < max){
      sid = it;
    }
  }
  return sid;
}

int main(){
  auto all_students = read_data("input.txt"); 
  auto sorted_students = sort_students(all_students);

  for (auto i : all_students){
    std::cout<< i.get_name() << " " << i.get_average() <<std::endl; }
 
  std::cout<< *lowest_grade(all_students) <<std::endl;
}
