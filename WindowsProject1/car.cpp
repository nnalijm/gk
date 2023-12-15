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
	glColor3f(1.f, 0.f, 0.f);

	glBegin(GL_TRIANGLE_STRIP);
	
	glVertex3f(0,0,0);
	glVertex3f(0, getHeight()/3,0);
	glVertex3f(0, 0, getWidth());
	glVertex3f(0, getHeight()/3, getWidth());
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0, getHeight()/3*2, 0);
	glVertex3f(0, getHeight(), 0);
	glVertex3f(0, getHeight() / 3 * 2, getWidth());
	glVertex3f(0, getHeight(), getWidth());
	glEnd();

	/*glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0, getHeight()/3, getWidth()/3);
	glVertex3f(getHeight()/6, getHeight()/2, getWidth()/3);
	glVertex3f(0, getHeight()/3, getWidth()/3*2);
	glVertex3f(getHeight()/6, getHeight()/2, getWidth()/3*2);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);

	glVertex3f(0, getHeight()/3*2, getWidth()/3);
	glVertex3f(getHeight()/6, getHeight()/2, getWidth()/3);
	glVertex3f(0, getHeight()/3*2, getWidth()/3*2);
	glVertex3f(getHeight()/6, getHeight()/2, getWidth()/3*2);*/

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0, getHeight() / 3, getWidth() / 3);
	glVertex3f(0, getHeight() / 3, getWidth() / 3 * 2);
	glVertex3f(5, getHeight() / 3 + 5, getWidth() / 3 + 5);
	glVertex3f(5, getHeight() / 3 + 5, (getWidth() / 3) * 2 - 5);
	glEnd();

	glEnd();
}