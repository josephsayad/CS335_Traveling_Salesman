#include <iostream>
#include "InputParser.h"

using namespace std;

int main(int argc, char* argv[]) { 
  InputParser theParser;
  
  if(argv[1] == nullptr) {
    cout << "Please provide name of input file...\n";
    exit(1);
  }
  else {
  	string inputDir = "data/";
  	string inputFileName = argv[1];
  	theParser.parseFile(inputDir + inputFileName);
  }

  theParser.printParsedData();
  
  return 0; 
}
