#ifndef OMBRAGE_H
#define OMBRAGE_H

#include <QtCore>
#include <QtGui>
#include <QGLWidget>
#include <GL/glu.h>
#include <GL/glut.h>    // Header File For The GLUT Library 
#include <GL/gl.h>	// Header File For The OpenGL32 Library
#include <QColorDialog>
#include <QMessageBox>

#include "gaoptions.h"
#include "creature.h"
#include "surface.h"
#include <iostream>
#include <fstream>
#include <sstream>

#define RADPERDEG 0.0174533

enum Dessin { SURFACE, SCENE, CLEAR };

class Ombrage : public QGLWidget
{
	Q_OBJECT
public:
	Ombrage(Dessin d = SCENE, QWidget * parent = 0);
	~Ombrage();

	void updateSurface(f2dPolygon * polygon);

private slots:	
	void surfaceDrow(QStringList list, string f);
	void updateColor(QColor col, int i);
	void setModeleFile(string file);
	void setZeniteAzimithFile(string file);

	void startAlgoGen(GAOptions * option);

protected:
	void initializeGL();
	void resizeGL(int width, int height);
	void paintGL();
	void mousePressEvent(QMouseEvent * event);
	void mouseMoveEvent(QMouseEvent * event);
	void wheelEvent (QWheelEvent * event);

private:
	void draw();
	int faceAtPosition(const QPoint & pos);
	
	GLfloat translate;
	GLfloat rotationX;
	GLfloat rotationY;
	GLfloat rotationZ;

	QPoint lastPos;

	QColor voileColor;
	QColor ombreColor;
	QColor solColor;

	Creature * creature;

	Dessin dessin;
	Surface * surface;

	bool update;
	string surfaceFile;
	string modeleFile;
	string ZAFile;
};

#endif