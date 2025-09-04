#include <iostream>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts( void )
{
    return(_nbAccounts);
}
int	Account::getTotalAmount( void )
{
    return(_totalAmount);
}
int	Account::getNbDeposits( void )
{
    return(_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
    return(_totalNbWithdrawals);
}
void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts()
    << ";total:" << getTotalAmount()
    << ";deposits:" << getNbDeposits()
    << ";withdrawals:" << getNbWithdrawals() << std::endl;
    return ;
}

Account::Account(void) : _accountIndex(0), _amount(0), _nbDeposits(0), _nbWithdrawals(0) {}

Account::Account(int initial_deposit)
{
    _totalAmount += initial_deposit;
    _nbAccounts += 1;
    _accountIndex = _nbAccounts - 1;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
    << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
    << ";amount:" << _amount << ";closed" << std::endl;
}

void	Account::_displayTimestamp( void )
{
    std::time_t now = std::time(NULL);
    std::tm* localTime = std::localtime(&now);


    std::cout << "[" << 1900 + localTime->tm_year << std::setfill('0') << std::setw(2) << localTime->tm_mon + 1
              << std::setw(2) << localTime->tm_mday << "_" << std::setw(2) << localTime->tm_hour
              << std::setw(2) << localTime->tm_min << std::setw(2) << localTime->tm_sec << "] ";
    return ;
}

void	Account::makeDeposit( int deposit )
{
    int p_amount;

    p_amount = _amount;
    _amount += deposit;
    _nbDeposits += 1;
    _totalAmount += deposit;
    _totalNbDeposits += 1;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
    << ";p_amount:" << p_amount
    << ";deposit:" << deposit
    << ";amount:" << _amount
    << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    int p_amount;

    p_amount = _amount;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
    << ";p_amount:" << p_amount
    << ";withdrawal:";
    if (withdrawal > _amount)
    {
        std::cout << "refused" << std::endl;
        return (false);
    }
    _amount -= withdrawal;
    _nbWithdrawals += 1;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals += 1;
    std::cout << withdrawal
    << ";amount:" << _amount
    << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (true);
}
int		Account::checkAmount( void ) const
{
    return (_amount);
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
    << ";amount:" << _amount
    << ";deposits:" << _nbDeposits
    << ";withdrawals:" << _nbWithdrawals << std::endl;
}

//diff <(sed 's/^\[[^]]*\] //' 19920104_091532.log) <(sed 's/^\[[^]]*\] //' mine.log)