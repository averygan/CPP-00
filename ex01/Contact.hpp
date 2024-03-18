/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:43:58 by agan              #+#    #+#             */
/*   Updated: 2024/03/11 19:43:59 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <limits>
#include <iomanip>
#include <cstdlib>
#include "PhoneBook.hpp"

#define SEARCH_WIDTH 17
#define MAX_CONTACTS 8
#define MAX_INDEX 7
#define B_GREEN "\033[1;32m"

class Contact
{
public:
	int get_index();
	std::string get_first_name();
	std::string get_last_name();
	std::string get_nickname();
	std::string get_phone_number();
	std::string get_darkest_secret();

	void set_index(int index);
	void set_first_name(std::string input);
	void set_last_name(std::string input);
	void set_nickname(std::string input);
	void set_phone_number(std::string input);
	void set_darkest_secret(std::string input);

private:
	int index;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
};

#endif