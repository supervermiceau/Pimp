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
    etape=0;
    clic_busy_out = false ;
    clic_busy_in = false;
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
    draw();
    SwapBuffers();
}
//----------------------------------------------------------------------
void OpenGLCanvas::OnSize( wxSizeEvent& event )
{
    wxGLCanvas::OnSize(event);
}
//----------------------------------------------------------------------
void OpenGLCanvas::OnEraseBackground( wxEraseEvent& event )
{
}
//----------------------------------------------------------------------
void OpenGLCanvas::draw()
{
    CMainFrame * maintmp = (CMainFrame*)GetParent();
    int i;
    int w, h;
    int r,g,b;
    
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    GLfloat thick;
    GetClientSize(&w, &h);
    glViewport(0, 0, (GLint) w, (GLint) h);
    glOrtho(-w/2., w/2., -h/2., h/2., -1., 3.);
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glClearColor( .3f, .4f, .6f, 1 );
    glClear( GL_COLOR_BUFFER_BIT);
    for (i=0; i<((CMainFrame*)GetParent())->num_tri; i++)
    {
        glLineWidth(((CMainFrame*)GetParent())->tab_tri[i].thickness);
        glBegin(GL_TRIANGLES);
        r=maintmp->tab_tri[i].colour->Red();
        g=maintmp->tab_tri[i].colour->Green();
        b=maintmp->tab_tri[i].colour->Blue();
        glColor3f(r,g,b);
        glVertex3f(maintmp->tab_tri[i].p1.x, maintmp->tab_tri[i].p1.y, 0.0f);
        glVertex3f(maintmp->tab_tri[i].p2.x, maintmp->tab_tri[i].p2.y, 0.0f);
        glVertex3f(maintmp->tab_tri[i].p3.x, maintmp->tab_tri[i].p3.y, 0.0f);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0.0,0.0,0.0);
        glVertex3f(maintmp->tab_tri[i].p1.x, maintmp->tab_tri[i].p1.y, 0.0f);
        glVertex3f(maintmp->tab_tri[i].p2.x, maintmp->tab_tri[i].p2.y, 0.0f);
        glVertex3f(maintmp->tab_tri[i].p2.x, maintmp->tab_tri[i].p2.y, 0.0f);
        glVertex3f(maintmp->tab_tri[i].p3.x, maintmp->tab_tri[i].p3.y, 0.0f);
        glVertex3f(maintmp->tab_tri[i].p3.x, maintmp->tab_tri[i].p3.y, 0.0f);
        glVertex3f(maintmp->tab_tri[i].p1.x, maintmp->tab_tri[i].p1.y, 0.0f);
        glEnd();
    }
    glFlush();
}
//----------------------------------------------------------------------
void OpenGLCanvas::OnMouseMove (wxMouseEvent& event)
{
	float r,g,b;
	int thick;
	
    draw();
    CMainFrame* maintmp =(CMainFrame*)GetParent();
    if (!maintmp->isdrawing) 
    {
		return;
	}
    if (maintmp->num_tri >= MAX_TRI || !maintmp->isdrawing)
    {
        return;
    }
    if (etape == 1)
    {
        glColor3f(0.0,0.0,0.0);
        thick= maintmp->get_epaisseur();
        glLineWidth(thick);
        glBegin(GL_LINES);
        glVertex3f(maintmp->tab_tri[maintmp->num_tri].p1.x, maintmp->tab_tri[maintmp->num_tri].p1.y,0.0f);
        glVertex3i(realX(event.GetX()),realY(event.GetY()),0);
        glEnd();
    }
    if (etape == 2)
    {
        r=maintmp->couleurcourante->Red();
        g=maintmp->couleurcourante->Green();
        b=maintmp->couleurcourante->Blue();
        glColor3f(r,g,b);
        glBegin(GL_TRIANGLES);
        glVertex3f(maintmp->tab_tri[maintmp->num_tri].p1.x, maintmp->tab_tri[maintmp->num_tri].p1.y,0.0f);
        glVertex3f(maintmp->tab_tri[maintmp->num_tri].p2.x, maintmp->tab_tri[maintmp->num_tri].p2.y,0.0f);
        glVertex3i(realX(event.GetX()), realY(event.GetY()), 0);
        glEnd();
        glColor3f(0.0f,0.0f,0.0f);
        glBegin(GL_LINES);
        glVertex3f(maintmp->tab_tri[maintmp->num_tri].p1.x, maintmp->tab_tri[maintmp->num_tri].p1.y,0.0f);
        glVertex3f(maintmp->tab_tri[maintmp->num_tri].p2.x, maintmp->tab_tri[maintmp->num_tri].p2.y,0.0f);
        glVertex3f(maintmp->tab_tri[maintmp->num_tri].p2.x, maintmp->tab_tri[maintmp->num_tri].p2.y,0.0f);
        glVertex3i(realX(event.GetX()), realY(event.GetY()), 0);
        glVertex3i(realX(event.GetX()), realY(event.GetY()), 0);
        glVertex3f(maintmp->tab_tri[maintmp->num_tri].p1.x, maintmp->tab_tri[maintmp->num_tri].p1.y,0.0f);
        glEnd();
    }
    glFlush();
    SwapBuffers();
}

