class Window : public wxFrame {
 public:
  Window(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxPoint(30, 30), wxSize(800, 600)) {
        connectKeyDownEvent(this);
    }
private:
    wxListBox* m_list = new wxListBox(this, wxID_ANY, wxPoint(30, 30), wxSize(300, 300));
    wxButton* m_button = new wxButton(this, wxID_ANY, "Submit", wxPoint(30, 370), wxSize(50, 20));
    wxTextCtrl* m_txt = new wxTextCtrl(this, wxID_ANY, " ", wxPoint(30, 330), wxSize(300, 30));
private:
  void connectKeyDownEvent(wxWindow* pclComponent) {
    if (pclComponent) {
      pclComponent->Bind(wxEVT_KEY_DOWN, &Window::onKeyDown, this);

      wxWindowListNode* pclNode = pclComponent->GetChildren().GetFirst();
      while (pclNode) {
        wxWindow* pclChild = pclNode->GetData();
        this->connectKeyDownEvent(pclChild);
        pclNode = pclNode->GetNext();
      }
    }
  }

  void onKeyDown(wxKeyEvent& event) {
    if (event.GetKeyCode() == WXK_ESCAPE) {
      std::exit(0);
    }
    event.Skip();
  }


};

