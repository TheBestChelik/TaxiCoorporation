#pragma once
#include "TaxiCorporation.h"

// Constructor without ID parameter
Driver::Driver(string FirstName, string LastName, string PhoneNumber, int Balance, int DrivingExperience)
    : Person(FirstName, LastName, PhoneNumber, Balance), CurrentCarId(0), DrivingExperience(DrivingExperience)
{
    workStatus = WorkStatus::OnBreak;
}

// Constructor with ID parameter
Driver::Driver(TaxiCorporation *tc, unsigned int id, string FirstName, string LastName, string PhoneNumber, int Balance, int DrivingExperience)
    : Person(FirstName, LastName, PhoneNumber, Balance), CurrentCarId(0), DrivingExperience(DrivingExperience)
{
    this->ID = id;
    this->taxiCoorporation = tc;
    workStatus = WorkStatus::OnBreak;
}

// Destructor
Driver::~Driver()
{
}

// Start working
int Driver::StartWork(unsigned int CarID)
{
    if (taxiCoorporation == nullptr)
        return -1;
    return taxiCoorporation->IssueCar(CarID, this->ID);
}

// Stop working
int Driver::StopWork()
{
    if (ActiveOrderID != 0)
        return -1;
    taxiCoorporation->ReturnCar(CurrentCarId);
    CurrentCarId = 0;
    workStatus = OnBreak;
    return 0;
}

// Change car
int Driver::ChangeCar(unsigned int CarID)
{
    taxiCoorporation->ReturnCar(CurrentCarId);
    CurrentCarId = CarID;
}
// Complete order
void Driver::CompeteOrder()
{
    taxiCoorporation->GetCarByID(CurrentCarId).DriveOrder();
    taxiCoorporation->FinishOrder(ActiveOrderID);
}

// Get the work status
WorkStatus Driver::GetWorkStatus() const
{
    return workStatus;
}

// Update the work status
void Driver::UpdateWorkStatus(WorkStatus ws)
{
    workStatus = ws;
}

// Get the current car ID
unsigned int Driver::GetCurrentCarID() const
{
    return CurrentCarId;
}

// Get the driving experience
int Driver::GetDrivingExperience() const
{
    return DrivingExperience;
}

// Output stream operator for WorkStatus
ostream &operator<<(ostream &os, const WorkStatus &ws)
{
    switch (ws)
    {
    case OnBreak:
        os << "On break";
        break;
    case WaitingForOrder:
        os << "Waiting for order";
        break;
    case OnOrder:
        os << "On order";
        break;
    default:
        os << "Unknown work status";
        break;
    }
    return os;
}

// Output stream operator for Driver
ostream &operator<<(ostream &os, const Driver &dr)
{
    os << "Driver ID: " << dr.GetID() << endl
       << "Name: " << dr.GetFirstName() << " " << dr.GetLastName() << endl
       << "Phone Number: " << dr.GetPhoneNumber() << endl
       << "Balance: " << dr.GetBalance() << endl
       << "Current Car ID: " << dr.CurrentCarId << endl
       << "Driving Experience: " << dr.DrivingExperience << endl
       << "Work Status: " << dr.workStatus << endl;
    return os;
}

// Output stream operator for list<Driver*>
ostream &operator<<(ostream &os, const list<Driver *> &dl)
{
    for (const auto &d : dl)
    {
        os << *d << endl;
    }
    return os;
}