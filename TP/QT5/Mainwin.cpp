#include "Mainwin.h"
//----------------------------------------------------------------------
Qonvertisseur::Qonvertisseur(QWidget *parent) 
	: QMainWindow(parent), Ui::MainWindow()
{
	setupUi(this); //permet d'init les widgets
					// definie dans Ui::MainWindow
}
//----------------------------------------------------------------------
Qonvertisseur::~Qonvertisseur()
{
}
//----------------------------------------------------------------------
