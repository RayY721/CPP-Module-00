#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Contact 
{
	public:
		Contact();

		void setContact(
			const std::string& first,
			const std::string& last,
			const std::string& nick,
			const std::string& phone,
			const std::string& secret
		);
		void displayFullContact() const;
		void displayContactSummary(int index) const;

    private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;

		std::string formatField(const std::string& str) const;
};

#endif