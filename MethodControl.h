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

using namespace std;

class MethodControl {
  public:
  
    /* Explicitly-defined default constructor */

    MethodControl();

    /* Set-up Graph */

    void fetchCommandLineArg(char* argv[]);
    void fillGraph();

  private:

    /* Private Data Members */

  	InputParser theParser_; //  Parse and fetches coords
    
    struct Node {
      double x_coord;
      double y_coord;
      double distanceTo; 

      Node *edgeOne;
      Node *edgeTwo; 

      /* Overloading the Struct Constructor */
      Node(const double& initialize_x, const double& initialize_y) 
        : x_coord{initialize_x}, y_coord{initialize_y}, edgeOne{nullptr}, edgeTwo{nullptr}  {}

      /* Overloading the operator<< */
      friend ostream& operator<<(ostream& out, const Node& node) {
        out << "(" << node.x_coord << ", " << node.y_coord << ")";
        return out;
      }
    };

    typedef unordered_map<unsigned int, Node> graphmap;
    graphmap tour_; //  Each node as a unique key [unsigned int]
};

#endif
