#include "openGLCanvas.h"
#include "mainframe.h"
#include <wx/event.h>
#include "triangle.h"
//----------------------------------------------------------------------
BEGIN_EVENT_TABLE(OpenGLCanvas, wxGLCanvas)    
	EVT_PAINT(OpenGLCanvas::OnPaint( wxPaintEvent& event);)
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
	wxPaintDC dc(this);
	SetCurrent();
	Draw();
	SwapBuffers();
}
//----------------------------------------------------------------------
void OpenGLCanvas::OnSize( wxSizeEvent& event )
{	
	wxGLCanvas::OnSize(event);

	int w, h;
	GetClientSize(&w, &h);
}
//----------------------------------------------------------------------
void OpenGLCanvas::OnEraseBackground( wxEraseEvent& event )
{
}
//----------------------------------------------------------------------
void OpenGLCanvas::Draw()
{
}
//----------------------------------------------------------------------
