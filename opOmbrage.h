#ifndef OPOMBRAGE_H
#define OPOMBRAGE_H

#include <QGLWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QColor>
#include <QColorDialog>
#include <QPushButton>

#define COULEUR_VOILE 1
#define COULEUR_OMBRE 2
#define COULEUR_SOL 3

#include "myLabel.h"

class OpOmbrage : public QWidget
{
	Q_OBJECT
public:
	OpOmbrage(QWidget * parent = 0);
	~OpOmbrage();

signals:
	void color(QColor, int);
	void startAlgo();

private slots:
	void couleurVoile();
	void couleurOmbre();
	void couleurSol();
	void startAlgoGen();

private:
	void couleurChange(int col);

	MyLabel * labelVoile;
	MyLabel * labelOmbre;
	MyLabel * labelSol;

	QPushButton * buttonAlgoGen;
};
#endif