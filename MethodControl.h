//
//  MethodControl.h
//  Project 2
//
//  Created by Joseph Sayad on 12/20/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#ifndef METHODCONTROL_H
#define METHODCONTROL_H

#include <iostream>
#include <chrono>
#include <unordered_map>

#include "InputParser.h"
#include "Node.h"
#include "MethodOne.h"
#include "MethodTwo.h"
#include "MethodThree.h"

using namespace std;

class MethodControl {
  public:
  
    /* Explicitly-defined default constructor */

    MethodControl();

    /* Set-up Graph */

    void fetchCommandLineArg(char* argv[]);
    //  Precondition: Pass int argc and char* argv[] by copy as arguements 
    //  to main() in main.cpp.
    //  Postcondition: Passes command line arguement to theParser_ for 
    //  error handling and parsing. 

    void fillGraph();
    //  Precondition: theParser_ implemented to pass a vector of coordinates 
    //  via get method. Must include the C++ STL vector, and unordered_map header 
    //  files.
    //  Postcondition: Fills a hash table with coordinates. The number of each
    //  city is distinct. It is used as the unique key which hashes to a city's
    //  coordinates.

    /* Running the Algorithms */

    void greedyTSP();
    //  Precondition: Country, InputParser, MethodControl, and methodOne must be implemented, 
    //  and compiled. MethodOne can be seen in MethodOne.h and MethodOne.cpp.
    //  Postcondition: Writes the tour acquired via Greedy TSP heuristic approximation algorithm,
    //  the time it took, and total cost of trip to console. 

    void nearestInsertion();
    //  Precondition: Country, InputParser, MethodControl, and methodTwo must be implemented, 
    //  and compiled. MethodTwo can be seen in MethodTwo.h and MethodTwo.cpp.
    //  Postcondition: Writes the tour acquired via Nearest Insertion heuristic approximation 
    //  algorithm, the time it took, and total cost of trip to console. 

    void nearestNeighbor();
    //  Precondition: Country, InputParser, MethodControl, and methodThree must be implemented, 
    //  and compiled. MethodThree can be seen in MethodThree.h and MethodThree.cpp.
    //  Postcondition: Writes the tour acquired via Nearest Neighbor heuristic approximation 
    //  algorithm, the time it took, and total cost of trip to console. 

    /* Convenience Function */

    void printDivider() const;
    //  Postcondition: Prints a series of '*' characters to console for the
    //  purpose of display aesthetic. 

    void printCountryData() const;
    //  Postcondition: Writes country-related data to console.

  private:

    /* Private Data Members */

    InputParser theParser_; //  Parse and gets city coordinates.

    typedef unordered_map<unsigned int, Node> graphmap;
    graphmap theMap_; //  Unique key [unsigned int] hashes to distinct city in the map.
};

#endif
