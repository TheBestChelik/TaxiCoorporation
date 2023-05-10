#pragma once
#include "TaxiCorporation.h"

Person::Person(const string &FirstName, const string &LastName, const string &PhoneNumber, int Balance)
    : FirstName(FirstName), LastName(LastName), PhoneNumber(PhoneNumber),
      taxiCoorporation(nullptr), ActiveOrderID(0), Balance(Balance), ID(0)
{
}

// Destructor
Person::~Person()
{
}
// Sets the order
void Person::SetOrder(unsigned int OrderID)
{
    this->ActiveOrderID = OrderID;
}
// Get the first name
string Person::GetFirstName() const
{
    return FirstName;
}

// Get the last name
string Person::GetLastName() const
{
    return LastName;
}

// Get the phone number
string Person::GetPhoneNumber() const
{
    return PhoneNumber;
}

// Get the active order ID
unsigned int Person::GetActiveOrderID() const
{
    return ActiveOrderID;
}

// Get the balance
int Person::GetBalance() const
{
    return Balance;
}

// Get the ID
unsigned int Person::GetID() const
{
    return ID;
}

// Add money to the balance
void Person::TopUpBalance(int sum)
{
    Balance += sum;
}

// Deduct money from the balance
int Person::ReduceBalance(int sum)
{
    if (Balance >= sum)
    {
        Balance -= sum;
        return sum;
    }
    else
    {
        int reducedSum = Balance;
        Balance = 0;
        return reducedSum;
    }
}
