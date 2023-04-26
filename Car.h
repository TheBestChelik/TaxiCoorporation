#pragma once
#include <TaxiCoorporation.h>
using namespace std;
class Car
{
private:
    string CarNumber;
    string Color;
    unsigned int SerialNumber;
    unsigned int ID;
    CarClass carClass;
    bool Occupied;

public:
    Car(unsigned int ID, string CarNumber = "",
        string Color = "",
        unsigned int SerialNumber = 0,
        CarClass carClass = Econom);
    ~Car();

    void DriveOrder(Order *order);
    void UpdateOccupiedState(bool occupied);

    CarClass GetCarClass() const;
    string GetCarNumber() const;
    string GetColor() const;
    unsigned int GetSerialNumber() const;
    unsigned int GetID() const;

    friend ostream &operator<<(ostream &os,
                               const CarClass &cc);
    friend ostream &operator<<(ostream &os,
                               const list<Car> &cl);
    friend ostream &operator<<(ostream &os,
                               const Car &c);
};