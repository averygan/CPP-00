/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:43:09 by agan              #+#    #+#             */
/*   Updated: 2024/03/11 19:43:10 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <limits>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"


#define SEARCH_WIDTH 17
#define MAX_CONTACTS 8
#define MAX_INDEX 7
#define B_GREEN "\033[1;32m"

class PhoneBook 
{
private:
	Contact contacts[8];
	int index;

public:
	PhoneBook();
	int search();
	void print_contact(int i);
	void add_contact(Contact& new_contact);
	int within_range(int i);
	void display_contacts();
};

void print_header(std::string header);

#endif