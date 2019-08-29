/***************************************************************
 * Name:      LoginMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Sanjula ()
 * Created:   2019-08-01
 * Copyright: Sanjula ()
 * License:
 **************************************************************/

#include "LoginMain.h"
#include "Recovery.h"
#include "ResetPassword.h"
#include <wx/msgdlg.h>

 //(*InternalHeaders(LoginDialog)
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stdpaths.h>
//*)

//helper functions
enum wxbuildinfoformat {
	short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
	wxString wxbuild(wxVERSION_STRING);

	if (format == long_f)
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

//(*IdInit(LoginDialog)
const long LoginDialog::ID_WELCOMETEXT = wxNewId();
const long LoginDialog::ID_INSTRUCTIONTEXT = wxNewId();
const long LoginDialog::ID_USERNAMEBITMAP = wxNewId();
const long LoginDialog::ID_USERNAMECTRL = wxNewId();
const long LoginDialog::ID_USERNAMEPANEL = wxNewId();
const long LoginDialog::ID_PASSWORDBITMAP = wxNewId();
const long LoginDialog::ID_PASSWORDCTRL = wxNewId();
const long LoginDialog::ID_PASSWORDPANEL = wxNewId();
const long LoginDialog::ID_REMEMBERMECHECKBOX = wxNewId();
const long LoginDialog::ID_LOGINBUTTON = wxNewId();
const long LoginDialog::ID_FORGOTPASSWORDHYPERLINK = wxNewId();
//*)

BEGIN_EVENT_TABLE(LoginDialog, wxDialog)
//(*EventTable(LoginDialog)
//*)
END_EVENT_TABLE()

LoginDialog::LoginDialog(wxWindow* parent, wxWindowID id)
{
	//(*Initialize(LoginDialog)
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer3;

	Create(parent, wxID_ANY, _("Login"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetBackgroundColour(wxColour(51, 50, 50, 1));
	FlexGridSizer1 = new wxFlexGridSizer(7, 1, 0, 0);
	wxFont WelcomeTextFont(14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, _T("Segoe UI Semibold"), wxFONTENCODING_DEFAULT);
	WelcomeText = new wxStaticText(this, ID_WELCOMETEXT, _("Welcome"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_WELCOMETEXT"));
	WelcomeText->SetFont(WelcomeTextFont);
	WelcomeText->SetForegroundColour(wxColour(255, 255, 255));
	FlexGridSizer1->Add(WelcomeText, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 8);
	wxFont InstructionTextFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, _T("Segoe UI Semibold"), wxFONTENCODING_DEFAULT);
	InstructionText = new wxStaticText(this, ID_INSTRUCTIONTEXT, _("Enter Username and Password"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_INSTRUCTIONTEXT"));
	FlexGridSizer1->Add(InstructionText, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL | wxST_NO_AUTORESIZE, 8);
	InstructionText->SetFont(InstructionTextFont);
	InstructionText->SetForegroundColour(wxColour(255, 255, 255));
	UsernamePanel = new wxPanel(this, ID_USERNAMEPANEL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_USERNAMEPANEL"));
	FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
	wxString usernameLocation = wxStandardPaths::Get().GetResourcesDir() + wxT("/Username.png");
	wxString passwordLocation = wxStandardPaths::Get().GetResourcesDir() + wxT("/Password.png");
	UsernameBitmap = new wxStaticBitmap(UsernamePanel, ID_USERNAMEBITMAP, wxBitmap(wxImage(usernameLocation)), wxDefaultPosition, wxSize(wxImage(usernameLocation).GetWidth() + 2, wxImage(usernameLocation).GetHeight() + 6), wxSIMPLE_BORDER, _T("ID_USERNAMEBITMAP"));
	UsernameBitmap->SetBackgroundColour(wxColour(*wxWHITE));
	FlexGridSizer2->Add(UsernameBitmap, 1, wxLEFT | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 8);
	UsernameCtrl = new wxTextCtrl(UsernamePanel, ID_USERNAMECTRL, wxEmptyString, wxDefaultPosition, wxSize(200, wxImage(usernameLocation).GetHeight() + 6), 0, wxDefaultValidator, _T("ID_USERNAMECTRL"));
	UsernameCtrl->SetHint("Username");
	FlexGridSizer2->Add(UsernameCtrl, 1, wxRIGHT | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 8);
	UsernamePanel->SetSizer(FlexGridSizer2);
	FlexGridSizer2->Fit(UsernamePanel);
	FlexGridSizer2->SetSizeHints(UsernamePanel);
	FlexGridSizer1->Add(UsernamePanel, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 8);
	PasswordPanel = new wxPanel(this, ID_PASSWORDPANEL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PASSWORDPANEL"));
	FlexGridSizer3 = new wxFlexGridSizer(0, 3, 0, 0);
	PasswordBitmap = new wxStaticBitmap(PasswordPanel, ID_PASSWORDBITMAP, wxBitmap(wxImage(passwordLocation)), wxDefaultPosition, wxSize(wxImage(passwordLocation).GetWidth() + 2, wxImage(passwordLocation).GetHeight() + 6), wxSIMPLE_BORDER, _T("ID_PASSWORDBITMAP"));
	PasswordBitmap->SetBackgroundColour(wxColour(*wxWHITE));
	FlexGridSizer3->Add(PasswordBitmap, 1, wxLEFT | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 8);
	PasswordCtrl = new wxTextCtrl(PasswordPanel, ID_PASSWORDCTRL, wxEmptyString, wxDefaultPosition, wxSize(200, wxImage(passwordLocation).GetHeight() + 6), wxTE_PASSWORD, wxDefaultValidator, _T("ID_PASSWORDCTRL"));
	PasswordCtrl->SetHint("Password");
	wxFont UsernamePasswordCtrlTextFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, _T("Segoe UI Semibold"), wxFONTENCODING_DEFAULT);
	UsernameCtrl->SetFont(UsernamePasswordCtrlTextFont);
	PasswordCtrl->SetFont(UsernamePasswordCtrlTextFont);
	FlexGridSizer3->Add(PasswordCtrl, 1, wxRIGHT | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 8);
	PasswordPanel->SetSizer(FlexGridSizer3);
	FlexGridSizer3->Fit(PasswordPanel);
	FlexGridSizer3->SetSizeHints(PasswordPanel);
	FlexGridSizer1->Add(PasswordPanel, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 8);
	wxFont RememberMeTextFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, _T("Segoe UI Semibold"), wxFONTENCODING_DEFAULT);
	RememberMeCheckBox = new wxCheckBox(this, ID_REMEMBERMECHECKBOX, _("Remember Me"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_REMEMBERCHECKBOX"));
	RememberMeCheckBox->SetFont(RememberMeTextFont);
	RememberMeCheckBox->SetForegroundColour(wxColour(255, 255, 255));
	RememberMeCheckBox->SetValue(false);
	FlexGridSizer1->Add(RememberMeCheckBox, 1, wxALL |  wxALIGN_CENTER_VERTICAL, 8);
	LoginButton = new wxButton(this, ID_LOGINBUTTON, _("Login"), wxDefaultPosition, wxDefaultSize, wxNO_BORDER, wxDefaultValidator, _T("LOGINBUTTON"));
	wxFont LoginButtonFont(10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, _T("Segoe UI Semibold"), wxFONTENCODING_DEFAULT);
	LoginButton->SetFont(LoginButtonFont);
	LoginButton->SetBackgroundColour(wxColour(65, 65, 65, 1));
	LoginButton->SetForegroundColour(wxColour(255, 255, 255));
	FlexGridSizer1->Add(LoginButton, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 8);
	ForgotPasswordHyperLink = new wxHyperlinkCtrl(this, ID_FORGOTPASSWORDHYPERLINK, _("Forgot Account"), wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHL_CONTEXTMENU | wxHL_ALIGN_CENTRE | wxNO_BORDER, _T("ID_FORGOTPASSWORDHYPERLINK"));
	FlexGridSizer1->Add(ForgotPasswordHyperLink, 1, wxBOTTOM | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 8);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);
	
	Connect(ID_LOGINBUTTON, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&LoginDialog::OnLoginButtonClick);
	Connect(ID_FORGOTPASSWORDHYPERLINK, wxEVT_HYPERLINK, (wxObjectEventFunction)&LoginDialog::OnForgotPasswordHyperLinkClick);

	//Sample data
	originalData["User1"] = "Pass1";
	originalData["User2"] = "Pass2";
	originalData["User3"] = "Pass3";
	originalData["User4"] = "Pass4";
	//*)
}


void LoginDialog::OnLoginButtonClick(wxCommandEvent& event)
{
	for (std::map<std::string, std::string>::iterator it = originalData.begin();it != originalData.end();it++) {
		if (it->first == UsernameCtrl->GetValue() && it->second == PasswordCtrl->GetValue()) {
			this->Close();
			/***************************************************************
			 *INSERT CODE FOR AFTER LOGIN IS CORRECT
			 **************************************************************/
		}
	}
	InstructionText->SetLabelText("Invalid Username or Password");
}

void LoginDialog::OnForgotPasswordHyperLinkClick(wxCommandEvent& event)
{
	//Forgot Password
	Recovery temp_recovery(this);
	int recoverydlg = temp_recovery.ShowModal();
	std::string password = std::string(temp_recovery.EmailCtrl->GetValue());
	UsernameCtrl->Clear();
	PasswordCtrl->Clear();
		
	if (temp_recovery.RecoverButton->GetId()== wxOK) {
		ResetPassword temp_reset(this);
		int resetdlg = temp_reset.ShowModal();
	}
}