#ifndef PIZZA_H
#define PIZZA_H

// C++14 STD

#include <stdexcept>
#include <iostream>
#include <memory>

using namespace std;

class Pizza {
public:
	virtual int getPrice() const = 0;
	virtual ~Pizza() {}
};

class HamAndMushroomPizza : public Pizza {
public:
	virtual int getPrice() const { return 5; };
	virtual ~HamAndMushroomPizza() {};
};

class DeluxePizza : public Pizza {
public:
	virtual int getPrice() const { return 5; };
	virtual ~DeluxePizza() {};
};

class HawaiianPizza : public Pizza {
public:
	virtual int getPrice() const { return 6; };
	virtual ~HawaiianPizza() {};
};

class PizzaFactory {
public:
	enum PizzaType {
		HamMushroom,
		Deluxe,
		Hawaiian
	};

	static unique_ptr<Pizza> createPizza(PizzaType pizzaType) {
		switch (pizzaType) {
		case HamMushroom: return make_unique<HamAndMushroomPizza>();
		case Deluxe:      return make_unique<DeluxePizza>();
		case Hawaiian:    return make_unique<HawaiianPizza>();
		}
		throw "invalid pizza type.";
	}
};

/*
* Create all available pizzas and print their prices
*/
void pizza_information(PizzaFactory::PizzaType pizzatype)
{
	unique_ptr<Pizza> pizza = PizzaFactory::createPizza(pizzatype);
	cout << "Price of " << pizzatype << " is " << pizza->getPrice() << std::endl;
}

#endif
