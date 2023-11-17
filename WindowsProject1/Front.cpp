#include "Front.h"

Front::Front(const float length, const float width, const float heigth, const float posX, const float posY, const float posZ) : length(length),
																																width(width),
																																heigth(heigth),
																																posX(posX),
																																posY(posY),
																																posZ(posZ)

{}

void Front::sciana() const
{
	
	for (float z = this->posZ; z < heigth; z += 1.0)
	{
		glBegin(GL_TRIANGLE_STRIP);
			for (float y = this->posY; y <= width; y += 1.0)
			{
				glVertex3f(this->posX, z, y);
				glVertex3f(this->posX, z + 1.0, y);
			}
		glEnd();
	}
}

void Front::lightsaber(const float posY, const float radius) const
{
	float y, z;
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(this->posX - 3.0, this->posZ + heigth - radius, posY + radius);
	for (float alpha = 0.0; alpha <= 2 * GL_PI + 1; alpha += GL_PI / 128)
	{
		y = radius * sin(alpha);
		z = radius * cos(alpha);
		
		glVertex3f(this->posX - 3.0, this->posZ + heigth - z, posY + y + radius);
	}
	glEnd();
}

void Front::draw() const
{
	this->sciana();
	glColor3f(1.0, 1.0, 0.0);
	this->lightsaber(this->posY, 5);
}