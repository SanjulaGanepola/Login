/***************************************************************
 * Name:      LoginMain.h
 * Purpose:   Defines Application Frame
 * Author:    Sanjula ()
 * Created:   2019-08-01
 * Copyright: Sanjula ()
 * License:
 **************************************************************/

#ifndef LOGINMAIN_H
#define LOGINMAIN_H

 //(*Headers(LoginDialog)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/hyperlink.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <map>;
//*)

class LoginDialog : public wxDialog
{
public:

	LoginDialog(wxWindow* parent, wxWindowID id = -1);

	std::map<std::string, std::string> originalData;

private:

	//(*Handlers(LoginDialog)
	void OnLoginButtonClick(wxCommandEvent& event);
	void OnForgotPasswordHyperLinkClick(wxCommandEvent& event);	
	//*)

	//(*Identifiers(LoginDialog)
	static const long ID_WELCOMETEXT;
	static const long ID_INSTRUCTIONTEXT;
	static const long ID_USERNAMEBITMAP;
	static const long ID_USERNAMECTRL;
	static const long ID_USERNAMEPANEL;
	static const long ID_PASSWORDBITMAP;
	static const long ID_PASSWORDCTRL;
	static const long ID_PASSWORDPANEL;
	static const long ID_REMEMBERMECHECKBOX;
	static const long ID_LOGINBUTTON;
	static const long ID_FORGOTPASSWORDHYPERLINK;
	//*)

	//(*Declarations(LoginDialog)
	wxButton* LoginButton;
	wxCheckBox* RememberMeCheckBox;
	wxHyperlinkCtrl* ForgotPasswordHyperLink;
	wxPanel* UsernamePanel;
	wxPanel* PasswordPanel;
	wxStaticBitmap* UsernameBitmap;
	wxStaticBitmap* PasswordBitmap;
	wxStaticText* WelcomeText;
	wxStaticText* InstructionText;
	wxTextCtrl* UsernameCtrl;
	wxTextCtrl* PasswordCtrl;
	//*)

	DECLARE_EVENT_TABLE()
};

#endif // LOGINMAIN_H
