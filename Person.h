class TaxiCorporation;
using namespace std;
class Person
{
protected:
    string FirstName;
    string LastName;
    string PhoneNumber;
    TaxiCorporation *taxiCoorporation;
    unsigned int ActiveOrderID;
    int Balance;
    unsigned int ID;

public:
    Person(const string &FirstName = "",
           const string &LastName = "",
           const string &PhoneNumber = "",
           int Balance = 0);
    ~Person();

    string GetFirstName() const;
    string GetLastName() const;
    string GetPhoneNumber() const;
    unsigned int GetActiveOrderID() const;
    void SetOrder(unsigned int OrderID);
    int GetBalance() const;
    unsigned int GetID() const;

    void TopUpBalance(int sum);
    int ReduceBalance(int sum);
};