#include "initial.hpp"


InitialWindow::InitialWindow(MainWindow &win):
table_main(1,1,false),
frame_preferences("Select Preferences File"),frame_crypto_data("Select Cryptocurrency Database File"),frame_sync_nodes("Select Synchronization Nodes File"),
fcb_preferences("Select Preferences File"),fcb_crypto_data("Select Cryptocurrency Database File"),fcb_sync_nodes("Select Synchronization Nodes File"),
hbb_main(Gtk::BUTTONBOX_END,5),
btn_ok(Gtk::Stock::OK),btn_quit(Gtk::Stock::QUIT),
mw(&win)
{
    //Window options
    set_title("Set Initial Options");
//    set_border_width(5);
    set_default_size(300,-1);
    set_modal(true);
    set_keep_above(true);
    set_resizable(false);
    set_deletable(false);

    //Window components
    table_main.attach(frame_preferences,0,1,0,1,Gtk::FILL,Gtk::FILL,3,3);
    frame_preferences.add(fcb_preferences);
    fcb_preferences.set_hexpand(true);
    fcb_preferences.set_margin_top(5);fcb_preferences.set_margin_bottom(5);fcb_preferences.set_margin_start(5);fcb_preferences.set_margin_end(5);

    table_main.attach(frame_crypto_data,0,1,1,2,Gtk::FILL,Gtk::FILL,3,3);
    frame_crypto_data.add(fcb_crypto_data);
    fcb_crypto_data.set_hexpand(true);
    fcb_crypto_data.set_margin_top(5);fcb_crypto_data.set_margin_bottom(5);fcb_crypto_data.set_margin_start(5);fcb_crypto_data.set_margin_end(5);

    table_main.attach(frame_sync_nodes,0,1,2,3,Gtk::FILL,Gtk::FILL,3,3);
    frame_sync_nodes.add(fcb_sync_nodes);
    fcb_sync_nodes.set_hexpand(true);
    fcb_sync_nodes.set_margin_top(5);fcb_sync_nodes.set_margin_bottom(5);fcb_sync_nodes.set_margin_start(5);fcb_sync_nodes.set_margin_end(5);

    table_main.attach(hbb_main,0,1,3,4,Gtk::FILL,Gtk::FILL,3,3);
    hbb_main.add(btn_ok);
    hbb_main.add(btn_quit);

    //Signal handlers
    btn_ok.signal_clicked().connect(sigc::mem_fun(*this,&InitialWindow::on_btn_ok_click));
    btn_quit.signal_clicked().connect(sigc::mem_fun(*this,&InitialWindow::on_btn_quit_click));

    add(table_main);
    show_all_children();
}

InitialWindow::~InitialWindow(){
}

void InitialWindow::on_btn_ok_click(){

    //Closing window
    mw->closeTopWindow(*this,false);
}

void InitialWindow::on_btn_quit_click(){
    mw->closeTopWindow(*this,true);
}
