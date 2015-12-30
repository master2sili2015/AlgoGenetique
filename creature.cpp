#include "creature.h"

Creature::Creature()
	: _nbGenes(0), _nbPoints(0), _fitness(0.0)
{}

Creature::Creature(int nbGenes)
	: _nbGenes(nbGenes), _nbPoints(nbGenes / 3), _fitness(0.0)
{
	genome = new float[_nbGenes];
}

Creature::Creature(const Creature & c) {
	_nbGenes = c.nbGenes();
	_nbPoints = _nbGenes / 3;
	_fitness = c.fitness();

	genome = new float[_nbGenes];
	for(int i = 0; i < _nbGenes; ++i) {
		genome[i] = c.gene(i);
	}
}

Creature::~Creature() {
	delete[] genome;
}

f2dPolygon Creature::shadow(const f3dVector & v) const {
	f2dPolygon s(_nbPoints);
	for(int i=0; i < _nbPoints; ++i) {
		f3dPoint p(genome[3*i], genome[(3*i)+1], genome[(3*i)+2]);
		s.set(i, Geometry::projectionPointXY(p, v));
	}

	return s;
}

f3dPolygon Creature::polygon() const {
	f3dPolygon p(_nbPoints);
	for(int i=0 ; i < _nbPoints; ++i) {
		p.set(i, genome[3*i], genome[(3*i)+1], genome[(3*i)+2]);
	}
	return p;
}

void Creature::operator=(Creature const & c) {
	_nbGenes = c.nbGenes();
	_nbPoints = _nbGenes / 3;
	_fitness = c.fitness();

	genome = new float[_nbGenes];
	for(int i = 0; i < _nbGenes; ++i) {
		genome[i] = c.gene(i);
	}
}