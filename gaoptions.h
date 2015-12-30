#ifndef GA_OPTIONS
#define GA_OPTIONS

#include <stdlib.h>

#define DEFAULT_PMUTATION 0.001f
#define DEFAULT_SCALING 1.0f
#define DEFAULT_POP_SIZE 50
#define DEFAULT_FITNESS_HEURISTIC DOUBLE_ALL
#define DEFAULT_FITNESS_TRESHOLD 0.75f
#define DEFAULT_SELECTION_SIZE 10
#define DEFAULT_SELECTION_HEURISTIC NUMBER
#define DEFAULT_CHILDREN_PER_COUPLE 2
#define DEFAULT_CROSSOVER_HEURISTIC RANDOM_MIX
#define DEFAULT_MUTATION_HEURISTIC SIMPLE_MUTATION
#define DEFAULT_INVALID_HEURISTIC LOWER_FITNESS


// evaluation of a Creature for a single position of the sun
enum Single_eval_heuristic { 
	BOOL_BARYCENTER, 		// barycenter covered { 0.0, 1.0 }
	BOOL_BORDER, 			// all border points covered { 0.0, 1.0 }
	BOOL_MIDDLE, 			// all middle points covered { 0.0, 1.0 }
	BOOL_TRESHOLD_BORDER, 	// at least a given proportion [0.0;1.0] of border points covered { 0.0 1.0 }
	BOOL_TRESHOLD_MIDDLE, 	// at least a given proportion [0.0;1.0] of middle points covered { 0.0 1.0 }
	BOOL_TRESHOLD_ALL, 		// at least a given proportion [0.0;1.0] of all points covered { 0.0 1.0 }
	DOUBLE_BORDER, 			// nb_points_border_covered / nb_points_border [0;1]
	DOUBLE_MIDDLE, 			// nb_points_border_middle / nb_point_middle [0;1]
	DOUBLE_ALL 				// nb_points_covered / nb_points [0;1]
};
typedef Single_eval_heuristic SEH;


// how to create children
enum Crossover_heuristic {
	SWAP_GENE,				// swap a gene of the two parents to create two children (random gene index)
	SWAP_POINT,				// swap a point (3 genes) of the two parents to create two children (random point index)
	SWAP_PART,				// swap two parts of the two parents to create two children (random separation index) (ex : ffff & mmmm -> fmmm & mfff)
	SWAP_N_GENES,			// swap a random number of genes of the parents to create two children (")
	SWAP_N_POINTS,			// swap a random number of points of the parents to create two children (")
	RANDOM_MIX,				// randomly use any of the previous heuristic for each couple of parents
	NUM_CH
};
typedef Crossover_heuristic CH;


// how the mutation affects a creature
enum Mutation_heuristic {
	SIMPLE_MUTATION,		// attribute a random valid value to a random gene
	COMPLEX_MUTATION		// change global height or position (random) of the creature
};
typedef Mutation_heuristic MH;


// how we deal with Creature from crossover or mutation which are not valid creature
enum Invalid_creature_heuristic {
	IGNORE,					// ignore creature validity
	LOWER_FITNESS,			// fitness is computed then divided by 10
	NEW_CREATURE			// during crossover or mutation, require that the generated Creatures are valid
};
typedef Invalid_creature_heuristic ICH;


// how much creatures do we select for crossover
enum Selection_heuristic {
	HALF,					// will select population_size / 2 creatures
	THIRD,					// will select population_size / 3 creatures				
	QUARTER,				// will select population_size / 4 creatures
	TENTH,					// will select population_size / 10 creatures
	NUMBER 					// will select a given number of creatures (int:childen_per_couple)
};
typedef Selection_heuristic SH;



class GAOptions {

private:
	// general
	float _pmutation;		// mutation probability
	//float _scaling;			// scaling of the population for each generation
	int _popSize;			// init population size, definite population size if scaling = 1.0

	// fitness
	SEH _fitness_h;
	float _fitnessTreshold;		// treshold used depending of the fitness heuristic

	// selection
	int _selectionSize;
	SH _selection_h;

	// crossover
	int _childrenPerCouple;
	CH _crossover_h;

	// mutation
	MH _mutation_h;

	// validlidity
	ICH _invalid_h;

	// merge

public:
	GAOptions();
	GAOptions(float pm, float scl, int ps, SEH fh, SH sh, int ss, int cpc, CH ch, MH mh, ICH ich);

	// setters & getters	
	float pmutation()					{ return _pmutation; }
	int popSize()						{ return _popSize; }
	SEH fitness_heur()					{ return _fitness_h; }
	float fitnessTreshold()				{ return _fitnessTreshold; }
	SH selection_heur()					{ return _selection_h; }
	int selection_size()				{ return _selectionSize; }
	int childrenPerCouple()				{ return _childrenPerCouple; }
	CH crossover_heur()					{ return _crossover_h; }
	MH mutation_heur()					{ return _mutation_h; }
	ICH invalid_heur()					{ return _invalid_h; }

	void set_pmutation(float f)			{ _pmutation = f; }
	void set_popSize(int i)				{ _popSize = i; }
	void set_fitness_h(SEH e)			{ _fitness_h = e; }
	void set_fitnessTreshold(float f)	{ _fitnessTreshold = f; }
	void set_selection_h(SH e)			{ _selection_h = e; }
	void set_selectionSize(int i)		{ _selectionSize = i; }
	void set_childrenPerCouple(int i)	{ _childrenPerCouple = i; }
	void set_crossover_h(CH e)			{ _crossover_h = e; }
	void set_mutation_h(MH e)			{ _mutation_h = e; }
	void set_invalid_h(ICH e)			{ _invalid_h = e; }

};

#endif //GA_OPTIONS