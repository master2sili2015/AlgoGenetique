#include "ombrage.h"

Ombrage::Ombrage(Dessin d, QWidget * parent) : QGLWidget(parent)
{
	setFormat(QGLFormat(QGL::DoubleBuffer | QGL::DepthBuffer));
	dessin = d;
	surfaceFile = "";
	surface = NULL;
	creature = NULL;
	update = false;

	translate = -10.0;
	rotationX = 0.0;
	rotationY = 0.0;
	rotationZ = 0.0;

	voileColor = Qt::yellow;
	ombreColor = Qt::darkRed;
	solColor = Qt::lightGray;

	/*creature = new Creature(12);

	creature->set(0, 1);
	creature->set(1, 1);
	creature->set(2, 0.5);
	creature->set(3, 1);
	creature->set(4, -1);
	creature->set(5, 0.5);
	creature->set(6, -1);
	creature->set(7, -1);
	creature->set(8, 0.5);
	creature->set(9, -1);
	creature->set(10, 1);
	creature->set(11, 0.5);*/
}

Ombrage::~Ombrage()
{
	delete creature;
}

void Ombrage::initializeGL()
{
	qglClearColor(Qt::black);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
}

void Ombrage::resizeGL(int width, int height)
{
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLfloat x = GLfloat(width) / height;
	gluPerspective(70, x, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
}

void Ombrage::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(-2,3,2,0,0,1,0,1,0);
	draw();
}

void Ombrage::draw()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (dessin == SCENE) glTranslatef(0.0, -2.5, translate);
	if (dessin == SURFACE) glTranslatef(0.0, -1.0, translate);
	
	glRotatef(rotationX, 1.0, 0.0, 0.0);
	glRotatef(rotationY, 0.0, 1.0, 0.0);
	glRotatef(rotationZ, 0.0, 0.0, 1.0);

	if (dessin == CLEAR) return;

	if (dessin == SCENE && creature != NULL)
	{
		cout << "aaaaa" << endl;
		//La position du voile
		vector<f3dPoint> voile = creature->polygon().getPoints();

		glBegin(GL_POLYGON);
		qglColor(voileColor);
		for (unsigned int i = 0; i < voile.size(); ++i)
		{
			glVertex3f(voile[i].x, voile[i].z, voile[i].y);
		}
		glEnd();

		//L'Ombre projeté
		f3dVector f3d(1, 2, 3);
		f3d.normalize();
		std::vector<f2dPoint> ombre = creature->shadow(f3d).getPoints();

		glBegin(GL_POLYGON);
		qglColor(ombreColor);
		for (unsigned int i = 0; i < ombre.size(); ++i)
		{
			glVertex3f(ombre[i].x, 0, ombre[i].y);
		}
		glEnd();

		//La direction du soleil
		/*glLineWidth(10.0);
		glBegin(GL_LINES);	
		qglColor(Qt::blue);
		glVertex3f(1, 2, 3);
		glVertex3f(-1, -2, -3);
		glEnd();*/
	}

	if (dessin == SURFACE)
	{
		glLineWidth(5.0);
		//Axe X
		glBegin(GL_LINES);	
		qglColor(Qt::red);
		glVertex3f(0, 0, 0);
		glVertex3f(1, 0, 0);
		glEnd();
		//Axe Y
		glBegin(GL_LINES);	
		qglColor(Qt::white);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 1, 0);
		glEnd();
		//Axe Z
		glBegin(GL_LINES);	
		qglColor(Qt::blue);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 1);
		glEnd();
	}

	if (update) return;
	if (surface == NULL) return;
	//Surface à ombrer
	glBegin(GL_POLYGON);	
	qglColor(solColor);
	vector<f2dPoint> pointSurface = surface->points(BORDER);
	for (unsigned int i = 0; i < pointSurface.size(); ++i)
	{
		glVertex3f(pointSurface[i].x, -0.01, pointSurface[i].y);
	}
	glEnd();
	
}

