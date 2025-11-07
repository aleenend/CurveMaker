/*
  Aleene Dupuy
  P2 Due 4/9
  CPSC 6050

  This file is the main and catrom functions for making the catrom curve.
  Explanations for each function are above the function.
*/

#include "Point.h"
#include "FileIO.h"

/*
  Performs the calculations to generate the points for the catrom curve. It
  puts the original points into a temp vector and makes a point at every 0.1+
  between each point. The math is a bit messy, so the comments explain the
  calculation performed in each block. The original vector is set to equal the
  temp vector at the end to return the points.
*/
void catromPoints(std::vector<Point>* p) {
  std::vector<Point> temp;
  Point ab, c, d;

  for(int i = 0; i < (int) p->size(); i++) {
    //puts on existing points
    temp.push_back(p->at(i));
    //point creation
    if(i < (int) p->size() - 1) {
      double j =  i + 0.1;
      double t;

      while(j >= i+0.1 && j < i + 1) {
        t = j - i;
        //P0 + T0t
        ab = p->at(i);
        ab.setX(ab.getX() + ab.getTanx() * t);
        ab.setY(ab.getY() + ab.getTany() * t);
        ab.setZ(ab.getZ() + ab.getTanz() * t);

        //C
        c = (p->at(i + 1) - p->at(i)) * 3.0;
        c.setX(c.getX() - p->at(i + 1).getTanx() - p->at(i).getTanx() * 2.0);
        c.setY(c.getY() - p->at(i + 1).getTany() - p->at(i).getTany() * 2.0);
        c.setZ(c.getZ() - p->at(i + 1).getTanz() - p->at(i).getTanz() * 2.0);

        //D
        d = (p->at(i + 1) - p->at(i)) * 2.0;
        d.setX(p->at(i + 1).getTanx() + p->at(i).getTanx() - d.getX());
        d.setY(p->at(i + 1).getTany() + p->at(i).getTany() - d.getY());
        d.setZ(p->at(i + 1).getTanz() + p->at(i).getTanz() - d.getZ());

        //(P0 + T0t) + Ct2 + Dt3
        temp.push_back(ab + c * (t*t) + d * (t*t*t));
        j += 0.1;
      }
    }

  }

  p->clear();
  *p = temp;
  temp.clear();
}

/*
  Reads in the points from the input file. Then calls the catromPoints function
  to generate the points for the catrom curve. Once done, prints out the points
  to the output file.
*/
int main(int argc, char *argv[]) {
  std::vector<Point> points;

  readPoints(&points,argv[1]);

  catromPoints(&points);

  printPoints(&points);

  points.clear();
  return 0;
}
