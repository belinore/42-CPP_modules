#include "phonebook.hpp"

void    add_contact(PhoneBook *book)
{
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string secret;

    std::cout << "First name: " << std::endl;
    while (first_name.empty())
        std::getline(std::cin,first_name);
    std::cout << "Last name: " << std::endl;
    while (last_name.empty())
        std::getline(std::cin, last_name);
    std::cout << "Nickname: " << std::endl;
    while (nickname.empty())
        std::getline(std::cin, nickname);
    std::cout << "Phone number: " << std::endl;
    while (phone_number.empty())
        std::getline(std::cin, phone_number);
    std::cout << "Darkest secret: " << std::endl;
    while (secret.empty())
        std::getline(std::cin, secret);
    Contact n(first_name, last_name, nickname, phone_number, secret);
    book->add_contact_to_back(n);
}

void add_dummy_contacts(PhoneBook *book)
{
    std::cout << "Adding dummy contacts..." << std::endl;  
    book->add_contact_to_back(Contact("Alex", "Turner", "Al", "555-1234", "Afraid of pigeons"));
    book->add_contact_to_back(Contact("Beth", "Harmon", "Queen", "555-5678", "Once ate 12 boiled eggs"));
    book->add_contact_to_back(Contact("Carla", "Espinosa", "CJ", "555-9012", "Never learned to ride a bike"));
    book->add_contact_to_back(Contact("Daniel", "Jackson", "DJ", "555-3456", "Talks to plants"));
    book->add_contact_to_back(Contact("Elena", "Gilbert", "Lena", "555-7890", "Believes in aliens"));
    book->add_contact_to_back(Contact("Finn", "Mertens", "FJ", "555-2345", "Cried during a toothpaste ad"));
    book->add_contact_to_back(Contact("Grace", "Hopper", "Codebug", "555-6789", "Hates bananas"));
    book->add_contact_to_back(Contact("Hugo", "Reyes", "Hurley", "555-1122", "Thinks birds are spying on him"));
}

int main()
{
    PhoneBook book;
    std::string input;

    std::cout << "Welcome to your new PhoneBook!"
    while (1)
    {
        std::cout << "\nSelect from the following: [1] ADD [2] SEARCH [3] EXIT" << std::endl;
        std::getline(std::cin, input);
        if (input == "ADD" || input == "1")
        {
            std::cout << "Adding contact..." << std::endl;
            add_contact(&book);
        }
        else if (input == "SEARCH" || input == "2")
        {
            std::cout << "Browsing phonebook..." << std::endl;
            book.print_contacts();
        }
        else if (input == "EXIT" || input == "3")
        {
            std::cout << "Shutting down..." << std::endl;
            break ;
        }
        else if (input == "D")
            add_dummy_contacts(&book);
    }
}