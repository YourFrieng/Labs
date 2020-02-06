#include <iostream>

class Workers {

public:
	std::string name, post;
	int age, experiance;
	void SetPrivDate(std::string lst_name, std::string prv_wrk);
	void print_all_date();
	void print();
private:
	std::string last_name, prev_work;

};


int main()
{
	Workers worker1;
	worker1.name = "Natalie";
	worker1.age = 25;
	worker1.experiance = 5;
	worker1.post = "Product Manager";
	worker1.SetPrivDate("Glumberg", "GL");
	worker1.print_all_date();
	worker1.print();
}

void Workers::SetPrivDate(std::string lst_name, std::string prv_wrk)
{
	last_name = lst_name;
	prev_work = prv_wrk;
}

void Workers::print_all_date()
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Last Name: " << last_name << std::endl;
	std::cout << "Age: " << age << std::endl;
	std::cout << "Post: " << post << std::endl;
	std::cout << "Experiance: " << experiance << std::endl;
	std::cout << "Previous work: " << prev_work << std::endl;
}

void Workers::print()
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Age: " << age << std::endl;
	std::cout << "Experiance: " << experiance << std::endl;
}
