#ifndef __MULTIENTRYDIALOG_H
#define __MULTIENTRYDIALOG_H

#include <gtkmm.h>

class MultiEntryDialog : public Gtk::MessageDialog {
  public:
    // This constructor is identical to Gtk::MessageDialog
    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1MessageDialog.html
    MultiEntryDialog(Gtk::Window& parent,
                const Glib::ustring& message, 
                bool use_markup=false, 
                Gtk::MessageType type=Gtk::MESSAGE_OTHER, 
                Gtk::ButtonsType buttons=Gtk::BUTTONS_OK, 
                bool modal=false);

    // These methods are identical to those of the same name in Gtk::Entry
    // https://developer.gnome.org/gtkmm/stable/classGtk_1_1Entry.html
    void set_name_text (const Glib::ustring& text);
    void set_phone_text (const Glib::ustring& text);
    void set_email_text (const Glib::ustring& text);
    Glib::ustring get_name_text () const;
    Glib::ustring get_phone_text() const;
    Glib::ustring get_email_text() const;
  protected:
    Gtk::VBox* m_vbox;
    Gtk::HBox* m_hbox;
    
    Gtk::Label* label_name;
    Gtk::Entry* entry_name;

    Gtk::Label* label_phone;
    Gtk::Entry* entry_phone;

    Gtk::Label* label_email;
    Gtk::Entry* entry_email;
};
#endif
