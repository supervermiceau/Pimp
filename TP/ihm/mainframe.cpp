#include <stdio.h>
#include <stdlib.h>
#include <wx/wx.h>
#include <wx/accel.h>

#include "mainframe.h"

//----------------------Table evenement---------------------------------
BEGIN_EVENT_TABLE(CMainFrame, wxFrame)
EVT_MENU(MENU_NEW, CMainFrame::OnNew)
EVT_MENU(MENU_OUVRIR, CMainFrame::OnOpen)
EVT_MENU(MENU_SAVE, CMainFrame::OnSave)
EVT_MENU(MENU_QUIT, CMainFrame::OnQuit)
EVT_MENU(MENU_AIDE, CMainFrame::OnAide)
EVT_MENU(MENU_EPAISSEUR, CMainFrame::OnEpaisseur)
EVT_MENU(MENU_COULEUR, CMainFrame::OnCouleur)
EVT_MENU(MENU_GESTION, CMainFrame::OnGest)
EVT_MENU(MENU_NEWDRAW, CMainFrame::OnDraw)
EVT_MENU(MENU_TOOLBAR, CMainFrame::OnToolBar)
EVT_MENU(MENU_OUVRIR_AIDE, CMainFrame::OnHelp)
END_EVENT_TABLE()
//----------------------------------------------------------------------
CMainFrame::CMainFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
: wxFrame((wxFrame *)NULL, -1, title, pos, size) 
{
	//initialisation des variables
	iEpaisseurTraitCourante= 1;
	wCouleurCourante= wxBLACK;
	num_tri= 0;
	opgcan=new OpenGLCanvas(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, wxT("OpenGLCANVAS"));

} //constructor
//----------------------------------------------------------------------
void CMainFrame::CreateMyToolbar() 
{
	//creation de la barre vide ( avec certaine propriete)
	m_toolbar=CreateToolBar(wxNO_BORDER | wxTB_HORIZONTAL | wxTB_TEXT,TOOLBAR_TOOLS);
	
	//Chargement des images bitmap utlisées par les boutons de la barre
	wxBitmap toolBarBitmaps[4];
	toolBarBitmaps[0] = wxBitmap(wxT("new.bmp"),wxBITMAP_TYPE_BMP);
	toolBarBitmaps[1] = wxBitmap(wxT("open.bmp"),wxBITMAP_TYPE_BMP);
	toolBarBitmaps[2] = wxBitmap(wxT("save.bmp"),wxBITMAP_TYPE_BMP);
	toolBarBitmaps[3] = wxBitmap(wxT("draw.bmp"),wxBITMAP_TYPE_BMP);
	
	//ajustement taille de la barre aux icones
	m_toolbar->SetToolBitmapSize(wxSize(toolBarBitmaps[0].GetWidth(),toolBarBitmaps[0].GetHeight()));
	
	//affectation des images aux icones
	m_toolbar->AddTool(MENU_NEW, wxT("Nouveau"), toolBarBitmaps[0]);
	m_toolbar->AddTool(MENU_OUVRIR, wxT("Ouvrir"), toolBarBitmaps[1]);
	m_toolbar->AddTool(MENU_SAVE, wxT("Sauvegarder"), toolBarBitmaps[2]);
	//ajout separateur
	m_toolbar->AddSeparator();
	//ajout 4eme bouton via addchektool
	m_toolbar->AddCheckTool(MENU_NEWDRAW, wxT("Nouveau dessin"), toolBarBitmaps[3]);
	
	//Creation et affichage barre d'outils
	m_toolbar->Realize();
	SetToolBar(m_toolbar);
}
//--------------Fonction ouvrir-----------------------------------------
void CMainFrame::OnNew(wxCommandEvent& event)
{
	//suppresion du tableau de triangle
	if(num_tri > 0)
	{
		for(int iCpt=num_tri-1; iCpt>=0; iCpt--)
		{
			free(tab_tri[iCpt]);
		}
	}
	num_tri=0;
	opgcan->Refresh();
}
//--------------Fonction open-------------------------------------------
void CMainFrame::OnOpen(wxCommandEvent& event)
{

	wxFileDialog openFileDialog(this, _("Ouvrir Fichier .tri file"), "", "", "Fichier tri (*.tri)|*.tri", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea...
    
    // proceed loading the file chosen by the user;
    // this can be done with e.g. wxWidgets input streams:
	std::ifstream fo(openFileDialog.GetPath().fn_str(), std::ios::in);	
	
	// if open file failed, show an error message box
	if (!fo)
	{
		  wxString errormsg, caption;
		  errormsg.Printf(wxT("Unable to open file "));
		  errormsg.Append(openFileDialog.GetPath());
		  caption.Printf(wxT("Erreur"));
		  wxMessageDialog msg(this, errormsg, caption, wxOK | wxCENTRE | wxICON_ERROR);
		  msg.ShowModal();
		  return ;
	}
	
	fo>> num_tri;
	int iCpt, r,g,b;
	float t1, t2;
	for(iCpt=0; iCpt<num_tri; iCpt++)
	{
		tab_tri[iCpt]=new Triangle();
		//recuperation x et y
		fo>>t1>>t2;
		tab_tri[iCpt]->p1.x=t1;
		tab_tri[iCpt]->p1.y=t2;
		
		//recuperation x et y
		fo>>t1>>t2;
		tab_tri[iCpt]->p2.x=t1;
		tab_tri[iCpt]->p2.y=t2;
		
		//recuperation x et y
		fo>>t1>>t2;
		tab_tri[iCpt]->p3.x=t1;
		tab_tri[iCpt]->p3.y=t2;

		
		//recuperation couleur rgb
		fo>>r>>g>>b;

		//affection des couleurs en fonction des valeurs
		if(r == 255)
		{
			tab_tri[iCpt]->colour=wxRED;
		}
		else 
			if(g == 255)
			{
				tab_tri[iCpt]->colour=wxGREEN;
			}
			else 
				if(b == 255)
				{
					tab_tri[iCpt]->colour=wxBLUE;
				}
				else 
					{
						tab_tri[iCpt]->colour=wxBLACK;
					}
					
		//recuperation epaisseur
		fo>>tab_tri[iCpt]->thickness;
	}


	if(num_tri>0)
	{
		menu_bar->Enable(MENU_GESTION,true);
	}	
	opgcan->Refresh();
}
//--------------Fonction Save-------------------------------------------
void CMainFrame::OnSave(wxCommandEvent& event)
{
	wxFileDialog saveFileDialog(this, _("Save tri file"), "", "","tri files (*.tri)|*.tri", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
	if (saveFileDialog.ShowModal() == wxID_CANCEL)
        return;    
	
    

    std::ofstream fs(saveFileDialog.GetPath().fn_str(), std::ios::out);	

	if (!fs)
	{
		wxString errormsg, caption;
		errormsg.Printf(wxT("Unable to open file "));
		errormsg.Append(saveFileDialog.GetPath());
		caption.Printf(wxT("Erreur"));
		wxMessageDialog msg(this, errormsg, caption, wxOK | wxCENTRE | wxICON_ERROR);
		msg.ShowModal();

		return ;
	}
	
	fs<<num_tri;
	fs<<"\n";
	fs<<"\n";

	//boucle d'enregistrement
	for(int iCpt=0; iCpt<num_tri; iCpt++)
	{
		//enregistrement point du tri
		fs<<tab_tri[iCpt]->p1.x<<" "<<tab_tri[iCpt]->p1.y<<" ";
		fs<<tab_tri[iCpt]->p2.x<<" "<<tab_tri[iCpt]->p2.y<<" ";
		fs<<tab_tri[iCpt]->p3.x<<" "<<tab_tri[iCpt]->p3.y<<"\n";
		
		//enregistrement couleur
		if(tab_tri[iCpt]->colour == wxRED)
		{
			fs<<"255 0 0 \n";
		}
		if(tab_tri[iCpt]->colour == wxGREEN)
		{
			fs<<"0 255 0 \n";
		}
		if(tab_tri[iCpt]->colour == wxBLUE)
		{
			fs<<"0 0 255 \n";
		}
		
		//enregistrement epaisseur
		fs<<tab_tri[iCpt]->thickness;
		fs<<"\n";
		fs<<"\n";
	}
	
}
//--------------Fonction Quit-------------------------------------------
void CMainFrame::OnQuit(wxCommandEvent& event)
{
	Close(TRUE);
}
//--------------Fonction Aide-------------------------------------------
void CMainFrame::OnAide(wxCommandEvent& event)
{
	//affichage boite aide
	VersionDialog vdlg(this, -1, wxT("Aide"));
	vdlg.ShowModal();
}
//--------------Fonction Epaisseur--------------------------------------
void CMainFrame::OnEpaisseur(wxCommandEvent& event)
{
	//affichage boite
	EpaisseurDialog edlg(this, -1, wxT("Epaisseur"));
	edlg.slider->SetValue(iEpaisseurTraitCourante);
	edlg.ShowModal();
}
//--------------Fonction Couleur----------------------------------------
void CMainFrame::OnCouleur(wxCommandEvent& event)
{
	//affichage boite
	CouleurDialog cdlg(this, -1, wxT("Couleur"));
	if(wCouleurCourante == wxRED)
		cdlg.radio->SetSelection(0);
	if(wCouleurCourante == wxGREEN)
		cdlg.radio->SetSelection(1);
	if(wCouleurCourante == wxBLUE)
		cdlg.radio->SetSelection(2);
		
	cdlg.ShowModal();
}
//--------------Fonction Gestion----------------------------------------
void CMainFrame::OnGest(wxCommandEvent& event)
{
	GestDialog gdlg(this, -1, wxT("Gestion"));
	
	gdlg.Rafraichir();
	gdlg.ShowModal();
}
//--------------Fonction Gestion----------------------------------------
void CMainFrame::OnDraw(wxCommandEvent& event)
{
	//changement de bIsDrawing en fonction de l'etat du bouton
	if (bIsDrawing == TRUE)
	{
		bIsDrawing = FALSE;
	}
	else
	{
		bIsDrawing = TRUE;
	}
}
//--------------Tool Bar affiche----------------------------------------
void CMainFrame::OnToolBar(wxCommandEvent& event)
{
	//
	if(affichage->IsChecked(MENU_TOOLBAR)==0)
	{
		//affichage->Check(MENU_TOOLBAR,FALSE);
		m_toolbar->Hide();
	}
	else
	{
		m_toolbar->Show();
		//affichage->Check(MENU_TOOLBAR,TRUE);
	}
}
//---------------Set Epaisseur------------------------------------------
void CMainFrame::SetEpaisseur(int iNewEpaisseur)
{
	iEpaisseurTraitCourante = iNewEpaisseur;
}
//----------------Set Couleur-------------------------------------------
void CMainFrame::SetCouleur(wxColour xwcNew)
{
}
//----------------Set Bool----------------------------------------------
void CMainFrame::SetBool(bool bnew)
{
	
}
//----------------------------------------------------------------------
void CMainFrame::Supprimer_tri(int n)
{
	Triangle *tfree;
	
	//n dans ensemble
	if((n > 4)||(n<0))
	{
		return;
	}
	
	tfree=tab_tri[n];
	//suppression n
	for(int iCpt =  n; iCpt<num_tri; iCpt++)
	{	
		tab_tri[iCpt]=tab_tri[iCpt+1];
	}
	num_tri--;
	free(tfree);
}
//----------------------------------------------------------------------
void CMainFrame::OnHelp(wxCommandEvent& event)
{
	help.DisplayContents();
}
