#ifndef COORDSOL_H
#define COORDSOL_H

#include "ombrage.h"
#include "myListView.h"

class CoordSol : public QWidget
{
	Q_OBJECT
public:
	CoordSol(QWidget * parent = 0);
	~CoordSol();

signals:
	void updateDraw();
	void drawSurface(QStringList, string);

private slots:
	void rafraichDraw(QStringList list);
	void updateSurface(QStringList list, string str);

private:
	QHBoxLayout * layoutGeneral;

	Ombrage * ombrage;
	MyListView * listView;

	string fileUse;
};
#endif