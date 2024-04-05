#include <iostream>
using std::string;

class abstractEmployee {
	virtual void askForPromotion() = 0;
};

class Employee: abstractEmployee {
private:
	string Company;
	int Age;
protected: 
	string Name;
public:
	void setName(string name) {
		Name = name;
	}
	string getName() {
		return Name;
	}
	void setAge(int age) {
		if(age >= 18)
		Age = age;
	}
	int getAge() {
		return Age;
	}
	void setCompany(string company) {
		Company = company;
	}
	string getCompany() {
		return Company;
	}

	void introduceYourself() {
		std::cout << "Name - " << Name << std::endl;
		std::cout << "Company - " << Company << std::endl;
		std::cout << "Age - " << Age << std::endl;
	}
	Employee(string name , string company, int age) {
		Name = name;
		Company = company;
		Age = age;
	}
	void askForPromotion() {
		if (Age > 20)
			std::cout << Name << " got promoted!" << std::endl;
		else
			std::cout << Name << " was not promoted" << std::endl;
	}
	void Work() {
		std::cout << Name << " has gone to work" << std::endl;
	}
};
class Developer: public Employee {
public:
	string favoriteProgrammingLanguage;
	Developer(string name, string company, int age, string favProgrammingLanguage)
		:Employee(name, company, age)
	{
		favoriteProgrammingLanguage = favProgrammingLanguage;
	}
	void fixBug() {
		std::cout << Name << " fixed bug using " << favoriteProgrammingLanguage << std::endl;
	}
	virtual void Work() {
		std::cout << Name << " is writing code" << std::endl;
	}
};
class Teacher : public Employee {
public:
	string Subject;
	Teacher(string name, string company, int age, string subject)
		:Employee(name, company, age)
	{
		Subject = subject;
	}
	void prepareLesson() {
		std::cout << Name << " has prepared a " << Subject << " lesson" << std::endl;
	}
	void Work() {
		std::cout << Name << " is teaching " << Subject << std::endl;
	}
};

int main() {

	Employee employee1 = Employee("Aiya", "CPH", 18);
	Employee employee2 = Employee("Jimmy", "CPH", 21);
	Developer d = Developer("Mark", "google", 30, "C++");
	Teacher t = Teacher("John", "CPH", 45, "History");

}
