#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename Type> void iter(Type *array, const size_t length, void (*function)(Type &))
{
    for (size_t i = 0; i < length; i++)
        function(array[i]);
}

#endif
