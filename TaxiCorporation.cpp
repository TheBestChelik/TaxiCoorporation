#pragma once
#include "TaxiCorporation.h"
#include <map>

// Private methods

bool TaxiCorporation::CarInList(unsigned int ID) const
{
    for (const auto &c : Cars)
    {
        if (c.GetID() == ID)
        {
            return true;
        }
    }
    return false;
}

bool TaxiCorporation::DriverInList(unsigned int ID) const
{
    for (const auto &d : Drivers)
    {
        if (d.GetID() == ID)
        {
            return true;
        }
    }
    return false;
}

bool TaxiCorporation::CustomerInList(unsigned int ID) const
{
    for (const auto &c : Customers)
    {
        if (c.GetID() == ID)
        {
            return true;
        }
    }
    return false;
}

bool TaxiCorporation::OrderInList(unsigned int ID) const
{
    for (const auto &o : Orders)
    {
        if (o.GetID() == ID)
        {
            return true;
        }
    }
    return false;
}

int TaxiCorporation::FindOrderForDriver(int DriverID)
{
    Driver &Driver = GetDriverByID(DriverID);
    auto CarID = Driver.GetCurrentCarID();
    if (CarID == 0)
        return -1;
    CarClass cc = GetCarByID(CarID).GetCarClass();
    for (auto &o : Orders)
    {
        if (!o.GetOrderDoneState())
        {
            if (o.carClass == cc)
            {
                Driver.SetOrder(o.GetID());
                o.DriverID = DriverID;
                o.CarID = CarID;
                return 0;
            }
        }
    }
    return 1;
}

int TaxiCorporation::FindDriverForOrder(int OrderID)
{
    Order &order = GetOrderByID(OrderID);
    CarClass carClass = order.carClass;
    for (auto &d : Drivers)
    {
        if (d.workStatus == WaitingForOrder)
        {
            CarClass cc = GetCarByID(d.GetCurrentCarID()).GetCarClass();
            if (cc == carClass)
            {
                d.SetOrder(OrderID);
                order.DriverID = d.GetID();
                order.CarID = d.GetCurrentCarID();
                return 0;
            }
        }
    }
    return 1;
}

// Public methods

TaxiCorporation::TaxiCorporation(const string &CorporationName)
{
    this->CorporationName = CorporationName;
    GetPrice.insert(std::make_pair(CarClass::Econom, 10));
    GetPrice.insert(std::make_pair(CarClass::Standart, 15));
    GetPrice.insert(std::make_pair(CarClass::Business, 20));
}

TaxiCorporation::~TaxiCorporation()
{
}

int TaxiCorporation::FinishOrder(unsigned int orderID)
{
    Order &order = GetOrderByID(orderID);
    order.FinishOrder();
}

int TaxiCorporation::IssueCar(unsigned int CarID, unsigned int DriverID)
{
    if (!CarInList(CarID) || !DriverInList(DriverID))
        return -3;
    if (GetCarByID(CarID).GetOccupiedState() == true)
        return -2;
    Driver &driver = GetDriverByID(DriverID);
    driver.ChangeCar(CarID);

    driver.workStatus = WaitingForOrder;
    int res = FindOrderForDriver(DriverID);
    if (res < 0)
        return -5;
    if (res == 0)
    {
        driver.workStatus = OnOrder;
    }
    return 0;
}

int TaxiCorporation::ReturnCar(unsigned int CarID)
{
    if (CarID != 0)
        GetCarByID(CarID).UpdateOccupiedState(false);
    return 0;
}

unsigned int TaxiCorporation::PostOrder(unsigned int CustomerID, const string &StartAdress,
                                        const string &FinalAdress, float distance, const CarClass &CarClass)
{
    Customer &customer = GetCustomerByID(CustomerID);
    float Price = CalculatePrice(CarClass, distance);
    if (!customer.CheckBalance(customer.UseDiscount(Price)))
    {
        return 0;
    }
    unsigned int id = Orders.empty() ? 1 : (Orders.back().GetID() + 1);
    Orders.push_back(Order(this, id, CustomerID, StartAdress, FinalAdress, distance, CarClass, Price));
    int res = FindDriverForOrder(id);

    return id;
}

int TaxiCorporation::RemoveOrder(unsigned int OrderID)
{
    for (auto it = Orders.begin(); it != Orders.end(); ++it)
    {
        if (it->GetID() == OrderID)
        {
            Orders.erase(it);
            return 0;
        }
    }
}

int TaxiCorporation::CalculatePrice(CarClass CarClass, float Distance)
{
    return Distance * GetPrice[CarClass];
}

unsigned int TaxiCorporation::AddNewDriver(const string &FirstName,
                                           const string &LastName,
                                           const string &PhoneNum,
                                           int DrivingExperience)
{
    unsigned int id = Drivers.empty() ? 1 : (Drivers.back().GetID() + 1);
    Drivers.push_back(Driver(this, id, FirstName, LastName, PhoneNum, 0, DrivingExperience));
    return id;
}

unsigned int TaxiCorporation::AddNewCustomer(const string &FirstName,
                                             const string &LastName,
                                             const string &PhoneNum, float Discount)
{
    unsigned int id = Customers.empty() ? 1 : (Customers.back().GetID() + 1);
    Customers.push_back(Customer(id, this, FirstName, LastName, PhoneNum, 0, Discount));
    return id;
}

unsigned int TaxiCorporation::AddNewCar(const string &CarNumber,
                                        const string &Color, unsigned int serialNuber,
                                        const CarClass &CarClass)
{
    unsigned int id = Cars.empty() ? 1 : (Cars.back().GetID() + 1);
    Cars.push_back(Car(id, CarNumber, Color, serialNuber, CarClass));
    return id;
}

Order &TaxiCorporation::GetOrderByID(unsigned int OrderID) const
{
    for (auto &o : Orders)
    {
        if (o.GetID() == OrderID)
        {
            return const_cast<Order &>(o);
        }
    }
    throw invalid_argument("No order with the specified ID.");
}

Customer &TaxiCorporation::GetCustomerByID(unsigned int CustomerID) const
{
    for (auto &c : Customers)
    {
        if (c.GetID() == CustomerID)
        {
            return const_cast<Customer &>(c);
        }
    }
    throw invalid_argument("No customer with the specified ID.");
}

Driver &TaxiCorporation::GetDriverByID(unsigned int DriverID) const
{
    for (auto &d : Drivers)
    {
        if (d.GetID() == DriverID)
        {
            return const_cast<Driver &>(d);
        }
    }
    throw invalid_argument("No driver with the specified ID.");
}

Car &TaxiCorporation::GetCarByID(unsigned int CarID) const
{
    for (auto &c : Cars)
    {
        if (c.GetID() == CarID)
        {
            return const_cast<Car &>(c);
        }
    }
    throw invalid_argument("No car with the specified ID.");
}

int TaxiCorporation::RemoveDriver(unsigned int DriverID)
{
    if (!DriverInList(DriverID))
        return 1;
    if (GetDriverByID(DriverID).workStatus != OnBreak)
    {
        return -1;
    }
    Drivers.remove_if([&](Driver &d)
                      { return d.GetID() == DriverID; });
    return 0;
}

int TaxiCorporation::RemoveCustomer(unsigned int CustomerID)
{
    if (!CustomerInList(CustomerID))
        return 1;
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
    if (!CarInList(CarID))
        return 1;
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
