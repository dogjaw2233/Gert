/***************************************************************
 * Name:      gertMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2016-06-17
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef GERTMAIN_H
#define GERTMAIN_H

//(*Headers(gertFrame)
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/textctrl.h>
//*)

class gertFrame: public wxFrame
{
    public:

        gertFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~gertFrame();

    private:

        //(*Handlers(gertFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnToggleButton1Toggle(wxCommandEvent& event);
        //*)

        //(*Identifiers(gertFrame)
        static const long ID_txc1;
        static const long ID_TEXTCTRL2;
        static const long ID_TEXTCTRL3;
        static const long idMenuQuit;
        static const long ID_MENUITEM1;
        static const long ID_MENUITEM2;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(gertFrame)
        wxTextCtrl* TextCtrl3;
        wxStatusBar* StatusBar1;
        wxMenu* Menu3;
        wxMenuItem* MenuItem3;
        wxTextCtrl* TextCtrl1;
        wxMenuItem* MenuItem4;
        wxTextCtrl* TextCtrl2;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // GERTMAIN_H
