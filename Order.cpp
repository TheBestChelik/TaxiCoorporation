#pragma once
#include "TaxiCorporation.h"
// Default constructor
Order::Order(TaxiCorporation *tc, unsigned int Id,
             string StartingAdress, string FinalAdress, float Distance,
             CarClass CarClass) : taxiCorporation(tc), ID(Id), carClass(CarClass)
{
    this->route.StartAdress = StartingAdress;
    this->route.FinishAdress = FinalAdress;
    this->route.Distance = Distance;
}
// Destructor
Order::~Order()
{
}

// Finish the order and update the customer and driver balances and order status
int Order::FinishOrder()
{
}

// Get the order done state
bool Order::GetOrderDoneState() const
{
    return OrderDone;
}

// Get the order route
Route Order::GetRoute() const
{
    return route;
}

// Get the customer ID
unsigned int Order::GetCusomerID() const
{
    return CustomerID;
}

// Get the driver ID
unsigned int Order::GetDriverID() const
{
    return DriverID;
}

// Get the order ID
unsigned int Order::GetID() const
{
    return ID;
}

// Get the car ID
unsigned int Order::GetCarID() const
{
    return CarID;
}

// Get the price for the customer
float Order::GetPriceForCustomer() const
{
    return Price;
}

// Get the price for the driver
float Order::GetPriceForDriver() const
{
    return Price;
}

// Get the order time
time_t Order::GetOrderTime() const
{
    return OrderDataTime;
}

// Get the payment for the order
int Order::GetPayment()
{
}

// Pay the driver for the order
int Order::PayDriver()
{
}

// Output stream operator for Route
ostream &operator<<(ostream &os, const Route &r)
{
    os << r.StartAdress << " - " << r.FinishAdress << " (" << r.Distance << " km)";
    return os;
}
// Output stream operator for Order
ostream &operator<<(ostream &os, const Order &ord)
{
    os << "Order ID: " << ord.ID << endl
       << "Customer ID: " << ord.CustomerID << endl
       << "Driver ID: " << ord.DriverID << endl
       << "Car ID: " << ord.CarID << endl
       << "Route: " << ord.route << endl
       << "Price for customer: " << ord.GetPriceForCustomer() << endl
       << "Price for driver: " << ord.GetPriceForDriver() << endl
       << "Order time: " << ctime(&ord.OrderDataTime) << endl
       << "Order done: " << (ord.OrderDone ? "Yes" : "No") << endl;
    return os;
}

// Output stream operator for list<Order*>
ostream &operator<<(ostream &os, const list<Order *> &ords)
{
    for (const auto &o : ords)
    {
        os << *o << endl;
    }
    return os;
}