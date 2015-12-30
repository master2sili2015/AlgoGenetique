#ifndef CREATURE_H
#define CREATURE_H

#include "geometry.h"


class Creature {

private:
	float *genome;
	int _nbGenes;
	int _nbPoints;
	double _fitness;

public:
	Creature();
	Creature(int nbGenes);
	Creature(const Creature & c);
	~Creature();

	// initialize();

	f2dPolygon shadow(const f3dVector & v) const;
	f3dPolygon polygon() const;

	float gene(int n) const			{ return genome[n]; }
	double fitness() const			{ return _fitness; }
	int nbGenes() const				{ return _nbGenes; }

	void set(int n, float f)		{ genome[n] = f; }
	void setFitness(double fitness)	{ _fitness = fitness;}

	void operator=(Creature const & c);
};

inline bool operator<(Creature const &a, Creature const& b)	{ return a.fitness() < b.fitness(); }
inline bool operator>(Creature const &a, Creature const& b)	{ return b<a; }

#endif // CREATURE_H