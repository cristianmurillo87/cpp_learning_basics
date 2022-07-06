//
//  main.cpp
//  mediator-pattern
//
//  Created by Cristian on 15/04/22.
//

#include <iostream>

class Mediator
{
public:
    virtual void mediate(const std::string &event) = 0;
};

class InterfaceElement
{
protected:
    Mediator *mediator;
    std::string name;
    bool is_visible = true;
public:
    InterfaceElement(const std::string &name, bool is_visible,
        Mediator *mediator):
    name(name), is_visible(is_visible), mediator(mediator) {};
    
    void set_visible(bool is_visible)
    {
        this->is_visible = is_visible;
    }
    
    std::string get_description()
    {
        return is_visible
            ? name + " is visible"
            : name + " is not visible";
    }
};

class ButtonElement: public InterfaceElement
{
public:
    ButtonElement(const std::string &name, bool is_visible, Mediator *mediator):
        InterfaceElement(name, is_visible, mediator) {};
    virtual ~ButtonElement() {};
    virtual void click()
    {
        mediator->mediate(name + " clicked");
    };
};

class TextBox: public InterfaceElement
{
    std::string text_value = "";
public:
    TextBox(const std::string &name, bool is_visible, Mediator *mediator):
        InterfaceElement(name, is_visible, mediator) {};
    virtual ~TextBox() {};
    virtual void change_text(const std::string &new_value)
    {
        text_value = new_value;
        mediator->mediate(name + " is " + (new_value.empty() ? "" : " not ")
                          + " empty");
    };
};

class CheckBox: public InterfaceElement
{
    bool checked = false;
public:
    CheckBox(const std::string &name, bool is_visible, Mediator *mediator):
        InterfaceElement(name, is_visible, mediator) {};
    virtual ~CheckBox() {};
    virtual void set_checked(bool checked)
    {
        this->checked = checked;
        mediator->mediate(name + " is " + (checked ? "checked" : "unchecked"));
    };
};

class UserInterface: public Mediator
{
    TextBox *name_textbox;
    CheckBox *is_married_checkbox;
    TextBox *spouse_name_textbox;
    ButtonElement *submit_button;
public:
    UserInterface()
    {
        name_textbox = new TextBox("Name textbox", true, this);
        is_married_checkbox = new CheckBox("Is married checkbox", true, this);
        spouse_name_textbox = new TextBox("Spouse's name text box", false, this);
        submit_button = new ButtonElement("Submit button", false, this);
    }
    
    ~UserInterface()
    {
        delete name_textbox;
        delete is_married_checkbox;
        delete spouse_name_textbox;
        delete submit_button;
    }
    
    void mediate(const std::string &event) override
    {
        std::cout << "Mediating event: " << event << "....\n";
        
        if (event == "Name textbox is empty")
        {
            submit_button->set_visible(false);
        } else if (event == "Name textbox is not empty")
        {
            submit_button->set_visible(true);
        } else if (event == "Is married checkbox is checked")
        {
            spouse_name_textbox->set_visible(true);
        } else if (event == "Is married checkbox is unchecked")
        {
            spouse_name_textbox->set_visible(false);
        } else if (event == "Submit button clicked")
        {
            std::cout << "Submitted\n";
        } else
        {
            std::cout << "Unrecongnized event" << std::endl;
        }
    }
    
    TextBox *get_name_textbox() {return name_textbox; };
    CheckBox *get_is_married_checkbox() {return is_married_checkbox; };
    TextBox *get_spouse_textbox() {return spouse_name_textbox; };
    ButtonElement *get_submit_button() {return submit_button;};
};


int main(int argc, const char * argv[]) {
    UserInterface *ui = new UserInterface();
    
    InterfaceElement *elements[] = {
        ui->get_name_textbox(),
        ui->get_is_married_checkbox(),
        ui->get_spouse_textbox(),
        ui->get_submit_button()
    };
    
    for(auto element: elements)
    {
        std::cout << element->get_description() << std::endl;
    }
    
    ui->get_is_married_checkbox()->set_checked(true);
    
    for(auto element: elements)
    {
        std::cout << element->get_description() << std::endl;
    }
    
    delete ui;
    return 0;
}
