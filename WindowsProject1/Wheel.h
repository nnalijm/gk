#pragma once
#include "includes.h"

class Wheel
{
private:
	float radius{};

	float width{};

	float posX{};

	float posY{};

	float posZ{};

	void outerObject() const;

	void crochet(const float) const;

	void innerObject() const;

	void protector() const;

	void cuboid(const float, const float, const float, const float, const float) const;
public:
	Wheel(const float, const float, const float, const float, const float);
	
	void draw() const;
};

