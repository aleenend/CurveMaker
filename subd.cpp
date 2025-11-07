/*
  Aleene Dupuy
  P2 Due 4/9
  CPSC 6050

  This file is the main and subdivision functions for making the subdivision
  curve. Explanations for each function are above the function.
*/

#include "Point.h"
#include "FileIO.h"

/*
  Performs the calculations to get the points. Cycles through the vector and
  puts the old and new points in a temp vector. Then sets the old vector equal
  to the temp vector and clears the temp one.
*/
void subdivide(std::vector<Point>* p) {
  std::vector<Point> temp;
  Point poi;

  for(int i = 0; i < (int) p->size(); i++) {
    //puts on first and last points
    if(i == 0 || i == (int) p->size() - 1) {
      temp.push_back(p->at(i));
    }
    //filers even (original) points
    else {
      poi = (p->at(i - 1) + p->at(i) * 6.0 + p->at(i + 1)) * (1.0/8.0);
      temp.push_back(poi);
    }
    //adds midpoints
    if(i < (int) p->size() - 1) {
      poi = (p->at(i) + p->at(i + 1)) * (1.0/2.0);
      temp.push_back(poi);
    }
  }

  p->clear();
  *p = temp;
  temp.clear();
}

/*
  Reads in the points from the file to a vector. Calls the subdivide function
  to generate the subdivision curve. Subdivides multiple times to generate more
  points. Then prints the points to the output file.
*/
int main(int argc, char *argv[]) {

  std::vector<Point> points;
  int subdNum = 5;

  readPoints(&points,argv[1]);

  //just a for loop to subdivide multiple times
  for(int i = 0; i < subdNum; i++) {
    subdivide(&points);
  }

  printPoints(&points);

  points.clear();

  return 0;
}
