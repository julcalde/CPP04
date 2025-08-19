/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:34:42 by julcalde          #+#    #+#             */
/*   Updated: 2025/08/19 20:30:43 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>
#include <string>

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat default constructor called!" << std::endl;
	brain = new Brain();
}

Cat::~Cat()
{
	if (brain)
	{
		delete brain;
		brain = NULL;
	}
	std::cout << "Cat destructor called!" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other)
{
	brain = other.brain ? new Brain(*other.brain) : NULL;
	std::cout << "Cat copy constructor called!" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
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
	std::cout << "Cat assignment operator called!" << std::endl;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow meow!" << std::endl;
}

// Updating for Brain integration

Brain* Cat::getBrain() const
{
	return (brain);
}