/***************************************************************
 * Name:      gertApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2016-06-17
 * Copyright:  ()
 * License:
 **************************************************************/

#include "gertApp.h"

//(*AppHeaders
#include "gertMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(gertApp);

bool gertApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	gertFrame* Frame = new gertFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
