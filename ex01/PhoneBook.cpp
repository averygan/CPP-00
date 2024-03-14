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

#include "PhoneBook.h"

/* Function to set contact data for each contact variable */
int set_contact_data(std::string prompt, std::string &data)
{
	std::cout << "Enter " << prompt << ": ";
	std::getline(std::cin, data);
	if (std::cin.eof())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return 0;
	}
	return 1;
}

/* Function to add contact to phonebook */
void add_contact(PhoneBook& pb, Contact& new_contact)
{
	if (pb.index < MAX_CONTACTS)
	{
		new_contact.index = pb.index;
		pb.contacts[pb.index] = new_contact;
		pb.index++;
		std::cout << "Contact added!" << std::endl;
	}
	else
	{
		new_contact.index = pb.index % MAX_CONTACTS;
		pb.contacts[pb.index % MAX_CONTACTS] = new_contact;
		pb.index++;
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

/* Function for add method */
int add(PhoneBook& pb)
{
	Contact new_contact;

	if (!set_contact_data("first name", new_contact.first_name) 
		|| !set_contact_data("last name", new_contact.last_name) 
		|| !set_contact_data("nickname", new_contact.nickname)
		|| !set_contact_data("phone number", new_contact.phone_number)
		|| !set_contact_data("darkest secret", new_contact.darkest_secret))
		return 0;
	if (!new_contact.first_name.empty() && !new_contact.last_name.empty() && \
		!new_contact.nickname.empty()
		&& !new_contact.phone_number.empty() && \
		!new_contact.darkest_secret.empty())
		add_contact(pb, new_contact);
	else
		std::cout << "Unable to add contacts: did not receive all required information." << std::endl;
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

/* Function to print contact indicated by search index */
void print_contact(int i, PhoneBook pb)
{
	std::cout << std::endl << "Results" << std::endl << "-----------------------" << std::endl;
	std::cout << std::setw(SEARCH_WIDTH) << "Index: " << std::to_string(i) << std::endl;
	std::cout << std::setw(SEARCH_WIDTH) << "First name: " << pb.contacts[i].first_name << std::endl;
	std::cout << std::setw(SEARCH_WIDTH) << "Last name: " << pb.contacts[i].last_name << std::endl;
	std::cout << std::setw(SEARCH_WIDTH) << "Nickname: " << pb.contacts[i].nickname << std::endl;
	std::cout << std::setw(SEARCH_WIDTH) << "Phone number: " << pb.contacts[i].phone_number << std::endl;
	std::cout << std::setw(SEARCH_WIDTH) << "Darkest secret: " << pb.contacts[i].darkest_secret << std::endl;
	std::cout << std::endl;
}

/* Function to display headers and contacts */
void display_contacts(PhoneBook pb)
{
	int j;
	if (pb.index > MAX_INDEX)
		j = MAX_CONTACTS;
	else
		j = pb.index;
	print_header("Index");
	print_header("First name");
	print_header("Last name");
	print_header("Nickname");
	for (int i = 0; i < j; i++)
	{
		print_data(std::to_string(pb.contacts[i].index), 1);
		print_data(pb.contacts[i].first_name, 1);
		print_data(pb.contacts[i].last_name, 1);
		print_data(pb.contacts[i].nickname, 0);
	}
}

int is_numeric(std::string search)
{
	int i;

	i = 0;
	while (search[i])
	{
		if (!isdigit(search[i]))
			return 0;
		i++;
	}
	return 1;
}

int within_range(PhoneBook pb, int i)
{
	if (i < 0 || i >= MAX_CONTACTS)
	{
		std::cout << "Index is not within range.\n";
		return 0;
	}
	else if (i > pb.index - 1)
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
int search(PhoneBook pb)
{
	int to_search;
	std::string search;

	to_search = -1;
	display_contacts(pb);
	if (pb.index == 0)
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
			to_search = std::stoi(search);
		if (!is_numeric(search))
			std::cout << "Index is not numeric.\n";
	}
	while (!is_numeric(search) || !within_range(pb, to_search));
	if (within_range(pb, to_search))
		print_contact(to_search, pb);
	return 1;
}

int main(void)
{
	std::string method;
	PhoneBook pb;

	pb.index = 0;
	while (1)
	{
		get_method(method);
		if (method == "ADD" && !add(pb))
			break;
		else if (method == "SEARCH" && !search(pb))
			break;
		else if (method == "EXIT" || std::cin.eof())
			break ;
	}
	return 0;
}