void Ombrage::mousePressEvent(QMouseEvent * event)
{
	lastPos = event->pos();
}

void Ombrage::mouseMoveEvent(QMouseEvent * event)
{
	GLfloat dx = GLfloat(event->x() - lastPos.x()) / width();
	GLfloat dy = GLfloat(event->y() - lastPos.y()) / height();

	if (event->buttons() & Qt::LeftButton)
	{
		rotationX += 180 * dy;
		rotationY += 180 * dx;
		updateGL();
	}else if (event->buttons() & Qt::RightButton)
	{
		rotationX += 180 * dy;
		rotationZ += 180 * dx;
		updateGL();
	}
	lastPos = event->pos();
}

int Ombrage::faceAtPosition(const QPoint & pos)
{
	const int MaxSize = 512;
	GLuint buffer[MaxSize];
	GLint viewport[4];

	makeCurrent();

	glGetIntegerv(GL_VIEWPORT, viewport);
	glSelectBuffer(MaxSize, buffer);
	glRenderMode(GL_SELECT);

	glInitNames();
	glPushName(0);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluPickMatrix(GLdouble(pos.x()), GLdouble(viewport[3] - pos.y()), 5.0, 5.0, viewport);

	GLfloat x = GLfloat(width()) / height();
	glFrustum(-x, x, -1.0, 1.0, 4.0, 15.0);
	draw();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	if (!glRenderMode(GL_RENDER))
	{
		return -1;
	}
	return buffer[3];
}

void Ombrage::wheelEvent (QWheelEvent * event)
{
	if (event->delta() < 0)
	{
		if ((translate + 0.2) < 1)
		{
			translate += 0.2;
		}
	}else translate -= 0.2;
	updateGL();
}

void Ombrage::updateSurface(f2dPolygon * polygon)
{
	update = true;
	surface = new Surface(*polygon);
	updateGL();
	paintGL();
	update = false;
}

void Ombrage::surfaceDrow(QStringList list, string f)
{
	f2dPolygon * polygon = NULL;
	polygon = new f2dPolygon(list.size());
	for(int i=0; i < list.size(); ++i) {
		float x,y;
		istringstream iss(list[i].toStdString());
		iss >> x >> y;
		polygon->set(i, x, y);
	}
	surface = new Surface(*polygon);
	if (polygon != NULL) delete polygon;
	updateGL();
	surfaceFile = f;
}

void Ombrage::updateColor(QColor col, int i)
{
	switch(i)
	{
		case 1:
			voileColor = col;
		break;

		case 2:
			ombreColor = col;
		break;

		case 3:
			solColor = col;
		break;
	}
	updateGL();
}

void Ombrage::setModeleFile(string file)
{
	modeleFile = file;
}

void Ombrage::setZeniteAzimithFile(string file)
{
	ZAFile = file;
}

void Ombrage::startAlgoGen(GAOptions * option)
{
	if (!QFile::exists(QString::fromStdString(ZAFile)))
	{
		QMessageBox::information(this, "FILE NOT FOUND", "The file zenit and azimith is not found.");
		return;
	}
	
	if (!QFile::exists(QString::fromStdString(modeleFile)))
	{
		QMessageBox::information(this, "FILE NOT FOUND", "The gene model file is not found.");
		return;
	}

	if (!QFile::exists(QString::fromStdString(surfaceFile)))
	{
		QMessageBox::information(this, "FILE NOT FOUND", "The file of coordinates of surface points are not found.");
		return;
	}

	if (option == NULL)
	{
		QMessageBox::information(this, "INCORRECTE OPTIONS CHOOSE", "The options chosen are not correct.");
		return;
	}

	//creature = le retour du resultat de l'algorithme genetique
			// Les parametre 
				//	ZAFile 			/Le fichier de zenith et azimuth
				//	modeleFile		/Le fichier de model de gene
				//	surfaceFile 	/*Le fichier du surface*/
				//	option 			/*pointeur de Goption*/


	updateGL();
}