#pragma once
#include "Item.hpp"

class Weapon : public Item {
public:
	int getDamage() const {
		return damage;
	}
	void setDamage(const int _damage) {
		damage = _damage;
	}
private:
	int damage = 0;
};