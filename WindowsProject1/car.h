#pragma once

#include "includes.h"

class car
{
public:
	car(GLfloat length, GLfloat width, GLfloat height, GLfloat posX, GLfloat posY, GLfloat posZ);
	void draw();
private:
	GLfloat length{};
	GLfloat width{};
	GLfloat height{};
	GLfloat posX{};
	GLfloat posY{}; 
	GLfloat posZ{};

	void setLength(GLfloat length);
	void setWidth(GLfloat width);
	void setHeight(GLfloat height);
	void setPosX(GLfloat posX);
	void setPosY(GLfloat posY);
	void setPosZ(GLfloat posZ);

	void drawBack() const;
	void drawBackInPlate() const;
	void drawBackHeadlight() const;
	void drawBackLeftHeadlight() const;
	void drawBackRightHeadlight() const;

	GLfloat getLength() const;
	GLfloat getWidth() const;
	GLfloat getHeight() const;
	GLfloat getPosX() const;
	GLfloat getPosY() const;
	GLfloat getPosZ() const;
};

