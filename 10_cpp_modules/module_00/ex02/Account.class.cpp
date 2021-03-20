
#include <iostream>
#include <ctime>
#include "Account.class.hpp"
//if we declare static variable in class, 
//we need to set them first, like this:
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void)
{
    return;
}

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
    //this->_amount = initial_deposit;
    this->_accountIndex = _nbAccounts++;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _totalAmount += initial_deposit;
    std::cout << "[here'll be a timestamp] " \
    << "index:" << this->_accountIndex \
    << ";amount:" << this->_amount \
    << ";created" << std::endl;
    return;
}

Account::~Account(void)
{
    std::cout << "[here'll be a timestamp] " \
    << "index:" << this->_accountIndex \
    << ";amount:" << this->_amount \
    << ";closed" << std::endl;
    return;
}

void	Account::displayAccountsInfos( void )
{
    //accounts:8;total:20049;deposits:0;withdrawals:0
    std::cout << "[here'll be a timestamp] " \
    << "accounts:" << getNbAccounts() \
    << ";total:" << getTotalAmount() \
    << ";deposits:" << getNbDeposits() \
    << ";withdrawals:" << getNbWithdrawals() \
    << std::endl;
    return;
}

void    Account::displayStatus( void ) const
{
    //[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
    std::cout << "[here'll be a timestamp] " \
    << "index:" << this->_accountIndex \
    << ";amount:" << this->_amount \
    << ";deposits:" << this->_nbDeposits \
    << ";withdrawals:" << this->_nbWithdrawals \
    << std::endl;
    return;
}

int	Account::getNbAccounts( void )
{
    return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
    return _totalAmount;
}

int	Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}

void    Account::makeDeposit( int deposit )
{
    //[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
    this->_amount += deposit;
    _totalNbDeposits += 1;
    _totalAmount += deposit;
    std::cout << "[here'll be a timestamp] " \
    << "index:" << this->_accountIndex \
    << ";p_amount:" << this->_amount - deposit \
    << ";deposit:" << deposit \
    << ";amount:" << this->_amount \
    << ";nb_deposits:" << ++this->_nbDeposits \
    << std::endl;
    return;
}

bool    Account::makeWithdrawal( int withdrawal )
{
    //[19920104_091532] index:0;p_amount:47;withdrawal:refused
    //[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
    std::cout << "[here'll be a timestamp] " \
    << "index:" << this->_accountIndex \
    << ";p_amount:" << this->_amount \
    << ";withdrawal:";
    if (this->_amount - withdrawal < 0)
    {
        std::cout << "refused" << std::endl;
        return false;
    }
    else
    {
        _amount -= withdrawal;
        _nbWithdrawals += 1;
        _totalNbWithdrawals += 1;
        _totalAmount -= withdrawal;
        std::cout << withdrawal \
        << ";amount:" << _amount \
        << ";nb_withdrawals:" << _nbWithdrawals \
        << std::endl;
    }
    return true;
}

int     Account::checkAmount( void ) const
{
	return 0;
}

void	Account::_displayTimestamp( void )
{
	return;
}
