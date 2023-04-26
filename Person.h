#pragma once
#include <TaxiCoorporation.h>
using namespace std;
class Person
{
protected:
    string FirstName;
    string LastName;
    string PhoneNumber;
    TaxiCoorporation *taxiCoorporation;
    unsigned int ActiveOrderID;
    int Balance;
    unsigned int ID;

public:
    Person(TaxiCoorporation *taxi, string FirstName = "",
           string LastName = "", string PhoneNumber = "",
           int Balance = 0);
    ~Person();

    string GetFirstName();
    string GetLastName();
    string GetPhoneNumber();
    unsigned int GetActiveOrderID();
    int GetBalance();
    unsigned int GetID();

    void TopUpBalance(int sum);
    int ReduceBalance(int sum);
};