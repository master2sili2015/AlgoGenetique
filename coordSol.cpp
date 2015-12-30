#include "coordSol.h"

CoordSol::CoordSol(QWidget * parent) : QWidget(parent)
{
	ombrage = new Ombrage(SURFACE);	

	listView = new MyListView("Coord X", "Coord Y", SOL, true);
	listView->setMaximumWidth(230);

	layoutGeneral = new QHBoxLayout;
	layoutGeneral->addWidget(listView);
	layoutGeneral->addWidget(ombrage);
	ombrage->setMinimumWidth(this->width()/2);

	setLayout(layoutGeneral);

	connect(this, SIGNAL(updateDraw()), ombrage, SLOT(updateGL()));
	connect(listView, SIGNAL(draw(QStringList)), this, SLOT(rafraichDraw(QStringList)));
	connect(listView, SIGNAL(drowSurface(QStringList, string)), this, SLOT(updateSurface(QStringList, string)));
}

CoordSol::~CoordSol()
{

}

void CoordSol::rafraichDraw(QStringList list)
{
	f2dPolygon *polygon;
	polygon = new f2dPolygon(list.size());

	for(int i=0; i < list.size(); ++i) {
		float x,y;
		istringstream iss(list[i].toStdString());
		iss >> x >> y;
		polygon->set(i, x, y);
	}

	ombrage->updateSurface(polygon);
	emit updateDraw();	
}

void CoordSol::updateSurface(QStringList list, string str)
{
	QMessageBox::StandardButton reply;
	reply = QMessageBox::question(this, "Update shading area", "Want to get an update of the shading area ?",
							QMessageBox::Yes | QMessageBox::No);
	if (reply == QMessageBox::Yes) emit drawSurface(list, str);
}