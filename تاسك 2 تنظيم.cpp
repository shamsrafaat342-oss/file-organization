#include <iostream>
#include <fstream>
using namespace std;

int main()
{

  string f1,f2,f3;

  ifstream x("Fruit.txt");

  x>>f1>>f2>>f3;

  x.close() ;

  ofstream out("Fruit.txt",ios::app);

  out<<"Fresh Fruits";

  out.close();


    return 0;
}
