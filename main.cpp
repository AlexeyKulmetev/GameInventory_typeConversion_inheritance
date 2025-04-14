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
	gm.createItems();
	gm.useAllItems();
	return 0;
}