#pragma once
#include "includes.h"
class SideSciana
{
private:
	float length{};

	float width{};

	float heigth{};

	float posX{};

	float posY{};

	float posZ{};

	float holeScianaLength, scianaLength;

	float radius = 20.0;

	void holeSciana(const float, const float) const;

	void sciana() const;
public:
	SideSciana(const float length, const float width, const float heigth, const float posX, const float posY, const float posZ);

	void draw() const;
};

