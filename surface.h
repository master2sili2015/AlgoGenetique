#ifndef SURFACE_H
#define SURFACE_H

#include <stdlib.h>
#include <vector>
#include <cmath>

#include "geometry.h"

using namespace std;


enum Strategy { BARYCENTER=0, BORDER=1, MIDDLE=2, ALL=3 };  

/*
	Représente la surface à ombrager.
	Est définie par un polygone.
	on se propose de calculer le barycentre de la zone ainsi que des points intermédiaires 
	entre le barycentre et chaque point de la bordure.
*/

class Surface {

private:
	f2dPolygon border;
	f2dPoint _barycenter;
	vector<f2dPoint> middlePoints; 

	void computeAll();
	void computeBarycenter();
	void computeMiddlePoints();

public:
	Surface();
	Surface(f2dPolygon polygon);
	Surface(const Surface & surface);

	f2dPoint barycenter() const { return _barycenter; }
	vector<f2dPoint> points(Strategy s=ALL);
	f2dPolygon polygon() const { return border; }
};

#endif // SURFACE_H