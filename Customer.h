#pragma once
#include <TaxiCoorporation.h>
using namespace std;
class Customer : public Person
{
private:
    float Discount;

public:
    Customer(TaxiCoorporation *taxi, int ID,
             string FirstName = "Customer", string LastName = "",
             string PhoneNumber = "", int Balance = 0,
             float Discount = 0);
    ~Customer();

    int OrderTaxi(string startAdress, string FinalAdress,
                  float distance, CarClass carClass);
    bool CheckBalance(int sum);
    int CancelOrder();

    void UpdateDiscount(float discount);
    int UseDiscount(float price);

    friend ostream &operator<<(ostream &os, const Customer &c);
    friend ostream &operator<<(ostream &os, const list<Customer *> &cl);
};