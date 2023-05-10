#include "TaxiCorporation.h"
#include <cstring>
#include <cassert>

void testCar()
{
    // Test default constructor
    Car car1;
    assert(car1.GetID() == 0);
    assert(car1.GetCarNumber() == "");
    assert(car1.GetColor() == "");
    assert(car1.GetSerialNumber() == 0);
    assert(car1.GetCarClass() == CarClass::Standart);
    assert(!car1.GetOccupiedState());

    // Test parameterized constructor
    Car car2(1, "ABC123", "Red", 123, CarClass::Standart);
    assert(car2.GetID() == 1);
    assert(car2.GetCarNumber() == "ABC123");
    assert(car2.GetColor() == "Red");
    assert(car2.GetSerialNumber() == 123);
    assert(car2.GetCarClass() == CarClass::Standart);
    assert(!car2.GetOccupiedState());

    // UpdateOccupiedState methods
    Order order(nullptr, 1, 132, "123 Main St", "456 Elm St", 10.5, CarClass::Standart, 125);
    car2.UpdateOccupiedState(true);
    assert(car2.GetOccupiedState());
    car2.UpdateOccupiedState(false);
    assert(!car2.GetOccupiedState());
}
void testCustomer()
{
    // Test default constructor
    Customer customer1;
    assert(customer1.GetID() == 0);
    assert(customer1.GetFirstName() == "");
    assert(customer1.GetLastName() == "");
    assert(customer1.GetPhoneNumber() == "");
    assert(customer1.GetBalance() == 0);
    assert(customer1.GetDiscount() == 0);

    // Test parameterized constructor
    Customer customer2(1, nullptr, "John", "Doe", "123-456-7890", 100, 0.1f);
    assert(customer2.GetID() == 1);
    assert(customer2.GetFirstName() == "John");
    assert(customer2.GetLastName() == "Doe");
    assert(customer2.GetPhoneNumber() == "123-456-7890");
    assert(customer2.GetBalance() == 100);
    assert(customer2.GetDiscount() == 0.1f);
}
void testTaxiCorporation()
{
    // Test adding and removing cars
    TaxiCorporation taxi("Taxi Corp");
    unsigned int carID = taxi.AddNewCar("ABC123", "Red", 123, CarClass::Standart);
    assert(taxi.GetCars().size() == 1);
    assert(taxi.GetCarByID(carID).GetID() == carID);
    taxi.RemoveCar(carID);
    assert(taxi.GetCars().size() == 0);

    // Test adding and removing drivers
    unsigned int driverID = taxi.AddNewDriver("John", "Doe", "555-1234", 2);
    assert(taxi.GetDrivers().size() == 1);
    assert(taxi.GetDriverByID(driverID).GetID() == driverID);
    taxi.RemoveDriver(driverID);
    assert(taxi.GetDrivers().size() == 0);

    // Test adding and removing customers
    unsigned int customerID = taxi.AddNewCustomer("Jane", "Doe", "555-5678", 0.1);
    assert(taxi.GetCustomers().size() == 1);
    assert(taxi.GetCustomerByID(customerID).GetID() == customerID);
    taxi.RemoveCustomer(customerID);
    assert(taxi.GetCustomers().size() == 0);
}
void testDriver()
{
    // Test default constructor
    Driver driver1;
    assert(driver1.GetID() == 0);
    assert(driver1.GetFirstName() == "Driver");
    assert(driver1.GetLastName() == "");
    assert(driver1.GetPhoneNumber() == "");
    assert(driver1.GetBalance() == 0);
    assert(driver1.GetDrivingExperience() == 0);
    assert(driver1.GetCurrentCarID() == 0);
    assert(driver1.workStatus == OnBreak);
    // Test parameterized constructor
    TaxiCorporation taxiCorp;
    Driver driver2(&taxiCorp, 1, "John", "Doe", "123-456-7890", 100, 5);
    assert(driver2.GetID() == 1);
    assert(driver2.GetFirstName() == "John");
    assert(driver2.GetLastName() == "Doe");
    assert(driver2.GetPhoneNumber() == "123-456-7890");
    assert(driver2.GetBalance() == 100);
    assert(driver2.GetDrivingExperience() == 5);
    assert(driver2.GetCurrentCarID() == 0);
    assert(driver2.workStatus == OnBreak);
}
void TestOrder()
{
    // Create a TaxiCorporation object to pass as a parameter to Order constructor
    TaxiCorporation taxiCorp;
    // Test constructor
    Order order1(&taxiCorp, 1, 2, "123 Main St", "456 Elm St", 5.0, CarClass::Standart, 125);
    assert(order1.GetID() == 1);
    assert(order1.GetCusomerID() == 2);
    assert(order1.DriverID == 0);
    assert(order1.CarID == 0);
    assert(order1.GetOrderDoneState() == false);
    assert(order1.GetRoute().StartAdress == "123 Main St");
    assert(order1.GetRoute().FinishAdress == "456 Elm St");
    assert(order1.GetRoute().Distance == 5.0);
    assert(order1.carClass == CarClass::Standart);

    // Test setters and getters
    order1.DriverID = 3;
    order1.CarID = 4;
    assert(order1.DriverID == 3);
    assert(order1.CarID == 4);
}
void testAddingRemoving()
{
    TaxiCorporation taxiCorp = TaxiCorporation();
    unsigned int driver1ID = taxiCorp.AddNewDriver("John", "Doe", "123-456-7890", 5);
    unsigned int driver2ID = taxiCorp.AddNewDriver("Jane", "Doe", "098-765-4321", 2);
    unsigned int customer1ID = taxiCorp.AddNewCustomer("Alice", "Smith", "555-123-4567", 0.2);
    unsigned int customer2ID = taxiCorp.AddNewCustomer("Bob", "Johnson", "555-987-6543", 0.1);
    unsigned int car1ID = taxiCorp.AddNewCar("ABC123", "Red", 12345, Econom);
    unsigned int car2ID = taxiCorp.AddNewCar("DEF456", "Blue", 67890, Business);

    assert(taxiCorp.GetDrivers().size() == 2);
    assert(taxiCorp.GetCustomers().size() == 2);
    assert(taxiCorp.GetCars().size() == 2);

    taxiCorp.RemoveDriver(driver1ID);
    taxiCorp.RemoveCustomer(customer2ID);
    taxiCorp.RemoveCar(car1ID);

    assert(taxiCorp.GetDrivers().size() == 1);
    assert(taxiCorp.GetCustomers().size() == 1);
    assert(taxiCorp.GetCars().size() == 1);

    taxiCorp.RemoveCar(777);
    taxiCorp.RemoveDriver(777);
    taxiCorp.RemoveCustomer(777);

    assert(taxiCorp.GetDrivers().size() == 1);
    assert(taxiCorp.GetCustomers().size() == 1);
    assert(taxiCorp.GetCars().size() == 1);
}
void testFindingByID()
{
    TaxiCorporation taxiCorp = TaxiCorporation();
    taxiCorp.AddNewDriver("John", "Doe", "123-456-7890", 5);
    taxiCorp.AddNewDriver("Jane", "Doe", "098-765-4321", 2);
    auto id1 = taxiCorp.AddNewCustomer("Alice", "Smith", "555-123-4567", 0.2);
    auto id2 = taxiCorp.AddNewCustomer("Bob", "Johnson", "555-987-6543", 0.1);
    taxiCorp.AddNewCar("ABC123", "Red", 12345, Econom);
    taxiCorp.AddNewCar("DEF456", "Blue", 67890, Business);

    assert(taxiCorp.GetDriverByID(2).GetFirstName() == "Jane");
    try
    {
        taxiCorp.GetDriverByID(77);
        assert(false && "Expected std::invalid_argument exception");
    }
    catch (const std::invalid_argument &e)
    {
        assert(strcmp(e.what(), "No driver with the specified ID.") == 0);
    }
    assert(taxiCorp.GetCustomerByID(1).GetFirstName() == "Alice");
    assert(taxiCorp.GetDriverByID(1).GetFirstName() == "John");
    try
    {
        taxiCorp.GetCustomerByID(77);
        assert(false && "Expected std::invalid_argument exception");
    }
    catch (const std::invalid_argument &e)
    {
        assert(strcmp(e.what(), "No customer with the specified ID.") == 0);
    }
    assert(taxiCorp.GetCarByID(2).GetCarNumber() == "DEF456");
    assert(taxiCorp.GetDriverByID(2).GetFirstName() == "Jane");
    try
    {
        taxiCorp.GetCarByID(77);
        assert(false && "Expected std::invalid_argument exception");
    }
    catch (const std::invalid_argument &e)
    {
        assert(strcmp(e.what(), "No car with the specified ID.") == 0);
    }
    assert(taxiCorp.GetDriverByID(2).GetFirstName() == "Jane");
    taxiCorp.GetCustomerByID(2).TopUpBalance(100);

    assert(taxiCorp.GetCustomerByID(2).GetBalance() == 100);
}

