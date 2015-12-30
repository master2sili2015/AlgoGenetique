#ifndef INTERFACE_H
#define INTERFACE_H 

#include "posSun.h"
#include "ConcaString.h"
#include "coordSol.h"
#include "optionGenerate.h"
#include "opOmbrage.h"
#include <QTabWidget>
#include <QMainWindow>

class Interface : public QMainWindow
{
	Q_OBJECT
public:
	Interface(QWidget * parent = 0);
	~Interface();

protected:
	void resizeEvent ( QResizeEvent * event );

private:
	OptionGenerate * optionOmbrageGenerate;
	MyListView * listView;
	OpOmbrage * colorOmbrage;
	Ombrage * ombrage;
	PosSun * posSun;
	CoordSol * sol;
	ConcatString * Concat;
	QWidget * centralWidget;
	QTabWidget * tabs;
};

#endif