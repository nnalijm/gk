#include "Top.h"

Top::Top(const float length, const float width, const float heigth, const float posX, const float posY, const float posZ) : length(length),
																															width(width),
																															heigth(heigth),
																															posX(posX),
																															posY(posY),
																															posZ(posZ)
{}

void Top::topSciana() const
{
	for (float y = this->posY; y < this->width + this->posY; y += 1.0)
	{
		glBegin(GL_TRIANGLE_STRIP);
			for (float x = this->posX; x <= this->length + this->posX; x += 1.0)
			{
				glVertex3f(x + 5.0f, heigth + this->posZ, y + 5.0f);	
				glVertex3f(x + 5.0f, heigth + this->posZ, y + 6.0);	
			}
		glEnd();
	}
}

void Top::downSciana() const
{
	for (float y = this->posY; y < this->width + this->posY + 10.0f; y += 1.0)
	{
		glBegin(GL_TRIANGLE_STRIP);
		for (float x = this->posX; x <= this->length + this->posX + 5.0f; x += 1.0)
		{
			glVertex3f(x, this->posZ, y);
			glVertex3f(x, this->posZ, y + 1.0f);
		}
		glEnd();
	}
}

void Top::frontSciana() const
{
	float xGory = this->posX + 5.0f, yGory = this->posY + 5.0f, zGory = this->posZ + this->heigth;
	float xDolu = this->posX, yDolu = this->posY, zDolu = this->posZ;

	
		for (float x = xGory; x <= xGory + this->length; x += this->length)
		{
			glBegin(GL_TRIANGLE_FAN);
				for (float y = yGory; y <= yGory + this->width; y += this->width)
				{

				}
			glEnd();
		}
	
}

void Top::draw() const
{
	glColor3f(1.0, 0.0, 0.0);
	this->topSciana();
	this->downSciana();
}

