#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <unordered_map>
using namespace std;
struct Student
{
    int id;
    string name;
    int age;
    float grade;
};
// write
void SaveAllToFile(unordered_map<int, Student> &Students);
vector<Student> SortStudents(unordered_map<int, Student> &Students);
void DisplayStudent(unordered_map<int, Student> &Students);
void AddStudent(unordered_map<int, Student> &Students)
{
    // add then sort then save to file;
    ofstream myFile("Student.txt");
    Student s;
    cout << " student name? ";

    cin.ignore(); // لمسح الـ buffer
getline(cin, s.name);
    cout << " student id? ";
    cin >> s.id;
    cout << " student age? ";
    cin >> s.age;
    cout << " student grade? ";
    cin >> s.grade;
    Students[s.id] = s;
    // sort the students list is invoked in this function ;
    SaveAllToFile(Students);
}
void DisplayAll(unordered_map<int, Student> &Students)
{
    ifstream inFile("Student.txt");
    if (inFile.is_open())
    {
        string line;
        while (getline(inFile, line))
        {
            cout << line << endl;
        }
    }
}
vector<Student> SortStudents(unordered_map<int, Student> &Students)
{
    vector<Student> SortedStudentsList;
    for (auto &pair : Students)
    {
        SortedStudentsList.push_back(pair.second);
    }
    sort(SortedStudentsList.begin(), SortedStudentsList.end(), [](const Student &a, const Student &b)
         {
             return a.grade > b.grade; // الأعلى أولاً
         });
    return SortedStudentsList;
}
Student SearchStudentsList(unordered_map<int, Student> &Students)
{

    int SearchId;
    cout << "student ID?\n";
    cin >> SearchId;
    if (Students.count(SearchId))
    {

        return Students[SearchId];
    }
    return Student{-1, "", -1, -1};
}
void updateStudent(unordered_map<int, Student> &students)
{
    int searchId;
    cout << "Enter student ID to update: ";
    cin >> searchId;

    if (students.count(searchId) == 0)
    {
        cout << "Student with ID " << searchId << " not found.\n";
        return;
    }

    int choice;
    cout << "\nWhat do you want to update?\n";
    cout << "1 - Name\n";
    cout << "2 - Age\n";
    cout << "3 - Grade\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Enter new name: ";
        cin >> students[searchId].name;
        cout << " Student name has been edited successfully!\n";
       

        break;
    case 2:
        cout << "Enter new age: ";
        cin >> students[searchId].age;
        

        break;
    case 3:
        cout << "Enter new grade: ";
        cin >> students[searchId].grade;
        SortStudents(students);
        

        break;
    default:
        cout << "Invalid choice.\n";
        return;
    }
    SaveAllToFile(students);
    Student updatedStudent = students[searchId];
    cout << "\nUpdated Student Data:\n";
    cout << updatedStudent.id << " " << updatedStudent.name << " "
         << updatedStudent.age << " " << updatedStudent.grade << "\n";
}
void DisplayStudent(unordered_map<int, Student> &Students)
{
    Student s = SearchStudentsList(Students);

    cout << s.id << " " << s.name << " " << s.age << " " << s.grade << endl;
}
void DeleteStudents(unordered_map<int, Student> &Students)
{
    int id;
    cout << "Student id for deletion" << endl;
    cin >> id;
    Students.erase(id);
    // SortStudents(Students);
    SaveAllToFile(Students);
}
void SaveAllToFile(unordered_map<int, Student> &Students)
{
    ofstream myFile("Student.txt");
    vector<Student> Sorted = SortStudents(Students);
    if (myFile.is_open())
    {
        for (const auto &student : Sorted)
        {
            myFile << student.id << " " << student.name << " "
                   << student.age << " " << student.grade << endl;
        }
        myFile.close();
    }
}

void LoadFromFile(unordered_map<int, Student> &Students)
{
    Students.clear();
    ifstream inFile("Student.txt");
    if (inFile.is_open())
    {
        Student s;
        while (inFile >> s.id >> s.name >> s.age >> s.grade)
        {
            Students[s.id] = s;
        }
        inFile.close();
    }
}