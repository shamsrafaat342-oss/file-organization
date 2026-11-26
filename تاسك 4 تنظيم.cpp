#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

struct person{

   string name;
   int age;
};

int main()
{

 int n;
 cout<<"how many persons do you want to add?";

 ofstream x("persons.txt");
 for(int i=0;i<n;i++){
    person p;
    cout<<"Enter name and age for person " << i+1 <<":";
    cin>>p.name>>p.age;
    x<<p.name<<" " <<p.age<<endl;
 }
 x.close();
  ifstream infile("persons.txt");
  if(!infile){
    cout<<"Error opening persons.txt for reading"<<endl;
    return 1;
  }
    vector<person> people;
    person temp;
    while(infile>>temp.name>>temp.age){
        people.push_back(temp);
    }

    infile.close();
    if(people.empty()){
        cout<<"No person data found in file."<<endl;
        return 0;
    }

    person youngest = people[0];
    person oldest = people[0];
    for(int i=1;i<people.size();i++){
        if(people[i].age<youngest.age){
            youngest=people[i];
        }
        if(people[i].age>oldest.age){
            oldest=people[i];
        }
    }
    ofstream resfile("results.txt");
    resfile <<"younger person: "<<youngest.name<<"("<<youngest.age<<")"<<endl;
    resfile <<"older person: "<<oldest.name<<"("<<oldest.age<<")"<<endl;
    resfile.close();
    cout<<"Done! Results saved to results.txt" <<endl;

    return 0;
}
