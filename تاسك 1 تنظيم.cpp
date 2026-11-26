#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string fullname;
    int id;
    float grade;
    cout<<"fullname";
    getline(cin,fullname);
    cout<<"id";
    cin>>id;
    cout<<"grade";
    cin>>grade;
  ofstream myfile("student.txt");
  if(!myfile.is_open())
  {
      cout<<"Error";
  }
  else
  {
      cout<<"opened";
  }


  myfile.close();
  return 0;

}
