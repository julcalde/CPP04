/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:34:48 by julcalde          #+#    #+#             */
/*   Updated: 2025/08/19 13:54:14 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog default constructor called!" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called!" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called!" << std::endl;
}

Dog& Doge::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << "Dog assignment operator called!" << std::endl;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Mr.Bubz: *WRAAAHHH*" << std::endl;
}
