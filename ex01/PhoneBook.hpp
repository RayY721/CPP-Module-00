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