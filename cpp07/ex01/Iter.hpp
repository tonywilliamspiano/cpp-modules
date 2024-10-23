/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:02:29 by tony              #+#    #+#             */
/*   Updated: 2024/10/23 16:08:17 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void iter(T *array, int length, void (*func)(T &param)) {
    for (int i = 0; i < length; i++)
        (*func)(array[i]);
}

template<typename T>
void printElement(T &element) {
    std::cout << element << " ";
}

template<typename T>
void addFive(T &element) {
    element += 5;
}

#endif