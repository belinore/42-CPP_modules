/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:10:42 by belinore          #+#    #+#             */
/*   Updated: 2026/01/19 13:13:22 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

static void add_dummy_contacts(PhoneBook &book)
{
    std::cout << "Adding dummy contacts..." << std::endl;  
    book.add_contact_to_back(Contact("Alex", "Turner", "Al", "555-1234", "Afraid of pigeons"));
    book.add_contact_to_back(Contact("Beth", "Harmon", "Queen", "555-5678", "Once ate 12 boiled eggs"));
    book.add_contact_to_back(Contact("Carla", "Espinosa", "CJ", "555-9012", "Never learned to ride a bike"));
    book.add_contact_to_back(Contact("Daniel", "Jackson", "DJ", "555-3456", "Talks to plants"));
    book.add_contact_to_back(Contact("Elena", "Gilbert", "Lena", "555-7890", "Believes in aliens"));
    book.add_contact_to_back(Contact("Finn", "Mertens", "FJ", "555-2345", "Cried during a toothpaste ad"));
    book.add_contact_to_back(Contact("Grace", "Hopper", "Codebug", "555-6789", "Hates bananas"));
    book.add_contact_to_back(Contact("Hugo", "Reyes", "Hurley", "555-1122", "Thinks birds are spying on him"));
}

int main()
{
	PhoneBook book;
    std::string input;

    while (std::cin)
    {
        std::cout << "\nSelect from the following: [1] ADD [2] SEARCH [3] EXIT" << std::endl;
        if (!std::getline(std::cin, input))
			break ;
        if (input == "ADD" || input == "1")
        {
            std::cout << "Adding contact..." << std::endl;
            book.add_contact();
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
            add_dummy_contacts(book);
    }
}
