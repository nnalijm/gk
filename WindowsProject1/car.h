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

	// seters
	void setLength(GLfloat length);
	void setWidth(GLfloat width);
	void setHeight(GLfloat height);
	void setPosX(GLfloat posX);
	void setPosY(GLfloat posY);
	void setPosZ(GLfloat posZ);

	// geters
	GLfloat getLength() const;
	GLfloat getWidth() const;
	GLfloat getHeight() const;
	GLfloat getPosX() const;
	GLfloat getPosY() const;
	GLfloat getPosZ() const;


	// draw back side functions
	void drawBack() const;
	void drawBackInPlate() const;
	void drawBackHeadlight() const;
	void drawBackLeftHeadlight() const;
	void drawBackRightHeadlight() const;


	// draw sides functions
	void drawSides() const;
	void drawLeftSide() const;
	void drawRightSide() const;
	
	// draw front side functions
	void drawFront() const;
	void drawFrontPlate() const;
	void drawFrontHeadlight() const;
	void drawFrontLeftHeadlight() const;
	void drawFrontRightHeadlight() const;
};

