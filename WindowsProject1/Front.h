#pragma once
#include "includes.h"
class Front
{
private:
	float length{};

	float width{};

	float heigth{};

	float posX{};

	float posY{};

	float posZ{};
	
	void sciana() const;

	void lightsaber(const float, const float) const;
public:
	Front(const float length, const float width, const float heigth, const float posX, const float posY, const float posZ);

	void draw() const;
};

