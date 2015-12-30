#include "surface.h"

Surface::Surface() {
	border = f2dPolygon(0);
	computeAll();
}
#include <iostream>
Surface::Surface(f2dPolygon polygon)
	: border(polygon)
{
	computeAll();
}

Surface::Surface(const Surface & surface) {
	border = surface.polygon();
	_barycenter = surface.barycenter();
	middlePoints = surface.middlePoints;
}

void Surface::computeAll() {
	computeBarycenter();
	computeMiddlePoints();
}

void Surface::computeBarycenter() {
	float X, Y;
	for(int i=0; i < border.nbCorners(); ++i) {
		X += border.xat(i);
		Y += border.yat(i);
	}

	_barycenter.x = X / border.nbCorners();
	_barycenter.y = Y / border.nbCorners();
}

void Surface::computeMiddlePoints() {
	f2dPoint p;
	for(int i=0; i < border.nbCorners(); ++i) {
		p.x = (_barycenter.x + border.xat(i)) * 0.5;
		p.y = (_barycenter.y + border.yat(i)) * 0.5;
		if(Geometry::pointInPolygon(p, border))
			middlePoints.push_back(p);
	}
}

vector<f2dPoint> Surface::points(Strategy s) {

	vector<f2dPoint> result;

	if(s == BARYCENTER || s == ALL) {
		computeBarycenter();
		result.push_back(_barycenter);
	}
	if(s == BORDER || s == ALL) {
		for(int i=0; i < border.nbCorners(); ++i) {
			result.push_back(border.at(i));
		}
	}
	if(s == MIDDLE || s == ALL) {
		computeMiddlePoints();
		for(int i=0; i < middlePoints.size(); ++i) {
			result.push_back(middlePoints.at(i));
		}
	}
	return result;
}