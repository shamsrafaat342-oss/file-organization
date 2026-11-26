#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main() {

    ofstream outFile("grades.txt");
    if (!outFile) {
        cout << "Error creating grades.txt!" << endl;
        return 1;
    }

    int grade;
    cout << "Enter 5 integer grades:\n";
    for (int i = 0; i < 5; i++) {
        cin >> grade;
        outFile << grade << endl;
    }
    outFile.close();


    ifstream inFile("grades.txt");
    if (!inFile) {
        cout << "Error opening grades.txt for reading!" << endl;
        return 1;
    }

    cout << "\nGrades in file:\n";
    while (inFile >> grade) {
        cout << grade << endl;
    }
    inFile.close();


    int gradeToDelete;
    cout << "\nEnter the grade you want to delete: ";
    cin >> gradeToDelete;

    ifstream readGrades("grades.txt");
    ofstream tempFile("temp.txt");
    if (!readGrades || !tempFile) {
        cout << "Error opening files for deletion process!" << endl;
        return 1;
    }

    bool found = false;
    while (readGrades >> grade) {
        if (grade != gradeToDelete) {
            tempFile << grade << endl;
        } else {
            found = true;
        }
    }


    readGrades.close();
    tempFile.close();


    if (remove("grades.txt") != 0) {
        cout << "Error deleting original file!" << endl;
        return 1;
    }

    if (rename("temp.txt", "grades.txt") != 0) {
        cout << "Error renaming temporary file!" << endl;
        return 1;
    }

    if (found) {
        cout << "Grade deleted and file updated successfully!" << endl;
    } else {
        cout << "Grade not found, original file kept unchanged." << endl;
    }

    return 0;
}
