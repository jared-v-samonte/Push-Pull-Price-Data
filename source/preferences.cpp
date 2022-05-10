#include "preferences.hpp"

PreferencesWindow::PreferencesWindow(MainWindow &win):
table_main(1,1,false),
hbb_main(Gtk::BUTTONBOX_END,5),
btn_ok(Gtk::Stock::OK),btn_cancel(Gtk::Stock::CANCEL),
mw(&win)
{
    set_title("Preferences");
    set_default_size(100,100);
    set_modal(true);


    table_main.attach(hbb_main,0,1,0,1);
    hbb_main.add(btn_ok);
    hbb_main.add(btn_cancel);

    add(table_main);
    show_all_children();
}

PreferencesWindow::~PreferencesWindow(){
}

void PreferencesWindow::on_window_show(){

}

void PreferencesWindow::on_btn_ok_click(){

    //Closing window
    mw->closeTopWindow(*this,false);
}

void PreferencesWindow::on_btn_cancel_click(){
    mw->closeTopWindow(*this,false);
}
