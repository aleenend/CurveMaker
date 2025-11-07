/*
  Aleene Dupuy
  P2 Due 4/9
  CPSC 6050

  This file contains functions for reading and printing the points so they can
  be used by subd.cpp and catrom.cpp.
*/

#include "Point.h"

#include <iostream>
#include <vector>
#include <fstream>

/*
  Reads in the points from the input file specified in the command line.
*/
void readPoints(std::vector<Point>* p, char* filename) {
  std::ifstream inFile(filename);
  double x, y, z, tanx, tany, tanz;

  //checks that file exists and can be opened
  if (inFile.is_open()) {
    while(inFile >> x >> y >> z >> tanx >> tany >> tanz) {
      p->push_back(Point(x,y,z,tanx,tany,tanz));
    }
    inFile.close();
  }
  else {
    std::cout << "Error opening file. Please make sure it is in the directory"
      << " and run again." << std::endl;
  }
}

/*
  Prints the points to an output file specified in the command line. One point
  per line. Prints in order: x y z.
*/
void printPoints(std::vector<Point>* p) {
  for(int i = 0; i < (int) p->size(); i++) {
    std::cout << p->at(i).getX() << " " << p->at(i).getY() << " " <<
      p->at(i).getZ() << std::endl;
  }
}

/*
  Prints the points to an output file specified in the command line. One point
  per line. Prints in order: x y z tanx tany tanz.
*/
void printSpiral(std::vector<Point>* p) {
  for(int i = 0; i < (int) p->size(); i++) {
    std::cout << p->at(i).getX() << " " << p->at(i).getY() << " " <<
      p->at(i).getZ() << " " << p->at(i).getTanx() << " " << p->at(i).getTany()
      << " " << p->at(i).getTanz() << std::endl;
  }
}
