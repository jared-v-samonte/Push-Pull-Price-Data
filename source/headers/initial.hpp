#ifndef _initial_hpp_included_
#define _initial_hpp_included_

#include <gtkmm.h>
#include "global.hpp"
#include "daps.hpp"

class MainWindow;

class InitialWindow : public Gtk::Window {
    public:
        InitialWindow(MainWindow &win);
        virtual ~InitialWindow();
    private:
        Gtk::Table table_main;
        Gtk::Frame frame_preferences,frame_crypto_data,frame_sync_nodes;
        Gtk::FileChooserButton fcb_preferences,fcb_crypto_data,fcb_sync_nodes;

        Gtk::HButtonBox hbb_main;
        Gtk::Button btn_ok,btn_quit;

        MainWindow *mw;

        void on_btn_ok_click();
        void on_btn_quit_click();
};

#endif
