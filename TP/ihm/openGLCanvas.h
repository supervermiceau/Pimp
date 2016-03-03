#ifndef __OPENGLCANVAS_H__
#define __OPENGLCANVAS_H__
#include <wx/glcanvas.h>
#include <wx/dcclient.h>
#include "wx/wx.h"
//----------------Classe OpenGLCanvas-----------------------------------
class OpenGLCanvas : public wxGLCanvas 
{
    public:
		OpenGLCanvas(wxWindow *parent, wxWindowID id,const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize,long style=0, const wxString& name=wxT("GLCANVAS"));
        ~OpenGLCanvas(void);

    private:
    int etape;
    wxMenu popup;
    wxMenu popup_tri;
    wxMenu *submenu1;
    wxMenu *submenu2;
    wxMenu *submenu3;
    wxMenuItem* propri;
    wxMenuItem* supprim;
    bool clic_busy_out;
    bool clic_busy_in;
	int selected_tri;
    void OnPaint( wxPaintEvent& event);
    void OnSize (wxSizeEvent& event);
    void OnEraseBackground( wxEraseEvent& event);
    void OnMouseMove (wxMouseEvent& event);
	void OnLeftDown (wxMouseEvent& event);
	void OnLeftUp (wxMouseEvent& event);
	void OnRightDown(wxMouseEvent& event);
	void OnContextSupp (wxCommandEvent& event);
	void OnContextPptes (wxCommandEvent& event);
	int IsItIn(int x, int y);
	int realX(int x);
	int realY(int x);
	DECLARE_EVENT_TABLE();
    void Draw();
};

#endif //__OPENGLCANVAS_H__
