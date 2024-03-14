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
#include "Contact.hpp"

#define SEARCH_WIDTH 17
#define MAX_CONTACTS 8
#define MAX_INDEX 7
#define B_GREEN "\033[1;32m"

class PhoneBook 
{
public:
	Contact contacts[8];
	int index;
};

#endif