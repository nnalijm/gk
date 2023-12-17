#include "car.h"


car::car(GLfloat length, GLfloat width, GLfloat height) {
	setLength(length);
	setWidth(width);
	setHeight(height);
}

void car::setLength(GLfloat length) {
	this->length = length;
}

void car::setWidth(GLfloat width) {
	this->width = width;
}

void car::setHeight(GLfloat height) {
	this->height = height;
}

GLfloat car::getLength() const {
	return length;
}

GLfloat car::getWidth() const {
	return width;
}

GLfloat car::getHeight() const {
	return height;
}

void car::draw() {
	drawBack();
}

void car::drawBackInPlate() const {
	// inner back plate begin
	glColor3f(0.55f, 0.f, 0.f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0, getHeight() / 3, getWidth() / 3);
	glVertex3f(0, getHeight() / 3, getWidth() / 3 * 2);
	glVertex3f(5, getHeight() / 3 + 5, getWidth() / 3 + 5);
	glVertex3f(5, getHeight() / 3 + 5, (getWidth() / 3) * 2 - 5);
	glEnd();

	glColor3f(0.f, 0.f, 0.55f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0, getHeight() / 3 * 2, getWidth() / 3);
	glVertex3f(0, getHeight() / 3 * 2, getWidth() / 3 * 2);
	glVertex3f(5, (getHeight() / 3) * 2 - 5, getWidth() / 3 + 5);
	glVertex3f(5, (getHeight() / 3) * 2 - 5, (getWidth() / 3) * 2 - 5);
	glEnd();

	glColor3f(0.f, 0.55f, 0.f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0, getHeight() / 3, getWidth() / 3);
	glVertex3f(0, getHeight() / 3 * 2, getWidth() / 3);
	glVertex3f(5, getHeight() / 3 + 5, getWidth() / 3 + 5);
	glVertex3f(5, (getHeight() / 3) * 2 - 5, getWidth() / 3 + 5);
	glEnd();

	glColor3f(0.55f, 0.f, 0.55f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0, getHeight() / 3, getWidth() / 3 * 2);
	glVertex3f(0, getHeight() / 3 * 2, getWidth() / 3 * 2);
	glVertex3f(5, getHeight() / 3 + 5, (getWidth() / 3) * 2 - 5);
	glVertex3f(5, (getHeight() / 3) * 2 - 5, (getWidth() / 3) * 2 - 5);
	glEnd();
	// inner back plate end
}

void car::drawBackHeadlight() const {
	drawBackLeftHeadlight();
	drawBackRightHeadlight();
}

void car::drawBackRightHeadlight() const {
	//right rigth headlight
	glColor3f(1.f, 0.f, 0.f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0, getHeight() / 3 * 2, getWidth());
	glVertex3f(0, getHeight() / 3 * 2, getWidth() / 6 * 5);
	glVertex3f(-2, getHeight() / 3 * 2 - 2, getWidth() - 2);
	glVertex3f(-2, getHeight() / 3 * 2 - 2, getWidth() / 6 * 5);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0, getHeight() / 3 * 2, getWidth());
	glVertex3f(0, getHeight() / 2, getWidth());
	glVertex3f(-2, getHeight() / 3 * 2 - 2, getWidth() - 2);
	glVertex3f(-2, getHeight() / 2 + 2, getWidth() - 2);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0, getHeight() / 2, getWidth());
	glVertex3f(0, getHeight() / 2, getWidth() / 6 * 5);
	glVertex3f(-2, getHeight() / 2 + 2, getWidth() - 2);
	glVertex3f(-2, getHeight() / 2 + 2, getWidth() / 6 * 5);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0, getHeight() / 2, getWidth() / 6 * 5);
	glVertex3f(0, getHeight() / 3 * 2, getWidth() / 6 * 5);
	glVertex3f(-2, getHeight() / 2 + 2, getWidth() / 6 * 5);
	glVertex3f(-2, getHeight() / 3 * 2 - 2, getWidth() / 6 * 5);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-2, getHeight() / 3 * 2 - 2, getWidth() / 6 * 5);
	glVertex3f(-2, getHeight() / 3 * 2 - 6.3, getWidth() / 6 * 5);
	for (GLfloat x = -2.0, y = getHeight() / 3 * 2 - 2, z = (getWidth() / 6) * 5; z < getWidth()-2; z += 2.825) {
		glVertex3f(x, y, z);
		glVertex3f(x, y-4.3, z);
	}
	glEnd();

	//right left headlight
	glColor3f(1.f, 0.647f, 0.f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0, getHeight() / 3 * 2, getWidth() / 3 * 2);
	glVertex3f(0, getHeight() / 2, getWidth() / 3 * 2);
	glVertex3f(-2, getHeight() / 3 * 2 - 2, getWidth()/3*2);
	glVertex3f(-2, getHeight() / 2 + 2, getWidth() / 3 * 2);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0, getHeight() / 3 * 2, getWidth() / 3 * 2);
	glVertex3f(0, getHeight() / 3 * 2, getWidth() / 6 * 5);
	glVertex3f(-2, getHeight() / 3 * 2 - 2, getWidth() / 3 * 2);
	glVertex3f(-2, getHeight() / 3 * 2 - 2, getWidth() / 6 * 5);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0, getHeight() / 2, getWidth() / 3 * 2);
	glVertex3f(0, getHeight() / 2, getWidth() / 6 * 5);
	glVertex3f(-2, getHeight() / 2 + 2, getWidth() / 3 * 2);
	glVertex3f(-2, getHeight() / 2 + 2, getWidth() / 6 * 5);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-2, getHeight() / 3 * 2 - 2, getWidth() / 3 * 2);
	glVertex3f(-2, getHeight() / 3 * 2 - 6.3, getWidth() / 3 * 2);
	for (GLfloat x = -2, y = getHeight() / 3 * 2 - 2, z = getWidth() / 3*2; z < (getWidth() / 6) * 5; z+=3.325) {
		glVertex3f(x, y, z);
		glVertex3f(x, y - 4.3, z);
	}
	glEnd();
}

