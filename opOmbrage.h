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

class OpOmbrage : public QWidget
{
	Q_OBJECT
public:
	OpOmbrage(QWidget * parent = 0);
	~OpOmbrage();

signals:
	void color(QColor, int);

private slots:
	void couleurVoile();
	void couleurOmbre();
	void couleurSol();

private:
	void couleurChange(int col);

	QLabel * labelVoile;
	QLabel * labelOmbre;
	QLabel * labelSol;

	QPushButton * buttonAlgoGen;
};
#endif