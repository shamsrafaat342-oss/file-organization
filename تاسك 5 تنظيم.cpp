#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    char name[20];
    int id;
    float grade;
    char delim;
};

int main() {
    ofstream outFile("students.txt", ios::app);
    if (!outFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    Student s;
    s.delim = '$';
    char choice;

    do {
        cout << "Enter student name: ";
        cin.getline(s.name, 20);

        cout << "Enter student ID: ";
        cin >> s.id;

        cout << "Enter student grade: ";
        cin >> s.grade;


        outFile << s.name << ", " << s.id << ", " << s.grade << " " << s.delim << endl;

        cout << "Do you want to add another student? (y/n): ";
        cin >> choice;
        cin.ignore();
    } while (choice == 'y' || choice == 'Y');

    outFile.close();
    cout << "Students saved successfully to students.txt!" << endl;

    return 0;
}
