#include "myListView.h"

MyListView::MyListView(QString label1, QString label2, QString col1, QString col2, Type t, bool surfaceUpdate, QWidget * parent)
 : QWidget(parent)
{
	tabListe = new QTableView;
	mod = new QStandardItemModel(0, 2, this);
	tabListe->setModel(mod);
	tabListe->setSelectionBehavior(QAbstractItemView::SelectRows);
	tabListe->setEditTriggers(QAbstractItemView::NoEditTriggers);

	type 		= t;
	colonne1	= col1;
	colonne2	= col2;
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

	QVBoxLayout * layoutButton 	= new QVBoxLayout;
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
	QHBoxLayout * layoutEdit 	= new QHBoxLayout;
	layoutEdit->addWidget(labelX);
	layoutEdit->addWidget(coordX);
	layoutEdit->addWidget(labelY);
	layoutEdit->addWidget(coordY);
	
	QHBoxLayout * layoutPoint = new QHBoxLayout;
	layoutPoint->addWidget(tabListe);
	layoutPoint->addLayout(layoutButton);

	QVBoxLayout * layoutComposant = new QVBoxLayout;
	layoutComposant->addLayout(layoutPoint);
	layoutComposant->addLayout(layoutEdit);	
		
	model->setStringList(list);
	listView->setModel(model);

	setLayout(layoutComposant);
	setHesder();

	rafraichButton->setEnabled(false);

	connect(tabListe->selectionModel(), SIGNAL(selectionChanged(QItemSelection, QItemSelection)),
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

void MyListView::setHesder()
{
	mod->setHorizontalHeaderItem(0, new QStandardItem(colonne1));
	mod->setHorizontalHeaderItem(1, new QStandardItem(colonne2));	
	tabListe->setColumnWidth (0, 50);
	tabListe->setColumnWidth (1, 50);
}

void MyListView::remplirListe(string fic)
{
	ifstream file;
	file.open(fic, std::ios::in);
	
	if(file) {
		mod->clear();
		setHesder();
		string line;
		while(getline(file, line)) {
			if(line[0] == 'p' || line[0] == 'i'){
				float val1, val2;
			   	istringstream iss(line.substr(2).c_str());
				iss >> val1 >> val2;
				QList<QStandardItem *> items;
				items.append(new QStandardItem(QString::number(val1)));
				items.append(new QStandardItem(QString::number(val2)));

				mod->appendRow(items);
			}
		} // lines loop
		file.close();
	} // file loop
}

void MyListView::selectItemSlot(const QItemSelection& selection)
{
	if(selection.indexes().isEmpty()) {
    	this->coordX->setText("");
      	this->coordY->setText("");
   	} else {
   		QModelIndexList listSelect = tabListe->selectionModel()->selectedRows();
   		int i = listSelect[0].row();
   		QString x = mod->item(i, 0)->text();
   		QString y = mod->item(i, 1)->text();
   		this->coordX->setText(x);
      	this->coordY->setText(y);
   	}
}

void MyListView::insertItemSlot()
{	
	if (this->coordX->text() == "" || this->coordY->text() == "") return;
	QModelIndexList listSelect = tabListe->selectionModel()->selectedIndexes();
	
	QList<QStandardItem *> items;
	items.append(new QStandardItem(this->coordX->text()));
	items.append(new QStandardItem(this->coordY->text()));
	if (listSelect.count() > 0)
	{
		int i = listSelect[0].row();
		mod->removeRow(i);
		mod->insertRow(i, items);
	}else mod->appendRow(items);
	
	model->setStringList(list);
	listView->setModel(model);

	rafraichButton->setEnabled(true);
	this->coordX->setText("");
    this->coordY->setText("");
}

void MyListView::addItemSlot()
{
	QItemSelectionModel * selectionModel = tabListe->selectionModel();
	selectionModel->clearSelection();

	this->coordX->setText("");
    this->coordY->setText("");
}

void MyListView::deleteItemSlot()
{
	QModelIndexList indexes = tabListe->selectionModel()->selectedIndexes();
	if (indexes.count() > 0)
	{
		mod->removeRow(indexes[0].row());
		this->coordX->setText("");
    	this->coordY->setText("");
    	rafraich = true;
		rafraichButton->setEnabled(true);
	}
}

void MyListView::rafraichDraw()
{	
	if (!rafraichButton->isEnabled()) return;

	this->coordX->setText("");
   	this->coordY->setText("");

   	tabListe->selectAll();
	QModelIndexList listSelect = tabListe->selectionModel()->selectedRows();
	tabListe->selectionModel()->clearSelection();
   	list.clear();
   	for(int i = 0; i < listSelect.count(); ++i) {
   		int index = listSelect[i].row();
	   	list << mod->item(index, 0)->text() + " " + mod->item(index, 1)->text();
   	}

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

	tabListe->selectAll();
	QModelIndexList listSelect = tabListe->selectionModel()->selectedRows();
	tabListe->selectionModel()->clearSelection();

	list.clear();

	res += (type == SOL ? "n " : "g ") + QString::number(listSelect.count());
   	for(int i = 0; i < listSelect.count(); ++i) {
   		int index = listSelect[i].row();
	   	QString val = mod->item(index, 0)->text() + " " + mod->item(index, 1)->text();

	   	if (type == SOL) 
	   	{
	   		res += "\np " + val;
	   		list << val;
	   	}
		else res += "\ni " + val;
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

	tabListe->selectAll();
	QModelIndexList listSelect = tabListe->selectionModel()->selectedRows();
	tabListe->selectionModel()->clearSelection();   	

	list.clear();
   	for(int i = 0; i < listSelect.count(); ++i) {
   		int index = listSelect[i].row();
	   	list << mod->item(index, 0)->text() + " " + mod->item(index, 1)->text();
   	}

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
	QModelIndexList listSelect = tabListe->selectionModel()->selectedRows();
	if (listSelect.count() < 1) return;
	int index1 = listSelect[0].row();
	if (index1 == 0 && up) return;
	if (index1 == mod->rowCount() - 1 && !up) return;

	int index2 = (up ? index1 - 1 : index1 + 1);

	QStandardItem * item1Row1 = new  QStandardItem(mod->item(index1, 0)->text());
	QStandardItem * item2Row1 = new  QStandardItem(mod->item(index1, 1)->text());

	QStandardItem * item1Row2 = new  QStandardItem(mod->item(index2, 0)->text());
	QStandardItem * item2Row2 = new  QStandardItem(mod->item(index2, 1)->text());

	mod->setItem(index1, 0, item1Row2);
	mod->setItem(index1, 1, item2Row2);

	mod->setItem(index2, 0, item1Row1);
	mod->setItem(index2, 1, item2Row1);

	tabListe->selectRow(index2);
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