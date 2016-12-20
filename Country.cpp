//
//  Country.cpp
//  Project 2
//
//  Created by Joseph Sayad on 12/19/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#include <iostream>
#include "Country.h"

/* Explicitly-defined default & overloaded constructors */ 

Country::Country() {}

Country::Country(string name, unsigned int dimension, vector<pair<double, double>> coordinates) 
: name_(name), dimension_(dimension) {
  cityCoordinates_ = coordinates;
}

/* Mutator Function */

void Country::setName(string& newName) {
  name_ = newName;
}

void Country::setDimension(unsigned int& newDimension) {
  dimension_ = newDimension;
}

void Country::addCity(pair<double, double> newCoordinates) {
  cityCoordinates_.push_back(newCoordinates);
}

/* Accessor Function */

string Country::getName() const {
  return name_;
}

unsigned int Country::getDimension() const {
  return dimension_;
}

vector<pair<double, double>> Country::getCoordinates() const {
  return cityCoordinates_;
}

/* Overloading the Console Output Operator */

ostream& operator<<(ostream& out, const Country& country) {
  country.printDivider();
  out << "Name of Country: " << country.name_ << "\n";
  out << "Number of Cities: " << country.dimension_ << "\n";
  country.printDivider();
  country.printCityCoord();
  return out;  
}

/* Convenience functions */ 

void Country::printCityCoord() const {
  for(int i = 0; i < cityCoordinates_.size(); ++i) {
    cout << "City " << i + 1; 
    
    if(i < 9) { cout << "  * ("; }
    else { cout << " * ("; }

    cout << setprecision(10) << cityCoordinates_.at(i).first << ", " 
         << setprecision(10) << cityCoordinates_.at(i).second << ")\n";
  }
}

void Country::printDivider() const {
  cout << "*************************\n";
}
