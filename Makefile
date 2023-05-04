WFLAGS = -Wall -Wextra -Wpedantic

TaxiCorporation: test.o Car.o Customer.o Person.o Driver.o Order.o TaxiCorporation.o
	g++ $(WFLAGS) -g test.o Car.o Customer.o Person.o Driver.o Order.o TaxiCorporation.o -o TaxiCorporation

test.o: test.cpp Car.h Customer.h Driver.h Order.h Person.h structures.h TaxiCorporation.h
	g++ $(WFLAGS) -g -c test.cpp -o test.o

Car.o: Car.cpp  Car.h Customer.h Driver.h Order.h Person.h structures.h TaxiCorporation.h
	g++ $(WFLAGS) -g -c Car.cpp -o Car.o

Customer.o: Customer.cpp Customer.h Driver.h Order.h Person.h structures.h TaxiCorporation.h
	g++ $(WFLAGS) -g -c Customer.cpp -o Customer.o

Driver.o: Driver.cpp Customer.h Driver.h Order.h Person.h structures.h TaxiCorporation.h
	g++ $(WFLAGS) -g -c Driver.cpp -o Driver.o
Order.o: Order.cpp Customer.h Driver.h Order.h Person.h structures.h TaxiCorporation.h
	g++ $(WFLAGS) -g -c Order.cpp -o Order.o
Person.o: Person.cpp Customer.h Driver.h Order.h Person.h structures.h TaxiCorporation.h
	g++ $(WFLAGS) -g -c Person.cpp -o Person.o
TaxiCorporation.o: TaxiCorporation.cpp Customer.h Driver.h Order.h Person.h structures.h TaxiCorporation.h
	g++ $(WFLAGS) -g -c TaxiCorporation.cpp -o TaxiCorporation.o



clean:
	rm TaxiCorporation *.o
