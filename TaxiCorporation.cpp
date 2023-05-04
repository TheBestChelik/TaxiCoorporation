#pragma once
#include "TaxiCorporation.h"
#include <map>

// Private methods

int TaxiCorporation::FindOrderForDriver(int DriverID)
{
}

int TaxiCorporation::FindDriverForOrder(int OrderID)
{
}

// Public methods

TaxiCorporation::TaxiCorporation(string CorporationName)
{
    this->CorporationName = CorporationName;
    GetPrice.insert(std::make_pair(CarClass::Econom, 10));
    GetPrice.insert(std::make_pair(CarClass::Standart, 15));
    GetPrice.insert(std::make_pair(CarClass::Business, 20));
}

TaxiCorporation::~TaxiCorporation()
{
}

int TaxiCorporation::finishOrder(unsigned int orderID)
{
}

int TaxiCorporation::IssueCar(unsigned int CarID, unsigned int DriverID)
{
}

int TaxiCorporation::ReturnCar(unsigned int CarID)
{
}

unsigned int TaxiCorporation::PostOrder(string StartAdress, string FinalAdress, float distance, CarClass CarClass)
{
}

int TaxiCorporation::RemoveOrder(unsigned int OrderID)
{
}

int TaxiCorporation::FinidhOrder(unsigned int OrderID)
{
}
int TaxiCorporation::CalculatePrice(CarClass CarClass, float Distance)
{
    return Distance * GetPrice[CarClass];
}

unsigned int TaxiCorporation::AddNewDriver(string FirstName, string LastName, string PhoneNum, int DrivingExperience)
{
    unsigned int id = Drivers.empty() ? 1 : (Drivers.back().GetID() + 1);
    Drivers.push_back(Driver(this, id, FirstName, LastName, PhoneNum, 0, DrivingExperience));
    return id;
}

unsigned int TaxiCorporation::AddNewCustomer(string FirstName, string LastName, string PhoneNum, float Discount)
{
    unsigned int id = Customers.empty() ? 1 : (Customers.back().GetID() + 1);
    Customers.push_back(Customer(id, this, FirstName, LastName, PhoneNum, 0, Discount));
    return id;
}

unsigned int TaxiCorporation::AddNewCar(string CarNumber, string Color, unsigned int serialNuber, CarClass CarClass)
{
    unsigned int id = Cars.empty() ? 1 : (Cars.back().GetID() + 1);
    Cars.push_back(Car(id, CarNumber, Color, serialNuber, CarClass));
    return id;
}

const Order &TaxiCorporation::GetOrderByID(unsigned int OrderID) const
{
    for (auto &o : Orders)
    {
        if (o.GetID() == OrderID)
        {
            return o;
        }
    }
    throw invalid_argument("No order with the specified ID.");
}

const Customer &TaxiCorporation::GetCustomerByID(unsigned int CustomerID) const
{
    for (auto &c : Customers)
    {
        if (c.GetID() == CustomerID)
        {
            return c;
        }
    }
    throw invalid_argument("No customer with the specified ID.");
}

const Driver &TaxiCorporation::GetDriverByID(unsigned int DriverID) const
{
    for (auto &d : Drivers)
    {
        if (d.GetID() == DriverID)
        {
            return d;
        }
    }
    throw invalid_argument("No driver with the specified ID.");
}

const Car &TaxiCorporation::GetCarByID(unsigned int CarID) const
{
    for (auto &c : Cars)
    {
        if (c.GetID() == CarID)
        {
            return c;
        }
    }
    throw invalid_argument("No car with the specified ID.");
}

int TaxiCorporation::RemoveDriver(unsigned int DriverID)
{
    if (GetDriverByID(DriverID).GetWorkStatus() != OnBreak)
    {
        return -1;
    }
    Drivers.remove_if([&](Driver &d)
                      { return d.GetID() == DriverID; });
    return 0;
}

int TaxiCorporation::RemoveCustomer(unsigned int CustomerID)
{
    if (GetCustomerByID(CustomerID).GetActiveOrderID() != 0)
    {
        return -1;
    }
    Customers.remove_if([&](Customer &c)
                        { return c.GetID() == CustomerID; });
    return 0;
}

int TaxiCorporation::RemoveCar(unsigned int CarID)
{
    if (GetCarByID(CarID).GetOccupiedState())
    {
        return -1;
    }
    Cars.remove_if([&](Car &c)
                   { return c.GetID() == CarID; });
    return 0;
}

string TaxiCorporation::GetCorporationName() const
{
    return CorporationName;
}
list<Order> TaxiCorporation::GetOrders() const
{
    return Orders;
}
list<Car> TaxiCorporation::GetCars() const
{
    return Cars;
}

list<Driver> TaxiCorporation::GetDrivers() const
{
    return Drivers;
}

list<Customer> TaxiCorporation::GetCustomers() const
{
    return Customers;
}
ostream &operator<<(ostream &os, const list<Order> &orders)
{
    for (auto &order : orders)
    {
        os << order << endl;
    }
    return os;
}
