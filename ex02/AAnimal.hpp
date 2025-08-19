/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:34:24 by julcalde          #+#    #+#             */
/*   Updated: 2025/08/19 20:20:49 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <string>

class AAnimal
{
	protected:
		std::string type;

	public:
		AAnimal();
		virtual ~AAnimal() = 0; // Pure virtual destructor
		AAnimal(const AAnimal& other);
		AAnimal& operator=(const AAnimal& other);

		std::string getType() const;
		virtual void makeSound() const = 0; // Pure virtual function
};

#endif