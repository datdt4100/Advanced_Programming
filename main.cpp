
#include "University.h"
int main()
{
	int selection = 0;
	University* BK = new University("Ho Chi Minh city University of Technology");
	bool run = 1;
	
	
	cout << "1. Add new student.\n";
	cout << "2. Remove a student from the list based on the name input.\n";
	cout << "3. Display the list of all students and the scores.\n";
	cout << "4. Display the best student's information.\n";
	cout << "5. Exit\n";
	cout << setw(20) << "" << "-----------" << endl;
	
	while (run) {
		cout << "Press key for corressponding functionalities:\t";
		do {
			cin >> selection;
			string input;
			getline(cin, input, '\n');
			
			if (!cin.good() || input.length() != 0 ||
				selection < 1 || selection > 5) {
				cout << "Please press again key: \t";
				selection = 0;
				cin.clear();
				cin.ignore(0xffffffff, '\n');
			}
		} 		while (selection < 1 || selection > 5);
		switch (selection) {
		case 1:
		{
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
			BK->add(name, score);
			break;
		}
		case 2:
		{
			string name;
			cout << "Type name of student to remove: \t";
			cin >> name;
			BK->remove(name);
			break;
		}
		case 3:
		{
			BK->show();
			break;
		}
		case 4:
		{
			BK->showBestStu();
			break;
		}
		case 5:
		{
			run = 0;
			break;
		}
		}
	}
	delete BK;
	return EXIT_SUCCESS;
}

