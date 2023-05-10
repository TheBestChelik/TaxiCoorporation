#ifndef STRUCTURES_H
#define STRUCTURES_H
#include "structures.h"
#endif /* STRUCTURES_H */
class TaxiCorporation;
using namespace std;
class Customer : public Person
{
private:
    float Discount;

public:
    Customer(const string &FirstName = "", const string &LastName = "",
             const string &PhoneNumber = "", int Balance = 0,
             float Discount = 0);
    Customer(int ID, TaxiCorporation *tc,
             const string &FirstName = "", const string &LastName = "",
             const string &PhoneNumber = "", int Balance = 0,
             float Discount = 0);
    ~Customer();

    int OrderTaxi(const string &startAdress, const string &FinalAdress,
                  float distance, const CarClass &carClass);
    bool CheckBalance(int sum) const;
    int CancelOrder();

    int UpdateDiscount(float discount);
    float GetDiscount() const;
    int UseDiscount(float price);

    friend ostream &operator<<(ostream &os, const Customer &c);
    friend ostream &operator<<(ostream &os, const list<Customer *> &cl);
};