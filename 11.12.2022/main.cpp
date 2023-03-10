#include <iostream>
#include<fstream>
#include<string>
using namespace std;

#define DELIMITR "\n--------------------------------------------------------\n"

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age

class Human
{
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name() const
	{
		return last_name;
	}
	const std::string& get_first_name() const
	{
		return first_name;
	}
	unsigned int get_age() const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	
	// Constructor:
	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	// Methods:

	virtual void info()const
	{
		cout << last_name << " " << first_name << " " << age << " лет\n";
	}
};

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance


class Student:public Human
{
	std::string speciality;
	std::string group;
	double rating; //успеваемость
	double attendance; //посещаемость
public:
	const std::string& get_speciality() const
	{
		return speciality;
	}
	const std::string& get_group() const
	{
		return group;
	}
	double get_rating() const
	{
		return rating;
	}
	double get_attendance() const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}
	//Constructors:
	Student	(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS):Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance (attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}
	
	// Methods:

	void info()const override
	{
		Human::info();
		cout << speciality << " " << group << " " << rating << " " << attendance << endl;
	}
};

#define TEACHER_TAKE_PARAMETERS const std::string& speciality, unsigned int experience
#define TEACHER_GIVE_PARAMETERS speciality, experience


class Teacher :public Human
{
	std::string speciality;
	unsigned int experience;
public:
	
const std::string& get_speciality() const
	{
		return speciality;
	}
	unsigned int get_experience() const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	//Constructors:
	Teacher (HUMAN_TAKE_PARAMETERS,TEACHER_TAKE_PARAMETERS):Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}

	// Methods:

	void info()const override
	{
		Human::info();
		cout << speciality << " " << experience << endl;
	}
};

class Graduate :public Student
{
	std::string subject;
public:
	const std::string& get_subject() const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	//Constructors:
	Graduate
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, const std::string& group, double rating, double attendance,
		const std::string& subject
	) :Student(last_name, first_name, age, speciality, group, rating, attendance)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}

	// Methods:

	void info()const override
	{
		Student::info();
		cout << subject << endl;
	}
};

//#define INHERITANCE
#define POLYMORPHISM

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef INHERITANCE
Human human("Montana", "Antonio", 25);
	human.info();

	Student stud("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 80, 90);
	stud.info();

	Teacher white("White", "Walter", 50, "Chemistry", 25);
	white.info();

	Graduate grad("Schrader", "Hank", 40, "Criminalistic", "OBN", 85, 80, "How to catch Heisenberg");
	grad.info();
#endif // INHERITANCE

#ifdef POLYMORPHISM
	/*Human* p_human1 = new Student("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 80, 90);
	Human* p_human2 = new Teacher("White", "Walter", 50, "Chemistry", 25);
	p_human1->info();
	p_human2->info();*/

	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 80, 90),
		new Teacher("White", "Walter", 50, "Chemistry", 25),
		new Graduate("Schrader", "Hank", 40, "Criminalistic", "OBN", 85, 80, "How to catch Heisenberg"),
		new Student("Vercetti", "Tomas", 30, "Criminalistic", "Vice", 85, 98),
		new Teacher("Diaz", "Ricardo", 50, "Weapons destribution", 20)
	};
	cout << DELIMITR << endl;
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		group[i]->info();
		cout << DELIMITR << endl;
	}
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
#endif // POLYMORPHISM

}