/*
Problem #161

In the past, we've already tackled the challenge of deciding in which order to do certain jobs. 
However, now you need to work out which worker gets which job. What if some workers are only 
qualified to do certain jobs? How do you ensure there are no jobs or workers left out? Your 
challenge now is (given some jobs that need to be done, and some workers and the jobs they're 
allowed to do) compute who should be given which job, so no-one is doing a job they are not 
qualified for.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Person{
public:
	Person(std::string name, std::vector<std::string> skills) : _name(name), _skills(skills){}
	std::vector<std::string>::size_type skill_count() const { return _skills.size(); }
	std::string first_skill() const { return _skills[0]; }
	std::string get_name() const { return _name; }
	
	inline void erase_skill(std::string skill){ 
		for (auto i = std::begin(_skills); i!= std::end(_skills); 
			(*i == skill) ? i = _skills.erase(i) : ++i){} }

private:
	std::string _name;
	std::vector<std::string> _skills;
};

class Job{
public:
	Job(std::string title) : _title(title) {}
	void assign_job(const std::string name){ _assigned = name; }
	bool assigned() const{ return (_assigned == "") ? false : true; }
	std::string get_assigned() const { return _assigned; }
	std::string get_title() const { return _title; }
private:
	std::string _title, _assigned = "";
};

bool jobs_not_assigned(const std::vector<Job> &jobs){
	for (const auto &i: jobs) { if (!i.assigned()) return true; }
	return false;
}

void assign_jobs(std::vector<Person> &workers, std::vector<Job> &jobs)
{
	while(jobs_not_assigned(jobs)){
		std::vector<std::string>::size_type	leastSkills = 9999;
		for (const auto &worker : workers){
			auto skill_count = worker.skill_count();
			if (skill_count < leastSkills && skill_count > 0) leastSkills = skill_count;
		}
		auto fewestSkills = std::find_if(workers.begin(), workers.end(), 
			[leastSkills](Person const &w) { return w.skill_count() == leastSkills; } );

		auto firstSkill = fewestSkills->first_skill();

		auto job_it = std::find_if(jobs.begin(), jobs.end(), 
			[firstSkill] (Job const &j) { return j.get_title() == firstSkill; });

		job_it->assign_job(fewestSkills->get_name());
		workers.erase(fewestSkills);

		for (auto &i : workers){ i.erase_skill(firstSkill); }
	}
}

int main()
{
	std::vector<Person> people = {
	Person("Alice", {"GUI", "Backend", "Support"}),
	Person("Bill", {"Finances", "Backend"}),
	Person("Cath", {"Documentation", "Finances"}),
	Person("Jack", {"Documentation", "Frontend", "Support"}),
	Person("Michael", {"Frontend"}),
	Person("Steve", {"Documentation", "Backend"})};

	std::vector<Job> jobs = {
	Job("GUI"),
	Job("Documentation"),
	Job("Finances"),
	Job("Frontend"),
	Job("Backend"),
	Job("Support")};

	assign_jobs(people,jobs);

	for (auto &i : jobs)
		{ std::cout<<i.get_title()<<" : "<<i.get_assigned() <<std::endl; }
}