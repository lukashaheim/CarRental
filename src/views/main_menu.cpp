#include <iostream>

#include "main_menu.h"
#include "car/car_menu.h"

MainWindow::MainWindow(SQLite::Database& db)
    : db_ref(db)
{
    set_title("Car rental");
    set_default_size(800, 600);

    vbox.set_spacing(10);
    vbox.set_margin(10);

    // car menu button
    button_car_menu.signal_clicked().connect([this] {
        auto* car_window = new CarMenu(db_ref);
        car_window->present();
    });
    vbox.append(button_car_menu);


    // customer page button
    button_customer_page.signal_clicked().connect([this] {
        auto* car_window = new CarMenu(db_ref);
        car_window->present();
    });
    vbox.append(button_customer_page);


    // assign page button
    button_assign_page.signal_clicked().connect([this] {
        auto* car_window = new CarMenu(db_ref);
        car_window->present();
    });
    vbox.append(button_assign_page);

    // InpExp page button
    button_ImpExp_page.signal_clicked().connect([this] {
        auto* car_window = new CarMenu(db_ref);
        car_window->present();
    });
    vbox.append(button_ImpExp_page);


    set_child(vbox);
}