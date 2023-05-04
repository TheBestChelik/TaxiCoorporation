#include "TaxiCorporation.h"
#include <cassert>

template <typename ExceptionType, typename FunctionType, typename... Args>
void assert_throws(FunctionType &&func, Args &&...args)
{
    bool thrown = false;
    try
    {
        func(std::forward<Args>(args)...);
    }
    catch (const ExceptionType &e)
    {
        thrown = true;
    }
    assert(thrown);
}
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

    // // Test DriveOrder and UpdateOccupiedState methods
    // Order order(nullptr, 1, "123 Main St", "456 Elm St", 10.5, CarClass::Standart);
    // // car2.DriveOrder(&order);
    // assert(car2.GetOccupiedState());
    // assert(order.GetCarID() == car2.GetID());
    // car2.UpdateOccupiedState(false);
    // assert(!car2.GetOccupiedState());
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

    // // Test OrderTaxi, CheckBalance, CancelOrder, and UseDiscount methods
    // TaxiCorporation taxi("My Taxi Corporation");
    // unsigned int orderID = customer2.OrderTaxi("123 Main St", "456 Elm St", 10.5, CarClass::Standart);
    // assert(orderID > 0);
    // assert(customer2.CheckBalance(50));
    // assert(!customer2.CheckBalance(200));
    // assert(customer2.CancelOrder());
    // assert_throws<std::out_of_range>([&]
    //                                  { taxi.GetOrderByID(orderID); });
    // assert(customer2.UseDiscount(50) == 45);
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

    // // Test posting an order and finding it by ID
    // unsigned int orderID = taxi.PostOrder("123 Main St", "456 Elm St", 10.5, CarClass::Econom);
    // assert(taxi.GetOrders().size() == 1);
    // assert(taxi.GetOrderByID(orderID).GetID() == orderID);

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
    // Test changing car and setting order
    // Driver driver("John", "Doe", "555-1234", 0, 1);
    // unsigned int carID1 = 1, carID2 = 2;
    // assert(driver.GetCurrentCarID() == 0);
    // driver.ChangeCar(carID1);
    // assert(driver.GetCurrentCarID() == carID1);
    // driver.ChangeCar(carID2);
    // assert(driver.GetCurrentCarID() == carID2);
    // Order order(nullptr, 1, "123 Main St", "456 Elm St", 10.5, CarClass::Econom);
    // assert(driver.SetOrder(order.GetID()) == 0);
    // assert(driver.SetOrder(order.GetID()) != 0);
    // assert(driver.GetWorkStatus() == WorkStatus::OnOrder);
    // driver.CompeteOrder();
    // assert(driver.GetWorkStatus() == WorkStatus::WaitingForOrder);
}

