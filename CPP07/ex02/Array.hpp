/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 19:24:29 by belinore          #+#    #+#             */
/*   Updated: 2026/03/19 19:24:30 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    private:
    T* _array;
    unsigned int _size;

    public:
    Array();
    Array(unsigned int n);
    ~Array();
    Array(const Array &other);
    Array &operator=(const Array &other);
    T &operator[](unsigned int index);
    const T &operator[](unsigned int index) const;

    unsigned int size() const;

    class IndexOutOfBoundsException : public std::exception
    {
        public:
        virtual const char *what() const throw();
    };

};

template <typename T>
std::ostream &operator<<(std::ostream &os, Array<T> &array);

#include "Array.tpp"

#endif