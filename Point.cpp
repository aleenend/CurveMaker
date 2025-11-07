/*
  Aleene Dupuy
  P2 Due 4/9
  CPSC 6050

  This file is the function implementations for the Point class. All functions
  are just constructors, setters, getters, or operator overloads, thus there
  are not many comments explaining what each one does as it should be easy to
  determine.
*/

#include "Point.h"


Point::Point() {
  x = y = z = tanx = tany= tanz = 0.0;
}

Point::Point(double x, double y, double z, double tanx, double tany, double tanz) {
  this->x = x;
  this->y = y;
  this->z = z;
  this->tanx = tanx;
  this->tany = tany;
  this->tanz = tanz;

}

//setters
void Point::setX(double n) {
  x = n;
}

void Point::setY(double n) {
  y = n;
}

void Point::setZ(double n) {
  z = n;
}

void Point::setTanx(double tanN) {
  tanx = tanN;
}

void Point::setTany(double tanN) {
  tany = tanN;
}

void Point::setTanz(double tanN) {
  tanz = tanN;
}

//overloads
Point Point::operator+(const Point& p) {
  Point point;

  point.x = this->x + p.x;
  point.y = this->y + p.y;
  point.z = this->z + p.z;

  return point;
}

Point Point::operator-(const Point& p) {
  Point point;

  point.x = this->x - p.x;
  point.y = this->y - p.y;
  point.z = this->z - p.z;

  return point;
}

Point Point::operator*(const double n) {
  Point point;

  point.x = this->x * n;
  point.y = this->y * n;
  point.z = this->z * n;

  return point;
}

Point Point::operator/(const double n) {
  Point point;

  point.x = this->x / n;
  point.y = this->y / n;
  point.z = this->z / n;

  return point;
}

Point& Point::operator=(const Point& p) {
  Point point;

  x = p.x;
  y = p.y;
  z = p.z;
  tanx = p.tanx;
  tany = p.tany;
  tanz = p.tanz;

  return *this;
}
