/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:35:27 by julcalde          #+#    #+#             */
/*   Updated: 2025/08/19 14:49:33 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>
#include <string>

int main() {
    /* Test polymorphic behavior
        * This section tests the polymorphic behavior of the Animal class and its derived classes.
        * It creates instances of Animal, Dog, and Cat, and calls their makeSound() methods.
        * The output demonstrates that the correct sound is produced based on the actual object type,
        * even when accessed through a base class pointer.
     */
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

    /* Test non-polymorphic behavior
        * This section tests the non-polymorphic behavior of the WrongAnimal class and its derived class WrongCat.
        * It creates instances of WrongAnimal and WrongCat, and calls their makeSound() methods.
        * The output demonstrates that the WrongCat does not override the makeSound() method correctly,
        * producing a generic sound instead of the expected "Meow meow!".
    */
    std::cout << "\n=== Non-Polymorphic Test ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound(); // Outputs: Not the animal sound you wished for! (not Meow meow! (WrongCat))
    delete wrongMeta;
    delete wrongCat;

    /* Additional tests
        * This section tests the copy constructor and assignment operator of the Dog and Cat classes.
        * It creates instances of Dog and Cat, copies them using the copy constructor,
        * and assigns them using the assignment operator.
        * The output demonstrates that the copied objects behave as expected.
    */
    std::cout << "\n=== Additional Tests ===" << std::endl;
    Dog dog1;       // Default constructor
    Dog dog2(dog1); // Default constructor & Copy constructor
    Dog dog3;       // Default constructor
    dog3 = dog1;    // Default constructor & Assignment operator
    dog1.makeSound();
    dog2.makeSound();
    dog3.makeSound();

    Cat cat1;       // Default constructor
    Cat cat2(cat1); // Default constructor & Copy constructor
    Cat cat3;       // Default constructor
    cat3 = cat1;    // Default constructor & Assignment operator
    cat1.makeSound();
    cat2.makeSound();
    cat3.makeSound();
    return 0;
                    // All destructors called
}