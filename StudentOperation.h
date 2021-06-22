#ifndef _Student_Lib_
#define _Student_Lib_
#include "main.h"

class Student_Info {
private:
	string name;
	double score;
public:
	Student_Info() : name(""), score(0) {};
	void setName(string&&);
	void setScore(double&&);
	string&& getName();
	double&& getScore();
	~Student_Info() {};
};

double Add(Student_Info*&, int&);
void Remove(Student_Info*&, int&);
void Show(Student_Info*, int&&);
void ShowBestStudent(Student_Info*, int&&);

#endif // !_Student_Lib_

