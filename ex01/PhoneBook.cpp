/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:54:19 by agan              #+#    #+#             */
/*   Updated: 2024/03/11 19:54:21 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
}

/* Function to set contact data for each contact variable */
std::string set_contact_data(std::string prompt)
{
	std::string input; 

	while (input.empty())
	{
		if (std::cin.eof())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return input;
		}
		std::cout << "Enter " << prompt << ": ";
		std::getline(std::cin, input);
		if (input.empty() && !std::cin.eof())
			std::cout << "Please enter a valid " << prompt << std::endl;
	}
	return input;
}

/* Function to add contact to phonebook */
void PhoneBook::add_contact(Contact& new_contact)
{
	if (index < MAX_CONTACTS)
	{
		new_contact.set_index(index);
		contacts[index] = new_contact;
		index++;
		std::cout << "Contact added!" << std::endl;
	}
	else
	{
		new_contact.set_index(index % MAX_CONTACTS);
		contacts[index % MAX_CONTACTS] = new_contact;
		index++;
		std::cout << "Contact list full - Oldest contact replaced." << std::endl;
	}
}

/* Function to get method from user */
void get_method(std::string& method)
{
	std::cout << "ADD/SEARCH/EXIT: ";
	std::getline(std::cin, method);
	if (std::cin.eof())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

/* Function to print contact indicated by search index */
void PhoneBook::print_contact(int i)
{
	std::cout << std::endl << "Results" << std::endl << "-----------------------" << std::endl;
	std::cout << std::setw(SEARCH_WIDTH) << "Index: " << std::to_string(i) << std::endl;
	std::cout << std::setw(SEARCH_WIDTH) << "First name: " << contacts[i].get_first_name() << std::endl;
	std::cout << std::setw(SEARCH_WIDTH) << "Last name: " << contacts[i].get_last_name() << std::endl;
	std::cout << std::setw(SEARCH_WIDTH) << "Nickname: " << contacts[i].get_nickname() << std::endl;
	std::cout << std::setw(SEARCH_WIDTH) << "Phone number: " << contacts[i].get_phone_number() << std::endl;
	std::cout << std::setw(SEARCH_WIDTH) << "Darkest secret: " << contacts[i].get_darkest_secret() << std::endl;
	std::cout << std::endl;
}

/* Function to print contact in 4 columns */
void print_data(std::string data, int pipe)
{
	int len;

	len = data.length();
	if (len <= 10)
	{
		for (int i = 0; i < 10 - len; i++)
			std::cout << " ";
		std::cout << data;
	}
	else
		std::cout << data.substr(0, 9) << ".";
	if (pipe)
		std::cout << "|";
	else
		std::cout << std::endl;
}

/* Function to display headers and contacts */
void PhoneBook::display_contacts()
{
	int j;
	if (index > MAX_INDEX)
		j = MAX_CONTACTS;
	else
		j = index;
	print_header("Index");
	print_header("First name");
	print_header("Last name");
	print_header("Nickname");
	for (int i = 0; i < j; i++)
	{
		print_data(std::to_string(contacts[i].get_index()), 1);
		print_data(contacts[i].get_first_name(), 1);
		print_data(contacts[i].get_last_name(), 1);
		print_data(contacts[i].get_nickname(), 0);
	}
}

int is_numeric(std::string search)
{
	int i;

	i = 0;
	if (search[i] == '-' || search[i] == '+')
		i++;
	while (search[i])
	{
		if (!isdigit(search[i]))
			return 0;
		i++;
	}
	return 1;
}

int PhoneBook::within_range(int i)
{
	if (i < 0 || i >= MAX_CONTACTS)
	{
		std::cout << "Index is not within range.\n";
		return 0;
	}
	else if (i > index - 1)
	{
		std::cout << "No contact with this index.\n";
		return 0;
	}
	return 1;
}

/* Function for search function 
Displays 4 columns
Gets search index 
Displays search results */
int PhoneBook::search()
{
	int to_search;
	std::string search;

	to_search = -1;
	display_contacts();
	if (index == 0)
		return 1;
	do 
	{
		std::cout << "Search index: ";
		std::getline(std::cin, search);
		if (std::cin.eof())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return 0;
		}
		if (!search.empty() && is_numeric(search))
		{
			try
			{
				to_search = std::stoi(search);
			}
			catch(const std::exception& e)
			{
				to_search = -1;
			}
		}
		if (!is_numeric(search))
			std::cout << "Index is not numeric.\n";
	}
	while (!is_numeric(search) || !within_range(to_search));
	if (within_range(to_search))
		print_contact(to_search);
	return 1;
}

/* Function for add method */
int add(PhoneBook& pb)
{
	Contact new_contact;

	new_contact.set_first_name(set_contact_data("first name"));
	new_contact.set_last_name(set_contact_data("last name"));
	new_contact.set_nickname(set_contact_data("nickname"));
	new_contact.set_phone_number(set_contact_data("phone number"));
	new_contact.set_darkest_secret(set_contact_data("darkest secret"));
	if (!new_contact.Contact::get_last_name().empty() && 
		!new_contact.Contact::get_first_name().empty() &&
		!new_contact.Contact::get_nickname().empty() && 
		!new_contact.Contact::get_phone_number().empty() &&
		!new_contact.Contact::get_darkest_secret().empty())
		pb.add_contact(new_contact);
	else
		return 0;
	return 1;
}

/* Function to print headers of search */
void print_header(std::string header)
{
	if (header == "Nickname")
	    std::cout << std::setw(10) << header << std::endl;
	else
	{
		std::cout << std::setw(10) << header;
		std::cout << "|";
	}
}

int main(void)
{
	std::string method;
	PhoneBook pb;

	while (1)
	{
		get_method(method);
		if (method == "ADD" && !add(pb))
			break;
		else if (method == "SEARCH" && !pb.search())
			break;
		else if (method == "EXIT" || std::cin.eof())
			break ;
	}
	return 0;
}
