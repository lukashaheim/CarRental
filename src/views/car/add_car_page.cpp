#include "../../include/functions/addCar.h"
#include "add_car_page.h"

AddCarPage::AddCarPage(SQLite::Database& db)
    : db_ref(db)
{
    // Configure window
    set_title("Add car");
    set_default_size(400, 400);

    // Configure layout
    vbox.set_spacing(10);
    vbox.set_margin(10);

    // Configure entries

    entry_registration.set_placeholder_text("Eks, A123456");
    entry_brand.set_placeholder_text("Eks, Mercedes");
    entry_model.set_placeholder_text("Eks, C-Class");

    vbox.append(entry_registration_label);
    vbox.append(entry_registration);
    vbox.append(entry_brand_label);
    vbox.append(entry_brand);
    vbox.append(entry_model_label);
    vbox.append(entry_model);

    // Disable add button initially
    button_add.set_sensitive(false);

    // Connect field validation
    entry_registration.signal_changed().connect([this]() { validate_inputs(); });
    entry_brand.signal_changed().connect([this]() { validate_inputs(); });
    entry_model.signal_changed().connect([this]() { validate_inputs(); });

    // Configure button behavior
    button_add.signal_clicked().connect([this] {
        addCar(db_ref, entry_registration.get_text(), entry_brand.get_text(), entry_model.get_text());
        label_status.set_text("Car added successfully!");
    });

    vbox.append(button_add);

    // Add status label
    label_status.set_text("");
    vbox.append(label_status);

    // Final layout
    set_child(vbox);
}

void AddCarPage::validate_inputs() {
    bool all_filled =
        !entry_registration.get_text().empty() &&
        !entry_brand.get_text().empty() &&
        !entry_model.get_text().empty();

    button_add.set_sensitive(all_filled);
}