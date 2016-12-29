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
    // Precondition: Accepts variable of type string by reference.
    // Postcondition: Sets [name_] to the value of said variable.

    void setDimension(unsigned int& newDimension);
    // Precondition: Accepts variable of type unsigned int by reference.
    // Postcondition: Sets [dimension_] to the value of said variable.

    void addCity(pair<double, double> newCoordinates);
    // Precondition: Accepts variable of type std::pair<double, double> by copy.
    // Postcondition: Fills [cityCoordinates_] with a set of coordinates. 

    /* Accessor Function */

    string getName() const;
    // Postcondition: Returns a value of string.

    unsigned int getDimension() const;
    // Postcondition: Returns a value of unsigned int.

    vector<pair<double, double>> getCoordinates() const;
    // Postcondition: Returns a value a vector of std::pair<double, double>.

  	/* Overloading the operator<< */

  	friend ostream& operator<<(ostream& out, const Country& country);
    //  Precondition: Friend function requires two arguments: country, and an object of type ostream
    //  (e.g. cout) - the lhs operand. Thus, the iostream header must be included.
    //  Postcondition: Writes country-related data from respective "country containers" to console.

  	/* Convenience functions */ 

  	void printCityCoord() const;
    //  Precondition: Input file must be parsed and the data read into the 
    //  vector. 
    //  Postcondition: Iterates over and writes each cityCoordiante in the 
    //  vector cityCoordinates_ to console.  

  	void printDivider() const;
    //  Postcondition: Prints a series of '*' characters to console for the
    //  purpose of display aesthetic. 

  private: 

    /* Private Data Members */

  	string name_; //  Name of country. 
  	unsigned int dimension_; //  Number of cities. 
    vector<pair<double, double>> cityCoordinates_; //  Set of coordinates.
};

#endif
