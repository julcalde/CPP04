/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:35:27 by julcalde          #+#    #+#             */
/*   Updated: 2025/08/19 16:33:24 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>
#include <string>

int main(void)
{
    /* Required test
        * This section tests the basic functionality of the Animal, Dog, and Cat classes.
        * It creates instances of Dog and Cat, deletes them, and checks for memory leaks.
        * The output demonstrates that the correct destructor is called for each object,
        * ensuring proper cleanup of resources.
    */
    std::cout << "=== Required Test ===" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j; // Should not create a leak
    delete i;

    /* Array test
        * This section tests the creation of an array of Animal pointers,
        * where half of the pointers point to Dog objects and the other half to Cat objects.
        * It calls the makeSound() method on each object in the array,
        * demonstrating polymorphic behavior with arrays.
    */
    std::cout << "\n=== Array Test ===" << std::endl;
    const int size = 4;
    Animal* animals[size];
    for (int i = 0; i < size / 2; ++i) {
        animals[i] = new Dog();
    }
    for (int i = size / 2; i < size; ++i) {
        animals[i] = new Cat();
    }
    for (int i = 0; i < size; ++i) {
        animals[i]->makeSound();
    }
    for (int i = 0; i < size; ++i) {
        delete animals[i];
    }

    /* Deep copy test
        * This section tests the deep copy functionality of the Dog and Cat classes.
        * It creates instances of Dog and Cat, modifies their ideas in the Brain class,
        * and checks that the original and copied objects maintain their own separate states.
        * The output demonstrates that the deep copy is working correctly,
        * ensuring that changes to one object do not affect the other.
    */
    std::cout << "\n=== Deep Copy Test ===" << std::endl;
    Dog dog1;
    dog1.getBrain()->setIdea(0, "Chase tail");
    Dog dog2(dog1); // Copy constructor
    dog2.getBrain()->setIdea(0, "Bark at mailman");
    std::cout << "Dog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;

    Cat cat1;
    cat1.getBrain()->setIdea(0, "Pounce on toy");
    Cat cat2;
    cat2 = cat1; // Assignment operator
    cat2.getBrain()->setIdea(0, "Sleep on keyboard");   // comment out to test deep copy
    std::cout << "Cat1 idea: " << cat1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat2 idea: " << cat2.getBrain()->getIdea(0) << std::endl;
    return (0);
}