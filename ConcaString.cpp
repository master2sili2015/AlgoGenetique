#include "ConcaString.h"

ConcatString::ConcatString(QWidget * parent) : QWidget(parent)
{
    groupBoxInfo = new QGroupBox(tr("Saisi information"), this);
    cbb          = new QComboBox;
    cbb->addItem(tr("Min"));
    cbb->addItem(tr("Hour"));
    cbb->addItem(tr("Day"));
    cbb->addItem(tr("Mouth"));
    cbb->setFixedWidth(80);
    cbb->setCurrentIndex(1);

    dateDebut       = new QDateTimeEdit(QDate::currentDate());
    dateDebut->setDisplayFormat("dd/MM/yyyy HH:mm");
    dateDebut->setMaximumWidth(200);
    
    dateFin         = new QDateTimeEdit(QDate::currentDate().addDays(1));
    dateFin->setDisplayFormat("dd/MM/yyyy HH:mm");
    dateFin->setMaximumWidth(200);

    periode         = new QSpinBox;
    periode->setMinimum(1);
    timeZone        = new QSpinBox;
    timeZone->setMaximum(18);
    timeZone->setMinimum(-18);
    longitude       = new QLineEdit;
    altitude        = new QLineEdit;
    check           = new QCheckBox(tr("Sunsets sun values"));
    genAzimuthzenit = new QPushButton(tr("Zenit Azimuth generate"));
    genAzimuthzenit->setEnabled(false);

    QHBoxLayout * topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(new QLabel(tr("Date begin")));
    topLeftLayout->addWidget(dateDebut);
    topLeftLayout->addWidget(new QLabel(tr("Date end")));
    topLeftLayout->addWidget(dateFin);

    QHBoxLayout * topLeftLayout1  = new QHBoxLayout;
    topLeftLayout1->addWidget(new QLabel(tr("Periode")));
    topLeftLayout1->addWidget(periode);
    topLeftLayout1->addWidget(cbb);
    topLeftLayout1->addWidget(new QLabel);
    topLeftLayout1->addWidget(new QLabel(tr("Time zone")));
    topLeftLayout1->addWidget(timeZone);

    QHBoxLayout *topLeftLayout2 = new QHBoxLayout;
    topLeftLayout2->addWidget(new QLabel(tr("Longitude")));
    topLeftLayout2->addWidget(longitude);
    topLeftLayout2->addWidget(new QLabel(tr("Latitude")));
    topLeftLayout2->addWidget(altitude);    

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addLayout(topLeftLayout1);
    leftLayout->addLayout(topLeftLayout2);
    leftLayout->addWidget(check);
    leftLayout->addWidget(genAzimuthzenit);
   
    groupBoxInfo->setLayout(leftLayout);

    connect(genAzimuthzenit, SIGNAL(clicked()), this, SLOT(generateFile()));
    connect(longitude,       SIGNAL(textEdited(QString)), this, SLOT(longitudeEdit(QString)));
    connect(altitude,        SIGNAL(textEdited(QString)), this, SLOT(altitudeEdit(QString)));
}

void ConcatString::longitudeEdit(QString text)
{
    if (text.isEmpty()) return;
    if (!Global::valideFloat(text, this)) longitude->setText("");
    editing();
}

void ConcatString::altitudeEdit(QString text)
{
    if (text.isEmpty()) return;
    if (!Global::valideFloat(text, this)) altitude->setText("");
    editing();
}

void ConcatString::editing()
{
    if (!longitude->text().isEmpty() && !altitude->text().isEmpty())
        genAzimuthzenit->setEnabled(true);
    else genAzimuthzenit->setEnabled(false);
}

void ConcatString::generateFile()
{
    if (dateFin->dateTime() <= dateDebut->dateTime())
    {        
        QMessageBox::information(this, "INCORRECTE DATE", "The selected dates are incorrect.");
        return;
    }
    QString text = "";
    text += dateDebut->dateTime().toString("yyyy:MM:dd:hh:mm:ss");
    text += "  " + dateFin->dateTime().toString("yyyy:MM:dd:hh:mm:ss");
    int p = periode->value();
    switch(cbb->currentIndex())
    {
        case 1:
            p *= 60;
        break;
        case 2:
            p *= 24 * 60;
        break;
        case 3:
            p *= 30 * 24 * 60;
        break;
    }
    text += "  " + QString::number(p);
    text += "  " + QString::number(timeZone->value());
    text += "  " + longitude->text();
    text += "  " + altitude->text();

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
    file.close();

    string fic = fileName.toStdString();
    //string str = "2015:12:15:00:00:00 2015:12:15:23:59:00   15   1   -0.5549501000000419   47.4569901";
    calculate_all_position(text.toStdString(), fic, check->isChecked());
    emit zaFile(fic);
    genAzimuthzenit->setEnabled(false);
}

void ConcatString::enableFindButton(const QString &text)
{
    genAzimuthzenit->setEnabled(!text.isEmpty());
}
