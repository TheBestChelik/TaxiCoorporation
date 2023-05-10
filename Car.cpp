#pragma once
#include "TaxiCorporation.h"

Car::Car(unsigned int ID, const string &CarNumber, const string &Color,
         unsigned int SerialNumber, const CarClass &carClass)
    : ID(ID), CarNumber(CarNumber), Color(Color),
      SerialNumber(SerialNumber), carClass(carClass), Occupied(false)
{
}

Car::Car(const string &CarNumber, const string &Color, unsigned int SerialNumber,
         const CarClass &carClass)
    : Car(0, CarNumber, Color, SerialNumber, carClass)
{
}
Car::~Car() {}
// Get the car class
CarClass Car::GetCarClass() const
{
    return carClass;
}

// Get the car number
string Car::GetCarNumber() const
{
    return CarNumber;
}

// Get the car color
string Car::GetColor() const
{
    return Color;
}

// Get the car serial number
unsigned int Car::GetSerialNumber() const
{
    return SerialNumber;
}

// Get the car ID
unsigned int Car::GetID() const
{
    return ID;
}
void Car::UpdateOccupiedState(bool occupied)
{
    this->Occupied = occupied;
}
bool Car::GetOccupiedState() const
{
    return Occupied;
}
void Car::DriveOrder()
{
    // Car is driving
    // cout << "Car is driving" << endl;
}
// Output stream operator for CarClass enum
ostream &operator<<(ostream &os, const CarClass &cc)
{
    switch (cc)
    {
    case CarClass::Econom:
        os << "Econom";
        break;
    case CarClass::Business:
        os << "Business";
        break;
    case CarClass::Standart:
        os << "Standart";
        break;
    default:
        os << "Unknown";
        break;
    }
    return os;
}

// Output stream operator for list<Car>
ostream &operator<<(ostream &os, const list<Car> &cl)
{
    for (const auto &c : cl)
    {
        os << c << endl;
    }
    return os;
}

// Output stream operator for Car
ostream &operator<<(ostream &os, const Car &c)
{
    os << "Car #" << c.GetCarNumber() << endl
       << "Color: " << c.GetColor() << endl
       << "Serial Number: " << c.GetSerialNumber() << endl
       << "ID: " << c.GetID() << endl
       << "Class: " << c.GetCarClass() << endl
       << "Occupied: " << (c.Occupied ? "Yes" : "No") << endl;
    return os;
}