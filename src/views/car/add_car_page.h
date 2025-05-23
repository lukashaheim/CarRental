#ifndef ADD_CAR_PAGE_H
#define ADD_CAR_PAGE_H

#include <../../../../cmake-build-debug-visual-studio/vcpkg_installed/x64-windows/include/gtkmm-4.0/gtkmm.h>
#include <../../../../sqlitecpp/include/SQLiteCpp/SQLiteCpp.h>

class AddCarPage : public Gtk::Window {
public:
    AddCarPage(SQLite::Database& db);

protected:
    SQLite::Database& db_ref;

    Gtk::Box vbox {Gtk::Orientation::VERTICAL};
    Gtk::Entry entry_registration;
    Gtk::Label entry_registration_label { "Enter registration:" };
    Gtk::Entry entry_brand;
    Gtk::Label entry_brand_label { "Enter brand:" };
    Gtk::Entry entry_model;
    Gtk::Label entry_model_label { "Enter model:" };

    Gtk::Button button_add {"Add Car"};
    Gtk::Label label_status;

    void validate_inputs(); // Validate input before allowing to add a car
};



#endif //ADD_CAR_PAGE_H
