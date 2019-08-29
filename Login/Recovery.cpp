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
	wxFlexGridSizer* FlexGridSizer3;

	Create(parent, wxID_ANY, _("Forgot Account"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetBackgroundColour(wxColour(51, 50, 50, 1));
	FlexGridSizer1 = new wxFlexGridSizer(6, 1, 0, 0);
	wxFont ForgotPasswordTextFont(14, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, _T("Segoe UI Semibold"), wxFONTENCODING_DEFAULT);
	ForgotPasswordText = new wxStaticText(this, ID_FORGOTPASSWORDTEXT, _("Forgot Account"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_FORGOTPASSWORDTEXT"));
	ForgotPasswordText->SetFont(ForgotPasswordTextFont);
	ForgotPasswordText->SetForegroundColour(wxColour(255, 255, 255));
	FlexGridSizer1->Add(ForgotPasswordText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 8);
	wxFont InstructionTextFont(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, _T("Segoe UI Semibold"), wxFONTENCODING_DEFAULT);
	InstructionText = new wxStaticText(this, ID_INSTRUCTIONTEXT, _("Enter Email"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_INSTRUCTIONTEXT"));
	InstructionText->SetFont(InstructionTextFont);
	InstructionText->SetForegroundColour(wxColour(255, 255, 255));
	FlexGridSizer1->Add(InstructionText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 8);
	wxString emailLocation = wxStandardPaths::Get().GetResourcesDir() + wxT("/Email.png");
	EmailPanel = new wxPanel(this, ID_EMAILPANEL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_EMAILPANEL"));
	FlexGridSizer3 = new wxFlexGridSizer(0, 3, 0, 0);
	EmailBitmap = new wxStaticBitmap(EmailPanel, ID_EMAILBITMAP, wxBitmap(wxImage(emailLocation)), wxDefaultPosition, wxSize(wxImage(emailLocation).GetWidth() + 2, wxImage(emailLocation).GetHeight() + 6), wxSIMPLE_BORDER, _T("ID_EMAILBITMAP"));
	EmailBitmap->SetBackgroundColour(wxColour(*wxWHITE));
	FlexGridSizer3->Add(EmailBitmap, 1, wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 8);
	EmailCtrl = new wxTextCtrl(EmailPanel, ID_EMAILCTRL, wxEmptyString, wxDefaultPosition, wxSize(200, wxImage(emailLocation).GetHeight() + 6), 0, wxDefaultValidator, _T("ID_EMAILCTRL"));
	EmailCtrl->SetHint("Email");
	wxFont EmailCtrlTextFont(12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, _T("Segoe UI Semibold"), wxFONTENCODING_DEFAULT);
	EmailCtrl->SetFont(EmailCtrlTextFont);
	FlexGridSizer3->Add(EmailCtrl, 1, wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 8);
	EmailPanel->SetSizer(FlexGridSizer3);
	FlexGridSizer3->Fit(EmailPanel);
	FlexGridSizer3->SetSizeHints(EmailPanel);
	FlexGridSizer1->Add(EmailPanel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 8);
	RecoverButton = new wxButton(this, ID_RECOVERBUTTON, _("Recover"), wxDefaultPosition, wxDefaultSize, wxNO_BORDER, wxDefaultValidator, _T("ID_RECOVERBUTTON"));
	wxFont RecoverButtonFont(10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, _T("Segoe UI Semibold"), wxFONTENCODING_DEFAULT);
	RecoverButton->SetFont(RecoverButtonFont);
	RecoverButton->SetBackgroundColour(wxColour(65, 65, 65, 1));
	RecoverButton->SetForegroundColour(wxColour(255, 255, 255));
	FlexGridSizer1->Add(RecoverButton, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 8);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_RECOVERBUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Recovery::OnRecoverButtonClick);
	//*)
}

void Recovery::OnRecoverButtonClick(wxCommandEvent& event)
{
	if (!(EmailCtrl->IsEmpty()) && (EmailCtrl->GetValue()).Contains("@") && ((EmailCtrl->GetValue()).Contains(".com") || (EmailCtrl->GetValue()).Contains(".ca"))) {
		/***************************************************************
		 *INSERT CODE FOR SENDING EMAIL
		 **************************************************************/
		RecoverButton->SetId(wxOK);
		this->Close();
	}
	InstructionText->SetLabelText("Invalid Email");
}
