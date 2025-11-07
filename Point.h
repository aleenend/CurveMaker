/*
  Aleene Dupuy
  P2 Due 4/9
  CPSC 6050

  This file is the header for the Point class. I created the Point class to
  function as one point on a curve. The Point will contain an x, y, z, x
  tangent (tanx), y tangent (tany), and z tangent (tanz).

  The class contains getters, setters, and operator overloads to simplify some
  of the math performed in the curve files.
*/

#ifndef POINT_H
#define POINT_H

class Point {
private:
  double x, y, z;
  double tanx, tany, tanz;

public:
  //constructors
  Point();
  Point(double x, double y, double z, double tanx, double tany, double tanz);
  //getters
  double getX() {return x;}
  double getY() {return y;}
  double getZ() {return z;}
  double getTanx() {return tanx;}
  double getTany() {return tany;}
  double getTanz() {return tanz;}
  //setters
  void setX(double n);
  void setY(double n);
  void setZ(double n);
  void setTanx(double tanN);
  void setTany(double tanN);
  void setTanz(double tanN);
  //overloads
  Point operator+(const Point& p);
  Point operator-(const Point& p);
  Point operator*(const double n);
  Point operator/(const double n);
  Point& operator=(const Point& p);

};

#endif
