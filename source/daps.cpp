#include <gtkmm/window.h>
#include <gtkmm/main.h>
#include "daps.hpp"


MainWindow::MainWindow():
vbox_main(false,2),
notebook_main(),
table_notebook_dashboard(1,1,false),table_notebook_crypto_indexes_data(1,1,false),table_notebook_crypto_data(1,1,false),
lbl_notebook_dashboard("Dashboard"),lbl_notebook_crypto_indexes_data("Crypto Index Data"),lbl_notebook_crypto_data("Cryptocurrency Data"),
frame_crypto_indexes("Crypto Indexes"),frame_cryptos("Cryptocurrencies"),frame_daps_status("DAPS Status"),frame_api_status("API Status"),frame_database_status("Database Status"),frame_output("Command Output"),
grid_crypto_indexes(),grid_cryptos(),grid_daps_status(),grid_api_status(),grid_database_status(),grid_output(),
hbb_crypto_indexes(Gtk::BUTTONBOX_END,5),hbb_cryptos(Gtk::BUTTONBOX_END,5),
btn_crypto_indexes_edit("Edit"),btn_crypto_indexes_add("Add"),btn_crypto_indexes_remove("Remove"),
btn_cryptos_list("List"),btn_cryptos_add("Add"),btn_cryptos_remove("Remove"),
lbl_daps_status_localtime_title("Local Time: "),lbl_daps_status_localtime_value("-"),lbl_daps_status_utctime_title("UTC Time: "),lbl_daps_status_utctime_value("-"),lbl_daps_status_lastupdated_title("Last Updated: "),lbl_daps_status_lastupdated_value("-"),
lbl_api_status_title("API Status: "),lbl_api_status_value("-"),lbl_api_mcalls_title("Monthly Calls: "),lbl_api_mcalls_value("-"),lbl_api_dcalls_title("Daily Calls: "),lbl_api_dcalls_value("-"),
lbl_database_ci_status_title("IndexDB Status: "),lbl_database_ci_status_value("-"),lbl_database_cc_status_title("CryptoDB Status: "),lbl_database_cc_status_value("-"),
textview_output(),
topWins()
{
    set_title("Data Push Pull - Push and Pull Pricing Data");
    set_default_size(1200,800);
    set_modal(true);

    //Setting up main menu
    actiongroup_menu = Gtk::ActionGroup::create();
    //Main menu
    actiongroup_menu->add(Gtk::Action::create("MainMenu","Main"));
    actiongroup_menu->add(Gtk::Action::create("MainPreferences",Gtk::Stock::PREFERENCES),sigc::mem_fun(*this,&MainWindow::on_main_menu_preferences));
    actiongroup_menu->add(Gtk::Action::create("MainQuit",Gtk::Stock::QUIT),sigc::mem_fun(*this,&MainWindow::on_main_menu_quit));

    uimanager_menu = Gtk::UIManager::create();
    uimanager_menu->insert_action_group(actiongroup_menu);
    add_accel_group(uimanager_menu->get_accel_group());

    //Laying out actions in menubar
    Glib::ustring ui_info=
        "<ui>"
            "<menubar name='MenuBar'>"
                "<menu action='MainMenu'>"
                    "<menuitem action='MainPreferences'/>"
                    "<menuitem action='MainQuit'/>"
                "</menu>"
            "</menubar>"
        "</ui>";
    //Attempting to build menu
    try {
        uimanager_menu->add_ui_from_string(ui_info);
    } catch(const Glib::Error &ex) {
        std::cerr << "Building menu failed: " << ex.what();
    }
    Gtk::Widget *menubar_main = uimanager_menu->get_widget("/MenuBar");
    if(menubar_main) vbox_main.pack_start(*menubar_main,Gtk::PACK_SHRINK);

    vbox_main.pack_start(notebook_main,false,true,0);
    notebook_main.append_page(table_notebook_dashboard,lbl_notebook_dashboard);
    notebook_main.append_page(table_notebook_crypto_indexes_data,lbl_notebook_crypto_indexes_data);
    notebook_main.append_page(table_notebook_crypto_data,lbl_notebook_crypto_data);

    //Dashboard
    table_notebook_dashboard.attach(frame_crypto_indexes,0,1,0,3,Gtk::FILL,Gtk::FILL,3,3);
    table_notebook_dashboard.attach(frame_cryptos,1,2,0,3,Gtk::FILL,Gtk::FILL,3,3);
    table_notebook_dashboard.attach(frame_daps_status,2,3,0,1,Gtk::FILL,Gtk::FILL,3,3);
    table_notebook_dashboard.attach(frame_api_status,2,3,1,2,Gtk::FILL,Gtk::FILL,3,3);
    table_notebook_dashboard.attach(frame_database_status,2,3,2,3,Gtk::FILL,Gtk::FILL,3,3);
    table_notebook_dashboard.attach(frame_output,0,3,3,4,Gtk::FILL,Gtk::FILL,3,3);
    frame_crypto_indexes.set_hexpand(true);frame_crypto_indexes.set_vexpand(true);
    frame_crypto_indexes.set_margin_top(2);frame_crypto_indexes.set_margin_bottom(1);frame_crypto_indexes.set_margin_start(2);frame_crypto_indexes.set_margin_end(1);
    frame_crypto_indexes.set_label_align(0);
    frame_crypto_indexes.set_shadow_type(Gtk::SHADOW_ETCHED_IN);
    frame_crypto_indexes.set_size_request(500,600);
    frame_cryptos.set_hexpand(true);frame_cryptos.set_vexpand(true);
    frame_cryptos.set_margin_top(2);frame_cryptos.set_margin_bottom(1);frame_cryptos.set_margin_start(1);frame_cryptos.set_margin_end(1);
    frame_cryptos.set_label_align(0);
    frame_cryptos.set_size_request(500,600);
    frame_daps_status.set_hexpand(true);frame_daps_status.set_vexpand(true);
    frame_daps_status.set_margin_top(2);frame_daps_status.set_margin_bottom(1);frame_daps_status.set_margin_start(1);frame_daps_status.set_margin_end(2);
    frame_daps_status.set_label_align(0);
    frame_daps_status.set_size_request(200,200);
    frame_api_status.set_hexpand(true);frame_api_status.set_vexpand(true);
    frame_api_status.set_margin_top(1);frame_api_status.set_margin_bottom(1);frame_api_status.set_margin_start(1);frame_api_status.set_margin_end(2);
    frame_api_status.set_label_align(0);
    frame_api_status.set_size_request(200,200);
    frame_database_status.set_hexpand(true);frame_database_status.set_vexpand(true);
    frame_database_status.set_margin_top(1);frame_database_status.set_margin_bottom(1);frame_database_status.set_margin_start(1);frame_database_status.set_margin_end(2);
    frame_database_status.set_size_request(200,200);
    frame_output.set_hexpand(true);frame_output.set_vexpand(false);
    frame_output.set_margin_top(1);frame_output.set_margin_bottom(2);frame_output.set_margin_start(2);frame_output.set_margin_end(2);
    frame_output.set_label_align(0);
    frame_output.set_size_request(-1,200);

    //Frame crypto index
    frame_crypto_indexes.add(grid_crypto_indexes);
    grid_crypto_indexes.set_margin_top(5);grid_crypto_indexes.set_margin_bottom(5);grid_crypto_indexes.set_margin_start(5);grid_crypto_indexes.set_margin_end(5);
    grid_crypto_indexes.attach(sw_crypto_indexes,0,0,1,1);
    sw_crypto_indexes.set_hexpand(true);sw_crypto_indexes.set_vexpand(true);
    sw_crypto_indexes.set_policy(Gtk::POLICY_AUTOMATIC,Gtk::POLICY_AUTOMATIC);
    sw_crypto_indexes.add(tv_crypto_indexes);
    ls_crypto_indexes=Gtk::ListStore::create(m_columns_crypto_indexes);
    tv_crypto_indexes.set_model(ls_crypto_indexes);
    tv_crypto_indexes.append_column("Crypto Index",m_columns_crypto_indexes.m_col_crypto_index_name);
    tv_crypto_indexes.append_column("Price USD",m_columns_crypto_indexes.m_col_crypto_index_price_usd);
    tv_crypto_indexes.append_column("Price EUR",m_columns_crypto_indexes.m_col_crypto_index_price_eur);
    tv_crypto_indexes.append_column("Price BTC",m_columns_crypto_indexes.m_col_crypto_index_price_btc);
    tv_crypto_indexes.append_column("Price ETH",m_columns_crypto_indexes.m_col_crypto_index_price_eth);
    grid_crypto_indexes.attach(hbb_crypto_indexes,0,1,1,1);
    hbb_crypto_indexes.add(btn_crypto_indexes_edit);
    hbb_crypto_indexes.add(btn_crypto_indexes_add);
    hbb_crypto_indexes.add(btn_crypto_indexes_remove);

    frame_cryptos.add(grid_cryptos);
    grid_cryptos.set_margin_top(5);grid_cryptos.set_margin_bottom(5);grid_cryptos.set_margin_start(5);grid_cryptos.set_margin_end(5);
    grid_cryptos.attach(sw_cryptos,0,0,1,1);
    sw_cryptos.set_hexpand(true);sw_cryptos.set_vexpand(true);
    sw_cryptos.set_policy(Gtk::POLICY_AUTOMATIC,Gtk::POLICY_AUTOMATIC);
    sw_cryptos.add(tv_cryptos);
    ls_cryptos=Gtk::ListStore::create(m_columns_cryptos);
    tv_cryptos.set_model(ls_cryptos);
    tv_cryptos.append_column("Cryptocurrency",m_columns_cryptos.m_col_crypto_name);
    tv_cryptos.append_column("Price USD",m_columns_cryptos.m_col_crypto_price_usd);
    tv_cryptos.append_column("Price EUR",m_columns_cryptos.m_col_crypto_price_eur);
    tv_cryptos.append_column("Price BTC",m_columns_cryptos.m_col_crypto_price_btc);
    tv_cryptos.append_column("Price ETH",m_columns_cryptos.m_col_crypto_price_eth);
    grid_cryptos.attach(hbb_cryptos,0,1,1,1);
    hbb_cryptos.add(btn_cryptos_list);
    hbb_cryptos.add(btn_cryptos_add);
    hbb_cryptos.add(btn_cryptos_remove);

    //DAPS status
    frame_daps_status.add(grid_daps_status);
    grid_daps_status.set_margin_top(10);grid_daps_status.set_margin_bottom(10);grid_daps_status.set_margin_start(10);grid_daps_status.set_margin_end(10);
    grid_daps_status.set_column_homogeneous(false);
    grid_daps_status.attach(lbl_daps_status_localtime_title,0,0,1,1);
    grid_daps_status.attach(lbl_daps_status_localtime_value,1,0,1,1);
    grid_daps_status.attach(lbl_daps_status_utctime_title,0,1,1,1);
    grid_daps_status.attach(lbl_daps_status_utctime_value,1,1,1,1);
    grid_daps_status.attach(lbl_daps_status_lastupdated_title,0,2,1,1);
    grid_daps_status.attach(lbl_daps_status_lastupdated_value,1,2,1,1);
    lbl_daps_status_localtime_title.set_xalign(0);lbl_daps_status_localtime_title.set_margin_bottom(5);
    lbl_daps_status_localtime_value.set_xalign(0);lbl_daps_status_localtime_value.set_margin_bottom(5);lbl_daps_status_localtime_value.set_margin_start(5);
    lbl_daps_status_utctime_title.set_xalign(0);lbl_daps_status_utctime_title.set_margin_bottom(5);
    lbl_daps_status_utctime_value.set_xalign(0);lbl_daps_status_utctime_value.set_margin_bottom(5);lbl_daps_status_utctime_value.set_margin_start(5);
    lbl_daps_status_lastupdated_title.set_xalign(0);lbl_daps_status_lastupdated_title.set_margin_bottom(5);
    lbl_daps_status_lastupdated_value.set_xalign(0);lbl_daps_status_lastupdated_value.set_margin_bottom(5);lbl_daps_status_lastupdated_value.set_margin_start(5);

    //API status
    frame_api_status.add(grid_api_status);
    grid_api_status.set_margin_top(10);grid_api_status.set_margin_bottom(10);grid_api_status.set_margin_start(10);grid_api_status.set_margin_end(10);
    grid_api_status.set_column_homogeneous(false);
    grid_api_status.attach(lbl_api_status_title,0,0,1,1);
    grid_api_status.attach(lbl_api_status_value,1,0,1,1);
    grid_api_status.attach(lbl_api_mcalls_title,0,1,1,1);
    grid_api_status.attach(lbl_api_mcalls_value,1,1,1,1);
    grid_api_status.attach(lbl_api_dcalls_title,0,2,1,1);
    grid_api_status.attach(lbl_api_dcalls_value,1,2,1,1);
    lbl_api_status_title.set_xalign(0);lbl_api_status_title.set_margin_bottom(5);
    lbl_api_status_value.set_xalign(0);lbl_api_status_value.set_margin_bottom(5);lbl_api_status_value.set_margin_start(5);
    lbl_api_mcalls_title.set_xalign(0);lbl_api_mcalls_title.set_margin_bottom(5);
    lbl_api_mcalls_value.set_xalign(0);lbl_api_mcalls_value.set_margin_bottom(5);lbl_api_mcalls_value.set_margin_start(5);
    lbl_api_dcalls_title.set_xalign(0);lbl_api_dcalls_title.set_margin_bottom(5);
    lbl_api_dcalls_value.set_xalign(0);lbl_api_dcalls_value.set_margin_bottom(5);lbl_api_dcalls_value.set_margin_start(5);

    //Database status
    frame_database_status.add(grid_database_status);
    grid_database_status.set_margin_top(10);grid_database_status.set_margin_bottom(10);grid_database_status.set_margin_start(10);grid_database_status.set_margin_end(10);
    grid_database_status.set_column_homogeneous(false);
    grid_database_status.attach(lbl_database_ci_status_title,0,0,1,1);
    grid_database_status.attach(lbl_database_ci_status_value,1,0,1,1);
    grid_database_status.attach(lbl_database_cc_status_title,0,1,1,1);
    grid_database_status.attach(lbl_database_cc_status_value,1,1,1,1);
    lbl_database_ci_status_title.set_xalign(0);lbl_database_ci_status_title.set_margin_bottom(5);
    lbl_database_ci_status_value.set_xalign(0);lbl_database_ci_status_value.set_margin_bottom(5);lbl_database_ci_status_value.set_margin_start(5);
    lbl_database_cc_status_title.set_xalign(0);lbl_database_cc_status_title.set_margin_bottom(5);
    lbl_database_cc_status_value.set_xalign(0);lbl_database_cc_status_value.set_margin_bottom(5);lbl_database_cc_status_value.set_margin_start(5);

    //Command output
    frame_output.add(grid_output);
    grid_output.set_margin_top(5);grid_output.set_margin_bottom(5);grid_output.set_margin_start(5);grid_output.set_margin_end(5);
    grid_output.attach(sw_output,0,0,1,1);
    sw_output.set_hexpand(true);sw_output.set_vexpand(true);
    sw_output.set_policy(Gtk::POLICY_AUTOMATIC,Gtk::POLICY_AUTOMATIC);
    sw_output.add(textview_output);
    textview_output.set_editable(false);
    textview_output.set_cursor_visible(false);
    textview_output.set_top_margin(5);textview_output.set_bottom_margin(5);textview_output.set_left_margin(5);textview_output.set_right_margin(5);

    //Crypto indexes historical data window
    table_notebook_crypto_indexes_data.attach(sw_crypto_indexes_data,0,1,0,1);
    sw_crypto_indexes_data.set_policy(Gtk::POLICY_AUTOMATIC,Gtk::POLICY_AUTOMATIC);
    sw_crypto_indexes_data.add(tv_crypto_indexes_data);
    ls_crypto_indexes_data=Gtk::ListStore::create(m_columns_crypto_indexes_data);
    tv_crypto_indexes_data.set_model(ls_crypto_indexes_data);
    tv_crypto_indexes_data.append_column("Crypto Index",m_columns_crypto_indexes_data.m_col_crypto_index_name);
    tv_crypto_indexes_data.append_column("Crypto Index ID",m_columns_crypto_indexes_data.m_col_crypto_index_id);
    tv_crypto_indexes_data.append_column("Data Start Date",m_columns_crypto_indexes_data.m_col_crypto_index_startdate);
    tv_crypto_indexes_data.append_column("Data End Date",m_columns_crypto_indexes_data.m_col_crypto_index_enddate);
    tv_crypto_indexes_data.append_column("Status",m_columns_crypto_indexes_data.m_col_crypto_index_status);

    //Crypto historical data window
    table_notebook_crypto_data.attach(sw_crypto_data,0,1,0,1);
    sw_crypto_data.set_policy(Gtk::POLICY_AUTOMATIC,Gtk::POLICY_AUTOMATIC);
    sw_crypto_data.add(tv_crypto_data);
    ls_crypto_data=Gtk::ListStore::create(m_columns_crypto_data);
    tv_crypto_data.set_model(ls_crypto_data);
    tv_crypto_data.append_column("Cryptocurrency",m_columns_crypto_data.m_col_crypto_name);
    tv_crypto_data.append_column("Crypto ID",m_columns_crypto_data.m_col_crypto_id);
    tv_crypto_data.append_column("Data Start Date",m_columns_crypto_data.m_col_crypto_startdate);
    tv_crypto_data.append_column("Data End Date",m_columns_crypto_data.m_col_crypto_enddate);
    tv_crypto_data.append_column("Status",m_columns_crypto_data.m_col_crypto_status);

    //Signal handlers
    Glib::signal_timeout().connect(sigc::mem_fun(*this,&MainWindow::on_timeout),1000);
//    signal_show().connect(sigc::mem_fun(*this,&MainWindow::on_window_show));
    btn_crypto_indexes_edit.signal_clicked().connect(sigc::mem_fun(*this,&MainWindow::on_btn_crypto_indexes_edit_clicked));

    add(vbox_main);
    show_all_children();
}

