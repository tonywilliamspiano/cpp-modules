/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:25:06 by awilliam          #+#    #+#             */
/*   Updated: 2024/10/02 12:33:44 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP


template <typename T>
void swap(T &a, T &b) {
    T tmp;

    tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T max(T a, T b) {
    if (b > a) {
        return b;
    }
    return a;
}

template <typename T>
T min(T a, T b) {
    if (b < a) {
        return b;
    }
    return a;
}

#endif
