/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 19:22:39 by belinore          #+#    #+#             */
/*   Updated: 2026/03/19 19:23:14 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename Type, typename Func>
void iter(Type *array, size_t length, Func function)
{
    for (size_t i = 0; i < length; i++)
        function(array[i]);
}

#endif
