#include "myListView.h"

MyListView::MyListView(QString label1, QString label2, Type t, bool surfaceUpdate, QWidget * parent) : QWidget(parent)
{
	type 		= t;
	listView 	= new QListView;
	model 		= new QStringListModel(this);

	downButton 		= new QPushButton(tr("Down"));
	upButton 		= new QPushButton(tr("Up"));
	addItem 		= new QPushButton(tr("Add"));
	insertItem 		= new QPushButton(tr("Insert"));
	deleteItem 		= new QPushButton(tr("Delete"));
	saveButton		= new QPushButton(tr("Save"));
	rafraichButton	= new QPushButton(tr("Rafraich"));
	openButton		= new QPushButton(tr("Open File"));

	layoutButton 	= new QVBoxLayout;
	if (surfaceUpdate) layoutButton->addWidget(rafraichButton);
	layoutButton->addWidget(upButton);
	layoutButton->addWidget(downButton);
	layoutButton->addWidget(addItem);
	layoutButton->addWidget(insertItem);
	layoutButton->addWidget(deleteItem);
	layoutButton->addWidget(new QLabel());
	layoutButton->addWidget(openButton);	
	layoutButton->addWidget(saveButton);

	labelX 		= new QLabel(label1);
	labelY 		= new QLabel(label2);
	coordX 		= new QLineEdit;
	coordY 		= new QLineEdit;
	layoutEdit 	= new QHBoxLayout;
	layoutEdit->addWidget(labelX);
	layoutEdit->addWidget(coordX);
	layoutEdit->addWidget(labelY);
	layoutEdit->addWidget(coordY);
	
	layoutPoint = new QHBoxLayout;
	layoutPoint->addWidget(listView);
	layoutPoint->addLayout(layoutButton);

	layoutComposant = new QVBoxLayout;
	layoutComposant->addLayout(layoutPoint);
	layoutComposant->addLayout(layoutEdit);	
		
	model->setStringList(list);
	listView->setModel(model);

	setLayout(layoutComposant);

	rafraichButton->setEnabled(false);

	connect(listView->selectionModel(), SIGNAL(selectionChanged(QItemSelection, QItemSelection)),
			this, SLOT(selectItemSlot(QItemSelection)));
	connect(addItem,		SIGNAL(clicked()), this, SLOT(addItemSlot()));
	connect(insertItem, 	SIGNAL(clicked()), this, SLOT(insertItemSlot()));
	connect(deleteItem, 	SIGNAL(clicked()), this, SLOT(deleteItemSlot()));
	connect(rafraichButton, SIGNAL(clicked()), this, SLOT(rafraichDraw()));
	connect(saveButton, 	SIGNAL(clicked()), this, SLOT(save()));
	connect(openButton, 	SIGNAL(clicked()), this, SLOT(openFile()));
	connect(upButton, 		SIGNAL(clicked()), this, SLOT(upSlot()));
	connect(downButton, 	SIGNAL(clicked()), this, SLOT(downSlot()));

	connect(coordX, 		SIGNAL(textEdited(QString)), this, SLOT(textLineEdit1Valid(QString)));
	connect(coordY, 		SIGNAL(textEdited(QString)), this, SLOT(textLineEdit2Valid(QString)));
}

MyListView::~MyListView()
{

}

void MyListView::remplirListe(string fic)
{
	ifstream file;
	file.open(fic, std::ios::in);
	
	if(file) {
		list.clear();
		string line;
		while(getline(file, line)) {
			if(line[0] == 'p'){
				list << QString(line.substr(2).c_str());
			}
		} // lines loop
		file.close();
		model->setStringList(list);
		listView->setModel(model);
	} // file loop
}

void MyListView::selectItemSlot(const QItemSelection& selection)
{
	if(selection.indexes().isEmpty()) {
    	this->coordX->setText("");
      	this->coordY->setText("");
   	} else {
   		QModelIndexList listSelect = listView->selectionModel()->selectedIndexes();
   		string s = listSelect[0].data(Qt::DisplayRole).toString().toStdString();
   		float x,y;
   		istringstream iss(s);
		iss >> x >> y;
   		this->coordX->setText(QString::number(x));
      	this->coordY->setText(QString::number(y));
   	}
}

void MyListView::insertItemSlot()
{	
	if (this->coordX->text() == "" || this->coordY->text() == "") return;
	QString str = QString(this->coordX->text() + " " + this->coordY->text());
	QModelIndexList listSelect = listView->selectionModel()->selectedIndexes();
	int pos = -1;
	QString itemSelect = "";
	if (listSelect.count() > 0)
	{
		itemSelect = listSelect[0].data(Qt::DisplayRole).toString();
		QStringList tmp;
		for (int i = 0; i < list.size(); ++i)
		{
			if (list[i] == itemSelect)
			{
				tmp << str;
				pos = i;
			}else tmp << list[i];
		}
		list = tmp;
	}else list << str;
	
	model->setStringList(list);
	listView->setModel(model);

	QModelIndex index = model->index(pos, 0);
	if (index.isValid())
    	listView->selectionModel()->select(index, QItemSelectionModel::Select);

	rafraichButton->setEnabled(true);
	this->coordX->setText("");
    this->coordY->setText("");
}

