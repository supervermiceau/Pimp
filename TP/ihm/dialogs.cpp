#include "dialogs.h"
//----------------------------------------------------------------------
//--------------------CLASS VERSION-------------------------------------
//----------------------------------------------------------------------
//creation de la table d'evenements
BEGIN_EVENT_TABLE(VersionDialog, wxDialog)

END_EVENT_TABLE ()

//----------------------------------------------------------------------
VersionDialog::VersionDialog( wxWindow *parent, wxWindowID id, const wxString &title) 
: wxDialog( parent, id, title)
{
	//creation du conteneur vertical
	wxBoxSizer *item0 = new wxBoxSizer( wxVERTICAL );

	//creation du text
	wxStaticText *item1 = new wxStaticText( this, ID_TEXT, wxT("Version 1.0"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	
	//creation du bouton OK
	wxButton *item2 = new wxButton( this, wxID_OK, wxT("OK"), wxDefaultPosition);
	
	//ajout des elements dans item0
	item0->Add( item1, 0, wxALIGN_CENTRE|wxALL, 5 );
	item0->Add( item2, 0, wxALIGN_CENTRE|wxALL, 5 );
	
	//Optimisation et affichage boite de dialogue
	this->SetAutoLayout( TRUE );
	this->SetSizer( item0 );
	item0->Fit( this );
	item0->SetSizeHints( this );
}
//----------------------------------------------------------------------
//--------------------CLASS EPAISSEUR-----------------------------------
//----------------------------------------------------------------------
BEGIN_EVENT_TABLE(EpaisseurDialog, wxDialog)
EVT_COMMAND_SCROLL( ID_SLIDER, EpaisseurDialog::OnSlider)
END_EVENT_TABLE ()
//----------------------------------------------------------------------
EpaisseurDialog::EpaisseurDialog(wxWindow *parent, wxWindowID id,const wxString &title) : wxDialog( parent, id, title)
{
	//creation du conteneur vertical
	wxBoxSizer *item0 = new wxBoxSizer( wxVERTICAL );

	//creation du text
	wxStaticText *item1 = new wxStaticText( this, ID_TEXT, wxT("Choisir la nouvelle epaisseur du trait."), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );

	//creation du slider
	slider= new wxSlider(this, ID_SLIDER, 1, 1, 10, wxPoint(-1, -1), wxSize(125, 50), wxSL_LABELS);
	
	//creation du bouton OK
	wxButton *item2 = new wxButton( this, wxID_OK, wxT("OK"), wxDefaultPosition);
	
	//ajout des elements dans item0 ( forme)
	item0->Add( item1, 0, wxALIGN_CENTRE|wxALL, 5 );
	item0->Add( slider, 0, wxALIGN_CENTRE|wxALL, 5 );
	item0->Add( item2, 0, wxALIGN_CENTRE|wxALL, 5 );
	
	//Optimisation et affichage boite de dialogue
	this->SetAutoLayout( TRUE );
	this->SetSizer( item0 );
	item0->Fit( this );
	item0->SetSizeHints( this );
}
//-------------------EpaisseurDialog::OnSlider--------------------------
void EpaisseurDialog::OnSlider(wxScrollEvent& event)
{
	CMainFrame *main_frame=(CMainFrame*)this->GetParent();
	//Recuperation de la valeur de slider puis du main frame pour l'acces a epaisseur, puis definition de la nouvelle valeur
	int iTmp=slider->GetValue();
	main_frame->SetEpaisseur(iTmp);
}
//----------------------------------------------------------------------
//--------------------CLASS COULEUR-------------------------------------
//----------------------------------------------------------------------
BEGIN_EVENT_TABLE(CouleurDialog, wxDialog)
EVT_RADIOBOX(ID_COUL, CouleurDialog::OnRadio)
END_EVENT_TABLE ()
//----------------------------------------------------------------------
CouleurDialog::CouleurDialog(wxWindow *parent, wxWindowID id,const wxString &title): wxDialog( parent, id, title)
{
	wxString strs8[] = {wxT("Red"),  wxT("Green"),  wxT("Blue")};
	
	//creation du conteneur vertical
    wxBoxSizer *principale = new wxBoxSizer(wxVERTICAL);
    
    //creation du text
    wxStaticText *item1= new wxStaticText(this, ID_TEXT, wxT("Choisir la nouvelle couleur"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE);
   
   //creation du choix type radio
    radio= new wxRadioBox(this, ID_COUL, wxT("Couleur"), wxPoint(-1, -1), wxSize(-1,-1),3, strs8);
	
	//creation du bouton OK
    wxButton *item2 = new wxButton( this, wxID_OK, wxT("OK"), wxDefaultPosition);
    
	//ajout des elements dans item0 ( forme)
    principale->Add( item1, 0, wxALIGN_CENTRE | wxALL, 5);
    principale->Add( radio, 0, wxALIGN_CENTRE | wxALL, 5);
    principale->Add( item2, 0, wxALIGN_CENTRE | wxALL, 5);

    this->SetAutoLayout(true);
    this->SetSizer(principale);
    principale->Fit(this);
    principale->SetSizeHints(this);	
}
//----------------------------------------------------------------------
void CouleurDialog::OnRadio(wxCommandEvent& event)
{
  int col = radio->GetSelection();
  CMainFrame *main_frame=(CMainFrame*)this->GetParent();
  
	//affectation de la couleur en fonction de la selection
    switch (col)
    {
        case 0 : main_frame->wCouleurCourante=wxRED;
                 break;
        case 1 : main_frame->wCouleurCourante=wxGREEN;
                 break;
        case 2 : main_frame->wCouleurCourante=wxBLUE;
                 break;
        default : main_frame->wCouleurCourante=wxBLACK;
                  break;
	}
}
//----------------------------------------------------------------------
//--------------------CLASS GESTION-------------------------------------
//----------------------------------------------------------------------
BEGIN_EVENT_TABLE(GestDialog, wxDialog)
EVT_BUTTON(ID_PROP, GestDialog::OnProp)
EVT_BUTTON(ID_SUPP, GestDialog::OnSupp)

END_EVENT_TABLE ()
//----------------------------------------------------------------------
GestDialog::GestDialog(wxWindow *parent, wxWindowID id,const wxString &title): wxDialog( parent, id, title)
{
	//Creation des 3 formes 
	wxBoxSizer *principale = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *gauche = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *droite = new wxBoxSizer(wxVERTICAL);
    
    //creation texte
    wxStaticText *item1= new wxStaticText(this, ID_TEXT, wxT("Liste des triangles"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE);
    
    //Creation des 3 bouttons
    wxButton *wxb_prop = new wxButton( this, ID_PROP, wxT("Propriétés"), wxDefaultPosition);
    wxButton *wxb_supp = new wxButton( this, ID_SUPP, wxT("Supprimer"), wxDefaultPosition);
    wxButton *wxb_butt = new wxButton( this, wxID_OK, wxT("OK"), wxDefaultPosition);
    
    //Creation de la liste
	list = new wxListBox( this, IDBOX, wxPoint(1,1), wxDefaultSize ,0,NULL);
	
	//Ajout 2 elements dans gauche
	gauche->Add( item1, 0, wxALIGN_CENTRE | wxALL, 10);
    gauche->Add( list, 0, wxALIGN_CENTRE | wxALL, 10);

	//Ajout 3 elements dans droite
    droite->Add( wxb_prop, 0, wxALIGN_CENTRE | wxALL, 10);
    droite->Add( wxb_supp, 0, wxALIGN_CENTRE | wxALL, 10);
    droite->Add( wxb_butt, 0, wxALIGN_CENTRE | wxALL, 10);

	//Ajout droite et gauche dans forme principale
    principale->Add( gauche, 0, wxALIGN_CENTRE | wxALL, 10);
    principale->Add( droite, 0, wxALIGN_CENTRE | wxALL, 10);
    
    this->SetAutoLayout(true);
    this->SetSizer(principale);
    principale->Fit(this);
    principale->SetSizeHints(this);	
	
}
//--------------------Fonction propriete--------------------------------
void GestDialog::OnProp(wxCommandEvent& event)
{
	CMainFrame *main_frame=(CMainFrame*)this->GetParent();
	wxString stmp;
	int iT;
	PropDialog vdlg(this,-1,wxT("Vert"));
	
	//recuperation de la selection
	stmp=this->list->GetStringSelection();
	iT=this->list->GetSelection();
	
	//on affiche dans txtctrl
	vdlg.TxtCtrl->SetValue(stmp);
	
	//on initialise l'epaisseuir
	vdlg.epaisse->SetValue(main_frame->tab_tri[iT]->thickness);
	
	//initisalisation de la couleur
	if((main_frame->tab_tri[iT]->colour)==wxRED)
    {
		vdlg.radio->SetSelection(0);
	}
	else if((main_frame->tab_tri[iT]->colour)==wxGREEN)
		{
			vdlg.radio->SetSelection(1);
		}
		else if((main_frame->tab_tri[iT]->colour)==wxBLUE)
			{
				vdlg.radio->SetSelection(2);
			}	
	//affichage boite
	vdlg.ShowModal();	
}
//--------------------OnSupp--------------------------------------------
void GestDialog::OnSupp(wxCommandEvent& event)
{
	CMainFrame *main_frame=(CMainFrame*)this->GetParent();

	//deselection du menu si jamais il n'y a plus de triangles	
	if(main_frame->num_tri == 1)
	{
		main_frame->menu_bar->Enable(MENU_GESTION,false);
	}
	//decrementation de num_tri
	if(main_frame->num_tri>0)
	{
		main_frame->Supprimer_tri(list->GetSelection());
		Rafraichir();
	}
}
//----------------------------------------------------------------------
void GestDialog::Rafraichir()
{
	CMainFrame *main_frame=(CMainFrame*)this->GetParent();
	//vider la liste
	list->Clear();
	
	//recuperation des noms de triangles 
	for(int iCpt =0; iCpt < main_frame->num_tri; iCpt++)
	{
		list->Append(NameCol[iCpt]);
	}

}
//----------------------------------------------------------------------
//--------------------CLASS PROPRIETE-----------------------------------
//----------------------------------------------------------------------
BEGIN_EVENT_TABLE(PropDialog, wxDialog)
END_EVENT_TABLE()
//----------------------------------------------------------------------
PropDialog::PropDialog( wxWindow *parent, wxWindowID id,const wxString &title) : wxDialog( parent, id, wxT("Proprieté"))
{
    wxString strs8[] = {wxT("Rouge"), wxT("Vert"), wxT("Bleu")};

	//Creation 3 formes
    wxBoxSizer *principale = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *gauche = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *milieu = new wxBoxSizer(wxHORIZONTAL);
    
	//creation texte id + epaisseur
    wxStaticText *Id= new wxStaticText(this,ID_TEXT, wxT("Identifiant du triangle"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE);
    wxStaticText *Epaiss= new wxStaticText(this, ID_TEXT, wxT("Epaisseur du trait"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE);

	//Creation texte de controle ( remplir)
    TxtCtrl= new wxTextCtrl(this, ID_TEXT, title, wxPoint(-1, -1), wxSize(-1,-1),wxTE_PROCESS_TAB, wxDefaultValidator);
    
    //creation slection +-
    epaisse= new wxSpinCtrl(this, wxID_ANY, wxT("Epaisseur Trait"), wxPoint(-1,-1), wxSize(-1,-1),wxSP_ARROW_KEYS | wxSP_WRAP, 0 , 10, 1 );

	//Creation choix radio
    radio= new wxRadioBox(this, wxID_ANY, wxT("Couleur"), wxPoint(-1, -1), wxSize(-1,-1),3, strs8);

	//creation bouton ok
    wxButton *butt = new wxButton( this, wxID_OK, wxT("OK"), wxDefaultPosition);

	//ajout element a gauche
    gauche->Add( Id, 0, wxALIGN_CENTRE | wxALL, 10);
    gauche->Add( TxtCtrl, 0, wxALIGN_CENTRE | wxALL, 10);
    gauche->Add( Epaiss, 0, wxALIGN_CENTRE | wxALL, 10);
    gauche->Add( epaisse, 0, wxALIGN_CENTRE | wxALL, 10);

	//Ajout element milieu
    milieu->Add( gauche, 0, wxALIGN_CENTRE | wxALL, 10);
    milieu->Add( radio, 0, wxALIGN_CENTRE | wxALL, 10);

	//ajout element mileu
    principale-> Add(milieu, 0, wxALIGN_CENTRE | wxALL, 10);
    principale-> Add(butt, 0, wxALIGN_CENTRE | wxALL, 10);


    this->SetAutoLayout(true);
    this->SetSizer(principale);
    principale->Fit(this);
    principale->SetSizeHints(this);	
}
