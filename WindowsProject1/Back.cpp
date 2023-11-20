#include "Back.h"

Back::Back(const float length, const float width, const float heigth, const float posX, const float posY, const float posZ) : length(length),
																															  width(width),
																															  heigth(heigth),
																															  posX(posX),
																															  posY(posY),
																															  posZ(posZ)
{}

void Back::scianaW(const float width, const float heigth, const float posX, const float posY, const float posZ) const
{
	for (float z = posZ; z < posZ + heigth; z += 1.0)
	{
		glBegin(GL_TRIANGLE_STRIP);
			for (float y = posY; y <= posY + width; y += 1.0)
			{
				glVertex3f(posX, z, y);
				glVertex3f(posX, z + 1.0, y);
			}
		glEnd();
	}
}

void Back::scianaL(const float length, const float heigth, const float posX, const float posY, const float posZ) const
{
	for (float z = posZ; z < posZ + heigth; z += 1.0)
	{
		glBegin(GL_TRIANGLE_STRIP);
		for (float x = posX; x <= posX + length; x += 1.0)
		{
			glVertex3f(x, z, posY);
			glVertex3f(x, z + 1.0, posY);
		}
		glEnd();
	}
}

void Back::rama(const float length, const float width, const float heigth, const float posX, const float posY, const float posZ) const
{
	this->scianaW(width, heigth, posX, posY, posZ);
	this->scianaL(length, heigth, posX, posY, posZ);
	this->scianaL(length, heigth, posX, posY + width, posZ);

	for (float x = posX + length - 1; x >= posX; x -= 1.0)
	{
		glBegin(GL_TRIANGLE_STRIP);
			for (float y = posY; y <= this->posY; y += 1.0)
			{
				glVertex3f(x, posZ + heigth, y);
				glVertex3f(x + 1.0, posZ + heigth, y);
			}
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		for (float y = posY; y <= this->posY; y += 1.0)
		{
			glVertex3f(x, posZ, y);
			glVertex3f(x + 1.0, posZ, y);
		}
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
			for (float y = posY + width; y >= this->posY + this->width; y -= 1.0)
			{
				glVertex3f(x, posZ + heigth, y);
				glVertex3f(x + 1.0, posZ + heigth, y);
			}
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		for (float y = posY + width; y >= this->posY + this->width; y -= 1.0)
		{
			glVertex3f(x, posZ + heigth, y);
			glVertex3f(x + 1.0, posZ + heigth, y);
		}
		glEnd();
	}

	for (float y = this->posY; y <= this->posY + this->width; y += 1.0)
	{
		glBegin(GL_TRIANGLE_STRIP);
		for (float x = posX; x <= this->posX; x += 1.0)
		{
			glVertex3f(x, posZ + heigth, y);
			glVertex3f(x, posZ + heigth, y + 1.0);
		}
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		for (float x = posX; x <= this->posX; x += 1.0)
		{
			glVertex3f(x, posZ, y);
			glVertex3f(x, posZ, y + 1.0);
		}
		glEnd();
	}

	for (float z = posZ; z < posZ + heigth; z += 1.0)
	{
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(1.0, 1.0, 0.0);
		for (float y = posY; y <= this->posY; y += 1.0)
		{
			glVertex3f(posX + length, z, y);
			glVertex3f(posX + length, z + 1.0, y);
		}
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		for (float y = posY + width; y >= this->posY + this->width; y -= 1.0)
		{
			glVertex3f(posX + length, z, y);
			glVertex3f(posX + length, z + 1.0, y);
		}
		glEnd();
	}
}

void Back::lightsaber(const float length, const float width, const float heigth, const float posX, const float posY, const float posZ) const
{
	for (float z = posZ; z < posZ + heigth; z += 1.0)
	{
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(1.0, 0.0, 0.0);
		for (float y = posY; y <= posY + width; y += 1.0)
		{
			glVertex3f(posX, z, y);
			glVertex3f(posX, z + 1.0, y);
		}
		glEnd();
	}

	for (float x = posX; x <= this->posX; x += 1.0)
	{
		glBegin(GL_TRIANGLE_STRIP);
		for (float z = posZ; z <= posZ + heigth; z += 1.0)
		{
			glVertex3f(x, z, posY);
			glVertex3f(x + 1.0, z, posY);
		}
		glEnd();

		glBegin(GL_TRIANGLE_STRIP);
		for (float z = posZ; z <= posZ + heigth; z += 1.0)
		{
			glVertex3f(x, z, posY + width);
			glVertex3f(x + 1.0, z, posY + width);
		}
		glEnd();
	}
}

void Back::draw() const
{
	glColor3f(0.5, 0.5, 0.5);
	this->scianaW(this->width, this->heigth, this->posX, this->posY, this->posZ);
	glColor3f(1.0, 1.0, 0.0);
	this->rama(this->length, this->width + 4, 0.2 * this->heigth, this->posX - 2, this->posY - 2, (this->posZ + this->heigth) * 0.2);
	this->lightsaber(4, 5, 5, this->posX - 2, this->posY, this->posZ);
	this->lightsaber(4, 5, 5, this->posX - 2, this->posY+75, this->posZ);
}
