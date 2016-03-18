#ifndef MAINWIN_H
#define MAINWIN_H
//----------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "ui_mwin.h"
//----------------------------------------------------------------------
class Qonvertisseur : public QMainWindow, private Ui::MainWindow
{
	Q_OBJECT // Necessaire a QT
	public :
		Qonvertisseur(QWidget *parent = 0 );
		~Qonvertisseur();
		Bool QObject::
		private:
};
//----------------------------------------------------------------------
#endif
