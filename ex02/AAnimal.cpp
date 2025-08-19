/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 20:15:32 by julcalde          #+#    #+#             */
/*   Updated: 2025/08/19 20:18:36 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>
#include <string>

AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << "AAnimal default constructor called!" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called!" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type)
{
	std::cout << "AAnimal copy constructor called!" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "AAnimal assignment operator called!" << std::endl;
	return (*this);
}

std::string AAnimal::getType() const
{
	return (type);
}

void AAnimal::makeSound() const
{
	std::cout << "Unidentified aAnimal sound!" << std::endl;
}
