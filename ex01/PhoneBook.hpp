/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 19:04:24 by kuyu              #+#    #+#             */
/*   Updated: 2026/05/04 19:04:25 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>

class PhoneBook 
{
    private:
		Contact contacts[8];
		int contactCount;
		int nextIndex;
		
		std::string getNonEmptyInput(const std::string& prompt) const;
		void displayListHeader() const;
		int getValidIndex() const;
	public:
		PhoneBook();

		void addContact();
        void searchContact() const;
};

#endif