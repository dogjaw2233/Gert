/***************************************************************
 * Name:      gertMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2016-06-21
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef GERTMAIN_H
#define GERTMAIN_H

//(*Headers(gertFrame)
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
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
        //*)

        //(*Identifiers(gertFrame)
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT1;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(gertFrame)
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        wxButton* Button1;
        wxStaticText* StaticText1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // GERTMAIN_H
