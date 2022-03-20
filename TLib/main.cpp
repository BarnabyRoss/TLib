#include <iostream>
#include "SmartPointer.h"

using namespace std;
using namespace TLib;

class Test{

public:
  Test(){
    cout << "Test()" << endl;
  }
  ~Test(){
    cout << "~Test()" << endl;
  }
};

int main(int argc, char* argv[]){

  SmartPointer<Test> sp = new Test();
  SmartPointer<Test> nsp = sp;

  cout << "nsp is nullptr : " << nsp.isNULL() << endl;
  cout << "sp is nullptr : " << sp.isNULL() << endl;
  return 0;
}
