#include "SideSciana.h"

SideSciana::SideSciana(const float length, const float width, const float heigth, const float posX, const float posY, const float posZ) : length(length),
																																		  width(width),
																																		  heigth(heigth),
																																		  posX(posX),
																																		  posY(posY),
																																		  posZ(posZ)
{
	holeScianaLength = (this->length / 3) + 10;
	scianaLength = this->length / 3;
}

void SideSciana::holeSciana(const float posX, const float length) const
{
	float x {}, z {};
	
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(posX, this->posZ + heigth, this->posY + width);
	glVertex3f(posX, this->posZ, this->posY + width);
		for (float alpha = 0.0; alpha <= GL_PI / 2; alpha += GL_PI / 128)
		{
			x = ((length - 2 * radius) / 2) + (radius - radius * cos(alpha));
			z = radius * sin(alpha);
			glVertex3f(x + posX, z + this->posZ, this->posY + width);
		}
	glVertex3f(x + posX, this->posZ + heigth, this->posY + width);
	glEnd();
	
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.5f, 0.5f, 0.5f);
		glVertex3f(posX + length, this->posZ + heigth, this->posY + width);
		glVertex3f(posX + x, this->posZ + heigth, this->posY + width);
		for (float alpha = GL_PI / 2; alpha >= 0; alpha -= GL_PI / 128)
		{
			x = (length / 2) + cos(alpha) * radius;
			z = radius * sin(alpha);
			glVertex3f(posX + x, z + this->posZ, this->posY + width);
		}
	glVertex3f(posX + length, this->posZ, this->posY + width);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.5f, 0.5f, 0.5f);
		glVertex3f(posX, this->posZ + heigth, this->posY);
		glVertex3f(posX, this->posZ, this->posY);
		for (float alpha = 0; alpha <= GL_PI / 2; alpha += GL_PI / 128)
		{
			x = ((length - 2 * radius) / 2) + (radius - radius * cos(alpha));
			z = radius * sin(alpha);
			glVertex3f(posX + x, this->posZ + z, this->posY);
		}
		glVertex3f(posX + x, this->posZ + heigth, this->posY);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.5f, 0.5f, 0.5f);
	glVertex3f(posX + length, this->posZ + heigth, this->posY);
	glVertex3f(posX + x, this->posZ + heigth, this->posY);
	for (float alpha = GL_PI / 2; alpha >= 0; alpha -= GL_PI / 128)
	{
		x = (length / 2) + cos(alpha) * radius;
		z = radius * sin(alpha);
		glVertex3f(posX + x, this->posZ + z, this->posY);
	}
	glVertex3f(posX + length, this->posZ, this->posY);
	glEnd();

	for (float y = this->posY; y < this->posY + width; y += 10.0f)
	{
		glBegin(GL_TRIANGLE_STRIP);
			for (float alpha = 0.0f; alpha <= GL_PI / 2; alpha += GL_PI / 128)
			{
				x = ((length - 2 * radius) / 2) + (radius - radius * cos(alpha));
				z = radius * sin(alpha);
				glColor3f(0.0f, 1.0f, 1.0f);
				glVertex3f(posX + x, this->posZ + z, y);
				glVertex3f(posX + x, this->posZ + z, y + 10.0f);
			}
		glEnd();
	}

	for (float y = this->posY; y < this->posY + width; y += 10.0f) {
		glBegin(GL_TRIANGLE_STRIP);
			for (float alpha = GL_PI / 2; alpha >= 0; alpha -= GL_PI / 128)
			{
				x = (length / 2) + radius * cos(alpha);
				z = radius * sin(alpha);
				glColor3f(0.0f, 1.0f, 1.0f);
				glVertex3f(posX + x, this->posZ + z, y);
				glVertex3f(posX + x, this->posZ + z, y + 10.0f);
			}
		glEnd();
	}
}

void SideSciana::sciana() const
{
	for (float x = this->posX + holeScianaLength; x < this->posX + scianaLength + holeScianaLength; x += 10.0)
	{
		glBegin(GL_TRIANGLE_STRIP);
		for (float z = this->posZ; z <= this->posZ + heigth; z += 10.0)
		{
			glVertex3f(x, z, this->posY + width);
			glVertex3f(x + 10.0, z, this->posY + width);
		}
		glEnd();
	}

	for (float x = this->posX + holeScianaLength; x < this->posX + scianaLength + holeScianaLength; x += 10.0)
	{
		glBegin(GL_TRIANGLE_STRIP);
		for (float z = this->posZ; z <= this->posZ + heigth; z += 10.0)
		{
			glVertex3f(x, z, this->posY);
			glVertex3f(x + 10.0, z, this->posY);
		}
		glEnd();
	}

	for (float x = posX; x < posX + this->length + radius; x += 10.0f)
	{
		glBegin(GL_TRIANGLE_STRIP);
		for (float y = this->posY; y <= this->posY + width; y += 10.0f)
		{
			glColor3f(0.5f, 0.5f, 0.5f);
			glVertex3f(x, this->posZ + heigth, y);
			glVertex3f(x + 10.0f, this->posZ + heigth, y);
		}
		glEnd();
	}

}

void SideSciana::draw() const
{
	this->holeSciana(this->posX, holeScianaLength);
	glColor3f(0.5, 0.5, 0.5);
	this->sciana();
	this->holeSciana(this->posX + scianaLength + holeScianaLength, holeScianaLength);
}
