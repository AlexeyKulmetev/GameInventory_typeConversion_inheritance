#include "Constants.hpp"
#include <iostream>
#include "GameManager.hpp"
#include "Item.hpp"
#include "Potion.hpp"
#include <vector>
#include "Weapon.hpp"


int main() {
	GameManager gm;
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::vector<Item*> items;

	gm.createItems();

	gm.useAllItems();

	for (Item* i : items) {
		delete i;
	}
	return 0;
}