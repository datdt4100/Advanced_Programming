
#include "Class.h"

int main() {
    Node* list = NULL;
    char* nameCheckRemove = nullptr;

    // Add to list 5 staff, 5 teacher, and 5 student
    for (int i = 0; i < 15; i++) {
        bool checkRemove = 0;
        int n = rand() % 3;
        for (int j = 0; j < 2; j++) {
            bool swap = 0;
            switch (n) {
            case 0:
                if (Node::nStaff(list) == 5) {
                    n = 1;
                    swap = 1;
                }
                break;
            case 1:
                if (Node::nStudent(list) == 5) {
                    n = 2;
                    swap = 1;
                }
                break;
            case 2:
                if (Node::nTeacher(list) == 5) {
                    n = 0;
                    swap = 1;
                }
                break;
            }
            if (swap == 0) break;
        }
        
        switch (n) {
        case 0:
        {
            Staff* newElement = new Staff();
            newElement->set_BirthDay(Date(rand() % 7, rand() % 32, 5, 1990 + rand() % 8));
            newElement->set_DepartmentID(rand() % 15 + i);
            newElement->set_IDCode(rand() % 100 + i);
            newElement->set_JoinedDate(Date(rand() % 7, rand() % 32, 5, 2013 + rand() % 8));
            newElement->set_Level(rand() % 5);
            int lenName = rand() % 5 + 3;
            char* name = new char[lenName + 1];
            name[0] = (char)('A' + rand() % ('Z' - 'A' + 1));
            for (int i = 1; i < lenName; i++) {
                name[i] = (char)('a' + rand() % ('z' - 'a' + 1));
            }
            name[lenName] = '\0';
            newElement->set_Name(name);
            delete[] name;
            Node::Add(list, newElement, staff);
            break;
        }
        case 1:
        {
            Student* newElement = new Student();
            int nProj = rand() % 20 + 1;
            float* projScore = new float[nProj];
            for (int j = 0; j < nProj; j++) {
                projScore[j] = rand() % 11 * 0.1 + rand() % 11 * 0.3 + rand() % 11 * 0.6;
            }
            newElement->set_BirthDay(Date(rand() % 7, rand() % 32, 5, 1990 + rand() % 8));
            newElement->set_Grade(rand() % 12 + 1);
            newElement->set_IDCode(rand() % 100 + i);
            newElement->set_number_of_project(nProj);
            newElement->set_ProjectScore(projScore);
            int lenName = rand() % 5 + 3;
            char* name = new char[lenName + 1];
            name[0] = (char)('A' + rand() % ('Z' - 'A' + 1));
            for (int i = 1; i < lenName; i++) {
                name[i] = (char)('a' + rand() % ('z' - 'a' + 1));
            }
            name[lenName] = '\0';
            if (checkRemove == 0) {
                nameCheckRemove = new char[lenName + 1];
                strcpy(nameCheckRemove, name);
                checkRemove = 1;
            }
            newElement->set_Name(name);
            delete[] name;
            Node::Add(list, newElement, student);
            break;
        }
        case 2:
        {
            Teacher* newElement = new Teacher();
            newElement->set_BirthDay(Date(rand() % 7, rand() % 32, 5, 1990 + rand() % 8));
            newElement->set_DepartmentID(rand() % 15 + i);
            newElement->set_IDCode(rand() % 100 + i);
            newElement->set_JoinedDate(Date(rand() % 7, rand() % 32, 5, 2013 + rand() % 8));
            newElement->set_Level(rand() % 5);
            newElement->set_Class(rand() % 12 + 1);
            newElement->set_Subject((Sub)(rand() % 3));
            newElement->set_SecondSubject((Sub)(rand() % 3));
            int lenName = rand() % 5 + 3;
            char* name = new char[lenName + 1];
            
            name[0] = (char)('A' + rand() % ('Z' - 'A' + 1));
            for (int i = 1; i < lenName; i++) {
                name[i] = (char)('a' + rand() % ('z' - 'a' + 1));
            }
            name[lenName] = '\0';
            
            newElement->set_Name(name);
            delete[] name;
            Node::Add(list, newElement, teacher);
            break;
        }
        }
    }

    // Sort list group by type: staff first, teacher next, and student last
    Node* ptr0 = list;
    Node* ptr1 = nullptr;
    while (1) {
        while (ptr0 != nullptr && ptr0->dataType == staff) {
            ptr0 = ptr0->next;
        }
        if (ptr0 == nullptr) break;
        ptr1 = ptr0->next;
        while (ptr1 != nullptr && ptr1->dataType != staff) {
            ptr1 = ptr1->next;
        }
        if (ptr1 == nullptr) break;
        People* tmp = ptr0->data;
        ptr0->data = ptr1->data;
        ptr1->data = tmp;
        ptr1->dataType = ptr0->dataType;
        ptr0->dataType = staff;

        ptr0 = ptr0->next;
    }
    
    while (1) {
        while (ptr0 != nullptr && ptr0->dataType == teacher) {
            ptr0 = ptr0->next;
        }
        if (ptr0 == nullptr) break;
        ptr1 = ptr0->next;
        while (ptr1 != nullptr && ptr1->dataType != teacher) {
            ptr1 = ptr1->next;
        }
        if (ptr1 == nullptr) break;
        People* tmp = ptr0->data;
        ptr0->data = ptr1->data;
        ptr1->data = tmp;
        ptr1->dataType = ptr0->dataType;
        ptr0->dataType = teacher;

        ptr0 = ptr0->next;
    }
    cout << "\nList after sorting\n";
    ptr0 = list;
    while (ptr0 != nullptr) {
        ptr0->data->PrintInfo();
        ptr0 = ptr0->next;
    }





    cout << "\n-----------------------------------------------------------\n";
    cout << "\n List of all students have had average score more than 5.0\n";
    Node* tmp = list;
    while (tmp != nullptr) {
        if (tmp->dataType == student && ((Student*)tmp->data)->get_AvgScore() > 5) {
            tmp->data->PrintInfo();
        }
        tmp = tmp->next;
    }


    // Copy current list (9.3)
    tmp = list;
    Node* newList = NULL;
    while (tmp != nullptr) {
        switch (tmp->dataType)
        {
        case people:
        {
            People* newElement = new People(tmp->data);
            Node::Add(newList, newElement, people);
            break;
        }
        case staff:
        {
            Staff* newElement = new Staff((Staff*)tmp->data);
            Node::Add(newList, newElement, staff);
            break;
        }
        case student:
        {
            Student* newElement = new Student((Student*)tmp->data);
            Node::Add(newList, newElement, student);
            break;
        }
        case teacher:
        {
            Teacher* newElement = new Teacher((Teacher*)(tmp->data));
            Node::Add(newList, newElement, teacher);
            break;
        }
        }
        tmp = tmp->next;
    }

    //Check Remove a student from list
    Node::Remove(list, nameCheckRemove, student);


    
    // Write Student to file //
    FILE* file = NULL;
    file = fopen("output.bin", "wb");
    if (file == NULL) {
        cout << "Opening file to write failed!\n";
    }
    else {
        int nStu = Node::nStudent(list);
        fwrite(&nStu, sizeof(int), 1, file);
        tmp = list;
        while (tmp != nullptr) {
            if (tmp->dataType == student) {
                fwrite(tmp->data, sizeof(Student), 1, file);
            }
            tmp = tmp->next;
        }
    }
    fclose(file);

    // Read Student from file //
    cout << "\n-----------------------\n";
    cout << "\nRead Student from file\n";
    Node* List01 = NULL;
    file = fopen("output.bin", "rb");
    if (file == NULL) {
        cout << "Opening file to write failed!\n";
    }
    else {
        int nStu;
        fread(&nStu, sizeof(int), 1, file);
        for (int i = 0; i < nStu; i++) {
            Student* newElment = new Student();
            fread(newElment, sizeof(Student), 1, file);
            Node::Add(List01, newElment, student);
        }
    }
    fclose(file);
    tmp = List01;
    cout << "\n==============================\n";
    cout << "\nLIST OF STUDENT READ FROM FILE\n";
    while (tmp != nullptr) {
        tmp->data->PrintInfo();
        tmp = tmp->next;
    }
}