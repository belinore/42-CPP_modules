#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#define MAX_CONTACTS 8
#define COLUMN_WIDTH 10

class   Contact
{
    public:
    Contact() : _first_name(""), _last_name(""), _nickname(""), _phone_number(""), _darkest_secret("") {}
    Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret) : _first_name(first_name), _last_name(last_name), _nickname(nickname), _phone_number(phone_number), _darkest_secret(darkest_secret) {}
    std::string get_first_name() const { return _first_name; }
    std::string get_last_name() const { return _last_name; }
    std::string get_nickname() const { return _nickname; }
    std::string get_number() const { return _phone_number; }
    std::string get_darkest_secret() const { return _darkest_secret; }

    private:
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone_number;
    std::string _darkest_secret;
};

class   PhoneBook
{
    public: //visible to members of the class
    PhoneBook() : _last(-1), _total(0) {} //constructor
    void    add_contact_to_back(Contact contact);
    void    print_contacts();
    private: //implementation details or helper functions
    Contact _contacts[MAX_CONTACTS];
    int _last;
    int _total;
};

bool    is_numeric(std::string str);

#endif