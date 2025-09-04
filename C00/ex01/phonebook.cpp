#include "phonebook.hpp"

// Contact::Contact() {
//     _first_name = "";
//     _last_name = "";
//     _nickname = "";
//     _phone_number = "";
//     _darkest_secret = "";
// }

// PhoneBook::PhoneBook()
// {
//     _last = -1;
//     _total = 0;
//     std::cout << "Welcome to your new PhoneBook!";
// }

bool    is_numeric(std::string str)
{
    int len;

    len = str.length();
    for (int i = 0; i < len; i++)
    {
        if (!std::isdigit(str[i]))
            return (false);
    }
    return (true);
}

std::string truncate_to_width(std::string str)
{
    std::string truncated;

    if (str.length() <= COLUMN_WIDTH)
        return (str);
    truncated = str.substr(0, 9) + ".";
    return (truncated);
}

void    PhoneBook::print_contacts()
    {
        std::string str_input;
        int selected_contact;

        std::cout << "** Contacts **" << std::endl;
        std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|" << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << std::endl;
        for (int i = 0; i < 40; i++)
        {
            if (i > 0 && i % 10 == 0)
                std::cout << "|";
            std::cout << "_";
        }
        std::cout << std::endl;
        if (_total == 0)
            return ;
        for (int i = 0; i < _total; i++)
            std::cout << std::setw(COLUMN_WIDTH) << i << "|" << std::setw(COLUMN_WIDTH)
            << truncate_to_width(_contacts[i].get_first_name()) << "|" << std::setw(COLUMN_WIDTH)
            << truncate_to_width(_contacts[i].get_last_name()) << "|" << std::setw(COLUMN_WIDTH)
            << truncate_to_width(_contacts[i].get_nickname()) << std::endl;
        std::cout << std::endl;
        std::cout << "Indicate index of contact to display details" << std::endl;
        selected_contact = -1;
        while (true)
        {
            std::getline(std::cin, str_input);
            if (is_numeric(str_input))
            {
                selected_contact = std::stoi(str_input);
                if (selected_contact >= 0 && selected_contact < _total)
                    break ;
            }
            std::cout << "Error: Input number between 0 and " << _total - 1 << std::endl;
        }
        std::cout << "** Details for [" << selected_contact << "] **" << std::endl;
        std::cout << "First Name: " << _contacts[selected_contact].get_first_name() << "\nLast Name: " << _contacts[selected_contact].get_last_name() << "\nNickname: " << _contacts[selected_contact].get_nickname() << "\nPhone Number: " << _contacts[selected_contact].get_number() << "\nDarkest secret: " << _contacts[selected_contact].get_darkest_secret() << std::endl;  
    }

void    PhoneBook::add_contact_to_back(Contact contact)
{
    _last = (_last + 1) % 8;
    if (_total < 8)
        _total++;
    else
        std::cout << "Phonebook is full, overwriting oldest entry (" << _contacts[_last].get_first_name() << " " <<_contacts[_last].get_last_name() << ")" << std::endl;
    _contacts[_last] = contact;
    std::cout << "Contact added to PhoneBook." << std::endl;
}