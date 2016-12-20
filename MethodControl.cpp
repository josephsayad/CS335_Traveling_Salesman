//
//  MethodControl.cpp
//  Project 2
//
//  Created by Joseph Sayad on 12/20/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#include "MethodControl.h"

using namespace std;

/* Explicitly-defined default constructor */

MethodControl::MethodControl() {}

/* Set-up Graph Functions */

void MethodControl::fetchCommandLineArg(char* argv[]) {
  theParser_.toParse(argv);
}

void MethodControl::fillGraph() {
  vector<pair<double, double>> totalNodes;
  totalNodes = theParser_.getCoordinates();

  for(unsigned int i = 0; i < totalNodes.size(); ++i) {
    Node *nextNode = new Node(totalNodes.at(i).first, totalNodes.at(i).second);
    tour_.insert(make_pair(i + 1, *nextNode));
  }
  
  for (auto j : tour_) {
     cout << j.first << " " << j.second << endl;
  }
}
