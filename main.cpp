#include <iostream>
#include "MethodControl.h"

using namespace std;

int main(int argc, char* argv[]) { 
  MethodControl controllerOne; 
  controllerOne.fetchCommandLineArg(argv);
  controllerOne.fillGraph();
  controllerOne.greedyTSP();
  return 0; 
}