MainWindow::~MainWindow() {
    for(vectTpWin::iterator i=topWins.begin(); i<topWins.end(); i++) {
        (*i) -> hide();
        delete(*i);
    }
}

void MainWindow::co_display_text(Glib::RefPtr<Gtk::TextBuffer> &refBuffer,std::string text) {
    auto iter = refBuffer->get_iter_at_offset(0);
    iter=refBuffer->insert(iter, text);

    //Word wrap
    /*
    Gtk::TextBuffer::iterator start, end;
    refBuffer->get_bounds(start, end);
    refBuffer->apply_tag_by_name("word_wrap", start, end);
    */
}

void MainWindow::on_window_show() {
    //Open initial window if no preferences file found or get values from preferences file
    boost::filesystem::path preferences_path("DAPSConfig.txt");
    if(!boost::filesystem::exists(preferences_path)) {
        InitialWindow *win=new InitialWindow(*this);
        topWins.push_back(win);
        win -> show();
        //Hide main window
        hide();
        return;
    } else {
        std::ifstream preferences_file("DAPSConfig.txt");
        //std::getline(preferences_file, VAR);
        preferences_file.close();
    }
}

bool MainWindow::on_timeout() {
    time_t rawTime;
    time(&rawTime);
    struct tm *timeInfo = localtime(&rawTime);
//    std::cout << "Current time is " << 1900+timeInfo->tm_year << " " << 1+timeInfo->tm_mon << " " << timeInfo->tm_mday << " " << timeInfo->tm_hour << ":" << timeInfo->tm_min << ":" << timeInfo->tm_sec << std::endl;

    auto refBuffer=textview_output.get_buffer();
    string strTime = "Current time is ";
    strTime.append(std::to_string(1900+timeInfo->tm_year));
    strTime.append(" ");
    strTime.append(std::to_string(1+timeInfo->tm_mon));
    strTime.append(" ");
    strTime.append(std::to_string(timeInfo->tm_mday));
    strTime.append(" ");
    strTime.append(std::to_string(timeInfo->tm_hour));
    strTime.append(":");
    strTime.append(std::to_string(timeInfo->tm_min));
    strTime.append(":");
    strTime.append(std::to_string(timeInfo->tm_sec));
    strTime.append("\n");
    co_display_text(refBuffer, strTime);

    return true;
}

void MainWindow::on_main_menu_preferences() {
    PreferencesWindow *win = new PreferencesWindow(*this);
    topWins.push_back(win);
    win->show();
}

void MainWindow::on_main_menu_quit() {
    Gtk::Main::quit();
}

void MainWindow::on_btn_crypto_indexes_edit_clicked() {
//    std::cout << "Hello World" << std::endl;
    auto refBuffer=textview_output.get_buffer();
//   textview_output=Gtk::make_managed<Gtk::TextView>(refBuffer);
    co_display_text(refBuffer, "Hello Graham\n");

}

void MainWindow::closeTopWindow(Gtk::Window &win, bool quit_program) {
    #if 1
        vectTpWin::iterator i=std::find(topWins.begin(),topWins.end(),&win);
    #else
        vectTpWin::iterator i=topWins.begin();
        while(i!=topWins.end()){
            if((*i)!=&win) i++;
            else break;
        }
    #endif
        if(i == topWins.end()){
            std::cerr << "Ref window not found" << std::endl;
            ::exit(1);
        }
        (*i)->hide();
        delete(*i);
        topWins.erase(i);

        //Checks if program should quit
        if(quit_program==true) Gtk::Main::quit();

        //Showing MainWindow
        MainWindow::show();
}
