/***************************************************************
 * Name:      gertMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2016-06-21
 * Copyright:  ()
 * License:
 **************************************************************/

#include "gertMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(gertFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(gertFrame)
const long gertFrame::ID_BUTTON1 = wxNewId();
const long gertFrame::ID_STATICTEXT1 = wxNewId();
const long gertFrame::ID_PANEL1 = wxNewId();
const long gertFrame::idMenuQuit = wxNewId();
const long gertFrame::idMenuAbout = wxNewId();
const long gertFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(gertFrame,wxFrame)
    //(*EventTable(gertFrame)
    //*)
END_EVENT_TABLE()

gertFrame::gertFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(gertFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxFlexGridSizer* FlexGridSizer1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(194,97));
    FlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(183,50), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1->SetMaxSize(wxSize(-1,-1));
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Click to enter phone number"), wxPoint(0,0), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Enter your phone number"), wxPoint(0,32), wxSize(184,16), 0, _T("ID_STATICTEXT1"));
    FlexGridSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    SetSizer(FlexGridSizer1);
    Layout();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gertFrame::OnButton1Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&gertFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&gertFrame::OnAbout);
    //*)
}
int phone1, phone2, phone3 = 0;
std::string pnum1, pnum2, pnum3, finum;
gertFrame::~gertFrame()
{
    //(*Destroy(gertFrame)
    //*)
}

void gertFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void gertFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void gertFrame::OnButton1Click(wxCommandEvent& event)
{
    phone1 = rand() % 899 + 100;
    phone3 = rand() % 899 + 100;
    phone2 = rand() % 8999 + 1000;
    pnum1 = std::to_string(phone1);
    pnum2 = std::to_string(phone2);
    pnum3 = std::to_string(phone3);
    finum = "(" + pnum3 + ") - " + pnum1 + " - " + pnum2;
    Button1->SetLabel(finum);
}
