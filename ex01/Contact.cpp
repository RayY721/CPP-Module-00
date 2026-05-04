/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 19:03:23 by kuyu              #+#    #+#             */
/*   Updated: 2026/05/04 19:03:28 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact()
{

}

void Contact::setContact(
	const std::string& first,
	const std::string& last,
	const std::string& nick,
	const std::string& phone,
	const std::string& secret
)
{
	_firstName = first;
	_lastName = last;
	_nickName = nick;
	_phoneNumber = phone;
	_darkestSecret = secret;
}

void Contact::displayFullContact() const
{
	std::cout << "First name: " << _firstName << std::endl;
	std::cout << "Last name: " << _lastName << std::endl;
	std::cout << "Nickname: " << _nickName << std::endl;
	std::cout << "Phone number: " << _phoneNumber << std::endl;
	std::cout << "Darkest secret: " << _darkestSecret << std::endl;
}

void Contact::displayContactSummary(int index) const
{
	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << formatField(_firstName) << "|";
	std::cout << std::setw(10) << formatField(_lastName) << "|";
	std::cout << std::setw(10) << formatField(_nickName) << std::endl;
}

std::string Contact::formatField(const std::string& str) const
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

