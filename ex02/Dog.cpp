/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:34:48 by julcalde          #+#    #+#             */
/*   Updated: 2025/08/19 20:31:40 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>
#include <string>

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog default constructor called!" << std::endl;
	brain = new Brain();
}

Dog::~Dog()
{
	if (brain)
	{
		delete brain;
		brain = NULL;
	}
	std::cout << "Dog destructor called!" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other)
{
	brain = other.brain ? new Brain(*other.brain) : NULL;
	std::cout << "Dog copy constructor called!" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		if (brain)
		{
			delete brain;
		}
		brain = other.brain ? new Brain(*other.brain) : NULL;
	}
	std::cout << "Dog assignment operator called!" << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof woof!" << std::endl;
}

// Updating for Brain integration

Brain* Dog::getBrain() const
{
	return (brain);
}