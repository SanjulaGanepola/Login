#ifndef RECOVERY_H
#define RECOVERY_H

//(*Headers(Recovery)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class Recovery: public wxDialog
{
	public:

		Recovery(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);

		//(*Declarations(Recovery)
		wxButton* RecoverButton;
		wxPanel* UsernamePanel;
		wxPanel* EmailPanel;
		wxStaticBitmap* UsernameBitmap;
		wxStaticBitmap* EmailBitmap;
		wxStaticText* ForgotPasswordText;
		wxStaticText* InstructionText;
		wxTextCtrl* UsernameCtrl;
		wxTextCtrl* EmailCtrl;
		//*)

	protected:

		//(*Identifiers(Recovery)
		static const long ID_FORGOTPASSWORDTEXT;
		static const long ID_INSTRUCTIONTEXT;
		static const long ID_USERNAMEBITMAP;
		static const long ID_USERNAMECTRL;
		static const long ID_USERNAMEPANEL;
		static const long ID_EMAILBITMAP;
		static const long ID_EMAILCTRL;
		static const long ID_EMAILPANEL;
		static const long ID_RECOVERBUTTON;
		//*)

	private:

		//(*Handlers(Recovery)
		void OnRecoverButtonClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
