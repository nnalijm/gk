#pragma once
#include "includes.h"
class Top
{
private:
	float length{};

	float width {};

	float heigth {};

	float posX {};

	float posY {};

	float posZ {};

	void topSciana() const;

	void downSciana() const;

	void frontSciana() const;
public:
	Top(const float, const float, const float, const float, const float, const float);
	
	void draw() const;
};

