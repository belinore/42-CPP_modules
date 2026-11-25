/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:10:49 by belinore          #+#    #+#             */
/*   Updated: 2026/01/19 12:59:31 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() : _last(-1), _total(0)
{
    std::cout << "Welcome to your new PhoneBook!";
}

void PhoneBook::print_contact_details(std::string &str_input)
{
	int selected_contact;

	std::cout << "Indicate index of contact to display details" << std::endl;
	selected_contact = -1;
	while (std::getline(std::cin, str_input))
	{
		std::stringstream ss(str_input);
		ss >> selected_contact;
		if (!ss.fail() && ss.eof() && selected_contact >= 0 && selected_contact < _total)
			break ;
		std::cout << "Error: Input number between 0 and " << _total - 1 << std::endl;
	}
	if (!std::cin)
		return ;
	std::cout << "** Details for [" << selected_contact << "] **" << std::endl;
	std::cout << "First Name: " << _contacts[selected_contact].get_first_name()
	<< "\nLast Name: " << _contacts[selected_contact].get_last_name()
	<< "\nNickname: " << _contacts[selected_contact].get_nickname()
	<< "\nPhone Number: " << _contacts[selected_contact].get_number()
	<< "\nDarkest secret: " << _contacts[selected_contact].get_darkest_secret()
	<< std::endl;  
}

static std::string truncate_to_width(std::string str)
{
    std::string truncated;

    if (str.length() <= COLUMN_WIDTH)
        return (str);
    truncated = str.substr(0, 9) + ".";
    return (truncated);
}

void PhoneBook::print_contacts()
{
	std::string str_input;

	std::cout << "** Contacts **" << std::endl;
	std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|"
	<< std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << std::endl;
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
	print_contact_details(str_input);
}

void    PhoneBook::add_contact_to_back(Contact contact)
{
    _last = (_last + 1) % 8;
    if (_total < 8)
        _total++;
    else
        std::cout << "Phonebook is full, overwriting oldest entry ("
		<< _contacts[_last].get_first_name() << " " <<_contacts[_last].get_last_name()
		<< ")" << std::endl;
    _contacts[_last] = contact;
    std::cout << "Contact added to PhoneBook." << std::endl;
}

static bool	get_user_input(const std::string &prompt, std::string &dest)
{
	std::cout << prompt << std::endl;
	while (std::getline(std::cin,dest) && dest.empty())
		std::cout << prompt << std::endl;
	if (!std::cin)
		return (false);
	return (true);
}

static bool is_numeric(std::string str)
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

void    PhoneBook::add_contact()
{
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string secret;

	if (!get_user_input("First name: ", first_name))
		return ;
	if (!get_user_input("Last name: ", last_name))
		return ;
	if (!get_user_input("Nickname: ", nickname))
		return ;
	if (!get_user_input("Phone number ", phone_number))
		return ;
	while (!is_numeric(phone_number))
	{
		std::cout << "Error: must be numeric" << std::endl;
		if (!get_user_input("Phone number ", phone_number))
			return ;
	}
    if (!get_user_input("Darkest secret: ", secret))
		return ;
    Contact n(first_name, last_name, nickname, phone_number, secret);
    add_contact_to_back(n);
}
