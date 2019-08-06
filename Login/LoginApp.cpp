/***************************************************************
 * Name:      LoginApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Sanjula ()
 * Created:   2019-08-01
 * Copyright: Sanjula ()
 * License:
 **************************************************************/

#include "LoginApp.h"

 //(*AppHeaders
#include "LoginMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(LoginApp);

bool LoginApp::OnInit()
{
	//(*AppInitialize
	bool wxsOK = true;
	wxInitAllImageHandlers();
	if (wxsOK)
	{
		LoginDialog Dlg(0);
		SetTopWindow(&Dlg);
		Dlg.ShowModal();
		wxsOK = false;
	}
	//*)
	return wxsOK;

}
