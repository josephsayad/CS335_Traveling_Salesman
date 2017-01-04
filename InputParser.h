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
    //  Precondition: Country class must be implemented with a data member that
    //  holds all the coordinates for the cities in that country. The data structure
    //  used is a vector of std::pair<double, double>
    //  Postcondition: Error handles if necessary and passes the inputFileName 
    //  [dataDir + fileName] to the parse function.

    /* Parsing Functionality */

    void toParse(char* argv[]);
    //  Precondition: Accepts a variable of type char* by copy. Char* argv[]
    //  is command line argument and functions as an array of strings.
    //  Postcondition: Error handles if necessary and passes the inputFileName 
    //  [dataDir + fileName] to the parse function.

    /* Convenience functions */ 

    void printData() const;
    //  Precondition: operator<< overload is necessary in the country class. 
    //  Postcondition: Prints a country object.

  private: 
  
    /* Private Data Members */

    Country country_; //  Holds a vector of cityCoordinates.

    /* Private Member Parsing Functionality */
 
    void parse(const string& inputFileName); 
    //  Precondition: Accepts a variable of type string by reference. Must 
    //  include the C++ STL fstream, and sstream header files. 
    //  Postcondition: Parses an input file in the data dir - specified by 
    //  data/inputFileName - and reads into an object of type country. 

    void removeWhiteSpace(string& input);
    //  Postcondition: Removes whitespace from an object of type string: 
    //  the delimiter is whitespace.
};

#endif
