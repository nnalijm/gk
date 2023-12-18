#include "car.h"


car::car(GLfloat length, GLfloat width, GLfloat height, GLfloat posX, GLfloat posY, GLfloat posZ){
	setLength(length);
	setWidth(width);
	setHeight(height);
	
	setPosX(posX);
	setPosY(posY);
	setPosZ(posZ);
}

// seters
void car::setLength(GLfloat length) { this->length = length; }
void car::setWidth(GLfloat width) { this->width = width; }
void car::setHeight(GLfloat height) { this->height = height; }
void car::setPosX(GLfloat posX) { this->posX = posX; }
void car::setPosY(GLfloat posY) { this->posY = posY; }
void car::setPosZ(GLfloat posZ) { this->posZ = posZ; }

// geters
GLfloat car::getLength() const { return length; }
GLfloat car::getWidth() const { return width; }
GLfloat car::getHeight() const { return height; }
GLfloat car::getPosX() const { return posX; }
GLfloat car::getPosY() const { return posY; }
GLfloat car::getPosZ() const { return posZ; }

// main draw function
void car::draw() { drawBack(); drawSides(); }

// draw back side functions
void car::drawBackInPlate() const {
	// inner back plate begin
	glColor3f(0.55f, 0.f, 0.f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0+getPosX(), getHeight() / 3 + getPosY(), getWidth() / 3 + getPosZ());
	glVertex3f(0+getPosX(), getHeight() / 3 + getPosY(), getWidth() / 3 * 2 + getPosZ());
	glVertex3f(5+getPosX() , getHeight() / 3 + 5 + getPosY(), getWidth() / 3 + 5 + getPosZ());
	glVertex3f(5+getPosX(), getHeight() / 3 + 5 + getPosY(), (getWidth() / 3) * 2 - 5 + getPosZ());
	glEnd();

	glColor3f(0.f, 0.f, 0.55f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0 + getPosX(), getHeight() / 3 * 2 + getPosY(), getWidth() / 3 + getPosZ());
	glVertex3f(0 + getPosX(), getHeight() / 3 * 2 + getPosY(), getWidth() / 3 * 2 + getPosZ());
	glVertex3f(5 + getPosX(), (getHeight() / 3) * 2 - 5 + getPosY(), getWidth() / 3 + 5 + getPosZ());
	glVertex3f(5 + getPosX(), (getHeight() / 3) * 2 - 5 + getPosY(), (getWidth() / 3) * 2 - 5 + getPosZ());
	glEnd();

	glColor3f(0.f, 0.55f, 0.f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0 + getPosX(), getHeight() / 3 + getPosY(), getWidth() / 3 + getPosZ());
	glVertex3f(0 + getPosX(), getHeight() / 3 * 2 + getPosY(), getWidth() / 3 + getPosZ());
	glVertex3f(5 + getPosX(), getHeight() / 3 + 5 + getPosY(), getWidth() / 3 + 5 + getPosZ());
	glVertex3f(5 + getPosX(), (getHeight() / 3) * 2 - 5 + getPosY(), getWidth() / 3 + 5 + getPosZ());
	glEnd();

	glColor3f(0.55f, 0.f, 0.55f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0 + getPosX(), getHeight() / 3 + getPosY(), getWidth() / 3 * 2 + getPosZ());
	glVertex3f(0 + getPosX(), getHeight() / 3 * 2 + getPosY(), getWidth() / 3 * 2 + getPosZ());
	glVertex3f(5 + getPosX(), getHeight() / 3 + 5 + getPosY(), (getWidth() / 3) * 2 - 5 + getPosZ());
	glVertex3f(5 + getPosX(), (getHeight() / 3) * 2 - 5 + getPosY(), (getWidth() / 3) * 2 - 5 + getPosZ());
	glEnd();
	// inner back plate end
}
void car::drawBackHeadlight() const { drawBackLeftHeadlight(); drawBackRightHeadlight(); }
void car::drawBackRightHeadlight() const {
	//right rigth headlight
	glColor3f(1.f, 0.f, 0.f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0 + getPosX(), getHeight() / 3 * 2 + getPosY(), getWidth() + getPosZ());
	glVertex3f(0 + getPosX(), getHeight() / 3 * 2 + getPosY(), getWidth() / 6 * 5 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 3 * 2 - 2 + getPosY(), getWidth() - 2 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 3 * 2 - 2 + getPosY(), getWidth() / 6 * 5 + getPosZ());
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0 + getPosX(), getHeight() / 3 * 2 + getPosY(), getWidth() + getPosZ());
	glVertex3f(0 + getPosX(), getHeight() / 2 + getPosY(), getWidth() + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 3 * 2 - 2 + getPosY(), getWidth() - 2 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 2 + 2 + getPosY(), getWidth() - 2 + getPosZ());
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0 + getPosX(), getHeight() / 2 + getPosY(), getWidth() + getPosZ());
	glVertex3f(0 + getPosX(), getHeight() / 2 + getPosY(), getWidth() / 6 * 5 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 2 + 2 + getPosY(), getWidth() - 2 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 2 + 2 + getPosY(), getWidth() / 6 * 5 + getPosZ());
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0 + getPosX(), getHeight() / 2 + getPosY(), getWidth() / 6 * 5 + getPosZ());
	glVertex3f(0 + getPosX(), getHeight() / 3 * 2 + getPosY(), getWidth() / 6 * 5 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 2 + 2 + getPosY(), getWidth() / 6 * 5 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 3 * 2 - 2 + getPosY(), getWidth() / 6 * 5 + getPosZ());
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-2 + getPosX(), getHeight() / 3 * 2 - 2 + getPosY(), getWidth() / 6 * 5 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 3 * 2 - 6.3 + getPosY(), getWidth() / 6 * 5 + getPosZ());
	for (GLfloat x = -2.0 + getPosX(), y = getHeight() / 3 * 2 - 2 + getPosY(), z = (getWidth() / 6) * 5 + getPosZ(); z < getWidth() - 2 + getPosZ(); z += 2.825) {
		glVertex3f(x, y, z);
		glVertex3f(x, y - 4.3, z);
	}
	glEnd();

	//right left headlight
	glColor3f(1.f, 0.647f, 0.f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0 + getPosX(), getHeight() / 3 * 2 + getPosY(), getWidth() / 3 * 2 + getPosZ());
	glVertex3f(0 + getPosX(), getHeight() / 2 + getPosY(), getWidth() / 3 * 2 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 3 * 2 - 2 + getPosY(), getWidth() / 3 * 2 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 2 + 2 + getPosY(), getWidth() / 3 * 2 + getPosZ());
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0 + getPosX(), getHeight() / 3 * 2 + getPosY(), getWidth() / 3 * 2 + getPosZ());
	glVertex3f(0 + getPosX(), getHeight() / 3 * 2 + getPosY(), getWidth() / 6 * 5 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 3 * 2 - 2 + getPosY(), getWidth() / 3 * 2 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 3 * 2 - 2 + getPosY(), getWidth() / 6 * 5 + getPosZ());
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0 + getPosX(), getHeight() / 2 + getPosY(), getWidth() / 3 * 2 + getPosZ());
	glVertex3f(0 + getPosX(), getHeight() / 2 + getPosY(), getWidth() / 6 * 5 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 2 + 2 + getPosY(), getWidth() / 3 * 2 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 2 + 2 + getPosY(), getWidth() / 6 * 5 + getPosZ());
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-2 + getPosX(), getHeight() / 3 * 2 - 2 + getPosY(), getWidth() / 3 * 2 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 3 * 2 - 6.3 + getPosY(), getWidth() / 3 * 2 + getPosZ());
	for (GLfloat x = -2 + getPosX(), y = getHeight() / 3 * 2 - 2 + getPosY(), z = getWidth() / 3 * 2 + getPosZ(); z < (getWidth() / 6) * 5 + getPosZ(); z += 3.325) {
		glVertex3f(x, y, z);
		glVertex3f(x, y - 4.3, z);
	}
	glEnd();
}
void car::drawBackLeftHeadlight() const {
	//left left headlight
	glColor3f(1.f, 0.f, 0.f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0 + getPosX(), getHeight() / 3 * 2 + getPosY(), 0 + getPosZ());
	glVertex3f(0 + getPosX(), getHeight() / 3 * 2 + getPosY(), getWidth() / 6 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 3 * 2 - 2 + getPosY(), 2 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 3 * 2 - 2 + getPosY(), getWidth() / 6 + getPosZ());
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0 + getPosX(), getHeight() / 3 * 2 + getPosY(), 0 + getPosZ());
	glVertex3f(0 + getPosX(), getHeight() / 2 + getPosY(), 0 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 3 * 2 - 2 + getPosY(), 2 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 2 + 2 + getPosY(), 2 + getPosZ());
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0 + getPosX(), getHeight() / 2 + getPosY(), 0 + getPosZ());
	glVertex3f(0 + getPosX(), getHeight() / 2 + getPosY(), getWidth() / 6 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 2 + 2 + getPosY(), 2 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 2 + 2 + getPosY(), getWidth() / 6 + getPosZ());
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0 + getPosX(), getHeight() / 2 + getPosY(), getWidth() / 6 + getPosZ());
	glVertex3f(0 + getPosX(), getHeight() / 3 * 2 + getPosY(), getWidth() / 6 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 2 + 2 + getPosY(), getWidth() / 6 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 3 * 2 - 2 + getPosY(), getWidth() / 6 + getPosZ());
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-2 + getPosX(), getHeight() / 3 * 2 - 2 + getPosY(), 2 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 3 * 2 - 6.3 + getPosY(), 2 + getPosZ());
	for (GLfloat x = -2.0 + getPosX(), y = getHeight() / 3 * 2 - 2 + getPosY(), z = 4.825 + getPosZ(); z < 13.4 + getPosZ(); z += 2.825) {
		glVertex3f(x, y, z);
		glVertex3f(x, y - 4.3, z);
	}
	glEnd();

	//left right headlight

	glColor3f(1.f, 0.647f, 0.f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0 + getPosX(), getHeight() / 3 * 2 + getPosY(), getWidth() / 6 + getPosZ());
	glVertex3f(0 + getPosX(), getHeight() / 3 * 2 + getPosY(), getWidth() / 3 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 3 * 2 + getPosY() - 2, getWidth() / 6 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 3 * 2 - 2 + getPosY(), getWidth() / 3 + getPosZ());
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0 + getPosX(), getHeight() / 3 * 2 + getPosY(), getWidth() / 3 + getPosZ());
	glVertex3f(0 + getPosX(), getHeight() / 2 + getPosY(), getWidth() / 3 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 3 * 2 - 2 + getPosY(), getWidth() / 3 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 2 + 2 + getPosY(), getWidth() / 3 + getPosZ());
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0 + getPosX(), getHeight() / 2 + getPosY(), getWidth() / 6 + getPosZ());
	glVertex3f(0 + getPosX(), getHeight() / 2 + getPosY(), getWidth() / 3 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 2 + 2 + getPosY(), getWidth() / 6 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 2 + 2 + getPosY(), getWidth() / 3 + getPosZ());
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-2 + getPosX(), getHeight() / 3 * 2 - 2 + getPosY(), getWidth() / 6 + getPosZ());
	glVertex3f(-2 + getPosX(), getHeight() / 3 * 2 - 6.3 + getPosY(), getWidth() / 6 + getPosZ());
	for (GLfloat x = -2.0 + getPosX(), y = getHeight() / 3 * 2 - 2 + getPosY(), z = getWidth() / 6 + 3.325 + getPosZ(); z < 26.7 + getPosZ(); z += 3.325) {
		glVertex3f(x, y, z);
		glVertex3f(x, y - 4.3, z);
	}
	glEnd();
}
void car::drawBack() const{
	glColor3f(1.f, 0.f, 0.f);

	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(0.f, 0.f, 0.55f);
	glVertex3f(0 + getPosX(), 0 + getPosY(), 0 + getPosZ());
	glVertex3f(0 + getPosX(), getHeight() / 3 + getPosY(), 0 + getPosZ());
	glVertex3f(0 + getPosX(), 0 + getPosY(), getWidth() + getPosZ());
	glVertex3f(0 + getPosX(), getHeight() / 3 + getPosY(), getWidth() + getPosZ());
	glEnd();

	glColor3f(0.f, 0.55f, 0.f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0 + getPosX(), getHeight() / 3 * 2 + getPosY(), 0 + getPosZ());
	glVertex3f(0 + getPosX(), getHeight() + getPosY(), 0 + getPosZ());
	glVertex3f(0 + getPosX(), getHeight() / 3 * 2 + getPosY(), getWidth() + getPosZ());
	glVertex3f(0 + getPosX(), getHeight() + getPosY(), getWidth() + getPosZ());
	glEnd();

	
	glColor3f(0.f, 0.55f, 0.55f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0 + getPosX(), getHeight() / 3 + getPosY(), 0 + getPosZ());
	glVertex3f(0 + getPosX(), getHeight() / 3 + getPosY(), getWidth() / 3 + getPosZ());
	glVertex3f(0 + getPosX(), getHeight() / 2 + getPosY(), 0 + getPosZ());
	glVertex3f(0 + getPosX(), getHeight() / 2 + getPosY(), getWidth() / 3 + getPosZ());
	glEnd();

	glColor3f(0.55f, 0.55f, 0.55f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0 + getPosX(), getHeight() / 3 + getPosY(), getWidth() + getPosZ());
	glVertex3f(0 + getPosX(), getHeight() / 3 + getPosY(), (getWidth() / 3) * 2 + getPosZ());
	glVertex3f(0 + getPosX(), getHeight() / 2 + getPosY(), getWidth() + getPosZ());
	glVertex3f(0 + getPosX(), getHeight() / 2 + getPosY(), (getWidth() / 3) * 2 + getPosZ());
	glEnd();

	drawBackInPlate();
	drawBackHeadlight();

	
}

