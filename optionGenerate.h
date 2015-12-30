#ifndef OPTION_GENERATE
#define OPTION_GENERATE

#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QCheckBox>

#include "gaoptions.h"
#include "global.h"

class OptionGenerate : public QWidget
{
	Q_OBJECT
public:
	OptionGenerate(QWidget * parent = 0);
	~OptionGenerate();

	GAOptions * getOptionChoose();

private slots:
	void fitnessHeuristicSlot(int index);
	void selectionHeuristicSlot(int index);
	void mutationProbabilityValid(QString text);
	void popSizeValid(QString text);
	void fitnessTresholdValid(QString text);
	void selectionSizeValid(QString text);
	void childrenPerCoupleValid(QString text);
	
private:
	void initComboBoxValue();
	void selectDefaultValue();

	QCheckBox * check;

	QLabel * labelMutationHeuristic;	//Mutation
	QComboBox * mutationHeuristic;		//Mutation

	QLabel * labelValidity;				//Validity
	QComboBox * invalidCreature; 		//Validity

	//General
	QGroupBox * general;
	QLabel * labelMutationProbability;
	QLineEdit * mutationProbability;
	QLabel * labelScaling;
	QLabel * labelPopSize;
	QLineEdit * popSize;

	//Option
	//Fitness
	QComboBox * fitnessHeuristic;	
	QLineEdit * fitnessTreshold;

	//Selection
	QComboBox * selectionHeuristic;
	QLineEdit * selectionSize;

	//Crossover
	QComboBox * crossoverHeuristic;
	QLineEdit * childrenPerCouple;

	GAOptions * options;
};

#endif