//----------------------------------------------------------------------
void OpenGLCanvas::OnLeftUp (wxMouseEvent& event)
{
    CMainFrame* maintmp =(CMainFrame*)GetParent();
    wxMenuBar* menu=maintmp->GetMenuBar();
    wxString buffer = wxT("triangle");
    
    if (maintmp->num_tri >= MAX_TRI || !maintmp->isdrawing)
    {
        return;
    }
    buffer<<(maintmp->num_tri+1);
    switch(etape)
    {
        case 0 :
            maintmp->tab_tri[maintmp->num_tri].p1.x = realX(event.GetX());
            maintmp->tab_tri[maintmp->num_tri].p1.y = realY(event.GetY());
            etape ++;
            break;
        case 1 :
            maintmp->tab_tri[maintmp->num_tri].p2.x = realX(event.GetX());
            maintmp->tab_tri[maintmp->num_tri].p2.y = realY(event.GetY());
            etape ++;
            break;
        case 2 : 
            maintmp->tab_tri[maintmp->num_tri].p3.x = realX(event.GetX());
            maintmp->tab_tri[maintmp->num_tri].p3.y = realY(event.GetY());
            etape = 0;
            maintmp->nom_tri[maintmp->num_tri]=buffer;
            maintmp->tab_tri[maintmp->num_tri].thickness = maintmp->epaisseurtraitcourant;
            maintmp->epaisseurtraitcourant=1;
            glLineWidth(maintmp->epaisseurtraitcourant);
            maintmp->tab_tri[maintmp->num_tri].colour = maintmp->couleurcourante;
            maintmp->couleurcourante=wxBLACK;
            glColor3i(maintmp->couleurcourante->Red(),maintmp->couleurcourante->Green(),maintmp->couleurcourante->Blue());
            maintmp->num_tri++;
            menu->Enable(MENU_MANAGEMENT, true);
            break;
        default :
            break;
    }
}
//----------------------------------------------------------------------
void OpenGLCanvas::OnLeftDown (wxMouseEvent& event)
{
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
void OpenGLCanvas::OnRightDown(wxMouseEvent& event)
{
    CMainFrame * courant = (CMainFrame *)GetParent();
    int w, h;
    
    GetClientSize(&w, &h);
    selected_tri = IsItIn(event.m_x-w/2, -1*(event.m_y-h/2));
    if (selected_tri == -1)
    {
        if (!clic_busy_out)
        {
            //Init
            submenu1 = new wxMenu;
            submenu2 = new wxMenu;
            submenu3 = new wxMenu;
            submenu1->Append(MENU_OPEN, wxT("Ouvrir fichier"));
            submenu1->Append(MENU_SAVE, wxT("Sauvegarder fichier"));
            submenu2->Append(MENU_MANAGEMENT, wxT("Gestion des triangles"));
            submenu3->Append(MENU_COLOR, wxT("Couleurs courantes"));
            submenu3->Append(MENU_WIDTH, wxT("Epaisseur courante"));
            popup.Append(ID_SUB1, wxT("Fichier"),submenu1);
            popup.Append(ID_SUB2, wxT("Gestion"),submenu2);
            popup.Append(ID_SUB3, wxT("Valeurs courantes"),submenu3);
            clic_busy_out = true;
        }
        if (courant->num_tri > 0)
        {
            submenu2->Enable(MENU_MANAGEMENT,true);
		}
        else
        {
            submenu2->Enable(MENU_MANAGEMENT,false);
		}
        PopupMenu(&popup, event.GetX(), event.GetY());
    }
    else
    {
        if(!clic_busy_in)
        {
            //Init
            propri = new wxMenuItem(&popup_tri,ID_PROP, wxT("Proprietes de ce triangle"),wxEmptyString, wxITEM_NORMAL,NULL);
            supprim = new wxMenuItem(&popup_tri,ID_SUPP, wxT("Suppression de ce triangle"),wxEmptyString, wxITEM_NORMAL,NULL);
            
            popup_tri.Append(propri);
            popup_tri.Append(supprim);
            clic_busy_in = true;
        }
        PopupMenu(&popup_tri, event.GetX(), event.GetY());
    }
}
//----------------------------------------------------------------------
int OpenGLCanvas::IsItIn(int x, int y)
{
    CMainFrame * maintmp = (CMainFrame *)GetParent();
    int resultat=0;
    int i;
    
    for (i=maintmp->num_tri-1; i>=0;i--)
    {
        if (maintmp->tab_tri[i].IsPointInTriangle(x,y))
        {
            return i;
		}
    }
    return -1;
}
//----------------------------------------------------------------------
void OpenGLCanvas::OnContextSupp (wxCommandEvent& event)
{
    CMainFrame * maintmp=(CMainFrame *)GetParent();
    
    for (int i=selected_tri; i<maintmp->num_tri;i++)
    {
        maintmp->tab_tri[i]=maintmp->tab_tri[i+1];
        maintmp->nom_tri[i]=maintmp->nom_tri[i+1];
    }
    maintmp->num_tri--;
    if (maintmp->num_tri==0)
    {
        wxMenuBar* menu=maintmp->GetMenuBar();
        menu->Enable(MENU_MANAGEMENT,false);
    }
}
//----------------------------------------------------------------------
void OpenGLCanvas::OnContextPptes (wxCommandEvent& event)
{
    CMainFrame * maintmp = (CMainFrame *)GetParent();
    wxCommandEvent evt(wxEVT_COMMAND_BUTTON_CLICKED, ID_PROP);

    ManagDialog mdlg (maintmp,-1, wxT("Gestion des Triangles"));
    mdlg.list->Clear();
    for (int i=0; i<maintmp->num_tri;i++)
    {
        mdlg.list->Append(maintmp->nom_tri[i]);
    }
    mdlg.list->SetSelection(selected_tri);
    mdlg.GetEventHandler()->ProcessEvent(evt);
}
//----------------------------------------------------------------------

