#ifndef RESETPASSWORD_H
#define RESETPASSWORD_H

//(*Headers(ResetPassword)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class ResetPassword: public wxDialog
{
	public:

		ResetPassword(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);

		//(*Declarations(ResetPassword)
		wxButton* ResetButton;
		wxPanel* TemporaryPasswordPanel;
		wxPanel* NewPasswordPanel;
		wxStaticBitmap* TemporaryPasswordBitmap;
		wxStaticBitmap* NewPasswordBitmap;
		wxStaticText* InstructionText;
		wxStaticText* ResetPasswordText;
		wxTextCtrl* TemporaryPasswordCtrl;
		wxTextCtrl* NewPasswordCtrl;
		//*)

	protected:

		//(*Identifiers(ResetPassword)
		static const long ID_RESETPASSWORDTEXT;
		static const long ID_INSTRUCTIONTEXT;
		static const long ID_TEMPORARYPASSWORDBITMAP;
		static const long ID_TEMPORARYPASSWORDCTRL;
		static const long ID_TEMPORARYPASSWORDPANEL;
		static const long ID_NEWPASSWORDBITMAP;
		static const long ID_NEWPASSWORDCTRL;
		static const long ID_NEWPASSWORDPANEL;
		static const long ID_RESETBUTTON;
		//*)

	private:

		//(*Handlers(ResetPassword)
		void OnResetButtonClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
