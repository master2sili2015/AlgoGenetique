#include "interface.h"

Interface::Interface(QWidget * parent) : QMainWindow(parent)
{
    optionOmbrageGenerate = new OptionGenerate();
 	colorOmbrage = new OpOmbrage;
    ombrage = new Ombrage();
	posSun = new PosSun();
	Concat = new ConcatString;
	//Concat->setMinimumHeight(this->width()/3);
	//Concat->setMaximumWidth(230);
	Concat->setMaximumHeight(300);
	sol = new CoordSol;

	listView = new MyListView("Min", "Max", OTHER);
	listView->setMaximumWidth(230);
	listView->setMaximumHeight(300);

	QWidget * widgetParam = new QWidget;
	QVBoxLayout * layoutParam = new QVBoxLayout;
	QHBoxLayout * layoutModel = new QHBoxLayout;
	layoutModel->addWidget(Concat);
	layoutModel->addWidget(listView);
	layoutParam->addLayout(layoutModel);
	layoutParam->addWidget(sol);
	widgetParam->setLayout(layoutParam);

	QWidget * widgetOptionOmbrage = new QWidget;
	QVBoxLayout * layoutOptionOmbrage = new QVBoxLayout;
	QHBoxLayout * layoutOmbrage = new QHBoxLayout;
	layoutOmbrage->addWidget(optionOmbrageGenerate);
	layoutOmbrage->addWidget(colorOmbrage);
	layoutOptionOmbrage->addLayout(layoutOmbrage);
	layoutOptionOmbrage->addWidget(ombrage);
	widgetOptionOmbrage->setLayout(layoutOptionOmbrage);

	centralWidget = new QWidget(this);
	tabs = new QTabWidget(centralWidget);
	tabs->setMinimumSize(this->width(), this->height());
	tabs->addTab(widgetParam, QObject::tr("Paramètrage des données"));
	tabs->addTab(widgetOptionOmbrage, QObject::tr("Dessin 3D"));
  	tabs->addTab(posSun, QObject::tr("Position du soleil")); 	
	
	setCentralWidget(centralWidget);

	connect(sol, SIGNAL(drawSurface(QStringList, string)), 
		ombrage, SLOT(surfaceDrow(QStringList, string)));
	connect(listView, SIGNAL(updateFile(string)), ombrage, SLOT(setModeleFile(string)));
	connect(Concat, SIGNAL(zaFile(string)), posSun, SLOT(setTree(string)));
	connect(posSun, SIGNAL(zaFile(string)), ombrage, SLOT(setZeniteAzimithFile(string)));
}

Interface::~Interface()
{

}

void Interface::resizeEvent ( QResizeEvent * event )
{
	tabs->resize(this->width(), this->height());
}