void car::drawBackLeftHeadlight() const {
	//left left headlight
	glColor3f(1.f, 0.f, 0.f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0, getHeight() / 3 * 2, 0);
	glVertex3f(0, getHeight() / 3 * 2, getWidth() / 6);
	glVertex3f(-2, getHeight() / 3 * 2 - 2, 2);
	glVertex3f(-2, getHeight() / 3 * 2 - 2, getWidth() / 6);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0, getHeight() / 3 * 2, 0);
	glVertex3f(0, getHeight() / 2, 0);
	glVertex3f(-2, getHeight() / 3 * 2 - 2, 2);
	glVertex3f(-2, getHeight() / 2 + 2, 2);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0, getHeight() / 2, 0);
	glVertex3f(0, getHeight() / 2, getWidth() / 6);
	glVertex3f(-2, getHeight() / 2 + 2, 2);
	glVertex3f(-2, getHeight() / 2 + 2, getWidth() / 6);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0, getHeight() / 2, getWidth() / 6);
	glVertex3f(0, getHeight() / 3 * 2, getWidth() / 6);
	glVertex3f(-2, getHeight() / 2 + 2, getWidth() / 6);
	glVertex3f(-2, getHeight() / 3 * 2 - 2, getWidth() / 6);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-2, getHeight() / 3 * 2 - 2, 2);
	glVertex3f(-2, getHeight() / 3 * 2 - 6.3, 2);
	for (GLfloat x = -2.0, y = getHeight() / 3 * 2 - 2, z = 4.825; z < 13.4; z += 2.825) {
		glVertex3f(x, y, z);
		glVertex3f(x, y - 4.3, z);
	}
	glEnd();

	//left right headlight

	glColor3f(1.f, 0.647f, 0.f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0, getHeight() / 3 * 2, getWidth() / 6);
	glVertex3f(0, getHeight() / 3 * 2, getWidth() / 3);
	glVertex3f(-2, getHeight() / 3 * 2 - 2, getWidth() / 6);
	glVertex3f(-2, getHeight() / 3 * 2 - 2, getWidth() / 3);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0, getHeight() / 3 * 2, getWidth() / 3);
	glVertex3f(0, getHeight() / 2, getWidth() / 3);
	glVertex3f(-2, getHeight() / 3 * 2 - 2, getWidth() / 3);
	glVertex3f(-2, getHeight() / 2 + 2, getWidth() / 3);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0, getHeight() / 2, getWidth() / 6);
	glVertex3f(0, getHeight() / 2, getWidth() / 3);
	glVertex3f(-2, getHeight() / 2 + 2, getWidth() / 6);
	glVertex3f(-2, getHeight() / 2 + 2, getWidth() / 3);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-2, getHeight() / 3 * 2 - 2, getWidth() / 6);
	glVertex3f(-2, getHeight() / 3 * 2 - 6.3, getWidth() / 6);
	for (GLfloat x = -2.0, y = getHeight() / 3 * 2 - 2, z = getWidth() / 6 + 3.325; z < 26.7; z += 3.325) {
		glVertex3f(x, y, z);
		glVertex3f(x, y - 4.3, z);
	}
	glEnd();
}

void car::drawBack() const{
	glColor3f(1.f, 0.f, 0.f);

	glBegin(GL_TRIANGLE_STRIP);

	glColor3f(0.f, 0.f, 0.55f);
	glVertex3f(0, 0, 0);
	glVertex3f(0, getHeight() / 3, 0);
	glVertex3f(0, 0, getWidth());
	glVertex3f(0, getHeight() / 3, getWidth());
	glEnd();

	glColor3f(0.f, 0.55f, 0.f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0, getHeight() / 3 * 2, 0);
	glVertex3f(0, getHeight(), 0);
	glVertex3f(0, getHeight() / 3 * 2, getWidth());
	glVertex3f(0, getHeight(), getWidth());
	glEnd();

	
	glColor3f(0.f, 0.55f, 0.55f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0, getHeight() / 3, 0);
	glVertex3f(0, getHeight() / 3, getWidth() / 3);
	glVertex3f(0, getHeight() / 2, 0);
	glVertex3f(0, getHeight() / 2, getWidth() / 3);
	glEnd();

	glColor3f(0.55f, 0.55f, 0.55f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0, getHeight() / 3, getWidth());
	glVertex3f(0, getHeight() / 3, (getWidth() / 3) * 2);
	glVertex3f(0, getHeight() / 2, getWidth());
	glVertex3f(0, getHeight() / 2, (getWidth() / 3) * 2);
	glEnd();

	drawBackInPlate();
	drawBackHeadlight();

	
}