#include "Recovery.h"

//(*InternalHeaders(Recovery)
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stdpaths.h>
//*)

//(*IdInit(Recovery)
const long Recovery::ID_FORGOTPASSWORDTEXT = wxNewId();
const long Recovery::ID_INSTRUCTIONTEXT = wxNewId();
const long Recovery::ID_USERNAMEBITMAP = wxNewId();
const long Recovery::ID_USERNAMECTRL = wxNewId();
const long Recovery::ID_USERNAMEPANEL = wxNewId();
const long Recovery::ID_EMAILBITMAP = wxNewId();
const long Recovery::ID_EMAILCTRL = wxNewId();
const long Recovery::ID_EMAILPANEL = wxNewId();
const long Recovery::ID_RECOVERBUTTON = wxNewId();
//*)

BEGIN_EVENT_TABLE(Recovery,wxDialog)
	//(*EventTable(Recovery)
	//*)
END_EVENT_TABLE()

Recovery::Recovery(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Recovery)
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer3;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	this->SetBackgroundColour(wxColour("#4693d8"));
	FlexGridSizer1 = new wxFlexGridSizer(7, 1, 0, 0);
	ForgotPasswordText = new wxStaticText(this, ID_FORGOTPASSWORDTEXT, _("Forgot Password"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont forgotPassword = ForgotPasswordText->GetFont();
	forgotPassword.SetPointSize(14);
	forgotPassword.MakeBold();
	ForgotPasswordText->SetFont(forgotPassword);
	FlexGridSizer1->Add(ForgotPasswordText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	InstructionText = new wxStaticText(this, ID_INSTRUCTIONTEXT, _("Enter Username and Email"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer1->Add(InstructionText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	UsernamePanel = new wxPanel(this, ID_USERNAMEPANEL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
	wxString usernameLocation = wxStandardPaths::Get().GetResourcesDir() + wxT("/Username.png");
	wxString emailLocation = wxStandardPaths::Get().GetResourcesDir() + wxT("/email.png");
	UsernameBitmap = new wxStaticBitmap(UsernamePanel, ID_USERNAMEBITMAP, wxBitmap(wxImage(usernameLocation)), wxDefaultPosition, wxSize(wxImage(usernameLocation).GetWidth() + 2, wxImage(usernameLocation).GetHeight() + 6), wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
	UsernameBitmap->SetBackgroundColour(wxColour(*wxWHITE));
	FlexGridSizer2->Add(UsernameBitmap, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	UsernameCtrl = new wxTextCtrl(UsernamePanel, ID_USERNAMECTRL, wxEmptyString, wxDefaultPosition, wxSize(200, wxImage(usernameLocation).GetHeight() + 6), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer2->Add(UsernameCtrl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	UsernamePanel->SetSizer(FlexGridSizer2);
	FlexGridSizer2->Fit(UsernamePanel);
	FlexGridSizer2->SetSizeHints(UsernamePanel);
	FlexGridSizer1->Add(UsernamePanel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	EmailPanel = new wxPanel(this, ID_EMAILPANEL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	FlexGridSizer3 = new wxFlexGridSizer(0, 3, 0, 0);
	EmailBitmap = new wxStaticBitmap(EmailPanel, ID_EMAILBITMAP, wxBitmap(wxImage(emailLocation)), wxDefaultPosition, wxSize(wxImage(emailLocation).GetWidth() + 2, wxImage(emailLocation).GetHeight() + 6), wxSIMPLE_BORDER, _T("ID_STATICBITMAP2"));
	EmailBitmap->SetBackgroundColour(wxColour(*wxWHITE));
	FlexGridSizer3->Add(EmailBitmap, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	EmailCtrl = new wxTextCtrl(EmailPanel, ID_EMAILCTRL, wxEmptyString, wxDefaultPosition, wxSize(200, wxImage(emailLocation).GetHeight() + 6), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	wxFont textBox = UsernameCtrl->GetFont();
	textBox.SetPointSize(12);
	UsernameCtrl->SetFont(textBox);
	EmailCtrl->SetFont(textBox);
	FlexGridSizer3->Add(EmailCtrl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	EmailPanel->SetSizer(FlexGridSizer3);
	FlexGridSizer3->Fit(EmailPanel);
	FlexGridSizer3->SetSizeHints(EmailPanel);
	FlexGridSizer1->Add(EmailPanel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	RecoverButton = new wxButton(this, ID_RECOVERBUTTON, _("Recover"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	RecoverButton->SetBackgroundColour(wxColour("#f8ec7d"));
	FlexGridSizer1->Add(RecoverButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_RECOVERBUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Recovery::OnRecoverButtonClick);
	//*)
}

void Recovery::OnRecoverButtonClick(wxCommandEvent& event)
{
	if (!(UsernameCtrl->IsEmpty() || EmailCtrl->IsEmpty())) {
		RecoverButton->SetId(wxID_OK);
		this->Close();
	}
	InstructionText->SetLabelText("Invalid Username or Email");
}
