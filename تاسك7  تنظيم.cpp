#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {

    ofstream outFile("names.txt");
    outFile << "Hadeer Mahmoud\n";
    outFile << "Youssef Ali\n";
    outFile << "Ahmed Mostafa\n";
    outFile << "Esraa Ebrahim\n";
    outFile.close();


    ifstream input("names.txt");
    if (!input) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string line;
    vector<string> data;

    while (getline(input, line)) {
        if (!line.empty()) {
            data.push_back(line);
        }
    }
    input.close();


    sort(data.begin(), data.end());


    cout << "Names sorted successfully:\n";
    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << endl;
    }

    return 0;
}
