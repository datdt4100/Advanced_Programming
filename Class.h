#ifndef CLASS_H
#define CLASS_H
#pragma warning(disable : 4996)
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
enum Sub { MATHS, PHYS, ENGLISH };

struct Date {
	Date() : day_of_week(0), day(0), month(0), year(0) {};
	Date(unsigned char dayofweek, unsigned char d, unsigned char m, unsigned int y) : day_of_week(dayofweek), day(d), month(m), year(y) {};

	unsigned char day_of_week;
	unsigned char day;
	unsigned char month;
	unsigned int year;
	friend ostream& operator <<(ostream &os, const Date obj) {
		os << short int(obj.day) << "/" << short int(obj.month) << "/" << unsigned int(obj.year);
		return os;
	}
};

class People {
protected:
	char* Name;
	Date Birthday;
	int ID_code;
public:
	People() : Name(nullptr), ID_code(0) {};	
	People(People* obj) {
		this->set_BirthDay(obj->get_Birthday());
		this->set_IDCode(obj->get_IDCode());
		this->set_Name((char*)obj->get_Name());
	}
	virtual ~People() {
		delete[] this->Name;
		cout << "Name was deleted! \n";
	}
	virtual void PrintInfo() {
		cout << "\n======= Personal Infomation =======\n";
		cout << "Name:\t" << Name << endl;
		cout << "Birthday: \t" << Birthday << endl;
		cout << "ID Code: \t" << ID_code << endl;
		cout << "====================================\n";
	}
	const char* get_Name() {
		return this->Name;
	}
	const Date get_Birthday() {
		return this->Birthday;
	}
	const int get_IDCode() {
		return this->ID_code;
	}
	void set_Name(char* name) {
		this->Name = new char[strlen(name) + 1];
		strcpy(this->Name, name);
	}
	void set_BirthDay(Date Birthday) {
		this->Birthday = Birthday;
	}
	void set_IDCode(int ID_Code) {
		this->ID_code = ID_Code;
	}
};

class Staff : public People {
protected:
	int DepartmentID;
	Date Joined_Date;
	int level;
public:
	Staff() : DepartmentID(0), level(0) {};
	Staff(Staff* obj) : People(obj) {
		this->set_DepartmentID(obj->get_DepartmentID());
		this->set_JoinedDate(obj->get_JoinedDate());
		this->set_Level(obj->get_Level());
	}
	
	virtual void PrintInfo() : {
		cout << "\n======= Staff's Infomation =======\n";
		cout << "Name:\t" << Name << endl;
		cout << "Birthday: \t" << Birthday << endl;
		cout << "Department ID:\t" << DepartmentID << endl;
		cout << "ID Code: \t" << ID_code << endl;
		cout << "Level: \t" << level << endl;
		cout << "Joined Date:\t" << Joined_Date << endl;
		cout << "====================================\n";
	}
	const int get_DepartmentID() {
		return this->DepartmentID;
	}
	const Date get_JoinedDate() {
		return this->Joined_Date;
	}
	const int get_Level() {
		return this->level;
	}
	void set_DepartmentID(int Dep_ID) {
		this->DepartmentID = Dep_ID;
	}
	void set_JoinedDate(Date date) {
		this->Joined_Date = date;
	}
	void set_Level(int level) {
		this->level = level;
	}
};

class Student : public People {
private:
	int Grade;
	int nProj;
	float* Proj_Score;
	const float Cal_Avg_Score() {
		float sum = 0;
		for (int i = 0; i < nProj; i++) {
			sum += Proj_Score[i];
		}
		return roundf((sum / nProj) * 100) / 100;
	}
public:
	Student() : Grade(0), nProj(0), Proj_Score(nullptr) {};
	Student(Student* obj) : People(obj) {
		this->set_Grade(obj->get_Grade());
		this->set_number_of_project(obj->get_NumberOfProject());
		this->set_ProjectScore((float*)obj->getListScore());
	}
	~Student() {
		delete[] Proj_Score;
		cout << "Score List was deleted!\n";
	}
	void PrintInfo() {
		cout << "\n======= Student's Infomation =======\n";
		cout << "Name:\t" << Name << endl;
		cout << "Birthday: \t" << Birthday << endl;
		cout << "ID Code: \t" << ID_code << endl;
		cout << "Grade: \t" << Grade << endl;
		cout << "Number of project:\t" << nProj << endl;
		cout << "Score of each project: \n";
		for (int i = 0; i < nProj; i++) {
			cout << "Project " << i + 1 << ":\t" << Proj_Score[i] << endl;
		}
		cout << "====================================\n";
	}
	void set_Grade(int grade) {
		this->Grade = grade;
	}
	void set_number_of_project(int nProj) {
		this->nProj = nProj;
		this->Proj_Score = new float[nProj];
		for (int i = 0; i < nProj; i++) {
			Proj_Score[i] = 0;
		}
	}
	void set_ProjectScore(float* listScore) {
		for (int i = 0; i < this->nProj; i++) {
			this->Proj_Score[i] = listScore[i];
		}
	}
	const int get_Grade() {
		return this->Grade;
	}
	const int get_NumberOfProject() {
		return this->nProj;
	}
	const float get_ProjectScore(int nth_Project) {
		return this->Proj_Score[nth_Project - 1];
	}
	const float* getListScore() {
		return this->Proj_Score;
	}
	const float get_AvgScore() {
		return this->Cal_Avg_Score();
	}
};

