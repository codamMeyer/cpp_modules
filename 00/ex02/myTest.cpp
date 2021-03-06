#include "Account.hpp"
#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <functional>
#include <iostream>
#include <iterator>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

class AccountTest
{
public:
  AccountTest()
    : ClientA(initial_deposit)
  {}
  const int initial_deposit = 100;
  Account ClientA;
};

TEST_CASE_METHOD(AccountTest, "getNbAccounts : One account")
{
  CHECK(Account::getNbAccounts() == 1);
}

TEST_CASE_METHOD(AccountTest, "getTotalAmount")
{
  CHECK(Account::getTotalAmount() == initial_deposit);
}

TEST_CASE_METHOD(AccountTest, "getNbDeposits")
{
  CHECK(Account::getNbDeposits() == 0);
}

TEST_CASE_METHOD(AccountTest, "getNbWithdrawals")
{
  CHECK(Account::getNbWithdrawals() == 0);
}

TEST_CASE_METHOD(AccountTest, "Make Deposit")
{
  REQUIRE(ClientA.checkAmount() == initial_deposit);
  ClientA.makeDeposit(200);
  CHECK(ClientA.checkAmount() == 300);
  CHECK(Account::getTotalAmount() == 300);
  CHECK(Account::getNbDeposits() == 1);
}

TEST_CASE_METHOD(AccountTest, "Withdraw More than available")
{
  REQUIRE(ClientA.checkAmount() == initial_deposit);
  REQUIRE(Account::getNbWithdrawals() == 0);
  CHECK_FALSE(ClientA.makeWithdrawal(300));
  CHECK(ClientA.checkAmount() == initial_deposit);
  CHECK(Account::getNbWithdrawals() == 0);
}

TEST_CASE_METHOD(AccountTest, "Withdraw valid amount")
{
  REQUIRE(ClientA.checkAmount() == initial_deposit);
  REQUIRE(Account::getNbWithdrawals() == 0);
  CHECK(ClientA.makeWithdrawal(50));
  CHECK(ClientA.checkAmount() == 50);
  CHECK(Account::getTotalAmount() == 50);
  CHECK(Account::getNbWithdrawals() == 1);
}

TEST_CASE_METHOD(AccountTest,
		 "Check amount after Client creation (initial deposit)")
{
  CHECK(ClientA.checkAmount() == initial_deposit);
}

class MultipleAccountTest : public AccountTest
{
public:
  MultipleAccountTest()
    : amounts{ 100, 200, 300 }
    , accounts(std::begin(amounts), std::end(amounts))
  {}
  int const amounts[3];
  std::vector<Account> accounts;
};

TEST_CASE_METHOD(MultipleAccountTest, "Check Number of Accounts")
{
  REQUIRE(Account::getNbAccounts() == 4);
  CHECK(Account::getTotalAmount() == 700);
}

// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

class GlobalBankstersUnitedTest
{
public:
  GlobalBankstersUnitedTest()
    : amounts{ 42, 54, 957, 432, 1234, 0, 754, 16576 }
    , deposits{ 5, 765, 564, 2, 87, 23, 9, 20 }
    , withdrawals{ 321, 34, 657, 4, 76, 275, 657, 7654 }
    , accounts(std::begin(amounts), std::end(amounts))
  {
    std::cout << "\n\n";
    Account::displayAccountsInfos();
    for (int i = 0; i < Account::getNbAccounts(); ++i)
      accounts[i].displayStatus();
  }
  ~GlobalBankstersUnitedTest() { std::cout << "\n\n"; }
  int const amounts[8];
  int const deposits[8];
  int const withdrawals[8];
  std::vector<Account> accounts;
};

TEST_CASE_METHOD(GlobalBankstersUnitedTest, "Deposits")
{
  for (int i = 0; i < Account::getNbAccounts(); ++i) {
    int prev_amount = accounts[i].checkAmount();
    accounts[i].makeDeposit(deposits[i]);
    CHECK(accounts[i].checkAmount() == (prev_amount + deposits[i]));
  }
}

TEST_CASE_METHOD(GlobalBankstersUnitedTest, "Withdrawal")
{
  for (int i = 0; i < Account::getNbAccounts(); ++i) {
    int prev_amount = accounts[i].checkAmount();
    if (accounts[i].makeWithdrawal(withdrawals[i]))
      CHECK(accounts[i].checkAmount() == (prev_amount - withdrawals[i]));
    else
      CHECK(accounts[i].checkAmount() == prev_amount);
  }
}
