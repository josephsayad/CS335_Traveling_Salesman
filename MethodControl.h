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
#include <unordered_map>

#include "InputParser.h"
#include "Node.h"
#include "MethodOne.h"
#include "MethodTwo.h"

using namespace std;

class MethodControl {
  public:
  
    /* Explicitly-defined default constructor */

    MethodControl();

    /* Set-up Graph */

    void fetchCommandLineArg(char* argv[]);
    void fillGraph();

    /* Running the Algorithms */

    void greedyTSP();
    void nearestInsertion();

  private:

    /* Private Data Members */

    InputParser theParser_; //  Parse and fetches coords

    typedef unordered_map<unsigned int, Node> graphmap;
    graphmap theMap_; //  Each node as a unique key [unsigned int]
};

#endif
