#pragma once
#include <TaxiCoorporation.h>
using namespace std;
class Driver : public Person
{
private:
    unsigned int CurrentCarId;
    int DrivingExperience;
    WorkStatus workStatus;

public:
    Driver(string FirstName = "Driver",
           string LastName = "",
           string PhoneNumber = "", int Balance = 0,
           int DrivingExperience = 0);
    Driver(TaxiCorporation *tc, unsigned int id,
           string FirstName = "Driver",
           string LastName = "",
           string PhoneNumber = "", int Balance = 0,
           int DrivingExperience = 0);
    ~Driver();

    int StartWork(unsigned int CarID);
    int StopWork();
    int ChangeCar(unsigned int CarID);
    int SetOrder(unsigned int OrderID);
    void CompeteOrder();

    WorkStatus GetWorkStatus() const;
    void UpdateWorkStatus(WorkStatus ws);
    unsigned int GetCurrentCarID() const;
    int GetDrivingExperience() const;

    friend ostream &operator<<(ostream &os,
                               const WorkStatus &ws);
    friend ostream &operator<<(ostream &os,
                               const Driver &dr);
    friend ostream &operator<<(ostream &os,
                               const list<Driver *> &dl);
};