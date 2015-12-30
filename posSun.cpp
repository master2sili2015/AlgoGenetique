#include "posSun.h"

PosSun::PosSun(QWidget * parent) : QWidget(parent)
{
	buttonFile = new QPushButton(tr("Open File"));
	
	QVBoxLayout * boxLayout = new QVBoxLayout;

	treeView = new QTreeView;

	treeView->setSelectionMode(QAbstractItemView::MultiSelection);
	standardModel = new QStandardItemModel;
  	standardModel->setHorizontalHeaderItem( 0, new QStandardItem( "Sun position" ) );
	rootNode = standardModel->invisibleRootItem();
  	
    //this->generateTree("za_result.dat");

  	treeView->setModel(standardModel);
  	treeView->expandAll();

  	boxLayout->addWidget(buttonFile);
  	boxLayout->addWidget(treeView);
  	setLayout(boxLayout);

  	connect(buttonFile, SIGNAL(clicked()), this, SLOT(openFile()));
}

PosSun::~PosSun()
{	
}

void PosSun::generateTree(const string fic)
{
	ifstream file(fic.c_str(), ios::in);

    if (!file.is_open()) return;
    if (file.eof()) return;
    string line;
    getline(file, line);
    bool flag(false);
    rootNode->removeRows(0, rootNode->rowCount());
    if (line[0] == 'y') 
    {        
    	while (!file.eof())
    	{
    		QStandardItem * year = new QStandardItem(QString(line.substr(2).c_str()));
    		year->setEditable(false);
    		rootNode->appendRow(year);
    		getline(file, line);
    		while (line[0] != 'y' && line[0] != 'm' && !file.eof())
	    	{
	    		QStandardItem * month = new QStandardItem(QString(line.substr(2).c_str()));
	    		month->setEditable(false);
    			year->appendRow(month);
    			getline(file, line);
	    		while (!file.eof())
	    		{	    			
	    			if (line[0] == 'p')
	    			{
	    				QStandardItem * pos = new QStandardItem(QString(line.substr(2).c_str()));
	    				pos->setEditable(false);
    					month->appendRow(pos);
    					getline(file, line);
	    			}else break;
	    		}
	    	}
    	}
    }
    if (!flag && line[0] == 'm')
    {
    	while (!file.eof())
	    {
	    	QStandardItem * month = new QStandardItem(QString(line.substr(2).c_str()));
	    	month->setEditable(false);
    		rootNode->appendRow(month);
    		getline(file, line);
	    	while (!file.eof())
	    	{	    			
	    		if (line[0] == 'p')
	    		{
	    			QStandardItem * pos = new QStandardItem(QString(line.substr(2).c_str()));
	    			pos->setEditable(false);
    				month->appendRow(pos);
    				getline(file, line);
	    		}else break;
	    	}
	    }
    }
    if (!flag && line[0] == 'd')
    {
    	while (!file.eof())
	    {
	    	QStandardItem * day = new QStandardItem(QString(line.substr(2).c_str()));
	    	day->setEditable(false);
    		rootNode->appendRow(day);
    		getline(file, line);
	    	while (!file.eof())
	    	{	    			
	    		if (line[0] == 'p')
	    		{
	    			QStandardItem * pos = new QStandardItem(QString(line.substr(2).c_str()));
	    			pos->setEditable(false);
    				day->appendRow(pos);
    				getline(file, line);
	    		}else break;
	    	}
	    }
    }
    file.close();
}

void PosSun::setTree(string file)
{
	generateTree(file);
	emit zaFile(file);
}

void PosSun::openFile()
{
	QString filename = QFileDialog::getOpenFileName(this, "Open file",
						 ".", "file (*.dat);;All Files (*)");
	if(filename.isEmpty()) return;

	setTree(filename.toStdString());
}