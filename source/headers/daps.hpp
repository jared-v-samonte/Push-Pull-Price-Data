#ifndef _daps_hpp_included_
#define _daps_hpp_included_

#include <iostream>
#include <vector>
#include <fstream>

#include <gtkmm.h>
#include "boost/filesystem.hpp"
#include "../include/uint256_t/uint256_t.h"
#include "connection.hpp"
#include "initial.hpp"
#include "preferences.hpp"
#include "basicfunctions.hpp"

class MainWindow : public Gtk::Window {
    public:
        MainWindow();
        virtual ~MainWindow();

        void closeTopWindow(Gtk::Window &win, bool quit_program);

        //Menu controls
        Glib::RefPtr<Gtk::UIManager> uimanager_menu;
        Glib::RefPtr<Gtk::ActionGroup> actiongroup_menu;

        //Textview
        void co_display_text(Glib::RefPtr<Gtk::TextBuffer> &refBuffer,std::string text);

    private:
        typedef std::vector<Gtk::Window*> vectTpWin;
        vectTpWin topWins;

        //Main controls
//        Gtk::Table table_main;
        Gtk::VBox vbox_main;
        Gtk::Notebook notebook_main;
        Gtk::Table table_notebook_dashboard,table_notebook_crypto_indexes_data,table_notebook_crypto_data;
        Gtk::Label lbl_notebook_dashboard,lbl_notebook_crypto_indexes_data,lbl_notebook_crypto_data;

        //Dashboard
        Gtk::Frame frame_crypto_indexes,frame_cryptos,frame_daps_status,frame_api_status,frame_database_status,frame_output;

        //Crypto indexes
        Gtk::Grid grid_crypto_indexes;
        Gtk::ScrolledWindow sw_crypto_indexes;
        Gtk::TreeView tv_crypto_indexes;
        Glib::RefPtr<Gtk::ListStore> ls_crypto_indexes;

        class CryptoIndexesColumns : public Gtk::TreeModel::ColumnRecord{
            public:
                CryptoIndexesColumns()
                {add(m_col_crypto_index_name); add(m_col_crypto_index_price_usd); add(m_col_crypto_index_price_eur); add(m_col_crypto_index_price_btc); add(m_col_crypto_index_price_eth);}
                Gtk::TreeModelColumn<Glib::ustring> m_col_crypto_index_name;
                Gtk::TreeModelColumn<float> m_col_crypto_index_price_usd;
                Gtk::TreeModelColumn<float> m_col_crypto_index_price_eur;
                Gtk::TreeModelColumn<uint256_t> m_col_crypto_index_price_btc;
                Gtk::TreeModelColumn<uint256_t> m_col_crypto_index_price_eth;
        };
        CryptoIndexesColumns m_columns_crypto_indexes;

        Gtk::HButtonBox hbb_crypto_indexes;
        Gtk::Button btn_crypto_indexes_edit,btn_crypto_indexes_add,btn_crypto_indexes_remove;

        //Cryptos
        Gtk::Grid grid_cryptos;
        Gtk::ScrolledWindow sw_cryptos;
        Gtk::TreeView tv_cryptos;
        Glib::RefPtr<Gtk::ListStore> ls_cryptos;

        class CryptosColumns : public Gtk::TreeModel::ColumnRecord{
            public:
                CryptosColumns()
                {add(m_col_crypto_name); add(m_col_crypto_price_usd); add(m_col_crypto_price_eur); add(m_col_crypto_price_btc); add(m_col_crypto_price_eth);}
                Gtk::TreeModelColumn<Glib::ustring> m_col_crypto_name;
                Gtk::TreeModelColumn<float> m_col_crypto_price_usd;
                Gtk::TreeModelColumn<float> m_col_crypto_price_eur;
                Gtk::TreeModelColumn<uint256_t> m_col_crypto_price_btc;
                Gtk::TreeModelColumn<uint256_t> m_col_crypto_price_eth;
        };
        CryptosColumns m_columns_cryptos;

        Gtk::HButtonBox hbb_cryptos;
        Gtk::Button btn_cryptos_list,btn_cryptos_add,btn_cryptos_remove;

        //DAPS Status
        Gtk::Grid grid_daps_status;
        Gtk::Label lbl_daps_status_localtime_title,lbl_daps_status_localtime_value,lbl_daps_status_utctime_title,lbl_daps_status_utctime_value,lbl_daps_status_lastupdated_title,lbl_daps_status_lastupdated_value;

        //API Status
        Gtk::Grid grid_api_status;
        Gtk::Label lbl_api_status_title,lbl_api_status_value,lbl_api_mcalls_title,lbl_api_mcalls_value,lbl_api_dcalls_title,lbl_api_dcalls_value;

        //Database Status
        Gtk::Grid grid_database_status;
        Gtk::Label lbl_database_ci_status_title,lbl_database_ci_status_value,lbl_database_cc_status_title,lbl_database_cc_status_value;

        //Command output
        Gtk::Grid grid_output;
        Gtk::ScrolledWindow sw_output;
        Gtk::TextView textview_output;

        //Crypto indexes data
        Gtk::ScrolledWindow sw_crypto_indexes_data;
        Gtk::TreeView tv_crypto_indexes_data;
        Glib::RefPtr<Gtk::ListStore> ls_crypto_indexes_data;

        class CryptoIndexesDataColumns : public Gtk::TreeModel::ColumnRecord{
            public:
                CryptoIndexesDataColumns()
                {add(m_col_crypto_index_name); add(m_col_crypto_index_id); add(m_col_crypto_index_startdate); add(m_col_crypto_index_enddate); add(m_col_crypto_index_status);}
                Gtk::TreeModelColumn<Glib::ustring> m_col_crypto_index_name;
                Gtk::TreeModelColumn<unsigned int> m_col_crypto_index_id;
                Gtk::TreeModelColumn<Glib::ustring> m_col_crypto_index_startdate;
                Gtk::TreeModelColumn<Glib::ustring> m_col_crypto_index_enddate;
                Gtk::TreeModelColumn<Glib::ustring> m_col_crypto_index_status;
        };
        CryptoIndexesDataColumns m_columns_crypto_indexes_data;

        //Cryptocurrency data
        Gtk::ScrolledWindow sw_crypto_data;
        Gtk::TreeView tv_crypto_data;
        Glib::RefPtr<Gtk::ListStore> ls_crypto_data;

        class CryptoDataColumns : public Gtk::TreeModel::ColumnRecord{
            public:
                CryptoDataColumns()
                {add(m_col_crypto_name); add(m_col_crypto_id); add(m_col_crypto_startdate); add(m_col_crypto_enddate); add(m_col_crypto_status);}
                Gtk::TreeModelColumn<Glib::ustring> m_col_crypto_name;
                Gtk::TreeModelColumn<unsigned int> m_col_crypto_id;
                Gtk::TreeModelColumn<Glib::ustring> m_col_crypto_startdate;
                Gtk::TreeModelColumn<Glib::ustring> m_col_crypto_enddate;
                Gtk::TreeModelColumn<Glib::ustring> m_col_crypto_status;
        };
        CryptoDataColumns m_columns_crypto_data;

        //Signal handlers
        void on_window_show();
        bool on_timeout();

        void on_main_menu_preferences();
        void on_main_menu_quit();

        void on_btn_crypto_indexes_edit_clicked();
};

#endif
