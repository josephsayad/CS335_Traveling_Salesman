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
  unsigned int name;
  double x_coord;
  double y_coord;

  Node *toNextNode;
  Node *fromLastNode; 

  /* Overloading the Struct Constructor */
  
  Node(const unsigned int& init_name, const double& init_x, const double& init_y) 
    : name{init_name}, x_coord{init_x}, y_coord{init_y}, toNextNode{nullptr}, fromLastNode{nullptr}  {}

  /* Overloading the operator<< */
  
  friend ostream& operator<<(ostream& out, const Node& node) {
    out << node.name;
    return out;
  }

  bool hasTwoEdges() const { 
    return toNextNode != nullptr && fromLastNode != nullptr; 
  }

  bool hasOneEdge() const {
    if(toNextNode != nullptr && fromLastNode == nullptr) return true;
    if(toNextNode == nullptr && fromLastNode != nullptr) return true;
    else { return false; }
  }
};

struct Edge {
  double weight;
    
  Node* nodeOne; 
  Node* nodeTwo;

  Edge(const double& init_weight, Node *addressOne, Node *addressTwo) 
    : weight{init_weight}, nodeOne{addressOne}, nodeTwo{addressTwo}  {}
};

struct GreaterThanByWeight {
  bool operator()(const Edge& lhs, const Edge& rhs) const {
    return lhs.weight > rhs.weight;
  }
};

#endif
