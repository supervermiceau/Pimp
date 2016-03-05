#ifndef __DIALOGS_H__
#define __DIALOGS_H__
//----------------------------------------------------------------------
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include "mainframe.h"
#include <wx/colour.h>
//-------------------------VersionDialog--------------------------------
class VersionDialog: public wxDialog
{
public :
	VersionDialog(wxWindow *parent, wxWindowID id,const wxString &title);
private :
	DECLARE_EVENT_TABLE();
};
//------------------------EpaisseurDialog-------------------------------
class EpaisseurDialog: public wxDialog
{
public :
    EpaisseurDialog(wxWindow *parent, wxWindowID id,const wxString &title);
    //declaration du slider
    wxSlider *slider;
    void OnSlider(wxScrollEvent& event);
private :
	DECLARE_EVENT_TABLE();
};
//-----------------------CouleurDialog----------------------------------
class CouleurDialog: public wxDialog
{
public :
    CouleurDialog(wxWindow *parent, wxWindowID id,const wxString &title);
    //declaradion choix radio + lite
	wxRadioBox *radio;
	wxListBox *list;
	void OnRadio(wxCommandEvent& event);
private :
	DECLARE_EVENT_TABLE();
};
//-------------------------GestDialog-----------------------------------
class GestDialog: public wxDialog
{
public :
    GestDialog(wxWindow *parent, wxWindowID id,const wxString &title);
    //declaradion liste
    wxListBox *list;
    void Rafraichir();
    void OnProp(wxCommandEvent& event);
    void OnSupp(wxCommandEvent& event);
private :
	DECLARE_EVENT_TABLE();
};
//------------------------PropDialog------------------------------------
class PropDialog: public wxDialog
{
public :
	PropDialog(wxWindow *parent, wxWindowID id,const wxString &title);
    //declaradion 
    wxTextCtrl *TxtCtrl;
    wxSpinCtrl *epaisse;
    wxRadioBox *radio;
private :
	void OnRadio(wxCommandEvent& event);
	void OnSpin(wxSpinEvent& event);
	DECLARE_EVENT_TABLE();
};
#endif
