#include <iostream>
#include "Student.h"
using namespace std;
int main()
{
    unordered_map<int, Student> Students;
    LoadFromFile(Students);
//C:\Users\t\Desktop\basics\projects\student Records\student.cpp
    while (true)
    {
        cout << " Hello to students record \n";
        cout << "please choose the no of operation You want !\n";
        cout << " 1- add student\n";
        cout << " 2- Display All Students\n";
        cout << " 3- Search Student by ID\n";
        cout << " 4- Update Student\n";
        cout << " 5- Delete Student\n";
        cout << " 6- Sort Students (By Name / Grade / ID)\n";
        cout << " 7- Save to File\n";
        cout << "8-Display Student data\n ";
        // cout << " 8- Load from File\n";
        cout << " 9- Exit\n";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {

            // هعمل لوب هنا بعدد المرات times , ستدعي فيها function add

            cout << "how many time you wanna do this operation\n";
            int times;
            cin >> times;
            for (int i = 0; i < times; i++)
            {
                AddStudent(Students);
            }
            break;
        }
        case 2:
        {
            DisplayAll(Students);
            break;
        }
        case 3:
        {
            Student s = SearchStudentsList(Students);
            if (s.id != -1)
            {
                cout << s.id << " " << s.name << " " << s.age << " " << s.grade << endl;
            }
            break;
        }
        case 4:
        {

            updateStudent(Students);
            break;
        }
        case 5:
        {
            DeleteStudents(Students);
            break;
        }
        case 6:
        {

            vector<Student> sortedList = SortStudents(Students);
            for (const auto &s : sortedList)
            {
                cout << s.id << " " << s.name << " " << s.age << " " << s.grade << endl;
            }
            break;
        }
        case 7:
        {
            SaveAllToFile(Students);
            break;
        }
        // case 8:
        // {
        //     LoadFromFile(Students);
        //     break;
        // }
        case 8:
        {
            DisplayStudent(Students);
            break;
        }
        case 9:
        {

            cout << "file closed successfully!" << endl;
            return 0;
            
        }
        default:
        {
            cout << " invalid input! \n";
        }
        }
        cout << " Do you want any other service? y:n\n";
    char Service;
    cin >> Service;
    if (Service != 'y' && Service != 'Y')
    {
        return 0;
    }
    }
    
}
