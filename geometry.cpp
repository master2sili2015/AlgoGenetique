#include "geometry.h"

// f2dPolygon

f2dPolygon::f2dPolygon(const f2dPolygon & poly) {
  _nbCorners = poly.nbCorners();
  points = new f2dPoint[_nbCorners];
  for(int i=0; i < _nbCorners; ++i) {
    this->set(i, poly.xat(i), poly.yat(i));
  }
}

void f2dPolygon::operator=(f2dPolygon const & polygon) {
  if(_nbCorners != 0) {
    delete[] points;
  }
  _nbCorners = polygon.nbCorners();
  points = new f2dPoint[_nbCorners];
  for(int i=0; i < _nbCorners; ++i) {
    this->set(i, polygon.xat(i), polygon.yat(i));
  } 
}

//  Public-domain function by Darel Rex Finley, 2006.
float f2dPolygon::polygonArea() const { 
  float  area=0.;
  int i, j=_nbCorners-1;
  for (i=0; i<_nbCorners; i++) {
    area+=(points[j].x+points[i].x)*(points[j].y-points[i].y); 
    j=i; 
  }
  return std::abs(area*.5); 
}

vector<f2dPoint> f2dPolygon::getPoints() const {
  vector<f2dPoint> pts;
  for(int i=0; i < _nbCorners; ++i) {
    pts.push_back(points[i]);
  }
  return pts;
}

// ### f3dPolygon

f3dPolygon::f3dPolygon(const f3dPolygon & poly) {
  _nbCorners = poly.nbCorners();
  points = new f3dPoint[_nbCorners];
  for(int i=0; i < _nbCorners; ++i) {
    this->set(i, poly.xat(i), poly.yat(i), poly.zat(i));
  }
}

void f3dPolygon::operator=(f3dPolygon const & polygon) {
  if(_nbCorners != 0) {
    delete[] points;
  }
  _nbCorners = polygon.nbCorners();
  points = new f3dPoint[_nbCorners];
  for(int i=0; i < _nbCorners; ++i) {
    this->set(i, polygon.xat(i), polygon.yat(i), polygon.zat(i));
  }
}

f2dPolygon f3dPolygon::project(f3dVector v) const {
  f2dPolygon p(_nbCorners);
  for(int i=0; i < _nbCorners; ++i) {
    p.set(i, Geometry::projectionPointXY(points[i], v));
  }
  return p;
}

vector<f3dPoint> f3dPolygon::getPoints() const {
  vector<f3dPoint> pts;
  for(int i=0; i < _nbCorners; ++i) {
    pts.push_back(points[i]);
  }
  return pts;
}

// GEOMETRY FUNCTIONS

// http://alienryderflex.com/polygon/
bool Geometry::pointInPolygon(const f2dPoint p,  const f2dPolygon & polygon) {

  int   i, j=polygon.nbCorners()-1;
  bool  oddNodes=false;

  for (i=0; i<polygon.nbCorners(); i++) {
    if ((((polygon.yat(i)< p.y) && polygon.yat(j)>=p.y)
      ||   (polygon.yat(j)< p.y && polygon.yat(i)>=p.y))
      &&  (polygon.xat(i)<=p.x || polygon.xat(j)<=p.x)) {
      if (polygon.xat(i)+(p.y-polygon.yat(i))/(polygon.yat(j)-polygon.yat(i))*(polygon.xat(j)-polygon.xat(i))<p.x) {
        oddNodes=!oddNodes; 
      }
    }
    j=i; 
  }
  return oddNodes; 
}

f2dPoint Geometry::projectionPointXY(const f3dPoint & p, const f3dVector & v) {
  f2dPoint prj;
  float vx = v.x;
  float vy = v.y;
  float vz = v.z;

  if(vz > 0)
  {
    vx *= -1;
    vy *= -1;
    vz *= -1;
  }

  float n = std::abs(p.z / vz);
  prj.x = p.x + (vx * n);
  prj.y = p.y + (vy * n);

  return prj;
}


float Geometry::d2r(float d) {
  return PI * d / 180.0f;
}
