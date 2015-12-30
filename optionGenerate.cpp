#include "optionGenerate.h"

OptionGenerate::OptionGenerate(QWidget * parent) : QWidget(parent)
{
	///////// General information ///////////////////
	general = new QGroupBox(tr("General information"));
	QHBoxLayout * mutationProbabilityLayout = new QHBoxLayout;
	labelMutationProbability = new QLabel(tr("Mutation probability"));
	mutationProbability = new QLineEdit;
	mutationProbabilityLayout->addWidget(labelMutationProbability);
	mutationProbabilityLayout->addWidget(mutationProbability);
	general->setLayout(mutationProbabilityLayout);

	labelPopSize = new QLabel(tr("Init population size"));
	popSize = new QLineEdit;
	mutationProbabilityLayout->addWidget(labelPopSize);
	mutationProbabilityLayout->addWidget(popSize);

	check = new QCheckBox(tr("Age"));
	mutationProbabilityLayout->addWidget(check);
	//////////////////////////////////////////////

	/////////////// Fitness ///////////////////////
	QHBoxLayout * fitnessLayout = new QHBoxLayout;
	fitnessLayout->addWidget(new QLabel(tr("Choose evaluation of a creature")));
	fitnessHeuristic = new QComboBox;
	fitnessLayout->addWidget(fitnessHeuristic);
	fitnessLayout->addWidget(new QLabel(tr("Value")));
	fitnessTreshold = new QLineEdit;
	fitnessLayout->addWidget(fitnessTreshold);
	///////////////////////////////////////////////

	////////////////// Selection //////////////////
	QHBoxLayout * selectionLayout = new QHBoxLayout;
	selectionLayout->addWidget(new QLabel(tr("Choose how much creatures do we select for crossover")));
	selectionHeuristic = new QComboBox;
	selectionLayout->addWidget(selectionHeuristic);
	selectionLayout->addWidget(new QLabel(tr("Value")));
	selectionSize = new QLineEdit;
	selectionLayout->addWidget(selectionSize);
	//////////////////////////////////////////////
	
	////////////// Crossover /////////////////////
	QHBoxLayout * crossoverLayout = new QHBoxLayout;
	crossoverLayout->addWidget(new QLabel(tr("Choose how to create children")));
	crossoverHeuristic = new QComboBox;
	crossoverLayout->addWidget(crossoverHeuristic);
	crossoverLayout->addWidget(new QLabel(tr("Value")));
	childrenPerCouple = new QLineEdit;
	crossoverLayout->addWidget(childrenPerCouple);
	//////////////////////////////////////////////////

	//Mutation
	QHBoxLayout * mutation = new QHBoxLayout;
	labelMutationHeuristic = new QLabel(tr("Choose how the mutation affects a creature"));
	mutationHeuristic = new QComboBox;
	mutation->addWidget(labelMutationHeuristic);
	mutation->addWidget(mutationHeuristic);

	//Validity
	QHBoxLayout * validity = new QHBoxLayout;
	labelValidity = new QLabel(tr("Choose action if crossover or mutation are not valid creature"));
	invalidCreature = new QComboBox;
	validity->addWidget(labelValidity);
	validity->addWidget(invalidCreature);

	//options = new GAOptions;

	QVBoxLayout * generalLayout = new QVBoxLayout;
	generalLayout->addWidget(general);
	generalLayout->addLayout(fitnessLayout);
	generalLayout->addLayout(selectionLayout);
	generalLayout->addLayout(crossoverLayout);
	generalLayout->addLayout(mutation);
	generalLayout->addLayout(validity);

	setLayout(generalLayout);
	setMaximumHeight(270);

	initComboBoxValue();
	selectDefaultValue();

	connect(selectionHeuristic, SIGNAL(currentIndexChanged(int)), this, SLOT(selectionHeuristicSlot(int)));
	connect(fitnessHeuristic, SIGNAL(currentIndexChanged(int)), this, SLOT(fitnessHeuristicSlot(int)));

	connect(mutationProbability, SIGNAL(textEdited(QString)), this, SLOT(mutationProbabilityValid(QString)));
	connect(fitnessTreshold, SIGNAL(textEdited(QString)), this, SLOT(fitnessTresholdValid(QString)));
	connect(childrenPerCouple, SIGNAL(textEdited(QString)), this, SLOT(childrenPerCoupleValid(QString)));
	connect(popSize, SIGNAL(textEdited(QString)), this, SLOT(popSizeValid(QString)));
	connect(selectionSize, SIGNAL(textEdited(QString)), this, SLOT(selectionSizeValid(QString)));
}

