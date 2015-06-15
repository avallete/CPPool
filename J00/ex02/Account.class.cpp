/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallete <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/15 12:59:56 by avallete          #+#    #+#             */
/*   Updated: 2015/06/15 12:59:58 by avallete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <ctime>
#include <iostream>

Account::Account(void)
{
	return;
}

Account::Account(int initial_deposit ): _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';'; 
	std::cout << "amount:" << initial_deposit << ';'; 
	std::cout << "created" << std::endl; 
	_nbAccounts++;
	_totalAmount += initial_deposit;
	return;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';'; 
	std::cout << "amount:" << this->_amount << ';'; 
	std::cout << "closed" << std::endl; 
	_nbAccounts--;
	return;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	this->_nbDeposits++;
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "p_amount:" << this->checkAmount() << ';';
	this->_amount += deposit;	
	std::cout << "deposit:" << deposit << ';';
	std::cout << "amount:" << this->checkAmount() << ';';
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (this->_amount >= withdrawal)
	{
		this->_nbWithdrawals++;
		std::cout << "index:" << this->_accountIndex << ';';
		std::cout << "p_amount:" << this->checkAmount() << ';';
		this->_amount -= withdrawal;
		std::cout << "withdrawal:" << withdrawal << ';';
		std::cout << "amount:" << this->checkAmount() << ';';
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		return (true);
	}
	else
	{
		std::cout << "index:" << this->_accountIndex << ';';
		std::cout << "p_amount:" << this->checkAmount() << ';';
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "amount:" << this->checkAmount() << ';';
	std::cout << "deposits:" << this->_nbDeposits << ';';
	std::cout << "withdrawals:" << this->_nbWithdrawals;
	std::cout << std::endl;
}

void Account::_displayTimestamp(void)
{
	char date[20] = {0};
	time_t time = std::time(NULL);
	std::strftime(date, 15, "%Y%m%d_%H%M%S" , std::localtime(&time));
	std::cout << "[" << date << "] ";
	return;
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
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
