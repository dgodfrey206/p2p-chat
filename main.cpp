#include <iostream>
#include <wx/wx.h>
#include "Window.hpp"

class MyApp : public wxApp {
 public:
  bool OnInit() {
    Window* window = new Window(wxT("P2P Chat"));
    window->Show(true);
    return true;
  }
};

wxIMPLEMENT_APP(MyApp);