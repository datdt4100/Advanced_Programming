#ifndef _UNIVERSITY_H_
#define _UNIVERSITY_H_
#include "main.h"

class University {
public:
	class Student {
	private:
		string name;
		float score;
		Student* next;
		Student* prev;
		friend class University;
	public:
		Student() : name(""), score(0), next(nullptr), prev(nullptr) {};
		Student(string name, float score, Student* prev = nullptr, Student* next = nullptr) {
			this->name = name;
			this->score = score;
			this->prev = prev;
			this->next = next;
		}
		~Student() { next = nullptr; };
	};

private:
	string name;
	float maxScore;
	Student* list;
	int size;

public:
	University() : maxScore(0), list(nullptr), size(0) {};
	University(string name) {
		this->name = name;
		maxScore = 0;
		list = nullptr;
		size = 0;
	}
	~University() { this->clear(); };
	void clear() ;
	void add(string, float) ;
	void show() ;
	void showBestStu() ;
	void remove(string) ;
};

#endif // !_STUDENT_H_

