class TaxiCorporation;

using namespace std;
class Order
{
private:
    TaxiCorporation *taxiCorporation;
    int CustomerID;
    int DriverID;
    unsigned int ID;
    unsigned int CarID;
    Route route;
    float Price;
    time_t OrderDataTime;
    CarClass carClass;
    bool OrderDone;

    int GetPayment();
    int PayDriver();

public:
    Order(TaxiCorporation *tc, unsigned int ID, string StartingAdress, string FinalAdress, float Distance, CarClass CarClass);
    ~Order();

    int FinishOrder();

    bool GetOrderDoneState() const;
    Route GetRoute() const;
    unsigned int GetCusomerID() const;
    unsigned int GetDriverID() const;
    unsigned int GetID() const;
    unsigned int GetCarID() const;
    float GetPriceForCustomer() const;
    float GetPriceForDriver() const;
    time_t GetOrderTime() const;

    friend ostream &operator<<(ostream &os, const Route &r);
    friend ostream &operator<<(ostream &os, const Order &ord);
    friend ostream &operator<<(ostream &os,
                               const list<Order *> &ords);
};