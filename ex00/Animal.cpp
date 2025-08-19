/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:34:14 by julcalde          #+#    #+#             */
/*   Updated: 2025/08/19 13:47:28 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default constructor called!" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called!" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << "Animal copy constructor called!" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != other)
	{
		type = other.type;
	}
	std::cout << "Animal assignment operator called!" << std::endl;
	return (*this);
}

std::String Animal::getType() const
{
	return (type);
}

void Animal::makeSound() const
{
	std::cout << "Unidentified animal sound!" << std::endl;
}
