/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kuyu <kuyu@student.codam.nl>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 19:04:34 by kuyu              #+#    #+#             */
/*   Updated: 2026/05/04 19:09:45 by kuyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// At runtime, the program repeatedly waits for input:
// ADD / SEARCH/ EXIT
// ADD: Ask for : first name, last name, nickname, phone number, darkest secret
// No field can be empty

// max 8 contacts, if more than 8, the oldest one will be replaced by the new one
// ** Circular buffer **

#include "PhoneBook.hpp"
#include <string>
#include <iostream>

int main()
{
    PhoneBook phoneBook;
    std::string command;

    while (true)
	{
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command))
            break ;
        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else if (command == "EXIT")
            break ;
	}
    return 0;
}
