#pragma once
#include <list>
#include "Person.h"
#include "Customer.h"
#include "Driver.h"
#include "Order.h"
#include "Car.h"
#include "structures.h"
#include <string>
#include <ctime>
#include <iostream>
using namespace std;
class TaxiCoorporation
{
private:
    list<Customer> Customers;
    list<Driver> Drivers;
    TaxiDepot taxiDepot;
    Orders ordes;
    PriceList priceList;
    string CorporationName;

    int FindOrderForDriver(int DriverID);
    int FindDriverForOrder(int OrderID);

public:
    TaxiCoorporation(PriceList pl, string CorporationName = "");
    ~TaxiCoorporation();

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
    PriceList GetPriceList() const;
    Orders GetOrders() const;
    TaxiDepot GetTaxiDepot() const;
    list<Driver> GetDrivers() const;
    list<Customer> GetCustomers() const;

    friend ostream &operator<<(ostream &os,
                               const TaxiCoorporation &tc);
    friend ostream &operator<<(ostream &os,
                               const PriceList &pl);
    friend ostream &operator<<(ostream &os,
                               const Orders &ordrs);
    friend ostream &operator<<(ostream &os,
                               const TaxiDepot &td);
};