OptionGenerate::~OptionGenerate()
{

}

void OptionGenerate::initComboBoxValue()
{
	crossoverHeuristic->addItem(tr("swap a gene of the two parents"));
	crossoverHeuristic->addItem(tr("swap a point (3 genes) of the two parents"));
	crossoverHeuristic->addItem(tr("swap two parts of the two parents"));
	crossoverHeuristic->addItem(tr("swap a random number of genes of the parents"));
	crossoverHeuristic->addItem(tr("swap a random number of points of the parents"));
	crossoverHeuristic->addItem(tr("randomly use any of the previous heuristic"));
	crossoverHeuristic->addItem(tr("number crossover heuristic"));


	selectionHeuristic->addItem(tr("helf population"));
	selectionHeuristic->addItem(tr("third population"));
	selectionHeuristic->addItem(tr("quarter population"));
	selectionHeuristic->addItem(tr("tenth population"));
	selectionHeuristic->addItem(tr("other"));

	fitnessHeuristic->addItem(tr("barycenter covered"));
	fitnessHeuristic->addItem(tr("all border points covered"));
	fitnessHeuristic->addItem(tr("all middle points covered"));
	fitnessHeuristic->addItem(tr("at least a proportion of border points covered"));
	fitnessHeuristic->addItem(tr("at least a proportion of middle points covered"));
	fitnessHeuristic->addItem(tr("at least a proportion of all points covered"));
	fitnessHeuristic->addItem(tr("nb points border covered"));
	fitnessHeuristic->addItem(tr("nb points middle covered"));
	fitnessHeuristic->addItem(tr("nb points covered"));

	mutationHeuristic->addItem(tr("simple mutation"));
	mutationHeuristic->addItem(tr("complex mutation"));

	invalidCreature->addItem(tr("ignore"));
	invalidCreature->addItem(tr("lower fitness"));
	invalidCreature->addItem(tr("new creature"));
}

void OptionGenerate::selectDefaultValue()
{
	mutationProbability->setText(QString::number(DEFAULT_PMUTATION));
	popSize->setText(QString::number(DEFAULT_POP_SIZE));

	fitnessTreshold->setText(QString::number(DEFAULT_FITNESS_TRESHOLD));
	fitnessTreshold->setEnabled(false);
	fitnessHeuristic->setCurrentIndex(fitnessHeuristic->count() - 1);

	selectionSize->setText(QString::number(DEFAULT_SELECTION_SIZE));
	selectionHeuristic->setCurrentIndex(selectionHeuristic->count() - 1);

	childrenPerCouple->setText(QString::number(DEFAULT_CHILDREN_PER_COUPLE));
	crossoverHeuristic->setCurrentIndex(crossoverHeuristic->count() - 2);

	mutationHeuristic->setCurrentIndex(0);
	invalidCreature->setCurrentIndex(1);
}

void OptionGenerate::fitnessHeuristicSlot(int index)
{
	if (index > 2 && index < 6) fitnessTreshold->setEnabled(true);
	else fitnessTreshold->setEnabled(false);
}

void OptionGenerate::selectionHeuristicSlot(int index)
{
	if (index > 3) selectionSize->setEnabled(true);
	else selectionSize->setEnabled(false);
}

void OptionGenerate::mutationProbabilityValid(QString text)
{
	if (text.isEmpty()) return;
	if (!Global::valideInterval(text, this)) mutationProbability->setText("");
}

void OptionGenerate::popSizeValid(QString text)
{
	if (text.isEmpty()) return;
	if (!Global::valideInt(text, this)) popSize->setText("");
}

void OptionGenerate::fitnessTresholdValid(QString text)
{
	if (text.isEmpty()) return;
	if (!Global::valideInterval(text, this)) fitnessTreshold->setText("");
}

void OptionGenerate::selectionSizeValid(QString text)
{
	if (text.isEmpty()) return;
	if (!Global::valideInt(text, this)) selectionSize->setText("");
}

void OptionGenerate::childrenPerCoupleValid(QString text)
{
	if (text.isEmpty()) return;
	if (!Global::valideInt(text, this)) childrenPerCouple->setText("");
}

