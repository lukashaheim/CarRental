// #include "edit_car_page.h"
// #include "../../include/functions/editCar.h"

// EditCarPage::EditCarPage(SQLite::Database& db)
//     : db_ref(db)
// {
//     // Configure window
//     set_title("Edit car");
//     set_default_size(400, 400);
//
//     // Configure layout
//     vbox.set_spacing(10);
//     vbox.set_margin(10);
//
//     // Configure "on open" entries
//     entry_id.set_placeholder_text("Eks, 1");
//     vbox.append(entry_id_label);
//     vbox.append(button_load);
//     vbox.append(entry_id);
//
//     // Hide editing fields at first
//     entry_registration.set_visible(false);
//     entry_brand.set_visible(false);
//     entry_model.set_visible(false);
//     button_edit.set_visible(false);
//     entry_registration_label.set_visible(false);
//     entry_brand_label.set_visible(false);
//     entry_model_label.set_visible(false);
//
//     vbox.append(entry_registration_label);
//     vbox.append(entry_registration);
//     vbox.append(entry_brand_label);
//     vbox.append(entry_brand);
//     vbox.append(entry_model_label);
//     vbox.append(entry_model);
//     vbox.append(button_edit);
//     vbox.append(label_status);
//
//     entry_id.signal_changed().connect([this]() {
//         int id;
//         try {
//             id = std::stoi(entry_id.get_text());
//         } catch (...) {
//             // Invalid input: disable and hide everything
//             toggle_edit_fields(false);
//             label_status.set_text("Enter a valid ID");
//             return;
//         }
//
//         if (editCar_check(db_ref, id)) {
//             toggle_edit_fields(true);
//             label_status.set_text("Car found. You can edit it.");
//             current_id = id; // store it for later use
//         } else {
//             toggle_edit_fields(false);
//             label_status.set_text("Car ID not found.");
//         }
//     });
//
//
//     entry_registration.set_placeholder_text("Eks, A123456");
//     entry_brand.set_placeholder_text("Eks, Mercedes");
//     entry_model.set_placeholder_text("Eks, C-Class");
//
//     vbox.append(entry_registration_label);
//     vbox.append(entry_registration);
//     vbox.append(entry_brand_label);
//     vbox.append(entry_brand);
//     vbox.append(entry_model_label);
//     vbox.append(entry_model);
//
//     // Disable add button initially
//     button_edit.set_sensitive(false);
//
//     // Connect field validation
//     entry_registration.signal_changed().connect([this]() { validate_inputs(); });
//     entry_brand.signal_changed().connect([this]() { validate_inputs(); });
//     entry_model.signal_changed().connect([this]() { validate_inputs(); });
//
//     // Configure button behavior
//     button_edit.signal_clicked().connect([this] {
//         editCar(db_ref, entry_registration.get_text(), entry_brand.get_text(), entry_model.get_text());
//         label_status.set_text("Car added successfully!");
//     });
//
//     vbox.append(button_edit);
//
//     // Add status label
//     label_status.set_text("");
//     vbox.append(label_status);
//
//     // Final layout
//     set_child(vbox);
// }
//
// void EditCarPage::validate_inputs() {
//     bool all_filled =
//         !entry_registration.get_text().empty() &&
//         !entry_brand.get_text().empty() &&
//         !entry_model.get_text().empty();
//
//     button_edit.set_sensitive(all_filled);
//}