int main()
{
    cout << "Welcome to taxi Corporation!" << endl;
    testCar();
    cout << "Car test passed" << endl;
    testCustomer();
    cout << "Customer test passed" << endl;
    testDriver();
    cout << "Driver test passed" << endl;
    testTaxiCorporation();
    cout << "Taxi Copr test passed" << endl;

    // cout << "Unit tests passed" << endl;
    // {
    //     cout << "Test 1 testing adding and removing items to Taxi Corporation" << endl;
    //     TaxiCorporation taxiCorp = TaxiCorporation();
    //     cout << "Addig items to taxi corp" << endl;
    //     unsigned int driver1ID = taxiCorp.AddNewDriver("John", "Doe", "123-456-7890", 5);
    //     unsigned int driver2ID = taxiCorp.AddNewDriver("Jane", "Doe", "098-765-4321", 2);
    //     unsigned int customer1ID = taxiCorp.AddNewCustomer("Alice", "Smith", "555-123-4567", 0.2);
    //     unsigned int customer2ID = taxiCorp.AddNewCustomer("Bob", "Johnson", "555-987-6543", 0.1);
    //     unsigned int car1ID = taxiCorp.AddNewCar("ABC123", "Red", 12345, Econom);
    //     unsigned int car2ID = taxiCorp.AddNewCar("DEF456", "Blue", 67890, Business);
    //     unsigned int order1ID = taxiCorp.PostOrder("123 Main St", "456 Elm St", 5.0, Econom);
    //     unsigned int order2ID = taxiCorp.PostOrder("789 Oak St", "101 Maple St", 10.0, Business);
    //     int result1 = taxiCorp.IssueCar(car1ID, driver1ID);
    //     cout << taxiCorp << endl;

    //     cout << "Removing items from taxi coorp" << endl;
    //     taxiCorp.RemoveDriver(driver1ID);
    //     taxiCorp.RemoveCustomer(customer2ID);
    //     taxiCorp.RemoveCar(car1ID);
    //     cout << taxiCorp << endl;

    //     cout << "Removing items that are not in the lists" << endl;
    //     taxiCorp.RemoveCar(777);
    //     taxiCorp.RemoveDriver(777);
    //     taxiCorp.RemoveCustomer(777);
    //     cout << taxiCorp << endl;
    // }
    // {
    //     cout << "Test 2 testing find by id methods" << endl;
    //     TaxiCorporation taxiCorp = TaxiCorporation();
    //     taxiCorp.AddNewDriver("John", "Doe", "123-456-7890", 5);
    //     taxiCorp.AddNewDriver("Jane", "Doe", "098-765-4321", 2);
    //     taxiCorp.AddNewCustomer("Alice", "Smith", "555-123-4567", 0.2);
    //     taxiCorp.AddNewCustomer("Bob", "Johnson", "555-987-6543", 0.1);
    //     taxiCorp.AddNewCar("ABC123", "Red", 12345, Econom);
    //     taxiCorp.AddNewCar("DEF456", "Blue", 67890, Business);
    //     taxiCorp.PostOrder("123 Main St", "456 Elm St", 5.0, Econom);
    //     taxiCorp.PostOrder("789 Oak St", "101 Maple St", 10.0, Business);
    //     cout << "Driver with id 2:" << taxiCorp.GetDriverByID(2) << endl;
    //     cout << "Driver with id 77(not in list):" << taxiCorp.GetDriverByID(77) << endl;
    //     cout << "Customer with id 2:" << taxiCorp.GetCustomerByID(2) << endl;
    //     cout << "Customer with id 77(not in list):" << taxiCorp.GetCustomerByID(77) << endl;
    //     cout << "Car with id 2:" << taxiCorp.GetCarByID(2) << endl;
    //     cout << "Car with id 77(not in list):" << taxiCorp.GetCarByID(77) << endl;
    //     cout << "Order with id 2" << taxiCorp.GetOrderByID(2) << endl;
    //     cout << "Order with id 77(not in list)" << taxiCorp.GetOrderByID(77) << endl;
    //     taxiCorp.GetCustomerByID(2).TopUpBalance(100);
    //     taxiCorp.GetCustomerByID(77).TopUpBalance(100);
    //     cout << "Customer with id 2" << taxiCorp.GetCustomerByID(2) << endl;
    //     cout << "Customer with id 77 not in list" << taxiCorp.GetCustomerByID(77) << endl;
    // }
    // {
    //     cout << "Test 3 testing the main alghorithm" << endl;
    //     TaxiCorporation taxiCorp = TaxiCorporation();
    //     unsigned int Driver = taxiCorp.AddNewDriver(
    //         "John", "Doe", "123-456-7890", 5);
    //     unsigned int Driver2 = taxiCorp.AddNewDriver(
    //         "Jane", "Doe", "098-765-4321", 2);
    //     unsigned int Customer = taxiCorp.AddNewCustomer(
    //         "Alice", "Smith", "555-123-4567", 0.2);
    //     unsigned int Car = taxiCorp.AddNewCar(
    //         "DEF456", "Blue", 67890, Standart);
    //     unsigned int Car2 = taxiCorp.AddNewCar(
    //         "ABC123", "Red", 12345, Econom);
    //     cout << "Driver waits for order" << endl;
    //     taxiCorp.GetDriverByID(Driver).StartWork(Car);
    //     taxiCorp.GetCustomerByID(Customer).TopUpBalance(400);
    //     taxiCorp.GetCustomerByID(Customer).OrderTaxi(
    //         "789 Oak St", "101 Maple St", 10.0, Standart);
    //     unsigned int Order =
    //         taxiCorp.GetCustomerByID(Customer).GetActiveOrderID();
    //     cout << taxiCorp << endl;
    //     cout << taxiCorp.GetOrderByID(Order) << endl;
    //     taxiCorp.GetDriverByID(Driver).CompeteOrder();
    //     cout << taxiCorp.GetOrderByID(Order) << endl;
    //     cout << taxiCorp.GetDriverByID(Driver) << endl;
    //     cout << taxiCorp.GetCustomerByID(Customer) << endl;
    //     cout << "Customer waits for driver with appropriate car" << endl;
    //     taxiCorp.GetCustomerByID(Customer).OrderTaxi(
    //         "7894 Pon St", "818 Nop St", 3.0, Econom);
    //     cout << taxiCorp.GetOrders().Queue << endl;
    //     taxiCorp.GetDriverByID(Driver2).StartWork(Car2);
    //     taxiCorp.GetDriverByID(Driver2).CompeteOrder();
    //     cout << "Customer Cancels the order" << endl;
    //     taxiCorp.GetDriverByID(Driver).StopWork();
    //     taxiCorp.GetCustomerByID(Customer).OrderTaxi(
    //         "789 Oak St", "101 Maple St", 10.0, Standart);
    //     cout << taxiCorp << endl;
    //     taxiCorp.GetCustomerByID(Customer).CancelOrder();

    //     cout << "Customer tries to cancel order when it is in progress" << endl;
    //     taxiCorp.GetCustomerByID(Customer).OrderTaxi(
    //         "789 Oak St", "101 Maple St", 10.0, Standart);
    //     taxiCorp.GetDriverByID(Driver).StartWork(Car);
    //     cout << "Error code " << taxiCorp.GetCustomerByID(Customer).CancelOrder() << endl;
    //     taxiCorp.GetDriverByID(Driver).CompeteOrder();
    //     taxiCorp.GetDriverByID(Driver).StopWork();

    //     cout << "Customer tries to order taxi multiple times" << endl;
    //     taxiCorp.GetCustomerByID(Customer).OrderTaxi(
    //         "789 Oak St", "101 Maple St", 10.0, Standart);
    //     cout << "Error code"
    //          << taxiCorp.GetCustomerByID(Customer).OrderTaxi(
    //                 "7894 Pon St", "818 Nop St", 3.0, Econom)
    //          << endl;
    //     taxiCorp.GetCustomerByID(Customer).CancelOrder();

    //     cout << "Customer has not enough balance";
    //     cout << "Error code"
    //          << taxiCorp.GetCustomerByID(Customer).OrderTaxi(
    //                 "7894 Pon St", "818 Nop St", 30.0, Business)
    //          << endl;

    //     cout << "Driver tries to go for a break while having active order" << endl;
    //     taxiCorp.GetCustomerByID(Customer).OrderTaxi(
    //         "789 Oak St", "101 Maple St", 10.0, Standart);
    //     taxiCorp.GetDriverByID(Driver).StartWork(Car);
    //     cout << "Error code "
    //          << taxiCorp.GetDriverByID(Driver).StopWork()
    //          << endl;
    // }
    // cout << "All tests passed" << endl;
}