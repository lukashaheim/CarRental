#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <gtkmm.h>
#include <SQLiteCpp/SQLiteCpp.h>

class MainWindow : public Gtk::Window {
public:
    MainWindow(SQLite::Database& db); // pass db into constructor

protected:
    SQLite::Database& db_ref; // hold the db

    Gtk::Box vbox { Gtk::Orientation::VERTICAL };

    Gtk::Button button_car_menu { "Go to Car page" };

    Gtk::Button button_customer_page { "Go to customer page" };

    Gtk::Button button_assign_page { "Go to assign page" };

    Gtk::Button button_ImpExp_page { "Go to Import/Export page" };
};

#endif // MAIN_MENU_H