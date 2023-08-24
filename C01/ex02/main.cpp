/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yli <yli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:51:42 by yli               #+#    #+#             */
/*   Updated: 2023/08/22 21:28:30 by yli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string* strPTR = &str;
    std::string& strREF = str;

    //*strPTR = "aabb";
    //strREF = "zzyy";
    std::cout << "memory address of the string variable " << &str << std::endl;
    std::cout << "memory address held by stringPTR: " << strPTR << std::endl;
    std::cout << "memory address held by stringREF: " << &strREF << std::endl;
    std::cout << "value of the string variable: " << str << std::endl;
    std::cout << "value pointed to by stringPTR: " << *strPTR << std::endl;
    std::cout << "value pointed to by stringREF: " << strREF << std::endl;
}

//• stringPTR: A pointer to the string.
//• stringREF: A reference to the string.

// Pointer (stringPTR): A pointer holds the memory address of the object it's pointing to. In this case, stringPTR is a pointer to an std::string object, and it's holding the memory address of the str object. To remember this, think of "PTR" as an abbreviation for "Pointer," and recall that pointers point to memory addresses.

// Reference (stringREF): A reference is like an alias for an existing object. It behaves as if it's the same object with a different name. In this case, stringREF is a reference to the str object. To remember this, think of "REF" as an abbreviation for "Reference," and associate it with the idea that references refer to the same object using a different name.

// A helpful mnemonic to remember this relationship is to think of "Pointer" as pointing to memory addresses and "Reference" as referring to the same object. Additionally, you can consider these key points:

// Pointers need to be dereferenced (*ptr) to access the value they point to.
// References are used directly without needing to dereference.
// References cannot be reseated (changed to refer to a different object), unlike pointers.
// In your code example, both the pointer and the reference are being used to access the same underlying std::string object (str), but they do so in slightly different ways. The pointer uses the dereference operator *strPTR to access the value, while the reference uses strREF directly.
