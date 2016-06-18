/***************************************************************
 * Name:      gertMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2016-06-17
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
int phone = 0;
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
const long gertFrame::ID_txc1 = wxNewId();
const long gertFrame::ID_TEXTCTRL2 = wxNewId();
const long gertFrame::ID_TEXTCTRL3 = wxNewId();
const long gertFrame::idMenuQuit = wxNewId();
const long gertFrame::ID_MENUITEM1 = wxNewId();
const long gertFrame::ID_MENUITEM2 = wxNewId();
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

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(90,80));
    FlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
    TextCtrl1 = new wxTextCtrl(this, ID_txc1, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_txc1"));
    FlexGridSizer1->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    FlexGridSizer1->Add(TextCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    FlexGridSizer1->Add(TextCtrl3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu3 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu3, ID_MENUITEM1, _("back"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu3, ID_MENUITEM2, _("out"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem4);
    MenuBar1->Append(Menu3, _("jump"));
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

    Connect(ID_txc1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&gertFrame::OnQuit);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&gertFrame::OnQuit);
    Connect(ID_MENUITEM2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&gertFrame::OnButton1Click);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&gertFrame::OnAbout);
    //*)
}

gertFrame::~gertFrame()
{
    //(*Destroy(gertFrame)
    //*)
}

void gertFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}
virtual void TextCtrl1::SetMaxLength(4)
void gertFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void gertFrame::OnButton1Click(wxCommandEvent& event)
{Close();
}

void gertFrame::OnToggleButton1Toggle(wxCommandEvent& event)
{
    phone += 1;
}
