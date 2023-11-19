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
	
	void sciana(const float, const float, const float, const float) const;

	void lightsaber(const float, const float, const float, const float) const;
public:
	Front(const float, const float, const float, const float, const float, const float);

	void draw() const;
};

