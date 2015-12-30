#include "opOmbrage.h"

OpOmbrage::OpOmbrage(QWidget * parent) : QWidget(parent)
{
	QHBoxLayout * layoutVoile = new QHBoxLayout;
	QHBoxLayout * layoutOmbre = new QHBoxLayout;
	QHBoxLayout * layoutSol = new QHBoxLayout;

	buttonAlgoGen = new QPushButton(tr("start genetic algorithm"), NULL);
	QVBoxLayout * layout = new QVBoxLayout;
	layout->addWidget(buttonAlgoGen);
	layout->addWidget(new QLabel());

	labelVoile 	= new QLabel;
	labelOmbre 	= new QLabel;
	labelSol 	= new QLabel;

	layoutVoile->addWidget(new QLabel(tr("Voile color")));
	layoutVoile->addWidget(labelVoile);

	layoutOmbre->addWidget(new QLabel(tr("Ombre color")));
	layoutOmbre->addWidget(labelOmbre);

	layoutSol->addWidget(new QLabel(tr("Surface color")));
	layoutSol->addWidget(labelSol);

	QVBoxLayout * generalLayout = new QVBoxLayout;
	generalLayout->addLayout(layout);
	generalLayout->addLayout(layoutVoile);
	generalLayout->addLayout(layoutOmbre);
	generalLayout->addLayout(layoutSol);

	QPalette pal = palette();

	labelVoile->setAutoFillBackground(true);
    QBrush brushVoile(Qt::yellow);
    brushVoile.setStyle(Qt::SolidPattern);    
    pal.setBrush(QPalette::Active, QPalette::Window, brushVoile);
    labelVoile->setPalette(pal);
    labelVoile->setToolTip(tr("Voile color"));

    labelOmbre->setAutoFillBackground(true);
	QBrush brushOmbre(Qt::darkRed);
    brushOmbre.setStyle(Qt::SolidPattern);
	pal.setBrush(QPalette::Active, QPalette::Window, brushOmbre);
    labelOmbre->setPalette(pal);
    labelOmbre->setToolTip(tr("Ombrage color"));

	labelSol->setAutoFillBackground(true);
    QBrush brushSol(Qt::lightGray);
    brushSol.setStyle(Qt::SolidPattern);
	pal.setBrush(QPalette::Active, QPalette::Window, brushSol);
    labelSol->setPalette(pal);
    labelSol->setToolTip(tr("Surface color"));

    setLayout(generalLayout);
    setMaximumHeight(200);

	//connect(labelVoile, SIGNAL(clicked()), this, SLOT(couleurVoile()));
	//connect(labelOmbre, SIGNAL(clicked()), this, SLOT(couleurOmbre()));
	//connect(labelSol, SIGNAL(clicked()), this, SLOT(couleurSol()));
}

OpOmbrage::~OpOmbrage()
{

}

void OpOmbrage::couleurVoile()
{
	couleurChange(COULEUR_VOILE);
}

void OpOmbrage::couleurOmbre()
{
	couleurChange(COULEUR_OMBRE);
}

void OpOmbrage::couleurSol()
{
	couleurChange(COULEUR_SOL);
}

void OpOmbrage::couleurChange(int col)
{
	QColor couleur = QColorDialog::getColor(Qt::white, this);
 
    QPalette pal = palette();    
	QBrush brush(couleur);
	brush.setStyle(Qt::SolidPattern);
	pal.setBrush(QPalette::Active, QPalette::Window, brush);
	switch(col)
	{
		case COULEUR_VOILE:
			labelVoile->setPalette(pal);
		break;

		case COULEUR_OMBRE:
			labelOmbre->setPalette(pal);
		break;

		case COULEUR_SOL:
			labelSol->setPalette(pal);
		break;
	}	
    
    emit color(couleur, col);
}