// draw sides functions
void car::drawSides() const { drawLeftSide(); drawRightSide(); }
void car::drawLeftSide() const{
	glColor3f(1.f, 0.f, 0.f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(getPosX() + 0.f, getPosY() + 0.f, getPosZ() + 0.f);
	glVertex3f(getPosX() + getLength() / 4, getPosY() + 0.f, getPosZ() + 0.f);
	glVertex3f(getPosX() + 0.f, getPosY() + getHeight(), getPosZ() + 0.f);
	glVertex3f(getPosX() + getLength() / 4, getPosY() + getHeight(), getPosZ() + 0.f);
	glEnd();


	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(getPosX() + getLength() / 4, getPosY() + 0.f, getPosZ() + 0.f);
	glVertex3f(getPosX() + getLength() / 4, getPosY() + getHeight(), getPosZ() + 0.f);
	glVertex3f(getPosX() + getLength() / 2, getPosY() + 0.f, getPosZ() + 0.f);
	glVertex3f(getPosX() + getLength() / 2, getPosY() + getHeight(), getPosZ() + 0.f);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(getPosX() + getLength() / 2, getPosY() + 0.f, getPosZ() + 0.f);
	glVertex3f(getPosX() + getLength() / 2, getPosY() + getHeight(), getPosZ() + 0.f);
	glVertex3f(getPosX() + getLength() / 4 * 3, getPosY() + 0.f, getPosZ() + 0.f);
	glVertex3f(getPosX() + getLength() / 4 * 3, getPosY() + getHeight(), getPosZ() + 0.f);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(getPosX() + getLength() / 4 * 3, getPosY() + 0.f, getPosZ() + 0.f);
	glVertex3f(getPosX() + getLength() / 4 * 3, getPosY() + getHeight(), getPosZ() + 0.f);
	glVertex3f(getPosX() + getLength(), getPosY() + 0.f, getPosZ() + 0.f);
	glVertex3f(getPosX() + getLength(), getPosY() + getHeight(), getPosZ() + 0.f);
	glEnd();

}
void car::drawRightSide() const{
	glColor3f(1.f, 0.f, 0.f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(getPosX() + 0.f, getPosY() + 0.f, getPosZ() + getWidth());
	glVertex3f(getPosX() + getLength() / 4, getPosY() + 0.f, getPosZ() + getWidth());
	glVertex3f(getPosX() + 0.f, getPosY() + getHeight(), getPosZ() + getWidth());
	glVertex3f(getPosX() + getLength() / 4, getPosY() + getHeight(), getPosZ() + getWidth());
	glEnd();


	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(getPosX() + getLength() / 4, getPosY() + 0.f, getPosZ() + getWidth());
	glVertex3f(getPosX() + getLength() / 4, getPosY() + getHeight(), getPosZ() + getWidth());
	glVertex3f(getPosX() + getLength() / 2, getPosY() + 0.f, getPosZ() + getWidth());
	glVertex3f(getPosX() + getLength() / 2, getPosY() + getHeight(), getPosZ() + getWidth());
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(getPosX() + getLength() / 2, getPosY() + 0.f, getPosZ() + getWidth());
	glVertex3f(getPosX() + getLength() / 2, getPosY() + getHeight(), getPosZ() + getWidth());
	glVertex3f(getPosX() + getLength() / 4 * 3, getPosY() + 0.f, getPosZ() + getWidth());
	glVertex3f(getPosX() + getLength() / 4 * 3, getPosY() + getHeight(), getPosZ() + getWidth());
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(getPosX() + getLength() / 4 * 3, getPosY() + 0.f, getPosZ() + getWidth());
	glVertex3f(getPosX() + getLength() / 4 * 3, getPosY() + getHeight(), getPosZ() + getWidth());
	glVertex3f(getPosX() + getLength(), getPosY() + 0.f, getPosZ() + getWidth());
	glVertex3f(getPosX() + getLength(), getPosY() + getHeight(), getPosZ() + getWidth());
	glEnd();
}

// draw front side functions
void car::drawFront() const {
	drawFrontPlate();
	drawFrontHeadlight();
}
void car::drawFrontHeadlight() const {
	drawFrontLeftHeadlight();
	drawFrontRightHeadlight();
}
void car::drawFrontLeftHeadlight() const{}
void car::drawFrontRightHeadlight() const{}
void car::drawFrontPlate() const{}