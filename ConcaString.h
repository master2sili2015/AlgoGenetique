#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDateTimeEdit>
#include <QDate>
#include <QComboBox>
#include <QSpinBox>
#include <QMessageBox>
#include <QCheckBox>

#include "myListView.h"
#include "spa.h"  //include the SPA header file

class ConcatString : public QWidget
{
	Q_OBJECT
public:
	ConcatString(QWidget *parent = 0);

signals:
  void zaFile(string);  

private slots:
  void generateFile();
  void longitudeEdit(QString text);
  void altitudeEdit(QString text);

  void enableFindButton(const QString &text);

private:
  void editing();

  QDateTimeEdit * dateDebut;
  QDateTimeEdit * dateFin;
  QSpinBox * periode;
  QSpinBox * timeZone;
  QLineEdit * longitude;
  QLineEdit * altitude;
  QPushButton * genAzimuthzenit;

  QComboBox * cbb;
  QCheckBox * check;

  QGroupBox * groupBoxInfo;  
};
#endif
