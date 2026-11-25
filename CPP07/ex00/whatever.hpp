/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belinore <belinore@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 19:22:33 by belinore          #+#    #+#             */
/*   Updated: 2026/03/19 19:23:27 by belinore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename Type>
void swap(Type &param1, Type &param2)
{
	Type temp;
	temp = param1;
	param1 = param2;
	param2 = temp;

}

template <typename Type>
Type min(Type x, Type y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

template <typename Type>
Type max(Type x, Type y)
{
	if (x > y)
		return (x);
	else
		return (y);
}

#endif