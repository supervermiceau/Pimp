#include <QtGui>
#include "Mainwin.h"
//----------------------------------------------------------------------
int main(int argc, char *argv[])
{
	//Necessaire a QT
	QApplication app(argc, argv);
	
	//Creation et ouverture de la fenetre
	Qonvertisseur mainwin;
	mainwin.show();
	
	//lancement boucle principale
	//gestion des evenements utilisateur
	return app.exec();
}
