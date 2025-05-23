#include <iostream>

#include "add_car_page.h"
#include "car_menu.h"

CarMenu::CarMenu(SQLite::Database& db)
: db_ref(db)
{
    set_title("Car Menu");
    set_default_size(800, 600);

    label.set_label("This is the Car Menu");
    vbox.append(label);

    // Add car button
    button_addcar.signal_clicked().connect([this] {
        auto* car_window = new AddCarPage(db_ref);
        car_window->present();
    });
    vbox.append(button_addcar);

    set_child(vbox);
}