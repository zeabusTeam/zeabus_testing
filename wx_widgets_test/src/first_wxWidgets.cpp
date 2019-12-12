#include    <wx/frame.h> // include class/struct wxFrame
// reference https://docs.wxwidgets.org/stable/classwx_frame.html

#include    <wx/app.h> // include class/sturct wxApp
// reference https://docs.wxwidgets.org/trunk/classwx_app.html

class MyFrame : public wxFrame
{
    public:
        MyFrame( const wxString& title ) :
                wxFrame( NULL , wxID_ANY , title , wxDefaultPosition , wxSize( 300 , 100 ) )
        {

        };
};

// Below class will use to init application have application but don't have any frame
class MyApp : public wxApp
{

    public:
        // function OnInit will return continue (true) or not (false)
        // initialize the program
        bool OnInit()
        {
            MyFrame *first_frame = new MyFrame( wxT("FIRST") ); // Construct your frame
            first_frame->Show( true ); // show window title First

            MyFrame *second_frame = new MyFrame( wxT("SECOND") ); // Construct your frame
            second_frame->Show( true ); // show window title Second
            return true;
        } 

};

wxIMPLEMENT_APP( MyApp );
