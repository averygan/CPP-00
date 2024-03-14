/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account::cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:44:19 by agan              #+#    #+#             */
/*   Updated: 2024/03/14 15:44:20 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <chrono>
#include <iostream>
#include <string>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit): _nbDeposits(0), _nbWithdrawals(0)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_amount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << std::to_string(_accountIndex) << ";"
		<< "amount:" << std::to_string(_amount) 
		<< ";created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << std::to_string(_accountIndex) << ";"
		<< "amount:" << std::to_string(_amount) 
		<< ";" << "closed" << std::endl;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << std::to_string(_nbAccounts) 
		<< ";total:" << std::to_string(_totalAmount) 
		<< ";deposits:" << std::to_string(_totalNbDeposits) 
		<< ";withdrawals:" << std::to_string(_totalNbWithdrawals) << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << std::to_string(_accountIndex) 
		<< ";p_amount:" << std::to_string(_amount);
	_amount+= deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << ";deposit:" << std::to_string(deposit)
	<< ";amount:" << std::to_string(_amount)
	<< ";nb_deposits:" << std::to_string(_nbDeposits) << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << std::to_string(_accountIndex) 
		<< ";p_amount:" << std::to_string(_amount)
		<< ";withdrawal:";
	if (_amount >= withdrawal)
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout << std::to_string(withdrawal) 
			<< ";amount:" << std::to_string(_amount)
			<< ";nb_withdrawals:" << std::to_string(_nbWithdrawals) << std::endl;
		return (true);
	}
	else
		std::cout << "refused" << std::endl;
	return (false);
}

int	Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << std::to_string(_accountIndex) 
		<< ";amount:" << std::to_string(_amount)
		<< ";deposits:" << std::to_string(_nbDeposits)
		<< ";withdrawals:" << std::to_string(_nbWithdrawals) << std::endl;
}

void	Account::_displayTimestamp( void )
{
	char buffer[20];

	auto now = std::chrono::system_clock::now();
	std::time_t time = std::chrono::system_clock::to_time_t(now);
	std::tm tm_time = *std::localtime(&time);
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", &tm_time);
	std::cout << buffer << " ";
	return ;
}