void MyListView::addItemSlot()
{
	QItemSelectionModel * selectionModel = listView->selectionModel();
	selectionModel->clearSelection();

	this->coordX->setText("");
    this->coordY->setText("");
}

void MyListView::deleteItemSlot()
{
	QModelIndexList indexes = listView->selectionModel()->selectedIndexes();
	if (indexes.count() > 0)
	{
		model->removeRow(indexes[0].row());
		list = model->stringList();
		this->coordX->setText("");
    	this->coordY->setText("");
	}
	QItemSelectionModel * selectionModel = listView->selectionModel();
	selectionModel->clearSelection();

	rafraich = true;
	rafraichButton->setEnabled(true);
}

void MyListView::rafraichDraw()
{	
	if (!rafraichButton->isEnabled()) return;

	this->coordX->setText("");
   	this->coordY->setText("");

   	emit draw(list); 
	
   	rafraich = false;
   	rafraichButton->setEnabled(false);
}

void MyListView::save()
{
	QString fileName = QFileDialog::getSaveFileName(this,
         tr("Save file"), "",
         tr("All Files (*)"));
	if (fileName == NULL) return;

	if(!fileName.endsWith(".dat"))
		fileName += ".dat";

	QFile file(fileName);
	if(!file.open(QIODevice::WriteOnly)) {
		std::cerr << "Cannot open file" << endl;
		return;
	}

	QTextStream out(&file);
	QString res = "";

	res += (type == SOL ? "n " : "g ") + QString::number(list.size());
	for(int i=0; i < list.size(); ++i) {
		if (type == SOL) res += "\np " + list[i];
		else res += "\ni " + list[i];
	}	
	
	out << res;
	file.close();	

	emit updateFile(fileName.toStdString());
	if (type == SOL && list.size() > 2)
	{
		emit drowSurface(list, fileName.toStdString());
	}
}

void MyListView::openFile()
{
	QString filename = QFileDialog::getOpenFileName(this, "ouvrir fichier",
						 ".", "fichier coordonné (*.dat);;All Files (*)");
	if(filename.isEmpty()) return;

	remplirListe(filename.toStdString());

	rafraich = true;
	rafraichButton->setEnabled(true);

	emit updateFile(filename.toStdString());

	if (type == SOL && list.size() > 2)
	{
		emit draw(list);
		emit drowSurface(list, filename.toStdString());
	}
}

void MyListView::upSlot()
{
	upAndDown(true);
	rafraichButton->setEnabled(true);
}

void MyListView::downSlot()
{
	upAndDown(false);
	rafraichButton->setEnabled(true);
}

void MyListView::upAndDown(bool up)
{
	QModelIndexList listSelect = listView->selectionModel()->selectedIndexes();
	if (listSelect.count() < 1) return;
   	QString s = listSelect[0].data(Qt::DisplayRole).toString();
   	QString upDown = "";
   	QStringList tmp;
   	bool flag = false, insert = false;
   	int selectPos = -1;
   	for (int i = 0; i < list.size(); ++i)
   	{   		
   		if (list[i] != s)
   		{
   			tmp << list[i];
   			insert = flag;
   		}else
   		{
   			upDown = list[i];
   			if (up)
   			{
   				QStringList tmp2;
   				for (int j = 0; j < tmp.size() - 1; ++j)
   				{
   					tmp2 << tmp[j];
   				}
   				tmp2 << upDown;
   				if (tmp.size() > 0) tmp2 << tmp[tmp.size() - 1];
   				tmp = tmp2;
   				upDown = "";
   				selectPos = i > 0 ? i - 1 : 0;
   			}else flag = true;
   		}
   		if (upDown != "" && insert)
   		{
   			tmp << upDown;
   			upDown = "";
   			flag = false;
   			selectPos = i;
   		}
   	}
   	if (upDown != "")
   	{
   		tmp << upDown;
   		selectPos = list.size() > 0 ? list.size() - 1 : 0;
   	}
   	list = tmp;
   	model->setStringList(list);
	listView->setModel(model);

	QModelIndex index = model->index(selectPos, 0);
	if (index.isValid())
    	listView->selectionModel()->select(index, QItemSelectionModel::Select);
}

void MyListView::textLineEdit1Valid(QString text)
{
	if (text.isEmpty()) return;
	if (!Global::valideFloat(text, this)) coordX->setText("");
}

void MyListView::textLineEdit2Valid(QString text)
{
	if (text.isEmpty()) return;
	if (!Global::valideFloat(text, this)) coordY->setText("");
}