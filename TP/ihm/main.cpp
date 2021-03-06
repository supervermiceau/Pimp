#include <wx/wx.h>
#include "mainframe.h"
#include "dialogs.h"
//-----------------------MyApp------------------------------------------
class MyApp: public wxApp 
{
  virtual bool OnInit();
  CMainFrame *m_MainFrame;
};
//----------------------------------------------------------------------
IMPLEMENT_APP(MyApp)
//----------------------OnInit------------------------------------------
bool MyApp::OnInit() 
{	
	//creation objet du menu
	wxMenu *file_menu = new wxMenu;
	wxMenu *option = new wxMenu;
	wxMenu *aide = new wxMenu;
	
	m_MainFrame = new CMainFrame( wxString("Application Triangle", wxConvUTF8), wxPoint(50,50), wxSize(900,680) );
	m_MainFrame->Show(TRUE);
	m_MainFrame->menu_bar= new wxMenuBar;
	m_MainFrame->affichage = new wxMenu;
	
	//affichage dans le menu
	m_MainFrame->menu_bar->Append(file_menu, wxT("Fichier"));
	m_MainFrame->menu_bar->Append(m_MainFrame->affichage, wxT("Affichage"));
	m_MainFrame->menu_bar->Append(option, wxT("Option"));
	m_MainFrame->menu_bar->Append(aide, wxT("Aide"));
	
	//rubrique fichier
	file_menu->Append(MENU_NEW, wxT("Nouveau\tCtrl-N"));
	file_menu->AppendSeparator();
	file_menu->Append(MENU_OUVRIR, wxT("Ouvrir\tCtrl-O"));
	file_menu->Append(MENU_SAVE, wxT("Sauvegarder\tCtrl-S"));
	file_menu->AppendSeparator();
	file_menu->Append(MENU_QUIT, wxT("Quitter\tCtrl-Q"));
	
	//rubrique option
	option->Append(MENU_EPAISSEUR, wxT("Epaisseur trait\tCtrl-E"));
	option->Append(MENU_COULEUR, wxT("Couleur\tCtrl-C"));
	option->Append(MENU_GESTION, wxT("Gestion triangle\tCtrl-N"));
	
	//rubrique aide
	aide->Append(MENU_AIDE, wxT("Version\tCtrl-N"));
	aide->Append(MENU_OUVRIR_AIDE, wxT("Ouvrir l'aide"));

	//rubrique affichage
	m_MainFrame->affichage->AppendCheckItem(MENU_TOOLBAR,wxT("Toolbar\tCtrl-B"));
	m_MainFrame->affichage->Check(MENU_TOOLBAR,TRUE);
	m_MainFrame->menu_bar->Enable(MENU_GESTION,false);
	
	m_MainFrame->SetMenuBar(m_MainFrame->menu_bar);
	m_MainFrame->CreateMyToolbar();
	
	if(!m_MainFrame->help.Initialize("HELP"))
	{
		wxLogError(wxT("Cannot initialize the help system, aborting."));
		return FALSE;
	}
	
	return TRUE;
} 
//----------------------------------------------------------------------