void testMainAlgorithm()
{
    TaxiCorporation taxiCorp = TaxiCorporation();
    unsigned int Driver = taxiCorp.AddNewDriver(
        "John", "Doe", "123-456-7890", 5);
    unsigned int Driver2 = taxiCorp.AddNewDriver(
        "Jane", "Doe", "098-765-4321", 2);
    unsigned int Customer = taxiCorp.AddNewCustomer(
        "Alice", "Smith", "555-123-4567", 0.2);
    unsigned int Car = taxiCorp.AddNewCar(
        "DEF456", "Blue", 67890, Standart);
    unsigned int Car2 = taxiCorp.AddNewCar(
        "ABC123", "Red", 12345, Econom);

    assert(taxiCorp.GetDrivers().size() == 2);
    assert(taxiCorp.GetCustomers().size() == 1);
    assert(taxiCorp.GetCars().size() == 2);
    assert(taxiCorp.GetOrders().size() == 0);

    // Driver waits for order

    assert(taxiCorp.GetDriverByID(Driver).StartWork(Car) == 0);

    taxiCorp.GetCustomerByID(Customer).TopUpBalance(400);
    taxiCorp.GetCustomerByID(Customer).UpdateDiscount(0.15); // 15% discount
    assert(taxiCorp.GetCustomerByID(Customer).OrderTaxi(
               "789 Oak St", "101 Maple St", 10.0, Standart) == 0);

    assert(taxiCorp.GetOrders().size() == 1);

    unsigned int Order =
        taxiCorp.GetCustomerByID(Customer).GetActiveOrderID(); // should return the order id
    assert(Order == 1);
    assert(taxiCorp.GetOrderByID(Order).GetRoute().StartAdress == "789 Oak St");

    taxiCorp.GetDriverByID(Driver).CompeteOrder();

    assert(taxiCorp.GetOrderByID(Order).GetOrderDoneState() == true);
    assert(taxiCorp.GetDriverByID(Driver).workStatus == WorkStatus::WaitingForOrder);
    assert(taxiCorp.GetDriverByID(Driver).GetBalance() == 112);
    assert(taxiCorp.GetCustomerByID(Customer).GetBalance() == 273);
    assert(taxiCorp.GetCustomerByID(Customer).GetActiveOrderID() == 0);
    // Customer waits for driver
    assert(taxiCorp.GetCustomerByID(Customer).OrderTaxi(
               "7894 Pon St", "818 Nop St", 3.0, Econom) == 0);

    assert(taxiCorp.GetOrders().size() == 2);

    taxiCorp.GetDriverByID(Driver2).StartWork(Car2);

    assert(taxiCorp.GetOrderByID(2).DriverID == Driver2);

    taxiCorp.GetDriverByID(Driver2).CompeteOrder();

    assert(taxiCorp.GetOrderByID(2).GetOrderDoneState() == true);

    assert(taxiCorp.GetDriverByID(Driver).StopWork() == 0);

    assert(taxiCorp.GetCustomerByID(Customer).OrderTaxi(
               "789 Oak St", "101 Maple St", 10.0, Standart) == 0);

    assert(taxiCorp.GetOrders().size() == 3);

    assert(taxiCorp.GetCustomerByID(Customer).CancelOrder() == 0);

    assert(taxiCorp.GetOrders().size() == 2);

    assert(taxiCorp.GetCustomerByID(Customer).OrderTaxi(
               "789 Oak St", "101 Maple St", 10.0, Standart) == 0);
    assert(taxiCorp.GetDriverByID(Driver).StartWork(Car) == 0);

    assert(taxiCorp.GetDriverByID(Driver).GetActiveOrderID() == taxiCorp.GetCustomerByID(Customer).GetActiveOrderID());

    assert(taxiCorp.GetCustomerByID(Customer).CancelOrder() == -1);

    assert(taxiCorp.GetDriverByID(Driver).StopWork() == -1);
    taxiCorp.GetDriverByID(Driver).CompeteOrder();
    assert(taxiCorp.GetCustomerByID(Customer).OrderTaxi(
               "789 Oak St", "101 Maple St", 3.0, Standart) == 0);
    assert(taxiCorp.GetCustomerByID(Customer).OrderTaxi(
               "789 Oak St", "101 Maple St", 5.0, Econom) == -2); // 2 orders in same time
    taxiCorp.GetDriverByID(Driver).StartWork(Car);
    taxiCorp.GetDriverByID(Driver).CompeteOrder();
    assert(taxiCorp.GetCustomerByID(Customer).OrderTaxi(
               "7894 Pon St", "818 Nop St", 100.0, Business) == -1); // not enough money
}
int main()
{
    cout << "Welcome to taxi Corporation!" << endl;
    cout << "Car test: " << endl;
    testCar();
    cout << "Car test passed" << endl;
    cout << "Customer test:" << endl;
    testCustomer();
    cout << "Customer test passed" << endl;
    cout << "Driver test:" << endl;
    testDriver();
    cout << "Driver test passed" << endl;
    cout << "Taxi Copr test:" << endl;
    testTaxiCorporation();
    cout << "Taxi Copr test passed" << endl;
    cout << "Order Test:" << endl;
    TestOrder();
    cout << "Order test passed" << endl;
    cout << "Adding and removing items test:" << endl;
    testAddingRemoving();
    cout << "Adding and removing items test passed" << endl;
    cout << "Finding items by id test:" << endl;
    testFindingByID();
    cout << "Finding items by id test passed" << endl;
    cout << "Main algorithm test:" << endl;
    testMainAlgorithm();
    cout << "Main algorithm test passed" << endl;
    cout << "End of tests" << endl;
}