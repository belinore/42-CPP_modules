/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:09:15 by belinore          #+#    #+#             */
/*   Updated: 2026/03/19 17:09:16 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
#define TESTS_HPP
#include <string>

#define CYAN "\033[36m"
#define RESET "\033[0m"

bool get_yesno_input(const std::string &prompt);
void test_examples();

#endif
