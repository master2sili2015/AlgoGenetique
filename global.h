#ifndef GLOBAL_H
#define GLOBAL_H

#include <QWidget>
#include <QMessageBox>

class Global
{
public:
	static bool valideInterval(QString text, QWidget * widget = NULL, float min = 0.0, float max = 1.0);
	static bool valideFloat(QString text, QWidget * widget = NULL);
	static bool valideInt(QString text, QWidget * widget = NULL);
};
#endif