#pragma once

class Item {
public:
	virtual ~Item() = default;
	virtual void use() const = 0;
	virtual Item* clone() const = 0;
};