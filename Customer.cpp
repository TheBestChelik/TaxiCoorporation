#pragma once
#include "TaxiCorporation.h"

// Constructor without ID parameter
Customer::Customer(string FirstName, string LastName, string PhoneNumber, int Balance, float Discount)
    : Person(FirstName, LastName, PhoneNumber, Balance), Discount(Discount)
{
}

// Constructor with ID parameter
Customer::Customer(int ID, TaxiCorporation *tc, string FirstName, string LastName, string PhoneNumber, int Balance, float Discount)
    : Person(FirstName, LastName, PhoneNumber, Balance), Discount(Discount)
{
    this->ID = ID;
    this->taxiCoorporation = tc;
}

// Destructor
Customer::~Customer()
{
}

// Order a taxi
int Customer::OrderTaxi(string startAdress, string FinalAdress, float distance, CarClass carClass)
{
}

// Check if balance is enough for an order
bool Customer::CheckBalance(int sum) const
{
    return (Balance >= sum);
}

// Cancel an order
int Customer::CancelOrder()
{
}

// Update the discount
void Customer::UpdateDiscount(float discount)
{
    Discount = discount;
}

// Get the discount
float Customer::GetDiscount() const
{
    return Discount;
}

// Use the discount
int Customer::UseDiscount(float price)
{
    int discountPrice = price * Discount;
    Balance -= discountPrice;
    return discountPrice;
}

// Output stream operator for Customer
ostream &operator<<(ostream &os, const Customer &c)
{
    os << "Customer ID: " << c.GetID() << endl
       << "Name: " << c.GetFirstName() << " " << c.GetLastName() << endl
       << "Phone Number: " << c.GetPhoneNumber() << endl
       << "Balance: " << c.GetBalance() << endl
       << "Discount: " << c.Discount << endl;
    return os;
}

// Output stream operator for list<Customer*>
ostream &operator<<(ostream &os, const list<Customer *> &cl)
{
    for (const auto &c : cl)
    {
        os << *c << endl;
    }
    return os;
}