//
//  Node.h
//  Project 2
//
//  Created by Joseph Sayad on 12/20/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

struct Node {
  unsigned int name; //  Name of city.
  double x_coord; //  X-coordinate of city.
  double y_coord; //  Y-coordinate of city.
  bool isOnTour; //   If city is on tour. 

  Node *ptrOne; //  Points to an adjacent node.
  Node *ptrTwo; //  Points to an adjacent node.

  /* Overloading the Struct Constructor */
  
  Node(const unsigned int& init_name, const double& init_x, const double& init_y) 
    : name{init_name}, x_coord{init_x}, y_coord{init_y}, isOnTour{false},
      ptrOne{nullptr}, ptrTwo{nullptr} {}

  /* Overloading the operator<< */
  
  friend ostream& operator<<(ostream& out, const Node& node) {
    out << node.name;
    return out;
  }
  //  Precondition: Friend function requires two arguments: node, and an object of type ostream
  //  (e.g. cout) - the lhs operand. Thus, the iostream header must be included.
  //  Postcondition: Writes the name of the node to console.

  bool hasTwoEdges() const { 
    return ptrOne != nullptr && ptrTwo != nullptr; 
  }
  // Postcondition: Returns a bool. If this node has 2 edges then 
  // true is returned. 

  bool hasOneEdge() const {
    if(ptrOne != nullptr && ptrTwo == nullptr) { return true; }
    if(ptrOne == nullptr && ptrTwo != nullptr) { return true; }
    else { return false; }
  }
  // Postcondition: Returns a bool. If this node has 1 edge then 
  // true is returned. 

  bool isAdjacent(Node& nodeToCompare) const {
   return ptrOne == &nodeToCompare || ptrTwo == &nodeToCompare;
  }
  // Precondition: Accepts variable of type Node by reference. 
  // Postcondition: Returns if this node is adjacent to the node passed.
};

struct Edge {
  double weight; //  Cost of each edge. 
  
  /* Potential edge exists between nameOfNodeOne and nameOfNodeTwo */  

  unsigned int nameOfNodeOne; 
  unsigned int nameOfNodeTwo;

  Edge(const double& init_weight, const unsigned init_node_one, const unsigned init_node_two) 
    : weight{init_weight}, nameOfNodeOne{init_node_one}, nameOfNodeTwo{init_node_two}  {}
};

/* Custom comparator for priority queue used in the Greedy TSP Algorithm */

struct GreaterThanByWeight {
  bool operator()(const Edge& lhs, const Edge& rhs) const {
    return lhs.weight > rhs.weight;
  }
};

#endif