GAOptions * OptionGenerate::getOptionChoose()
{
	////////////General Information value ///////////////
	bool ok;
	if (!mutationProbability->text().isEmpty()) 
		options->set_pmutation(mutationProbability->text().toDouble(&ok));
	else options->set_pmutation(DEFAULT_PMUTATION);
	
	if (!popSize->text().isEmpty())
		options->set_popSize(popSize->text().toDouble(&ok));
	else options->set_popSize(DEFAULT_POP_SIZE);
	////////////////////////////////////////////////////

	/////////////// Fitness value ///////////////////////
	if (!fitnessTreshold->text().isEmpty()) 
		options->set_fitnessTreshold(fitnessTreshold->text().toDouble(&ok));
	else options->set_fitnessTreshold(DEFAULT_FITNESS_TRESHOLD);
	switch(fitnessHeuristic->currentIndex())
	{
		case 0:
			options->set_fitness_h(BOOL_BARYCENTER);
		break;
		case 1:
			options->set_fitness_h(BOOL_BORDER);
		break;
		case 2:
			options->set_fitness_h(BOOL_MIDDLE);
		break;
		case 3:
			options->set_fitness_h(BOOL_TRESHOLD_BORDER);			
		break;
		case 4:
			options->set_fitness_h(BOOL_TRESHOLD_MIDDLE);
		break;
		case 5:
			options->set_fitness_h(BOOL_TRESHOLD_ALL);
		break;
		case 6:
			options->set_fitness_h(DOUBLE_BORDER);
		break;
		case 7:
			options->set_fitness_h(DOUBLE_MIDDLE);
		break;
		case 8:
			options->set_fitness_h(DOUBLE_ALL);
		break;
		default:
			options->set_fitness_h(DOUBLE_ALL);
		break;
	}
	/////////////////////////////////////////////////////////

	////////////// Crossover value /////////////////////
	if (!childrenPerCouple->text().isEmpty()) 
		options->set_childrenPerCouple(childrenPerCouple->text().toDouble(&ok));
	else options->set_childrenPerCouple(DEFAULT_CHILDREN_PER_COUPLE);
	switch(crossoverHeuristic->currentIndex())
	{
		case 0:
			options->set_crossover_h(SWAP_GENE);
		break;
		case 1:
			options->set_crossover_h(SWAP_POINT);
		break;
		case 2:
			options->set_crossover_h(SWAP_PART);
		break;
		case 3:
			options->set_crossover_h(SWAP_N_GENES);
		break;
		case 4:
			options->set_crossover_h(SWAP_N_POINTS);
		break;
		case 5:
			options->set_crossover_h(RANDOM_MIX);			
		break;
		case 6:
			options->set_crossover_h(NUM_CH);
		break;
		default:
			options->set_crossover_h(NUM_CH);
		break;
		////////////////////////////////////////////////////

		//////////////////// Selection value //////////////////
		options->set_selectionSize(DEFAULT_SELECTION_SIZE);
		switch (selectionHeuristic->currentIndex())
		{
			case 0:
				options->set_selection_h(HALF);
			break;
			case 1:
				options->set_selection_h(THIRD);
			break;
			case 2:
				options->set_selection_h(QUARTER);
			break;
			case 3:
				options->set_selection_h(TENTH);
			break;
			case 4:
				options->set_selection_h(NUMBER);
				if (!selectionSize->text().isEmpty()) 
					options->set_selectionSize(selectionSize->text().toDouble(&ok));
				else options->set_selectionSize(DEFAULT_SELECTION_SIZE);
			break;
			default:
				options->set_selection_h(NUMBER);
			break;
		}
		////////////////////////////////////////////////

		//Mutation
		switch(mutationHeuristic->currentIndex())
		{
			case 0:
				options->set_mutation_h(SIMPLE_MUTATION);
			break;
			case 1:
				options->set_mutation_h(COMPLEX_MUTATION);
			break;
			default:
				options->set_mutation_h(SIMPLE_MUTATION);
			break;
		}

		//Validity
		switch (invalidCreature->currentIndex())
		{
			case 0:
				options->set_invalid_h(IGNORE);
			break;
			case 1:
				options->set_invalid_h(LOWER_FITNESS);
			break;
			case 2:
				options->set_invalid_h(NEW_CREATURE);
			break;
			default:
				options->set_invalid_h(LOWER_FITNESS);
			break;
		}
	}
	return options;
}