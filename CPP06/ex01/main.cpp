/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miturk <miturk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 11:13:07 by miturk            #+#    #+#             */
/*   Updated: 2024/11/12 14:47:21 by miturk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    // Create a Data object
    Data originalData(1, "Example");

    // Serialize the pointer to originalData
    uintptr_t serializedData = Serializer::serialize(&originalData);

    // Deserialize back to a Data pointer
    Data* deserializedData = Serializer::deserialize(serializedData);

    // Verify that the deserialized pointer matches the original pointer
    if (deserializedData == &originalData) {
        std::cout << "Test passed: deserialized pointer matches original pointer.\n";
        std::cout << "Data ID: " << deserializedData->_i << ", Name: " << deserializedData->_s << std::endl;
    } else {
        std::cout << "Test failed: deserialized pointer does not match original pointer.\n";
    }
    return 0;
}