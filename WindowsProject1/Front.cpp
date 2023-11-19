#include "Front.h"

Front::	Front(const float length, const float width, const float heigth, const float posX, const float posY, const float posZ) : length(length),
																																 width(width),
																																 heigth(heigth),
																																 posX(posX),
																																 posY(posY),
																																 posZ(posZ)

{}

void Front::sciana(const float posX, const float posY, const float angle, const float length) const
{
	for (float z = this->posZ; z < heigth; z += 1.0)
	{
		glBegin(GL_TRIANGLE_STRIP);
			for (float y = posY; y <= length + posY; y += 1.0)
			{
				glVertex3f(posX, z, y);
				glVertex3f(posX, z + 1.0, y);
			}
		glEnd();
	}
}

void Front::lightsaber(const float posX, const float posY, const float radius, const float angle) const
{
	float x, y, z;
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(posX, this->posZ + heigth - radius, posY + radius);
	for (float alpha = 0.0; alpha <= 2 * GL_PI + 1; alpha += GL_PI / 128)
	{
		y = radius * sin(alpha);
		z = radius * cos(alpha);
		
		glVertex3f(posX, this->posZ + heigth - z - radius, posY + y + radius);
	}
	glEnd();
	
	for (float alpha = 0.0; alpha < 2 * GL_PI + 1; alpha += GL_PI / 128)
	{
		y = radius * sin(alpha);
		z = radius * cos(alpha);
		glBegin(GL_TRIANGLE_STRIP);
		for(x = radius * sin(alpha) * cos(angle) / sin(angle); x <= 3.0; x += 1.0)
		{
			glVertex3f(posX + x, this->posZ + heigth - z - radius, posY + y + radius);

			y = radius * sin(alpha + GL_PI / 128);
			z = radius * cos(alpha + GL_PI / 128);

			glVertex3f(posX + x, this->posZ + heigth - z - radius, posY + y + radius);
		}	
		glEnd();
	}
}

void Front::draw() const
{
	glColor3f(1.0, 0.0, 0.0);
	/*
	this->scina1(this->posX, this->posY, GL_PI / 2.1);
	this->scina1(this->posX + (this->length / 2) * cos(GL_PI / 2.1), this->posY + (this->length / 2) * sin(GL_PI / 2.1), GL_PI / 2.4);
	glColor3f(1.0, 1.0, 0.0);
	this->lightsaber(this->posX - 3.0, this->posY, 5, GL_PI / 2.1);
	this->lightsaber(this->posX + 6.0, this->length - 5, 5, GL_PI / 2.4);
	*/
	glPushMatrix();
	glRotatef(15, 0.0, 1.0, 0.0);
	this->sciana(this->posX, this->posY, 15, this->length / 4);
	glPopMatrix();
	glLoadIdentity();
	glPushMatrix();
	glRotatef(-15, 0, 1, 0);
	this->sciana(this->posX, this->posY, 0, this->length / 4);
	glPopMatrix();
		
}