/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tony <tony@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:37:53 by tony              #+#    #+#             */
/*   Updated: 2024/10/02 11:51:46 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

// TODO - Review code to make sure I fully understand
//      - Test with valgrind for memory leaks
//      - Test rigorously against subject

int main() {
    Serializer s;
    Data *data = new Data;
    Data *newData;
    uintptr_t dataSerialized;

    data->clothingColor = "Blue";
    data->clothingType = "T-Shirt";
    std::cout << "Address of data is: " << data << std::endl;
    dataSerialized = s.serialize(data);
    std::cout << "Serialized data is: " << dataSerialized << std::endl;
    newData = s.deserialize(dataSerialized);
    std::cout << "Address of deserialized data is: " << newData << std::endl;

    std::cout << "Type: " << newData->clothingType << std::endl;
    std::cout << "Color: " << newData->clothingColor << std::endl;
    delete newData;
}