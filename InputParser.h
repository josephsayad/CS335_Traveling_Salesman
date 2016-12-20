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
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include "Country.h"

using namespace std;

class InputParser {
  public:
  
    /* Explicitly-defined default constructor */
  
    InputParser();

    /* Accessor Functions */
    
    vector<pair<double, double>> getCoordinates() const;

    /* Parsing Functionality */

    void toParse(char* argv[]);

    /* Convenience functions */ 

    void printData() const;

  private: 
  
    /* Private Data Members */

    Country country_;

    /* Private Member Parsing Functionality */
 
    void parse(const string& inputFileName); 
    void removeWhiteSpace(string& input);
};

#endif
