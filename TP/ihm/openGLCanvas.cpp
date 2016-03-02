#include "openGLCanvas.h"
#include "mainframe.h"
#include <wx/event.h>
#include "triangle.h"
//----------------------------------------------------------------------
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
//----------------------------------------------------------------------
OpenGLCanvas::OpenGLCanvas(wxWindow *parent, wxWindowID id,const wxPoint& pos, const wxSize& size,long style, const wxString& name):wxGLCanvas(parent, id, pos, size, style, name)
{
	etape = 0;
}
//----------------------------------------------------------------------
OpenGLCanvas::~OpenGLCanvas(void)
{
}
//----------------------------------------------------------------------
void OpenGLCanvas::OnPaint( wxPaintEvent& event )
{
	wxPaintDC dc(this);
	SetCurrent();
	Draw();
	SwapBuffers();
}
//----------------------------------------------------------------------
void OpenGLCanvas::OnSize( wxSizeEvent& event )
{
	wxGLCanvas::OnSize(event);
	int w,h;
	GetClientSize(&w, &h);
}
//----------------------------------------------------------------------
void OpenGLCanvas::OnEraseBackground( wxEraseEvent& event )
{
}
//----------------------------------------------------------------------
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
	
	for (iCpt=0; iCpt<main_frame->num_tri; iCpt++)
    {
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
//----------------------------------------------------------------------
void OpenGLCanvas::OnMouseMove (wxMouseEvent& event)
{
	int iTmp,iNbTri;
    CMainFrame* main_frame =(CMainFrame*)GetParent();
	Draw();
	iNbTri=main_frame->num_tri;
    if (iNbTri >= 4 || !main_frame->bIsDrawing)
    {
        return;
    }
    if (etape == 1)
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
}
//----------------------------------------------------------------------
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
			//main_frame->num_tri++;
            main_frame->tab_tri[nbtri]->p1.x = realX(event.GetX());
            main_frame->tab_tri[nbtri]->p1.y = realY(event.GetY());
            etape ++;
            break;
        case 1 :
            main_frame->tab_tri[nbtri]->p2.x = realX(event.GetX());
            main_frame->tab_tri[nbtri]->p2.y = realY(event.GetY());
            etape ++;
            break;
        case 2 : 
            main_frame->tab_tri[nbtri]->p3.x = realX(event.GetX());
            main_frame->tab_tri[nbtri]->p3.y = realY(event.GetY());
            etape = 0;
            //main_frame->nom_tri[nbtri]=buffer;
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
//----------------------------------------------------------------------
int OpenGLCanvas::realX(int x)
{
    int w, h;
    
    GetClientSize(&w, &h);
    
    return (x-(w/2));
}
//----------------------------------------------------------------------
int OpenGLCanvas::realY(int y)
{
    int w, h;
    
    GetClientSize(&w, &h);
    
    return (-1*(y-h/2));
}
//----------------------------------------------------------------------
void OpenGLCanvas::OnLeftUp (wxMouseEvent& event)
{
	printf(" X : %d, Y : %d \n",realX(event.GetX()), realY(event.GetY()));
}
//----------------------------------------------------------------------
void OpenGLCanvas::OnRightDown(wxMouseEvent& event)
{
    CMainFrame * main_frame = (CMainFrame *)GetParent();
    int w, h;
    
    GetClientSize(&w, &h);
    selected_tri = IsItIn(event.m_x-w/2, -1*(event.m_y-h/2));
    if (selected_tri == -1)
    {
        if (!clic_busy_in)
        {
            //Init
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
            clic_busy_in = true;
        }
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
    else
    {
        if(!clic_busy_out)
        {
            //Init
            propri = new wxMenuItem(&popup_tri,ID_PROP, wxT("Proprietes de ce triangle"),wxEmptyString, wxITEM_NORMAL,NULL);
            supprim = new wxMenuItem(&popup_tri,ID_SUPP, wxT("Suppression de ce triangle"),wxEmptyString, wxITEM_NORMAL,NULL);
            
            popup_tri.Append(propri);
            popup_tri.Append(supprim);
            clic_busy_out = true;
        }
        PopupMenu(&popup_tri, event.GetX(), event.GetY());
    }
}
//----------------------------------------------------------------------
int OpenGLCanvas::IsItIn(int x, int y)
{
    CMainFrame * main_frame = (CMainFrame *)GetParent();
    int resultat=0;
    int i;
    
    for (i=main_frame->num_tri-1; i>=0;i--)
    {
        if (main_frame->tab_tri[i]->IsPointInTriangle(x,y))
        {
            return i;
		}
    }
    return -1;
}
//----------------------------------------------------------------------
void OpenGLCanvas::OnContextSupp (wxCommandEvent& event)
{
    //~ CMainFrame * main_frame=(CMainFrame *)GetParent();
    //~ 
    //~ for (int i=selected_tri; i<main_frame->num_tri;i++)
    //~ {
        //~ main_frame->tab_tri[i]=main_frame->tab_tri[i+1];
        //~ //main_frame->nom_tri[i]=main_frame->nom_tri[i+1];
    //~ }
    //~ main_frame->num_tri--;
    //~ if (main_frame->num_tri==0)
    //~ {
        //~ wxMenuBar* menu=main_frame->GetMenuBar();
        //~ menu->Enable(MENU_GESTION,false);
    //~ }
    //~ CMainFrame *main_frame=(CMainFrame*)this->GetParent();
//~ 
	//~ //deselection du menu si jamais il n'y a plus de triangles	
	//~ if(main_frame->num_tri == 1)
	//~ {
		//~ main_frame->menu_bar->Enable(MENU_GESTION,false);
	//~ }
	//~ //decrementation de num_tri
	//~ if(main_frame->num_tri>0)
	//~ {
		//~ main_frame->Supprimer_tri(list->GetSelection());
		//~ Rafraichir();
		//~ printf("%d uu\n",main_frame->num_tri);
	//~ }
}
//----------------------------------------------------------------------
void OpenGLCanvas::OnContextPptes (wxCommandEvent& event)
{
    //~ CMainFrame * main_frame = (CMainFrame *)GetParent();
    //~ wxCommandEvent evt(wxEVT_COMMAND_BUTTON_CLICKED, ID_PROP);
//~ 
    //~ GestDialog mdlg (main_frame,-1, wxT("Gestion des Triangles"));
    //~ mdlg.list->Clear();
    //~ for (int i=0; i<main_frame->num_tri;i++)
    //~ {
        //~ mdlg.list->Append(main_frame->nom_tri[i]);
    //~ }
    //~ mdlg.list->SetSelection(selected_tri);
    //~ mdlg.GetEventHandler()->ProcessEvent(evt);
	
}
//---------------------------------------------------------------------
