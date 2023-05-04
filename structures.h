using namespace std;
enum WorkStatus
{
    OnBreak = 0,
    WaitingForOrder = 1,
    OnOrder = 2
};
enum CarClass
{
    Econom = 0,
    Standart = 1,
    Business = 2
};
struct Route
{
    string StartAdress;
    string FinishAdress;
    float Distance;
};