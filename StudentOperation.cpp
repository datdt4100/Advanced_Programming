#include "StudentOperation.h"

void Student_Info::setName(string&& name) {
	this->name = name;
}
void Student_Info::setScore(double&& score) {
	this->score = score;
}

string&& Student_Info::getName() {
	return std::move(this->name);
}

double&& Student_Info::getScore() {
	return std::move(this->score);
}

double Add(Student_Info* &list, int &size) {
	string name;
	double score;
	cout << "Please type the student's information!\n";
	cout << "Name: \t";
	cin >> name;
	cout << "Score:\t";
	do {
		cin >> score;
		string str;
		getline(cin, str, '\n');
		if (!cin.good() || (str.length() > 0)) {
			cout << "Please type score again: \t";
			cin.clear();
			cin.ignore(0xffffffff, '\n');
			score = -1;
		}
	} while (score < 0);
	size = size + 1;
	Student_Info* newList = new Student_Info[size];
	for (int i = 0; i < size - 1; i++) {
		newList[i].setName(list[i].getName());
		newList[i].setScore(list[i].getScore());
	}
	newList[size - 1].setName(std::move(name));
	newList[size - 1].setScore(std::move(score));
	delete[] list;
	list = newList;
	cout << "Add Successful\n";
	return score;
}
void Remove(Student_Info*& list, int& size) {
	if (size == 0) {
		cout << "No student in list!\n";
		return;
	}
	string name;
	cout << "Type name of student to remove: \t";
	cin >> name;
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (list[i].getName() == name) {
			count++;
		}
	}
	if (count == 0) {
		cout << "No student has such name in list!\n";
		return;
	}
	size = size - std::move(count);
	if (size == 0) {
		delete[] list;
		list = nullptr;
		cout << "Remove successful!\n";
		return;
	}
	Student_Info* newList = new Student_Info[size];
	for (int i = 0, j = 0; i < size; i++) {
		string str = list[j].getName();
		if (str != name) {
			newList[i].setName(std::move(str));
			newList[i].setScore(list[j].getScore());
		}
		else {
			j++;
			i--;
		}
	}
	delete[] list;
	list = newList;
	cout << "Remove successful!\n";
}
void Show(Student_Info* list, int&& size) {
	if (size == 0) {
		cout << "There is no student in list!\n";
		return;
	}
	cout << setw(20) << left << "Name" << setw(10) << "Score" << endl;

	for (int i = 0; i < size; i++) {
		cout << setw(20) << left << list[i].getName() << setw(10) << fixed << setprecision(2) << list[i].getScore() << endl;
	}
}
void ShowBestStudent(Student_Info* list, int&& size) {
	if (size == 0) {
		cout << "There is no student in list!\n";
		return;
	}
	double maxScore = 0;

	for (int i = 0; i < size; i++){
		double pScore = list[i].getScore();
		if (pScore > maxScore) maxScore = pScore;
	}
	cout << setw(20) << left << "Name" << setw(10) << "Score" << endl;

	for (int i = 0; i < size; i++) {
		if (list[i].getScore() == maxScore) {
			cout << setw(20) << left << list[i].getName() << setw(10) << fixed << setprecision(2) << list[i].getScore() << endl;
		}
	}
}