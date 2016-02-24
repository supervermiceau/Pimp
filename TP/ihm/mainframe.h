
#ifndef __MAINFRAME_H__
#define __MAINFRAME_H__

#include <wx/wx.h>
#include <fstream>
#include <wx/filedlg.h>
#include <string.h>
#include "dialogs.h"
#include "triangle.h"
//----------------------------------------------------------------------

static wxString NameCol[] = {wxT("Triangle 0"), wxT("Triangle 1"), wxT("Triangle 2"), wxT("Triangle 3")};
//----------------------------------------------------------------------
class CMainFrame: public wxFrame 
{
public:
	CMainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
	int iEpaisseurTraitCourante;
	const wxColour *wCouleurCourante;
	int  num_tri;
	Triangle *tab_tri[5];
	bool bIsDrawing;
	wxMenu *affichage;
	wxFileDialog *filedialog;
	void CreateMyToolbar();
	void OnNew(wxCommandEvent& event); 
	void OnOpen(wxCommandEvent& event);
	void OnSave(wxCommandEvent& event);
	void OnQuit(wxCommandEvent& event);
	void OnAide(wxCommandEvent& event);
	void OnEpaisseur(wxCommandEvent& event);
	void OnCouleur(wxCommandEvent& event);
	void OnGest(wxCommandEvent& event);
	void OnDraw(wxCommandEvent& event);
	void OnToolBar(wxCommandEvent& event);
	void SetEpaisseur(int iNewEpaisseur);
	void SetCouleur(wxColour xwcNew);
	void SetBool(bool bnew);
	void Supprimer_tri(int n);
	
	//creation menu
	wxMenuBar *menu_bar;
	 
private:
	wxToolBar *m_toolbar;

DECLARE_EVENT_TABLE();

}; //MyFrame

#endif
//----------------------------------------------------------------------
