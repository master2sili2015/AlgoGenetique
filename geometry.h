#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <cmath>
#include <vector>

using namespace std;

#define PI 3.14159265359

class f2dPoint;
class f3dPoint;
class f3dVector;
class f2dPolygon;
class f3dPolygon;

class Geometry {
public:
  static bool pointInPolygon(const f2dPoint p,  const f2dPolygon & polygon);
  static f2dPoint projectionPointXY(const f3dPoint & p, const f3dVector & v);
  static float d2r(float d);
};

// ###############################
// ##########  CLASSES  ##########
// ###############################

class f2dPoint {
public:
  float x,y;
  f2dPoint() : x(0), y(0) {};
  f2dPoint(float i, float j) : x(i), y(j) {};
  f2dPoint(const f2dPoint & p) : x(p.x), y(p.y) {};
};

class f3dPoint {
public:
  float x,y,z;
  f3dPoint() : x(0), y(0), z(0) {}
  f3dPoint(float i, float j, float k) : x(i), y(j), z(k) {};
  f3dPoint(const f3dPoint & p) : x(p.x), y(p.y), z(p.z) {};
};

class f3dVector : public f3dPoint  {
public:
  f3dVector(float x, float y, float z) : f3dPoint(x,y,z) {}
  f3dVector() : f3dPoint() {}
	float norm() const  { return sqrt(x*x + y*y + z*z); }
  void normalize()    { float n = norm();
                        if(n == 1)  return;
                        float r = 1 / n;  
                        x = r*x; y = r*y;  z = r*z; 
                      }
};

class f2dPolygon {
private:
	f2dPoint *points;
	int _nbCorners;
public:
  f2dPolygon() : _nbCorners(0)       {}
	f2dPolygon(int s) : _nbCorners(s)  { points = new f2dPoint[_nbCorners]; }
  f2dPolygon(const f2dPolygon & poly);
  ~f2dPolygon()                      { delete[] points; }
  void operator=(f2dPolygon const & polygon);
  // ###
  vector<f2dPoint> getPoints() const;
	f2dPoint at(int n) const			     { return points[n]; }
	float xat(int n) const 				     { return points[n].x; }
	float yat(int n) const 				     { return points[n].y; }
	void set(int n, f2dPoint p)			   { points[n] = p; } 
	void set(int n, float x, float y)	 { points[n] = f2dPoint(x,y); } 
	int nbCorners() const				       { return _nbCorners; }
  float polygonArea() const;
};

class f3dPolygon {
private:
  f3dPoint *points;
  int _nbCorners;
public:
  f3dPolygon() : _nbCorners(0)       {}
  f3dPolygon(int s) : _nbCorners(s)  { points = new f3dPoint[_nbCorners]; }
  f3dPolygon(const f3dPolygon & poly);
  ~f3dPolygon()                      { delete[] points; }
  void operator=(f3dPolygon const & polygon);
  // ###
  vector<f3dPoint> getPoints() const;
  f3dPoint at(int n) const           { return points[n]; }
  float xat(int n) const             { return points[n].x; }
  float yat(int n) const             { return points[n].y; }
  float zat(int n) const             { return points[n].z; }
  void set(int n, f3dPoint p)        { points[n] = p; } 
  void set(int n, float x, float y, float z)  { points[n] = f3dPoint(x,y,z); } 
  int nbCorners() const              { return _nbCorners; }
  f2dPolygon project(f3dVector v) const;
};

#endif // GEOMETRY_H