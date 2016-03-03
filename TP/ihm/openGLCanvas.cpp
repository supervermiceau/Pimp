#include "openGLCanvas.h"
#include "mainframe.h"
#include <wx/event.h>
#include "triangle.h"
//--------------------Table evenement-----------------------------------
BEGIN_EVENT_TABLE(OpenGLCanvas, wxGLCanvas)    
	EVT_PAINT(OpenGLCanvas::OnPaint)
    EVT_SIZE(OpenGLCanvas::OnSize)
    EVT_ERASE_BACKGROUND(OpenGLCanvas::OnEraseBackground)
    EVT_MOTION(OpenGLCanvas::OnMouseMove)
    EVT_LEFT_DOWN(OpenGLCanvas::OnLeftDown)
    EVT_LEFT_UP(OpenGLCanvas::OnLeftUp)
    EVT_RIGHT_DOWN(OpenGLCanvas::OnRightDown)
    EVT_MENU(ID_SUPP,OpenGLCanvas::OnContextSupp)
    EVT_MENU(ID_PROP,OpenGLCanvas::OnContextPptes)
END_EVENT_TABLE()
//--------------Constructeur--------------------------------------------
OpenGLCanvas::OpenGLCanvas(wxWindow *parent, wxWindowID id,const wxPoint& pos, const wxSize& size,long style, const wxString& name):wxGLCanvas(parent, id, pos, size, style, name)
{
	//init etape
	etape = 0;
	//init des menus
    submenu1 = new wxMenu;
    submenu2 = new wxMenu;
    submenu3 = new wxMenu;
    submenu1->Append(MENU_OUVRIR, wxT("Ouvrir fichier"));
    submenu1->Append(MENU_SAVE, wxT("Sauvegarder fichier"));
    submenu2->Append(MENU_GESTION, wxT("Gestion des triangles"));
    submenu3->Append(MENU_COULEUR, wxT("Couleurs courantes"));
    submenu3->Append(MENU_EPAISSEUR, wxT("Epaisseur courante"));
    popup.Append(ID_SUB1, wxT("Fichier"),submenu1);
    popup.Append(ID_SUB2, wxT("Gestion"),submenu2);
    popup.Append(ID_SUB3, wxT("Valeurs courantes"),submenu3);
    propri = new wxMenuItem(&popup_tri,ID_PROP, wxT("Proprietes de ce triangle"),wxEmptyString, wxITEM_NORMAL,NULL);
    supprim = new wxMenuItem(&popup_tri,ID_SUPP, wxT("Suppression de ce triangle"),wxEmptyString, wxITEM_NORMAL,NULL);
    popup_tri.Append(propri);
    popup_tri.Append(supprim);
}
//----------------Destructeur-------------------------------------------
OpenGLCanvas::~OpenGLCanvas(void)
{
}
//----------------OnPaint------------------------------------------------
void OpenGLCanvas::OnPaint( wxPaintEvent& event )
{
	wxPaintDC dc(this);
	SetCurrent();
	Draw();
	SwapBuffers();
}
//----------------OnSize------------------------------------------------
void OpenGLCanvas::OnSize( wxSizeEvent& event )
{
	wxGLCanvas::OnSize(event);
	int w,h;
	GetClientSize(&w, &h);
}
//----------------OnEraseBackground-------------------------------------
void OpenGLCanvas::OnEraseBackground( wxEraseEvent& event )
{
}
//----------------Draw--------------------------------------------------
void OpenGLCanvas::Draw()
{
	CMainFrame *main_frame=(CMainFrame*)this->GetParent();
	int w, h, iCpt;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GetClientSize(&w, &h);
	glOrtho(-w/2., w/2., -h/2., h/2., -1., 3.);
	glMatrixMode( GL_MODELVIEW);
	glLoadIdentity();
	glClearColor( .3f, .4f, .6f, 1);
	glClear( GL_COLOR_BUFFER_BIT);
	
	//recuperation couleur
	for (iCpt=0; iCpt<main_frame->num_tri; iCpt++)
    {
		//tracage triangles
        glLineWidth(main_frame->tab_tri[iCpt]->thickness);
        glBegin(GL_TRIANGLES);

		//gerer la couleur
		if (main_frame->tab_tri[iCpt]->colour==wxRED)
		{
			glColor3f(255,0,0);
		}
		else if( main_frame->tab_tri[iCpt]->colour==wxGREEN)
			{
				glColor3f(0,255,0);
			}
			else if (main_frame->tab_tri[iCpt]->colour==wxBLUE)
				{
					glColor3f(0,0,255);
				}
				else
				{
					glColor3f(0,0,0);
				}
	  
		//gerer les 3 points
		glVertex2f(main_frame->tab_tri[iCpt]->p1.x, main_frame->tab_tri[iCpt]->p1.y);
		glVertex2f(main_frame->tab_tri[iCpt]->p2.x, main_frame->tab_tri[iCpt]->p2.y);
		glVertex2f(main_frame->tab_tri[iCpt]->p3.x, main_frame->tab_tri[iCpt]->p3.y);
		glEnd();
		
		//Tracage triangle contour
		glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glVertex2f(main_frame->tab_tri[iCpt]->p1.x, main_frame->tab_tri[iCpt]->p1.y);
		glVertex2f(main_frame->tab_tri[iCpt]->p2.x, main_frame->tab_tri[iCpt]->p2.y);
		glEnd();
		
		glBegin(GL_LINES);
		glVertex2f(main_frame->tab_tri[iCpt]->p2.x, main_frame->tab_tri[iCpt]->p2.y);
		glVertex2f(main_frame->tab_tri[iCpt]->p3.x, main_frame->tab_tri[iCpt]->p3.y);
		glEnd();
		
		glBegin(GL_LINES);
		glVertex2f(main_frame->tab_tri[iCpt]->p1.x, main_frame->tab_tri[iCpt]->p1.y);
		glVertex2f(main_frame->tab_tri[iCpt]->p3.x, main_frame->tab_tri[iCpt]->p3.y);
		glEnd();
    }
    glFlush();
}
//-----------------OnMouseMove------------------------------------------
void OpenGLCanvas::OnMouseMove (wxMouseEvent& event)
{
	int iTmp,iNbTri;
    CMainFrame* main_frame =(CMainFrame*)GetParent();
	
	iNbTri=main_frame->num_tri;
	
	//verification nombre triangle
    if (iNbTri >= 4 || !main_frame->bIsDrawing)
    {
        return;
    }
    if (etape == 1) //etape
    {
        glColor3f(0.0,0.0,0.0);
        iTmp= main_frame->iEpaisseurTraitCourante;
        glLineWidth(iTmp);
        glBegin(GL_LINES);
        glVertex2f(main_frame->tab_tri[iNbTri]->p1.x, main_frame->tab_tri[iNbTri]->p1.y);
        glVertex2i(realX(event.GetX()),realY(event.GetY()));
        glEnd();
    }
    if (etape == 2)
    {
		//gerer la couleur
		if (main_frame->tab_tri[iNbTri]->colour==wxRED)
		{
			glColor3f(255,0,0);
		}
		else if( main_frame->tab_tri[iNbTri]->colour==wxGREEN)
			{
				glColor3f(0,255,0);
			}
			else if (main_frame->tab_tri[iNbTri]->colour==wxBLUE)
				{
					glColor3f(0,0,255);
				}
				else
				{
					glColor3f(0,0,0);
				}

        glBegin(GL_TRIANGLES);
        glVertex2f(main_frame->tab_tri[iNbTri]->p1.x, main_frame->tab_tri[iNbTri]->p1.y);
        glVertex2f(main_frame->tab_tri[iNbTri]->p2.x, main_frame->tab_tri[iNbTri]->p2.y);
        glVertex2i(realX(event.GetX()), realY(event.GetY()));
        glEnd();

        glColor3f(0.0f,0.0f,0.0f);
        glBegin(GL_LINES);
        glVertex2f(main_frame->tab_tri[iNbTri]->p1.x, main_frame->tab_tri[iNbTri]->p1.y);
        glVertex2f(main_frame->tab_tri[iNbTri]->p2.x, main_frame->tab_tri[iNbTri]->p2.y);
        glVertex2f(main_frame->tab_tri[iNbTri]->p2.x, main_frame->tab_tri[iNbTri]->p2.y);

        glVertex2i(realX(event.GetX()), realY(event.GetY()));
        glVertex2i(realX(event.GetX()), realY(event.GetY()));

        glVertex2f(main_frame->tab_tri[iNbTri]->p1.x, main_frame->tab_tri[iNbTri]->p1.y);
        glEnd();
    }
   
    glFlush();
    SwapBuffers();
    Draw();
}
//-----------------OnLeftDown-------------------------------------------
void OpenGLCanvas::OnLeftDown (wxMouseEvent& event)
{
	CMainFrame* main_frame =(CMainFrame*)GetParent();
    //wxMenuBar* menu=main_frame->GetMenuBar();
    
    wxString buffer = wxT("triangle");
    int nbtri=main_frame->num_tri;
    
    if (nbtri >= 4 || !main_frame->bIsDrawing)
    {
        return;
    }
   buffer<<(main_frame->num_tri);
    switch(etape)
    {
        case 0 :
			main_frame->tab_tri[nbtri]=new Triangle();
            main_frame->tab_tri[nbtri]->p1.x = realX(event.GetX());
            main_frame->tab_tri[nbtri]->p1.y = realY(event.GetY());
            etape ++;
            break;
            
        case 2 : 
            main_frame->tab_tri[nbtri]->p3.x = realX(event.GetX());
            main_frame->tab_tri[nbtri]->p3.y = realY(event.GetY());
            etape = 0;
            main_frame->tab_tri[nbtri]->thickness = main_frame->iEpaisseurTraitCourante;
            main_frame->iEpaisseurTraitCourante=1;
            glLineWidth(main_frame->iEpaisseurTraitCourante);
            main_frame->tab_tri[nbtri]->colour = main_frame->wCouleurCourante;
            glColor3i(main_frame->wCouleurCourante->Red(),main_frame->wCouleurCourante->Green(),main_frame->wCouleurCourante->Blue());
            main_frame->num_tri++;
            main_frame->menu_bar->Enable(MENU_GESTION,true);
            break;
        default :
            break;
    }
    Draw();
}
//-------------------------realX----------------------------------------
int OpenGLCanvas::realX(int x)
{
    int w, h;
    GetClientSize(&w, &h);
    return (x-(w/2));
}
//---------------------------realY--------------------------------------
int OpenGLCanvas::realY(int y)
{
    int w, h;
    GetClientSize(&w, &h);
    return (-1*(y-h/2));
}
//-----------------OnLeftUp---------------------------------------------
void OpenGLCanvas::OnLeftUp (wxMouseEvent& event)
{
	if(etape == 1)
	{
		main_frame->tab_tri[nbtri]->p2.x = realX(event.GetX());
		main_frame->tab_tri[nbtri]->p2.y = realY(event.GetY());
		etape ++;
	}
	//printf(" X : %d, Y : %d \n",realX(event.GetX()), realY(event.GetY()));
}
//-----------------OnRightDown------------------------------------------
void OpenGLCanvas::OnRightDown(wxMouseEvent& event)
{
    CMainFrame * main_frame = (CMainFrame *)GetParent();
    int w, h;
    
    GetClientSize(&w, &h);
    //recuperation triangle
    selected_tri = IsItIn(realX(event.GetX()), realY(event.GetY()));
    if (selected_tri == -1)// pas de triangle
    {
		//Pas de triangle on desactive la gestion de triangle
        if (main_frame->num_tri > 0)
        {
            submenu2->Enable(MENU_GESTION,true);
		}
        else
        {
            submenu2->Enable(MENU_GESTION,false);
		}
        PopupMenu(&popup, event.GetX(), event.GetY());
    }
    else // un triangle -> prop menu triangle
    {
        PopupMenu(&popup_tri, event.GetX(), event.GetY());
    }
}
//----------------IsItIn------------------------------------------------
int OpenGLCanvas::IsItIn(int x, int y)
{
    CMainFrame * main_frame = (CMainFrame *)GetParent();
    int resultat=0;
    int i;
	//on cherche si le point est dans un triangle
    for (i=main_frame->num_tri-1; i>=0;i--)
    {
        if (main_frame->tab_tri[i]->IsPointInTriangle(x,y))
        {
            return i;
		}
    }
    //si pas de triangle renvoie -1 pour gestion du cas hors triangle
    return -1;
}
//-----------------OnContextSupp----------------------------------------
void OpenGLCanvas::OnContextSupp (wxCommandEvent& event)
{
	CMainFrame * main_frame = (CMainFrame *)GetParent();
	//desactivation de gestion des triangles si 1 triangle
	if(main_frame->num_tri == 1)
	{
		main_frame->menu_bar->Enable(MENU_GESTION,false);
	}
	//suppression triangle
	main_frame->Supprimer_tri(selected_tri);
	Refresh();
	
}
//-----------------OnContextPptes---------------------------------------
void OpenGLCanvas::OnContextPptes (wxCommandEvent& event)
{
    CMainFrame * main_frame = (CMainFrame *)GetParent();
    //on creer un evenement "clique"
    wxCommandEvent evt(wxEVT_COMMAND_BUTTON_CLICKED, ID_PROP);

    GestDialog gdlg (main_frame,-1, wxT("Gestion des Triangles"));
    gdlg.list->Clear();
    //rafraichissement de la liste de triangle
    for (int i=0; i<main_frame->num_tri;i++)
    {
        gdlg.list->Append(NameCol[i]);
    }
    //on declenche l'evenement clique
    gdlg.list->SetSelection(selected_tri);
    gdlg.GetEventHandler()->ProcessEvent(evt);
    Refresh();
}
//---------------------------------------------------------------------
