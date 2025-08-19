/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:44:19 by julcalde          #+#    #+#             */
/*   Updated: 2025/08/19 16:29:17 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	for (int i = 0; i < 100; ++i)
	{
		ideas[i] = "";
	}
	std::cout << "Brain default constructor called!" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called!" << std::endl;
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; ++i)
	{
		ideas[i] = other.ideas[i];
	}
	std::cout << "Brain copy constructor called!" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
		{
			ideas[i] = other.ideas[i];
		}
	}
	std::cout << "Brain assignment operator called!" << std::endl;
	return (*this);
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
	{
		return (ideas[index]);
	}
	return ("");
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
	{
		ideas[index] = idea;
	}
}
