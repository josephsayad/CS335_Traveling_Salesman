//
//  InputParser.h
//  Project 2
//
//  Created by Joseph Sayad on 12/18/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <iostream>
#include <fstream> // parseFile()
#include <sstream>
#include <string> // getline()
#include <algorithm> // removeWhiteSpace()
#include "Country.h"

using namespace std;

class InputParser {
  public:
  
  /* Explicitly-defined default constructor */
  
  InputParser();

  /* Parsing Functionality */

  void parseFile(const string& inputFileName); 
  void removeWhiteSpace(string& input);

  /* Convenience functions */ 

  void printParsedData() const;

  private: 
  
  /* Private Data Members */

  Country country_;
};

#endif
