/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 17:09:36 by belinore          #+#    #+#             */
/*   Updated: 2026/03/19 17:09:37 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

class Data;

class Serializer
{
	public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

	private:
	Serializer();
	Serializer(const Serializer&);
	Serializer& operator=(const Serializer&);
	~Serializer();
};

#endif