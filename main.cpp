#include "Constants.hpp"
#include <iostream>
#include "Item.hpp"
#include "Potion.hpp"
#include <vector>
#include "Weapon.hpp"


void useItem(Item* item) {
	if (!item) {
		std::cout << "Null item";
		return;
	}
	if (Weapon* weapon = dynamic_cast<Weapon*>(item)) {
		std::cout << "Dealt " << weapon->getDamage() << " damage!";
	}
	else if (Potion* potion = dynamic_cast<Potion*>(item)) {
		std::cout << "Healed " << potion->getHealingPower() << " HP!";
	}
	else {
		std::cout << "Unknown item";
	}
}


int main() {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::vector<Item*> items;

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
	for (Item* i : items) {
		useItem(i);
		std::cout << "\n";
	}
	for (Item* i : items) {
		delete i;
	}
}