/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:02:24 by awilliam          #+#    #+#             */
/*   Updated: 2024/11/02 19:53:26 by awilliam         ###   ########.fr       */
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