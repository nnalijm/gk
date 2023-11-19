#pragma once
#include "includes.h"
class Back
{
private:
	float length{};

	float width{};

	float heigth{};

	float posX{};

	float posY{};

	float posZ{};

	void scianaW(const float, const float, const float, const float, const float) const;

	void scianaL(const float, const float, const float, const float, const float) const;

	void rama(const float, const float, const float, const float, const float, const float) const;

	void lightsaber(const float, const float, const float, const float, const float, const float) const;
public:
	Back(const float, const float, const float, const float, const float, const float);

	void draw() const;
};

