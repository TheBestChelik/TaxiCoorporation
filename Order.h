class TaxiCorporation;

using namespace std;
class Order
{
private:
    TaxiCorporation *taxiCorporation;
    int CustomerID;

    unsigned int ID;

    Route route;
    float Price;
    time_t OrderDataTime;

    bool OrderDone;

public:
    unsigned int CarID;
    int DriverID;
    CarClass carClass;
    Order(TaxiCorporation *tc, unsigned int ID, unsigned int CustomerID,
          const string &StartingAdress, const string &FinalAdress,
          float Distance, const CarClass &CarClass, float Price);
    ~Order();

    int FinishOrder();

    bool GetOrderDoneState() const;
    Route GetRoute() const;
    CarClass GetCarClass() const;
    unsigned int GetCusomerID() const;
    unsigned int GetID() const;
    float GetPriceForCustomer() const;
    float GetPriceForDriver() const;
    time_t GetOrderTime() const;

    friend ostream &operator<<(ostream &os, const Route &r);
    friend ostream &operator<<(ostream &os, const Order &ord);
    friend ostream &operator<<(ostream &os,
                               const list<Order *> &ords);
};