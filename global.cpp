#include "global.h"

bool Global::valideInterval(QString text, QWidget * widget, float min, float max)
{
	if (!valideFloat(text)) return false;
	bool ok;
    double d = text.toDouble(&ok);
    if (d >= min && d <= max) return true;
    else {
    	QString s = "The minimum value is " + QString::number(min) + " and the maximun is " +  QString::number(max) + "." ;
    	QMessageBox::information(widget, "INCORRECTE VALUE", s);
    	return false;
    }
}

bool Global::valideFloat(QString text, QWidget * widget)
{	
	bool ok;
    if (!text.toDouble(&ok) && text != "-" && (text != "0" || text != "-0"))
    {
    	QMessageBox::information(widget, "INCORRECTE VALUE", "This field must contain a real number.");
    	return false;
    }
    return true;
}

bool Global::valideInt(QString text, QWidget * widget)
{
	bool ok;
    if (!text.toDouble(&ok) && text != "-" && (text != "0" || text != "-0"))
    {
    	QMessageBox::information(widget, "INCORRECTE VALUE", "This field must contain an integer.");
    	return false;
    }
    return true;
}