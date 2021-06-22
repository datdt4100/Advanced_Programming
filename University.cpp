#include "University.h"
void University::add(string name, float score) {
	if (this->list == nullptr) {
		this->list = new Student(name, score);
	}
	else {
		Student* p = this->list;
		while (p->next != nullptr) {
			p = p->next;
		}
		p->next = new Student(name, score, p);
	}
	this->maxScore = (maxScore < score) ? score : maxScore;
	size++;
}
void University::show() {
	Student* p = this->list;
	if (p == nullptr) {
		cout << "There is no student in list!\n";
		return;
	}
	cout << setw(20) << left << "Name" << setw(10) << "Score" << endl;
	
	while (p != nullptr) {
		cout << setw(20) << left << p->name << setw(10) << setprecision(2) << p->score << endl;
		p = p->next;
	}
}
void University::remove(string name) {
	Student* p = this->list;
	bool deleteStu = 0;
	while (p != nullptr) {
		if (p->name == name) {
			deleteStu = 1;
			if (this->size == 1) {
				this->list = nullptr;
				delete p;
				p = nullptr;
			}
			else if (p->prev == nullptr) {
				this->list = p->next;
				p = p->next;
				delete p->prev;
			}
			else if (p->next == nullptr) {
				p->prev->next = nullptr;
				delete p;
				p = nullptr;
			}
			else {
				p->prev->next = p->next;
				p->next->prev = p->prev;
				Student* tmp = p;
				p = p->next;
				delete tmp;
			}
			size--;
		}
		else {
			p = p->next;
		}
	}
	if (!deleteStu) cout << "No student has such name in list;\n";
	else cout << "Remove successful\n";
}
void University::clear() {
	Student* p = this->list;
	while (p != nullptr) {
		Student* tmp = p;
		p = p->next;
		delete tmp;
	}
	this->list = nullptr;
	this->size = 0;
	this->maxScore = 0;
}
void University::showBestStu() {
	if (this->list == nullptr) {
		cout << "There is no student in list!\n";
		return;
	}
	Student* p = this->list;
	cout << "------Best Students-------\n";
	cout << setw(20) << left << "Name" << setw(10) << "Score" << endl;
	while (p != nullptr) {
		if (p->score == maxScore) {
			cout << setw(20) << left << p->name << setw(10) << setprecision(2) << p->score << endl;
		}
		p = p->next;
	}
}