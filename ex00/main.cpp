/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:35:27 by julcalde          #+#    #+#             */
/*   Updated: 2025/08/19 14:36:33 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <string>

int main() {
    // Test polymorphic behavior
    std::cout << "=== Polymorphic Test ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // Outputs: *WispTheCat hungry noise*
    j->makeSound(); // Outputs: Mr.Bubz: *WRAAAHHH*
    meta->makeSound(); // Outputs: Unidentified animal sound!
    delete meta;
    delete j;
    delete i;

    // Test non-polymorphic behavior
    std::cout << "\n=== Non-Polymorphic Test ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound(); // Outputs: Not the animal sound you wished for! (not Meow meow! (WrongCat))
    delete wrongMeta;
    delete wrongCat;

    // Additional tests
    std::cout << "\n=== Additional Tests ===" << std::endl;
    Dog dog1;
    Dog dog2(dog1); // Copy constructor
    Dog dog3;
    dog3 = dog1; // Assignment operator
    dog1.makeSound();
    dog2.makeSound();
    dog3.makeSound();

    Cat cat1;
    Cat cat2(cat1); // Copy constructor
    Cat cat3;
    cat3 = cat1; // Assignment operator
    cat1.makeSound();
    cat2.makeSound();
    cat3.makeSound();

    return 0;
}