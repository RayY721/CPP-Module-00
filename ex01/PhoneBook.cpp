/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 19:04:17 by kuyu              #+#    #+#             */
/*   Updated: 2026/05/04 19:04:18 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

PhoneBook::PhoneBook()
{
    contactCount = 0;
    nextIndex = 0;
}

std::string PhoneBook::getNonEmptyInput(const std::string& prompt) const
{
    std::string input;

    while (true)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, input))
            return ("");
        if (!input.empty())
            return (input);
        std::cout << "Field cannot be empty." << std::endl;
    }
}

void PhoneBook::addContact()
{
    std::string first;
    std::string last;
    std::string nick;
    std::string phone;
    std::string secret;

    first = getNonEmptyInput("First Name: ");
    if (first.empty())
        return ;
    last = getNonEmptyInput("Last Name: ");
    if (last.empty())
        return ;
    nick = getNonEmptyInput("Nickname: ");
    if (nick.empty())
        return ;
    phone = getNonEmptyInput("Phone number: ");
    if (phone.empty())
        return ;
    secret = getNonEmptyInput("Darkest secret: ");
    if (secret.empty())
        return ;

    contacts[nextIndex].setContact(first, last, nick, phone, secret);
    
    nextIndex = (nextIndex + 1) % 8;
    if (contactCount < 8)
        contactCount++;
    
    std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::displayListHeader() const
{
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;
}

int PhoneBook::getValidIndex() const
{
    std::string input;
    std::stringstream ss;
    int index;
    char extra;

    std::cout << "Enter index: ";
    if (!std::getline(std::cin, input))
        return (-1);
    
    ss << input;
    if (!(ss >> index))
        return (-1);
    if (ss >> extra)
        return (-1);
    if (index < 0 || index >= contactCount)
        return (-1);
    return (index);
}

void PhoneBook::searchContact() const
{
    int index;

    if (contactCount == 0)
    {
        std::cout << "PhoneBook is empty." << std::endl;
        return ;
    }

    this->displayListHeader();

    for (int i = 0; i < contactCount; i++)
        contacts[i].displayContactSummary(i);
    
    index = getValidIndex();
    if (index == -1)
    {
        std::cout << "Invalid index." << std::endl;
        return ;
    }
    contacts[index].displayFullContact();
}
