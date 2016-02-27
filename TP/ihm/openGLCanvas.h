#ifndef __OPENGLCANVAS_H__
#define __OPENGLCANVAS_H__
#include <wx/glcanvas.h>
#include <wx/dcclient.h>
#include "wx/wx.h"
//----------------------------------------------------------------------
class OpenGLCanvas : public wxGLCanvas 
{
    public:
		OpenGLCanvas(wxWindow *parent, wxWindowID id,const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize,long style=0, const wxString& name=wxT("GLCANVAS"));
        ~OpenGLCanvas(void);

    private:
    int etape;
    void OnPaint( wxPaintEvent& event);
    void OnSize (wxSizeEvent& event);
    void OnEraseBackground( wxEraseEvent& event);
    void OnMouseMove (wxMouseEvent& event);
	void OnLeftDown (wxMouseEvent& event);
	void OnLeftUp (wxMouseEvent& event);
	DECLARE_EVENT_TABLE();
    void Draw();
};
    //ééé
#endif //__OPENGLCANVAS_H__
