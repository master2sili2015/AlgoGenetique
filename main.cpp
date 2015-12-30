/////////////////////////////////////////////
//      Solar Position Algorithm (SPA)     //
//                   for                   //
//        Solar Radiation Application      //
//                                         //
//   Afshin Michael Andreas                //
//   afshin_andreas@nrel.gov (303)384-6383 //
//                                         //
//   Measurement & Instrumentation Team    //
//   Solar Radiation Research Laboratory   //
//   National Renewable Energy Laboratory  //
//   1617 Cole Blvd, Golden, CO 80401      //
/////////////////////////////////////////////

/////////////////////////////////////////////
// This sample program shows how to use    //
//    the SPA.C code.                      //
/////////////////////////////////////////////

#include <stdio.h>

#include "interface.h"
#include <QApplication>

int main (int argc, char *argv[])
{
    QApplication app( argc, argv );

    if (!QGLFormat::hasOpenGL())
    {
    	cerr << "No OpenGL support" << endl;
    	return 1;
    }

    Interface interface;
    interface.setWindowTitle(QObject::tr("Voile d'ombrage"));
    interface.resize(900, 950);
    interface.show();

    return app.exec();
}