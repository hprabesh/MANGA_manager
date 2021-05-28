#include "multientrydialog.h"

MultiEntryDialog::MultiEntryDialog(Gtk::Window& parent,
                                    const Glib::ustring& message, 
                                    bool use_markup, 
                                    Gtk::MessageType type, 
                                    Gtk::ButtonsType buttons, 
                                    bool modal)
    : MessageDialog(parent, message, use_markup, type, buttons, modal), label_name{new Gtk::Label("Name")}, label_phone{new Gtk::Label("Phone")}, label_email{new Gtk::Label("Email")},
    entry_name{new Gtk::Entry{}},entry_phone{new Gtk::Entry{}}, entry_email{new Gtk::Entry{}}{
    Gtk::Box *vbox= Gtk::manage(new Gtk::VBox);
    Gtk::Box *hbox1= Gtk::manage(new Gtk::HBox);
    hbox1->pack_start(*label_name);
    hbox1->pack_start(*entry_name);
    vbox->pack_start(*hbox1);
    Gtk::Box *hbox2= Gtk::manage(new Gtk::HBox);
    hbox2->pack_start(*label_phone);
    hbox2->pack_start(*entry_phone);
    vbox->pack_start(*hbox2);
    Gtk::Box *hbox3= Gtk::manage(new Gtk::HBox);
    hbox3->pack_start(*label_email);
    hbox3->pack_start(*entry_email);
    vbox->pack_start(*hbox3);
    // box->
    get_content_area()->pack_start(*vbox);
    vbox->show_all();
    // m_vbox->show();

    } 

void MultiEntryDialog::set_name_text(const Glib::ustring& text){
    entry_name->set_text(text);
}
void MultiEntryDialog::set_phone_text(const Glib::ustring& text){
    entry_phone->set_text(text);
}
void MultiEntryDialog::set_email_text(const Glib::ustring& text){
    entry_email->set_text(text);
}

Glib::ustring MultiEntryDialog::get_name_text() const{
    return entry_name->get_text();
}
Glib::ustring MultiEntryDialog::get_phone_text() const{
    return entry_phone->get_text();
}
Glib::ustring MultiEntryDialog::get_email_text() const{
    return entry_email->get_text();
}