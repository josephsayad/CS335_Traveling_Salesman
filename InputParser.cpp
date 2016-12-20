//
//  InputParser.cpp
//  Project 2
//
//  Created by Joseph Sayad on 12/18/16.
//  Copyright © 2016 Joseph Sayad. All rights reserved.
//

#include "InputParser.h"

using namespace std;

/* Explicitly-defined default constructor */
  
InputParser::InputParser() {}

/* Accessor Functions */

vector<pair<double, double>> InputParser::getCoordinates() const {
  return country_.getCoordinates();
}

/* Parsing Functionality */

void InputParser::toParse(char* argv[]) {
  if(argv[1] == nullptr) {
    cout << "Please provide 1 input file...\n";
    exit(1);
  }

  else if(argv[2] != nullptr) {
    cout << "Only 1 input file is permitted in the execution of this program...\n";
    exit(1);
  }

  else {
    string inputDir = "data/";
    string inputFileName = argv[1];
    parse(inputDir + inputFileName);
  }
}

/* Convenience functions */ 

void InputParser::printData() const { cout << country_; }

/* Parsing Member Parsing Functionality */

void InputParser::parse(const string& inputFileName) {
  ifstream inputFileHandler(inputFileName);
 
  //  Error Handling conditional...
  if(!inputFileHandler.is_open()) {
  	
    cout << "Input File (" << inputFileName << ") could not be read...\n";
    cout << "Is the input file nested in the data sub-directory...?\n";
  	
    inputFileHandler.close();
  	exit(1);
  }

  string lineOfFile, token, delimiter = ":";
  pair<double, double> coordinates; 
  double x_coord, y_coord;
  unsigned int numberOfCities; 

  while(getline(inputFileHandler, lineOfFile)) {
  	removeWhiteSpace(lineOfFile);
 
    if(lineOfFile.substr(0, 5) == "NAME:") {
      lineOfFile.erase(0, 5);
      stringstream strZero(lineOfFile); 
      strZero >> token;

      country_.setName(token);
    }
    
    else if(lineOfFile.substr(0, 10) == "DIMENSION:") {
      lineOfFile.erase(0, lineOfFile.find(delimiter) + delimiter.length()); 
      stringstream strOne(lineOfFile);
      strOne >> numberOfCities;

      country_.setDimension(numberOfCities);
    }

    else if(lineOfFile.substr(0, 18) == "NODE_COORD_SECTION") 
      break;
  }

  delimiter = " ";

  while(getline(inputFileHandler, lineOfFile)) {
    if(lineOfFile == "EOF") { break; }
    
    else {
      lineOfFile.erase(0, lineOfFile.find(delimiter) + delimiter.length());
      
      /* token is x_coord and lineOfFile is y_coord */
      token = lineOfFile.substr(0, lineOfFile.find(delimiter));	
      lineOfFile.erase(0, lineOfFile.find(delimiter) + delimiter.length());

      stringstream str_X_Coord(token);
      stringstream str_Y_Coord(lineOfFile);

      str_X_Coord >> x_coord;
      str_Y_Coord >> y_coord;

      
      coordinates = make_pair(x_coord, y_coord);
      country_.addCity(coordinates);
    }
  }

  inputFileHandler.close();
} 

void InputParser::removeWhiteSpace(string& input) {  
  input.erase(remove(input.begin(),input.end(), ' '),input.end());
}
