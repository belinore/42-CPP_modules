/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:10:38 by belinore          #+#    #+#             */
/*   Updated: 2026/01/16 20:05:06 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

class   Contact
{
    public:
    Contact();
    Contact(std::string first_name, std::string last_name, std::string nickname,
		std::string phone_number, std::string darkest_secret);
	std::string get_first_name() const;
    std::string get_last_name() const;
    std::string get_nickname() const;
    std::string get_number() const;
    std::string get_darkest_secret() const;

    private:
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone_number;
    std::string _darkest_secret;
};

#endif