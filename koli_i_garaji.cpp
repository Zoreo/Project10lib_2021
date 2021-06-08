#include <iostream>
#include <cstring>
#include <vector>

class Vehicle
{
protected:
    const std::string regnum;

public:
    Vehicle() = default;
    Vehicle(std::string new_regnum);
    virtual double get_parking_price() const = 0;
};
Vehicle::Vehicle(std::string new_regnum) : regnum(new_regnum) {}

class Car : public virtual Vehicle
{
protected:
    const int passenger_count;
    bool is_driver_good;

public:
    Car(std::string new_regnum, int new_passenger_count, bool new_is_driver_good);
    double get_parking_price() const override;
};
Car::Car(std::string new_regnum, int new_passenger_count, bool new_is_driver_good) : Vehicle(new_regnum), passenger_count(new_passenger_count), is_driver_good(new_is_driver_good) {}
double Car::get_parking_price() const
{
    return (is_driver_good) ? 1 : rand() % 8 + 2;
}

class Truck : public virtual Vehicle
{
protected:
    const double load_cap;

public:
    Truck(std::string new_regnum, double new_load_cap);
    double get_parking_price() const override;
};
Truck::Truck(std::string new_regnum, double new_load_cap) : Vehicle(new_regnum), load_cap(new_load_cap) {}
double Truck::get_parking_price() const
{
    return load_cap / 100;
}

class Minibus : public Car, public Truck
{
protected:
    int d_count;
public:
    Minibus() = default;
    Minibus(std::string new_regnum, int new_passenger_count, bool new_is_driver_good, double new_load_cap, int new_d_count);
    double get_parking_price() const override;
};
Minibus::Minibus(std::string new_regnum, int new_passenger_count, bool new_is_driver_good, double new_load_cap, int new_d_count) : Car(new_regnum, new_passenger_count, new_is_driver_good), Truck(new_regnum, new_load_cap), d_count(new_d_count){}
double Minibus::get_parking_price() const
{
    return (Car::get_parking_price() + Truck::get_parking_price()) / 2;
}

class Garage
{
private:
    std::vector<Vehicle *> vehicles;

public:
    Garage() = default;
    Garage(std::vector<Vehicle *> new_vehicles);
    void add_vehicle(Vehicle *vehicle);
    double get_total_rev() const;
};
Garage::Garage(std::vector<Vehicle *> new_vehicles) : vehicles(new_vehicles) {}
void Garage::add_vehicle(Vehicle *vehicle)
{
    vehicles.push_back(vehicle);
}
double Garage::get_total_rev() const
{
    double total_revenue = 0;
    for (Vehicle* vptr : vehicles)
    {
        total_revenue += vptr ->get_parking_price();
    }
    return total_revenue;
}

int main(int argc, const char** argv) {
    Garage garage = Garage();
    std::string regnums[] = {"V2345BV" , "S0987VS", "T4567HG", "I0074CD", "W2222ER"};
    Car car1 = Car(regnums[0], 4, true);//price should be 1
        std::cout << car1.get_parking_price() << std::endl;
    Car car2 = Car(regnums[1], 6, false);//price should be random(2-10) 
        std::cout << car2.get_parking_price() << std::endl;
    Truck truck1 = Truck(regnums[2], 350);//price should be 3.5
        std::cout << truck1.get_parking_price() << std::endl;
    Minibus minibus1 = Minibus(regnums[3], 4, true, 350, 6);//price should be (1 + 3.5)/2 = 2.25
        std::cout << minibus1.get_parking_price() << std::endl;
    Minibus minibus2 = Minibus(regnums[4], 6, false, 500, 7);//price should be (random + 5)/2 
        std::cout << minibus2.get_parking_price() << std::endl;

    garage.add_vehicle(&car1);
    garage.add_vehicle(&car2);
    garage.add_vehicle(&truck1);
    garage.add_vehicle(&minibus1);
    garage.add_vehicle(&minibus2);
    std::cout << garage.get_total_rev() << std::endl;
    return 0;
}
