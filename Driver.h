class TaxiCorporation;
using namespace std;
class Driver : public Person
{
private:
       unsigned int CurrentCarId;
       int DrivingExperience;

public:
       WorkStatus workStatus;

       Driver(const string &FirstName = "Driver",
              const string &LastName = "",
              const string &PhoneNumber = "", int Balance = 0,
              int DrivingExperience = 0);
       Driver(TaxiCorporation *tc, unsigned int id,
              const string &FirstName = "Driver",
              const string &LastName = "",
              const string &PhoneNumber = "", int Balance = 0,
              int DrivingExperience = 0);
       ~Driver();

       int StartWork(unsigned int CarID);
       int StopWork();
       int ChangeCar(unsigned int CarID);
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