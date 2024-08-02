/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:06:07 by tony              #+#    #+#             */
/*   Updated: 2023/07/25 12:28:41 by tony             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>

struct Data {
    std::string clothingType;
    std::string clothingColor;
};

class Serializer {
    public:
        Serializer();
        Serializer(const Serializer& other);
        ~Serializer();
        Serializer& operator=(const Serializer& other);

        Data* deserialize(uintptr_t raw);
        uintptr_t serialize(Data* ptr);
};

#endif