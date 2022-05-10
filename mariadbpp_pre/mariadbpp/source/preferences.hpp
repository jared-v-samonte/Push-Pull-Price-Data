#ifndef _preferences_hpp_included_
#define _preferences_hpp_included_

#include <gtkmm.h>
#include "global.hpp"
#include "daps.hpp"

class MainWindow;

class PreferencesWindow : public Gtk::Window {
    public:
        PreferencesWindow(MainWindow &win);
        virtual ~PreferencesWindow();
    private:
        Gtk::Table table_main;

        Gtk::HButtonBox hbb_main;
        Gtk::Button btn_ok,btn_cancel;

        MainWindow *mw;

        void on_window_show();
        void on_btn_ok_click();
        void on_btn_cancel_click();
};

#endif
