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
    //~ glBegin(GL_TRIANGLES);
    //~ 
    	//~ glVertex2f(0.0f, 0.0f);
		//~ glVertex2f(0.0f, 100.0f);
		//~ glVertex2f(100.0f, 0.0f);
		//~ glColor3f(255,255,0);
		//~ glEnd();
    glFlush();
}
//----------------------------------------------------------------------
void OpenGLCanvas::OnMouseMove (wxMouseEvent& event)
{
	int iTmp,iNbTri;
    CMainFrame* main_frame =(CMainFrame*)GetParent();
 
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
		printf(" 1 \n");
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
		printf(" 2 \n");
        glBegin(GL_TRIANGLES);
        glVertex2f(main_frame->tab_tri[iNbTri]->p1.x, main_frame->tab_tri[iNbTri]->p1.y);
        glVertex2f(main_frame->tab_tri[iNbTri]->p2.x, main_frame->tab_tri[iNbTri]->p2.y);
        glVertex2i(realX(event.GetX()), realY(event.GetY()));
        glEnd();
        printf(" 3 \n");
        glColor3f(0.0f,0.0f,0.0f);
        glBegin(GL_LINES);
        glVertex2f(main_frame->tab_tri[iNbTri]->p1.x, main_frame->tab_tri[iNbTri]->p1.y);
        glVertex2f(main_frame->tab_tri[iNbTri]->p2.x, main_frame->tab_tri[iNbTri]->p2.y);
        glVertex2f(main_frame->tab_tri[iNbTri]->p2.x, main_frame->tab_tri[iNbTri]->p2.y);
        printf(" 4 \n");
        glVertex2i(realX(event.GetX()), realY(event.GetY()));
        glVertex2i(realX(event.GetX()), realY(event.GetY()));
        printf(" 5 \n");
        glVertex2f(main_frame->tab_tri[iNbTri]->p1.x, main_frame->tab_tri[iNbTri]->p1.y);
        glEnd();
    }
    printf(" 6 \n");
    glFlush();
    SwapBuffers();
}
//----------------------------------------------------------------------
void OpenGLCanvas::OnLeftDown (wxMouseEvent& event)
{
	CMainFrame* main_frame =(CMainFrame*)GetParent();
    wxMenuBar* menu=main_frame->GetMenuBar();
    
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
			printf(" 0 1 \n");
            main_frame->tab_tri[nbtri]->p1.x = realX(event.GetX());
            printf(" 0 2 \n");
            main_frame->tab_tri[nbtri]->p1.y = realY(event.GetY());
            printf(" 0 3 \n");
            etape ++;
            printf(" 0 4 \n");
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
            main_frame->wCouleurCourante=wxBLACK;
            glColor3i(main_frame->wCouleurCourante->Red(),main_frame->wCouleurCourante->Green(),main_frame->wCouleurCourante->Blue());
            main_frame->num_tri++;
            menu->Enable(MENU_MANAGE, true);
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
