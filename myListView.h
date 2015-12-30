#ifndef MYLISTVIEW_H
#define MYLISTVIEW_H

#include <QGroupBox>
#include <QLineEdit>
#include <QPushButton>
#include <QListView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QFileDialog>
#include <QStringList>
#include <QStringListModel>
#include <QModelIndex>
#include <QTextStream>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
#include "global.h"

enum Type { SOL, OTHER };

class MyListView : public QWidget
{
	Q_OBJECT
public:
	MyListView(QString label1, QString label2, Type t = OTHER, bool surfaceUpdate = false, QWidget * parent = 0);
	~MyListView();

signals:
	void updateFile(string);
	void draw(QStringList);
	void drowSurface(QStringList, string);

private slots:
	void selectItemSlot(const QItemSelection& selection);
	void insertItemSlot();
	void addItemSlot();
	void deleteItemSlot();
	void rafraichDraw();
	void save();
	void openFile();
	void upSlot();
	void downSlot();
	void textLineEdit1Valid(QString text);
	void textLineEdit2Valid(QString text);

private:
	void remplirListe(string fic);
	void upAndDown(bool up);

	QListView * listView;

	QPushButton * saveButton;
	QPushButton * rafraichButton;
	QPushButton * openButton;

	QPushButton * upButton;
	QPushButton * downButton;

	QPushButton * addItem;
	QPushButton * insertItem;
	QPushButton * deleteItem;
	QVBoxLayout * layoutButton;

	QLabel * labelX;
	QLabel * labelY;
	QLineEdit * coordX;
	QLineEdit * coordY;
	QHBoxLayout * layoutEdit;

	QStringList list;
	QStringListModel * model;

	QVBoxLayout * layoutComposant;
	QHBoxLayout * layoutPoint;

	Type type;
	bool rafraich;
};
#endif