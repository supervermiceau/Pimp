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
	glOrtho(w/2., w/2., h/2., h/2., 1., 3.);
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
 
	iNbTri=main_frame->num_tri;
    if (iNbTri >= MAX_TRI || !main_frame->bIsDrawing)
    {
        return;
    }
    if (etape == 1)
    {
        glColor3f(0.0,0.0,0.0);
        iTmp= main_frame->get_epaisseur();
        glLineWidth(iTmp);
        glBegin(GL_LINES);
        glVertex2f(main_frame->tab_tri[iNbTri]->p1.x, main_frame->tab_tri[iNbTri]->p1.y);
        glVertex2i(realX(event.GetX()),realY(event.GetY()));
        glEnd();
    }
    if (etape == 2)
    {
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
}
//----------------------------------------------------------------------
