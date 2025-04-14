#pragma once
#include "Item.hpp"
#include <iostream>

class Potion : public Item {
public:
	// for Virtual Clone pattern
	Item* clone() const override {
		return new Potion(*this);
	}
	int getHealingPower() const {
		return healingPower;
	}
	void setHealingPower(const int _healingPower) {
		healingPower = _healingPower;
	}
	void use() const override {
		std::cout << "Healed " << healingPower << " HP!";
	}
private:
	int healingPower = 0;
};