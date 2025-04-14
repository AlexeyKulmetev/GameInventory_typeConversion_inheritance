#pragma once
#include "Item.hpp"
#include <iostream>

class Weapon : public Item {
public:
	// for Virtual Clone pattern
	Item* clone() const override {
		return new Weapon(*this);
	}
	int getDamage() const {
		return damage;
	}
	void setDamage(const int _damage) {
		damage = _damage;
	}
	void use() const override {
		std::cout << "Dealt " << damage << " damage!";
	}
private:
	int damage = 0;
};