#include <wx/wx.h>
 
class prime : public wxApp
{
public:
    bool OnInit() override;
};
 
wxIMPLEMENT_APP(prime);
 
class pframe : public wxFrame
{
public:
    pframe();
 
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
};
 
enum
{
    ID_Hello = 1
};
 
bool prime::OnInit()
{
    pframe *frame = new pframe();
    frame->Show(true);
    return true;
}
 
pframe::pframe()
    : wxFrame(nullptr, wxID_ANY, "Hello World")
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
 
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
 
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
 
    SetMenuBar( menuBar );
 
    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");
 
    Bind(wxEVT_MENU, &pframe::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &pframe::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &pframe::OnExit, this, wxID_EXIT);
}
 
void pframe::OnExit(wxCommandEvent& event)
{
    Close(true);
}
 
void pframe::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}
 
void pframe::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}