class Teacher : public Staff {
private:
	int Class;
	Sub Subject;
	Sub Second_Subject;
public:
	Teacher() : Class(0) {};
	Teacher(Teacher* obj) : Staff(obj){
		this->set_Class(obj->get_Class());
		this->set_Subject(obj->get_Subject());
		this->set_SecondSubject(obj->get_Second_Subject());
	}
	void PrintInfo() {
		cout << "\n======= Teacher's Infomation =======\n";
		cout << "Name:\t" << Name << endl;
		cout << "Birthday: \t" << Birthday << endl;
		cout << "Department ID:\t" << DepartmentID << endl;
		cout << "ID Code: \t" << ID_code << endl;
		cout << "Level: \t" << level << endl;
		cout << "Joined Date:\t" << Joined_Date << endl;
		cout << "Class:\t" << this->Class << endl;
		cout << "Subject:\t";
		switch (Subject)
		{
		case MATHS:
			cout << "Maths\n";
			break;
		case PHYS:
			cout << "Physics\n";
			break;
		case ENGLISH:
			cout << "English\n";
			break;
		}
		cout << "Second Subject:\t";
		switch (Second_Subject)
		{
		case MATHS:
			cout << "Maths\n";
			break;
		case PHYS:
			cout << "Physics\n";
			break;
		case ENGLISH:
			cout << "English\n";
			break;
		}
		cout << "====================================\n";
	}
	const int get_Class() {
		return this->Class;
	}
	const Sub get_Subject() {
		return this->Subject;
	}
	const Sub get_Second_Subject() {
		return this->Second_Subject;
	}
	void set_Class(int Class) {
		this->Class = Class;
	}
	void set_Subject(Sub subject) {
		this->Subject = subject;
	}
	void set_SecondSubject(Sub subject) {
		this->Second_Subject = subject;
	}
};

enum Type { people, staff, student, teacher };

class Node {
public:
	People* data;
	Node* next;
	Type dataType;
	Node() : data(NULL), next(NULL), dataType(people) {};
	~Node() {
		delete data;
	}

public:
	static int nPeople(Node* list) {
		int count = 0;
		while (list != nullptr) {
			if (list->dataType == people)
				count++;
			list = list->next;
		}
		return count;
	}

	static int nStaff(Node* list) {
		int count = 0;
		while (list != nullptr) {
			if (list->dataType == staff)
				count++;
			list = list->next;
		}
		return count;
	}

	static int nStudent(Node* list) {
		int count = 0;
		while (list != nullptr) {
			if (list->dataType == student)
				count++;
			list = list->next;
		}
		return count;
	}

	static int nTeacher(Node* list) {
		int count = 0;
		while (list != nullptr) {
			if (list->dataType == teacher)
				count++;
			list = list->next;
		}
		return count;
	}

	static void Add(Node* &list, People* data, Type ObjectType) {
		if (list == nullptr) {
			list = new Node();
			list->data = data;
			list->dataType = ObjectType;
		}
		else {
			Node* tmp = list;
			while (tmp->next != nullptr) {
				tmp = tmp->next;
			}
			tmp->next = new Node();
			tmp->next->data = data;
			tmp->next->dataType = ObjectType;
		}
	}
	static void Remove(Node*& list, char* Name, Type ObjectType) {
		Node* temp = list;
		Node* prev = NULL;

		
		if (temp != NULL && temp->dataType == ObjectType && strcmp(temp->data->get_Name(), Name) == 0)
		{
			list = temp->next; // Changed head
			delete temp;            // free old head
		}
		else
		{
			while (temp != NULL && (temp->dataType != ObjectType || strcmp(temp->data->get_Name(), Name) != 0))
			{
				prev = temp;
				temp = temp->next;
			}
			if (temp == NULL)
				return;
			prev->next = temp->next;
			delete temp;
		}
	}
};
#endif // !CLASS_H

