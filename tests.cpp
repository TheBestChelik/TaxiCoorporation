#include <TaxiCoorporation.h>

int main()
{
    {
        cout << "Test 0 simple unit tests" << endl;
        Driver driver = Driver("John", "Doe", "123-456-7890", 5);
        if (driver.GetFirstName() != "John")
            return 1;
        if (driver.GetLastName() != "Doe")
            return 1;
        if (driver.GetPhoneNumber() != "123-456-7890")
            return 1;
        if (driver.GetDrivingExperience() != 5)
            return 1;
        Customer customer = Customer("John", "Doe", "123-456-7890", 0.8);
        if (customer.GetDiscount() != 0.8)
            return 1;
        Car car = Car("ABC123", "Red", 12345, Econom);
        if (car.GetCarNumber() != "ABC123")
            return 1;
        if (car.GetSerialNumber() != 12345)
            return 1;
        if (car.GetColor() != "Red")
            return 1;
        if (car.GetCarClass() != Econom)
            return 1;
    }

    cout << "Unit tests passed" << endl;
    {
        cout << "Test 1 testing adding and removing items to Taxi Corporation" << endl;
        TaxiCorporation taxiCorp = TaxiCorporation();
        cout << "Addig items to taxi corp" << endl;
        unsigned int driver1ID = taxiCorp.AddNewDriver("John", "Doe", "123-456-7890", 5);
        unsigned int driver2ID = taxiCorp.AddNewDriver("Jane", "Doe", "098-765-4321", 2);
        unsigned int customer1ID = taxiCorp.AddNewCustomer("Alice", "Smith", "555-123-4567", 0.2);
        unsigned int customer2ID = taxiCorp.AddNewCustomer("Bob", "Johnson", "555-987-6543", 0.1);
        unsigned int car1ID = taxiCorp.AddNewCar("ABC123", "Red", 12345, Econom);
        unsigned int car2ID = taxiCorp.AddNewCar("DEF456", "Blue", 67890, Business);
        unsigned int order1ID = taxiCorp.PostOrder("123 Main St", "456 Elm St", 5.0, Econom);
        unsigned int order2ID = taxiCorp.PostOrder("789 Oak St", "101 Maple St", 10.0, Business);
        int result1 = taxiCorp.IssueCar(car1ID, driver1ID);
        cout << taxiCorp << endl;

        cout << "Removing items from taxi coorp" << endl;
        taxiCorp.RemoveDriver(driver1ID);
        taxiCorp.RemoveCustomer(customer2ID);
        taxiCorp.RemoveCar(car1ID);
        cout << taxiCorp << endl;

        cout << "Removing items that are not in the lists" << endl;
        taxiCorp.RemoveCar(777);
        taxiCorp.RemoveDriver(777);
        taxiCorp.RemoveCustomer(777);
        cout << taxiCorp << endl;
    }
    {
        cout << "Test 2 testing find by id methods" << endl;
        TaxiCorporation taxiCorp = TaxiCorporation();
        taxiCorp.AddNewDriver("John", "Doe", "123-456-7890", 5);
        taxiCorp.AddNewDriver("Jane", "Doe", "098-765-4321", 2);
        taxiCorp.AddNewCustomer("Alice", "Smith", "555-123-4567", 0.2);
        taxiCorp.AddNewCustomer("Bob", "Johnson", "555-987-6543", 0.1);
        taxiCorp.AddNewCar("ABC123", "Red", 12345, Econom);
        taxiCorp.AddNewCar("DEF456", "Blue", 67890, Business);
        taxiCorp.PostOrder("123 Main St", "456 Elm St", 5.0, Econom);
        taxiCorp.PostOrder("789 Oak St", "101 Maple St", 10.0, Business);
        cout << "Driver with id 2:" << taxiCorp.GetDriverByID(2) << endl;
        cout << "Driver with id 77(not in list):" << taxiCorp.GetDriverByID(77) << endl;
        cout << "Customer with id 2:" << taxiCorp.GetCustomerByID(2) << endl;
        cout << "Customer with id 77(not in list):" << taxiCorp.GetCustomerByID(77) << endl;
        cout << "Car with id 2:" << taxiCorp.GetCarByID(2) << endl;
        cout << "Car with id 77(not in list):" << taxiCorp.GetCarByID(77) << endl;
        cout << "Order with id 2" << taxiCorp.GetOrderByID(2) << endl;
        cout << "Order with id 77(not in list)" << taxiCorp.GetOrderByID(77) << endl;
        taxiCorp.GetCustomerByID(2).TopUpBalance(100);
        taxiCorp.GetCustomerByID(77).TopUpBalance(100);
        cout << "Customer with id 2" << taxiCorp.GetCustomerByID(2) << endl;
        cout << "Customer with id 77 not in list" << taxiCorp.GetCustomerByID(77) << endl;
    }
    {
        cout << "Test 3 testing the main alghorithm" << endl;
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
        cout << "Driver waits for order" << endl;
        taxiCorp.GetDriverByID(Driver).StartWork(Car);
        taxiCorp.GetCustomerByID(Customer).TopUpBalance(400);
        taxiCorp.GetCustomerByID(Customer).OrderTaxi(
            "789 Oak St", "101 Maple St", 10.0, Standart);
        unsigned int Order =
            taxiCorp.GetCustomerByID(Customer).GetActiveOrderID();
        cout << taxiCorp << endl;
        cout << taxiCorp.GetOrderByID(Order) << endl;
        taxiCorp.GetDriverByID(Driver).CompeteOrder();
        cout << taxiCorp.GetOrderByID(Order) << endl;
        cout << taxiCorp.GetDriverByID(Driver) << endl;
        cout << taxiCorp.GetCustomerByID(Customer) << endl;
        cout << "Customer waits for driver with appropriate car" << endl;
        taxiCorp.GetCustomerByID(Customer).OrderTaxi(
            "7894 Pon St", "818 Nop St", 3.0, Econom);
        cout << taxiCorp.GetOrders().Queue << endl;
        taxiCorp.GetDriverByID(Driver2).StartWork(Car2);
        taxiCorp.GetDriverByID(Driver2).CompeteOrder();
        cout << "Customer Cancels the order" << endl;
        taxiCorp.GetDriverByID(Driver).StopWork();
        taxiCorp.GetCustomerByID(Customer).OrderTaxi(
            "789 Oak St", "101 Maple St", 10.0, Standart);
        cout << taxiCorp << endl;
        taxiCorp.GetCustomerByID(Customer).CancelOrder();

        cout << "Customer tries to cancel order when it is in progress" << endl;
        taxiCorp.GetCustomerByID(Customer).OrderTaxi(
            "789 Oak St", "101 Maple St", 10.0, Standart);
        taxiCorp.GetDriverByID(Driver).StartWork(Car);
        cout << "Error code " << taxiCorp.GetCustomerByID(Customer).CancelOrder() << endl;
        taxiCorp.GetDriverByID(Driver).CompeteOrder();
        taxiCorp.GetDriverByID(Driver).StopWork();

        cout << "Customer tries to order taxi multiple times" << endl;
        taxiCorp.GetCustomerByID(Customer).OrderTaxi(
            "789 Oak St", "101 Maple St", 10.0, Standart);
        cout << "Error code"
             << taxiCorp.GetCustomerByID(Customer).OrderTaxi(
                    "7894 Pon St", "818 Nop St", 3.0, Econom)
             << endl;
        taxiCorp.GetCustomerByID(Customer).CancelOrder();

        cout << "Customer has not enough balance";
        cout << "Error code"
             << taxiCorp.GetCustomerByID(Customer).OrderTaxi(
                    "7894 Pon St", "818 Nop St", 30.0, Business)
             << endl;

        cout << "Driver tries to go for a break while having active order" << endl;
        taxiCorp.GetCustomerByID(Customer).OrderTaxi(
            "789 Oak St", "101 Maple St", 10.0, Standart);
        taxiCorp.GetDriverByID(Driver).StartWork(Car);
        cout << "Error code "
             << taxiCorp.GetDriverByID(Driver).StopWork()
             << endl;
    }
    cout << "All tests passed" << endl;
}