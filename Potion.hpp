#pragma once
#include "Item.hpp"

class Potion : public Item {
public:
	int getHealingPower() const {
		return healingPower;
	}
	void setHealingPower(const int _healingPower) {
		healingPower = _healingPower;
	}
private:
	int healingPower = 0;
};