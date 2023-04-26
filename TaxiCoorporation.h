#pragma once
#include <list>
#include "Person.h"
#include "Customer.h"
#include "Driver.h"
#include "Order.h"
#include "Car.h"
#include "structures.h"
#include <string>
#include <map>
#include <ctime>
#include <iostream>
using namespace std;
class TaxiCorporation
{
private:
    list<Customer> Customers;
    list<Driver> Drivers;
    list<Car> Cars;
    Orders ordes;
    map<CarClass, int> GetPrice;
    string CorporationName;

    int FindOrderForDriver(int DriverID);
    int FindDriverForOrder(int OrderID);

public:
    TaxiCorporation(string CorporationName = "");
    ~TaxiCorporation();

    int finishOrder(unsigned int orderID);
    int IssueCar(unsigned int CarID,
                 unsigned int DriverID);
    int ReturnCar(unsigned int CarID);
    unsigned int PostOrder(string StartAdress,
                           string FinalAdress,
                           float distance,
                           CarClass CarClass);
    int RemoveOrder(unsigned int OrderID);
    int FinidhOrder(unsigned int OrderID);
    int CalculatePrice(CarClass CarClass,
                       float Distance);

    unsigned int AddNewDriver(string FirstName,
                              string LastName,
                              string PhoneNum,
                              int DrivingExperience);
    unsigned int AddNewCustomer(string FirstName,
                                string LastName,
                                string PhoneNum,
                                float Discount);
    unsigned int AddNewCar(string CarNumber,
                           string Color,
                           unsigned int serialNuber,
                           CarClass CarClass);

    Order &GetOrderByID(unsigned int OrderID) const;
    Customer &GetCustomerByID(unsigned int CustomerID) const;
    Driver &GetDriverByID(unsigned int DriverID) const;
    Car &GetCarByID(unsigned int CarID) const;

    int RemoveDriver(unsigned int DriverID);
    int RemoveCustomer(unsigned int CustomerID);
    int RemoveCar(unsigned int CarID);

    string GetCorporationName() const;
    Orders GetOrders() const;
    list<Car> GetCars() const;
    list<Driver> GetDrivers() const;
    list<Customer> GetCustomers() const;

    friend ostream &operator<<(ostream &os,
                               const TaxiCorporation &tc);
    friend ostream &operator<<(ostream &os,
                               const Orders &ordrs);
};