#include "openGLCanvas.h"
#include "mainframe.h"
#include <wx/event.h>
#include "triangle.h"
//----------------------------------------------------------------------
BEGIN_EVENT_TABLE(OpenGLCanvas, wxGLCanvas)    
	EVT_PAINT(OpenGLCanvas::OnPaint)
    EVT_SIZE(OpenGLCanvas::OnSize)
    EVT_ERASE_BACKGROUND(OpenGLCanvas::OnEraseBackground)
END_EVENT_TABLE()
//----------------------------------------------------------------------
OpenGLCanvas::OpenGLCanvas(wxWindow *parent, wxWindowID id,const wxPoint& pos, const wxSize& size,long style, const wxString& name):wxGLCanvas(parent, id, pos, size, style, name)
{
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
	
	   for (iCpt=0; iCpt<main_frame->num_tri; i++)
    {
        glLineWidth(main_frame->tab_tri[iCpt].thickness);
        glBegin(GL_TRIANGLES);

//gerer la couleur

	if (main_frame->wCouleurCourante=wxRED)
	{
		glColor3f(255,0,0);
	}
	else if( main_frame->wCouleurCourante=wxGREEN)
		{
			glColor3f(0,255,0);
		}
        else if (main_frame->wCouleurCourante=wxBLUE)
			{
				glColor3f(0,0,255);
			}
			else
			{
			}
  
        //gerer les 3 points
        glVertex3f(maintmp->tab_tri[iCpt].p1.x, maintmp->tab_tri[i].p1.y, 0.0f);
        glVertex3f(maintmp->tab_tri[iCpt].p2.x, maintmp->tab_tri[i].p2.y, 0.0f);
        glVertex3f(maintmp->tab_tri[iCpt].p3.x, maintmp->tab_tri[i].p3.y, 0.0f);
        glEnd();
        glBegin(GL_LINES);
        glColor3f(0.0,0.0,0.0);
        glVertex3f(maintmp->tab_tri[iCpt].p1.x, maintmp->tab_tri[i].p1.y, 0.0f);
        glVertex3f(maintmp->tab_tri[iCpt].p2.x, maintmp->tab_tri[i].p2.y, 0.0f);
        glVertex3f(maintmp->tab_tri[iCpt].p2.x, maintmp->tab_tri[i].p2.y, 0.0f);
        glVertex3f(maintmp->tab_tri[iCpt].p3.x, maintmp->tab_tri[i].p3.y, 0.0f);
        glVertex3f(maintmp->tab_tri[iCpt].p3.x, maintmp->tab_tri[i].p3.y, 0.0f);
        glVertex3f(maintmp->tab_tri[iCpt].p1.x, maintmp->tab_tri[i].p1.y, 0.0f);
        glEnd();
    }
    glFlush();
}
//----------------------------------------------------------------------
