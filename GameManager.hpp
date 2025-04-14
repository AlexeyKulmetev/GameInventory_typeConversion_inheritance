#pragma once
#include "Item.hpp"
#include "Weapon.hpp"
#include "Potion.hpp"
#include "Constants.hpp"
#include <iostream>
#include <vector>

class GameManager {
public:
	GameManager() = default;

	// need Virtual Clone pattern
	GameManager(const GameManager& other) {
		for (const Item* item : other.items) {
			if (item) {
				items.push_back(item->clone());
			}
		}
	}
	GameManager(GameManager&& other) noexcept : items(std::move(other.items)) {
		other.items.clear();
	}
	GameManager& operator = (const GameManager& other) {
		if (&other == this) {
			return *this;
		}
		for (Item* item : items) {
			delete item;
		}
		items.clear();
		for (const Item* item : other.items) {
			if (item) {
				items.push_back(item->clone());
			}
		}
		return *this;
	}
	GameManager& operator = (GameManager&& other) noexcept{
		if (&other == this) {
			return *this;
		}
		for (Item* item : items) {
			delete item;
		}
		items = std::move(other.items);
		other.items.clear();
		return *this;
	}
	void createItems() {
		for (int i = 0; i < Constants::ITEMS_NUM; ++i) {
			if (rand() % 2 == 0) {
				Weapon* pWeapon = new Weapon;
				pWeapon->setDamage(rand() % 51);
				items.push_back(pWeapon);
			}
			else {
				Potion* pPotion = new Potion;
				pPotion->setHealingPower(rand() % 31 + 10);
				items.push_back(pPotion);
			}
		}
	}
	void useAllItems() const {
		for (Item* i : items) {
			i->use();
			std::cout << "\n";
		}
	}
	~GameManager() {
		for (Item* i : items) {
			delete i;
		}
	}
private:
	std::vector<Item*> items;
};