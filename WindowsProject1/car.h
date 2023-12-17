#pragma once

#include "includes.h"

class car
{
public:
	car(GLfloat length, GLfloat width, GLfloat height);
	void draw();
private:
	GLfloat length{};
	GLfloat width{};
	GLfloat height{};

	void setLength(GLfloat length);
	void setWidth(GLfloat width);
	void setHeight(GLfloat height);

	void drawBack() const;
	void drawBackInPlate() const;
	void drawBackHeadlight() const;
	void drawBackLeftHeadlight() const;
	void drawBackRightHeadlight() const;

	GLfloat getLength() const;
	GLfloat getWidth() const;
	GLfloat getHeight() const;

};

