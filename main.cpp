#include <gtkmm.h>
#include "src/views/main_menu.h"
#include <SQLiteCpp/SQLiteCpp.h>

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create();
    SQLite::Database db("CarRental.sqlite", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
    return app->make_window_and_run<MainWindow>(argc, argv, db);
}
