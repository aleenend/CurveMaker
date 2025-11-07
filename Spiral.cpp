/*
  Aleene Dupuy
  P2 Due 4/9
  CPSC 6050

  This file contains the main and genSpiral functions to generate the points
  and tangents in a spiral. The equation used for the spiral is
  x = acos(t)
  y = asin(t)
  z = bt

  I have swapped the x and z values so the spiral will lay in the same direction
  as the other curves.
*/

#include "Point.h"
#include "FileIO.h"

#include <cmath>

/*
  This function generates the points for the spiral and then calculates the
  tangent for xyz.
*/
void genSpiral(std::vector<Point>* p) {
  int start = -5;
  int end = 15;
  int a = 1;
  int b = 1;
  Point poi;

  for(int t = start; t < end; t++) {
    //sets x,y,z
    poi.setX(b * t);
    poi.setY(a * sin(t));
    poi.setZ(a * cos(t));

    //r = sqrt(a2 + b2) easier to just a*a instead of use power func
    double r = sqrt(a * a + b * b);
    //sets tangent
    poi.setTanx(b/r);
    poi.setTany((-a/r) * sin(t));
    poi.setTanz((a/r) * cos(t));

    p->push_back(poi);
  }

}

/*
  Generates the points for the spiral by calling the genSpiral function, and
  then prints the points to the output file.
*/
int main(void) {
  std::vector<Point> points;

  genSpiral(&points);

  printSpiral(&points);

  points.clear();

  return 0;
}
