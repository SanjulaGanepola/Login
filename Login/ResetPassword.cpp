#include "ResetPassword.h"

//(*InternalHeaders(ResetPassword)
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stdpaths.h>
//*)

//(*IdInit(ResetPassword)
const long ResetPassword::ID_RESETPASSWORDTEXT = wxNewId();
const long ResetPassword::ID_INSTRUCTIONTEXT = wxNewId();
const long ResetPassword::ID_TEMPORARYPASSWORDBITMAP = wxNewId();
const long ResetPassword::ID_TEMPORARYPASSWORDCTRL = wxNewId();
const long ResetPassword::ID_TEMPORARYPASSWORDPANEL = wxNewId();
const long ResetPassword::ID_NEWPASSWORDBITMAP = wxNewId();
const long ResetPassword::ID_NEWPASSWORDCTRL = wxNewId();
const long ResetPassword::ID_NEWPASSWORDPANEL = wxNewId();
const long ResetPassword::ID_RESETBUTTON = wxNewId();
//*)

BEGIN_EVENT_TABLE(ResetPassword,wxDialog)
	//(*EventTable(ResetPassword)
	//*)
END_EVENT_TABLE()

ResetPassword::ResetPassword(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(ResetPassword)
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer4;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(5, 0, 0, 0);
	ResetPasswordText = new wxStaticText(this, ID_RESETPASSWORDTEXT, _("Reset Password"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_RESETPASSWORDTEXT"));
	wxFont resetPassword = ResetPasswordText->GetFont();
	resetPassword.SetPointSize(14);
	resetPassword.MakeBold();
	ResetPasswordText->SetFont(resetPassword);
	FlexGridSizer1->Add(ResetPasswordText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	InstructionText = new wxStaticText(this, ID_INSTRUCTIONTEXT, _("Retrieve Temporary Email Password"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_INSTRUCTIONTEXT"));
	FlexGridSizer1->Add(InstructionText, 1, wxALL | wxALIGN_CENTER_HORIZONTAL | wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
	wxString TemporaryPasswordLocation = wxStandardPaths::Get().GetResourcesDir() + wxT("/TemporaryPassword.png");
	wxString newPasswordLocation = wxStandardPaths::Get().GetResourcesDir() + wxT("/Password.png");
	TemporaryPasswordPanel = new wxPanel(this, ID_TEMPORARYPASSWORDPANEL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_TEMPORARYPASSWORDPANEL"));
	FlexGridSizer3 = new wxFlexGridSizer(0, 3, 0, 0);
	TemporaryPasswordBitmap = new wxStaticBitmap(TemporaryPasswordPanel, ID_TEMPORARYPASSWORDBITMAP, wxBitmap(wxImage(TemporaryPasswordLocation)), wxDefaultPosition, wxSize(wxImage(TemporaryPasswordLocation).GetWidth() + 2, wxImage(TemporaryPasswordLocation).GetHeight() + 6), wxSIMPLE_BORDER, _T("ID_TEMPORARYPASSWORDBITMAP"));
	TemporaryPasswordBitmap->SetBackgroundColour(wxColour(*wxWHITE));
	FlexGridSizer3->Add(TemporaryPasswordBitmap, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	TemporaryPasswordCtrl = new wxTextCtrl(TemporaryPasswordPanel, ID_TEMPORARYPASSWORDCTRL, wxEmptyString, wxDefaultPosition, wxSize(200, wxImage(TemporaryPasswordLocation).GetHeight() + 6), wxTE_PASSWORD, wxDefaultValidator, _T("ID_TEMPORARYPASSWORDCTRL"));
	TemporaryPasswordCtrl->SetHint("Temporary Password");
	FlexGridSizer3->Add(TemporaryPasswordCtrl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	TemporaryPasswordPanel->SetSizer(FlexGridSizer3);
	FlexGridSizer3->Fit(TemporaryPasswordPanel);
	FlexGridSizer3->SetSizeHints(TemporaryPasswordPanel);
	FlexGridSizer1->Add(TemporaryPasswordPanel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	NewPasswordPanel = new wxPanel(this, ID_NEWPASSWORDPANEL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_NEWPASSWORDPANEL"));
	FlexGridSizer4 = new wxFlexGridSizer(0, 3, 0, 0);
	NewPasswordBitmap = new wxStaticBitmap(NewPasswordPanel, ID_NEWPASSWORDBITMAP, wxBitmap(wxImage(newPasswordLocation)), wxDefaultPosition, wxSize(wxImage(newPasswordLocation).GetWidth() + 2, wxImage(newPasswordLocation).GetHeight() + 6), wxSIMPLE_BORDER, _T("ID_NEWPASSWORDBITMAP"));
	NewPasswordBitmap->SetBackgroundColour(wxColour(*wxWHITE));
	FlexGridSizer4->Add(NewPasswordBitmap, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	NewPasswordCtrl = new wxTextCtrl(NewPasswordPanel, ID_NEWPASSWORDCTRL, wxEmptyString, wxDefaultPosition, wxSize(200, wxImage(newPasswordLocation).GetHeight() + 6), wxTE_PASSWORD, wxDefaultValidator, _T("ID_NEWPASSWORDCTRL"));
	NewPasswordCtrl->SetHint("New Password");
	wxFont textBox = TemporaryPasswordCtrl->GetFont();
	textBox.SetPointSize(12);
	TemporaryPasswordCtrl->SetFont(textBox);
	NewPasswordCtrl->SetFont(textBox);
	FlexGridSizer4->Add(NewPasswordCtrl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	NewPasswordPanel->SetSizer(FlexGridSizer4);
	FlexGridSizer4->Fit(NewPasswordPanel);
	FlexGridSizer4->SetSizeHints(NewPasswordPanel);
	FlexGridSizer1->Add(NewPasswordPanel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ResetButton = new wxButton(this, ID_RESETBUTTON, _("Reset"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RESETBUTTON"));
	FlexGridSizer1->Add(ResetButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_RESETBUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&ResetPassword::OnResetButtonClick);
	//*)
}

void ResetPassword::OnResetButtonClick(wxCommandEvent& event)
{
	if (!(TemporaryPasswordCtrl->IsEmpty() || NewPasswordCtrl->IsEmpty())) {
		/***************************************************************
		 *INSERT CODE FOR CHECKING IF TEMPORARY PASSWORD IS CORRECT
		 *INSERT CODE FOR RESETING PASSWORD
		 **************************************************************/
		this->Close();
	}
	InstructionText->SetLabelText("Invalid Temporary or New Password");
}
