#ifndef POSSUN_H
#define POSSUN_H

#include <QWidget>
#include <QTreeView>
#include <QStandardItemModel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFileDialog>

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class PosSun : public QWidget
{
	Q_OBJECT
public:
	PosSun(QWidget * parent = 0);
	~PosSun();

signals:
	void zaFile(string);

private slots:
	void setTree(string file);
	void openFile();

private:
	void generateTree(const string file);

	QTreeView  * treeView;
	QStandardItemModel * standardModel;
	QStandardItem * rootNode;

	QPushButton * buttonFile;

	QHBoxLayout * serchLayout;
	QVBoxLayout * boxLayout;
};

#endif
