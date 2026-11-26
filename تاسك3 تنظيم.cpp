#include <iostream>
#include <fstream>
using namespace std;

int main()
{

 ofstream x("welcome.txt");
  if(!x.is_open()){
    cout<<"error";
  }else{
  x<<"Hello Everybody";
  x.seekp(11);
  x<<"one ";




  }
    return 0;
}

