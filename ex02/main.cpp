/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:35:27 by julcalde          #+#    #+#             */
/*   Updated: 2025/08/19 20:29:04 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>
#include <string>

int main(void)
{
    /* Required test
    * Create a Dog and a Cat, call their makeSound() method, and delete them.
    * This will test the polymorphism and the virtual functions.
    */
    std::cout << "=== Required Test ===" << std::endl;
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    delete j;
    delete i;

    /* Array test
    * Create an array of AAnimal pointers, fill it with Dog and Cat objects,
    * call their makeSound() method, and delete them.
    * This will test the polymorphism and the virtual functions.
    */
    std::cout << "\n=== Array Test ===" << std::endl;
    const int size = 4;
    AAnimal* animals[size];
    for (int i = 0; i < size / 2; ++i)
    {
        animals[i] = new Dog();
    }
    for (int i = size / 2; i < size; ++i)
    {
        animals[i] = new Cat();
    }
    for (int i = 0; i < size; ++i)
    {
        animals[i]->makeSound();
    }
    for (int i = 0; i < size; ++i)
    {
        delete animals[i];
    }
    
    /* Deep copy
	* Create a Dog and a Cat, set an idea in their Brain, then create a deep copy
	* of each animal. Change the idea in the copied animal's Brain and print both
	* ideas to verify that the original and copied animals have separate Brain instances.
    */
    std::cout << "\n=== Deep Copy Test ===" << std::endl;
    Dog dog1;
    dog1.getBrain()->setIdea(0, "Chase tail");
    Dog dog2(dog1);
    dog2.getBrain()->setIdea(0, "Bark at mailman");
    std::cout << "Dog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;

    Cat cat1;
    cat1.getBrain()->setIdea(0, "Pounce on toy");
    Cat cat2;
    cat2 = cat1;
    cat2.getBrain()->setIdea(0, "Sleep on keyboard");
    std::cout << "Cat1 idea: " << cat1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat2 idea: " << cat2.getBrain()->getIdea(0) << std::endl;
    return (0);
}