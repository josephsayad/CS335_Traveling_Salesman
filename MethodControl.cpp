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

/* Set-up Graph */

void MethodControl::fetchCommandLineArg(char* argv[]) {
  theParser_.toParse(argv);
}

void MethodControl::fillGraph() {
  vector<pair<double, double>> totalNodes;
  totalNodes = theParser_.getCoordinates();

  for(unsigned int i = 0; i < totalNodes.size(); ++i) {
    Node *nextNode = new Node(i + 1, totalNodes.at(i).first, totalNodes.at(i).second);
    theMap_.insert(make_pair(i + 1, *nextNode));
  }
}

/* Running the Algorithms */

void MethodControl::greedyTSP() {
  graphmap copyOfMap_ = theMap_; 
  double totalDistance = 0.0;

  methodOne(copyOfMap_, totalDistance);
  cout << "Distance: " << totalDistance << "\n";
}

void MethodControl::nearestInsertion() {
  graphmap copyOfMap_ = theMap_; 
  methodTwo(copyOfMap_);
}
