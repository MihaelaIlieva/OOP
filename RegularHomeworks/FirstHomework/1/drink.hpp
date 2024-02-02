#pragma once
#include <cstring>
#pragma warning(disable:4996)
class Drink {
public:
    Drink();
    Drink(const char* init_name, const int init_calories, const double& init_quantity, const double& init_price);
    Drink(const Drink&);
    Drink& operator=(const Drink&);

    const char* get_name() const;
    int get_calories() const;
    double get_quantity() const;
    double get_price() const;

    void set_name(const char* new_name);
    ~Drink();
private:
    char* name;
    int calories;
    double quantity;
    double price;

    const char* defaultName = " ";
};
