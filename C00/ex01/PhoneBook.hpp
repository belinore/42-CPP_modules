/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:10:54 by belinore          #+#    #+#             */
/*   Updated: 2026/01/16 16:11:10 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include "Contact.hpp"

#define MAX_CONTACTS 8
#define COLUMN_WIDTH 10

class   PhoneBook
{
    public:
    PhoneBook();

    void    add_contact_to_back(Contact contact);
    void    print_contacts();
	void	print_contact_details(std::string &str_input);

    private:
    Contact _contacts[MAX_CONTACTS];
    int _last;
    int _total;
};

bool		is_numeric(std::string str);
std::string	truncate_to_width(std::string str);

#endif