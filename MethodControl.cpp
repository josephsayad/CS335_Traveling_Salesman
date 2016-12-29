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
  theParser_.toParse(argv); //  Passes to InputParser function.
}

void MethodControl::fillGraph() {
  vector<pair<double, double>> totalNodes;
  totalNodes = theParser_.getCoordinates();

  /* Unique unsigned int will hash to a distinct city coordinate 
   * in the graphmap. 
   */

  for(unsigned int i = 0; i < totalNodes.size(); ++i) {
    Node *nextNode = new Node(i + 1, totalNodes.at(i).first, totalNodes.at(i).second);
    theMap_.insert(make_pair(i + 1, *nextNode));
  }
}

/* Running the Algorithms */

/* Quick Note *****************************************************
 * ****************************************************************
 * 1: copyOfMap_ is declared as an graphmap [unordered_map] and holds 
 *    a copy of the data structures contents. This is to avoid change 
 *    to original data parsed by theParser_.
 * 2: totalDistance is passed by reference and will have it's value
 *    changed to the total cost of the tour.
 * 3: timeForMethods holds a value of type double. This value represents 
 *    the total time it took each algorithm to-run-to-completion and unit 
 *    of time is in milliseconds.
 * ****************************************************************
 */

void MethodControl::greedyTSP() {
  graphmap copyOfMap_ = theMap_;
  double totalDistance = 0.0, timeForMethod = 0.0;
  

  auto start = chrono::steady_clock::now();
  methodOne(copyOfMap_, totalDistance);
  auto end = chrono::steady_clock::now();
  auto diff = end - start;
  timeForMethod = chrono::duration <double, milli> (diff).count();

  cout << "Distance for Greedy TSP Algorithm: " << totalDistance << "\n";
  cout << "Time: " << timeForMethod << "ms.\n";
  printDivider();
}

void MethodControl::nearestInsertion() {
  graphmap copyOfMap_ = theMap_; 
  double timeForMethod = 0.0;
  
  auto start = chrono::steady_clock::now();
  methodTwo(copyOfMap_);
  auto end = chrono::steady_clock::now();
  auto diff = end - start;
  timeForMethod = chrono::duration <double, milli> (diff).count();

  cout << "Time: " << timeForMethod << "ms.\n";
  printDivider();
}

void MethodControl::nearestNeighbor() {
  graphmap copyOfMap_ = theMap_;
  double totalDistance = 0.0, timeForMethod = 0.0;

  auto start = chrono::steady_clock::now();
  methodThree(copyOfMap_, totalDistance);
  auto end = chrono::steady_clock::now();
  auto diff = end - start;
  timeForMethod = chrono::duration <double, milli> (diff).count();

  
  cout << "Distance for Nearest Neighbor Algorithm: " << totalDistance << "\n";
  cout << "Time: " << timeForMethod << "ms.\n";
  printDivider();
}

/* Convenience Function */

void MethodControl::printDivider() const {
  cout << "*****************************************************\n";
}

void MethodControl::printCountryData() const {
  theParser_.printData();
}
