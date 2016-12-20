//
//  Country.h
//  Project 2
//
//  Created by Joseph Sayad on 12/19/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#ifndef COUNTRY_H
#define COUNTRY_H

#include <iomanip>
#include <vector>
#include <utility>

using namespace std;

class Country {
  public:

  	/* Explicitly-defined default & overloaded constructors */ 

  	Country();
  	Country(string name, unsigned int dimension, vector<pair<double, double>> coordinates);

    /* Mutator Function */

    void setName(string& newName);
    void setDimension(unsigned int& newDimension);
    void addCity(pair<double, double> newCoordinates);

    /* Accessor Function */

    string getName() const;
    unsigned int getDimension() const;
    vector<pair<double, double>> getCoordinates() const;

  	/* Overloading the operator<< */

  	friend ostream& operator<<(ostream& out, const Country& country);

  	/* Convenience functions */ 

  	void printCityCoord() const;
  	void printDivider() const;

  private: 

    /* Private Data Members */

  	string name_; 
  	unsigned int dimension_;
    vector<pair<double, double>> cityCoordinates_;
};

#endif
