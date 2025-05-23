#ifndef CAR_MENU_H
#define CAR_MENU_H
#include <SQLiteCpp/SQLiteCpp.h>
#include <gtkmm.h>

class CarMenu : public Gtk::Window {
public:
    CarMenu(SQLite::Database& db);

protected:
    SQLite::Database& db_ref;
    Gtk::Box vbox { Gtk::Orientation::VERTICAL };
    Gtk::Label label;
    Gtk::Button button_addcar { "Add car" };
};


#endif //CAR_MENU_H
