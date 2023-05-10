#pragma once
#include "TaxiCorporation.h"

// Constructor without ID parameter
Customer::Customer(const string &FirstName, const string &LastName, const string &PhoneNumber,
                   int Balance, float Discount)
    : Person(FirstName, LastName, PhoneNumber, Balance), Discount(Discount)
{
}

// Constructor with ID parameter
Customer::Customer(int ID, TaxiCorporation *tc, const string &FirstName, const string &LastName,
                   const string &PhoneNumber, int Balance, float Discount)
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
int Customer::OrderTaxi(const string &startAdress, const string &FinalAdress,
                        float distance, const CarClass &carClass)
{
    if (ActiveOrderID != 0)
    {
        return -2;
    }
    this->ActiveOrderID = taxiCoorporation->PostOrder(this->ID, startAdress, FinalAdress, distance, carClass);
    if (ActiveOrderID == 0)
        return -1;
    return 0;
}

// Check if balance is enough for an order
bool Customer::CheckBalance(int sum) const
{
    return (Balance >= sum);
}

// Cancel an order
int Customer::CancelOrder()
{
    Order &order = taxiCoorporation->GetOrderByID(ActiveOrderID);
    if (order.DriverID != 0)
    {
        return -1;
    }
    taxiCoorporation->RemoveOrder(ActiveOrderID);
    ActiveOrderID = 0;
    return 0;
}

// Update the discount
int Customer::UpdateDiscount(float discount)
{

    if (discount < 0 || discount > 1)
        return -1;
    Discount = discount;
    return 0;
}

// Get the discount
float Customer::GetDiscount() const
{
    return Discount;
}

// Use the discount
int Customer::UseDiscount(float price)
{
    return price * (1 - Discount);
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