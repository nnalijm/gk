#include "Wheel.h"

Wheel::Wheel(const float radius, const float width, const float posX, const float posY, const float posZ) : radius(radius), 
																											width(width), 
																											posX(posX), 
																											posY(posY), 
																											posZ(posZ)
{}



void Wheel::cuboid(const float angle, const float partAngle, const float posY, const float width, const float heigth) const
{
	glBegin(GL_TRIANGLE_STRIP);
		for (float alpha = angle; alpha <= partAngle; alpha += GL_PI / 32)
		{
			float x1 = radius * cos(alpha);
			float z1 = radius * sin(alpha);

			float x2 = (radius + heigth) * cos(alpha);
			float z2 = (radius + heigth) * sin(alpha);
			glVertex3f(x1 + posX, z1 + posZ, posY);
			glVertex3f(x2 + posX, z2 + posZ, posY);
		}
	glEnd();
	
	glBegin(GL_TRIANGLE_STRIP);
		for (float alpha = angle; alpha <= partAngle; alpha += GL_PI / 32)
		{
			float x1 = radius * cos(alpha);
			float z1 = radius * sin(alpha);

			float x2 = (radius + heigth) * cos(alpha);
			float z2 = (radius + heigth) * sin(alpha);
			glVertex3f(x1 + posX, z1 + posZ, posY + width);
			glVertex3f(x2 + posX, z2 + posZ, posY + width);
		}
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
		for (float y = posY; y <= width + posY; y++)
		{
			float x1 = radius * cos(angle);
			float z1 = radius * sin(angle);

			float x2 = (radius + heigth) * cos(angle);
			float z2 = (radius + heigth) * sin(angle);

			glVertex3f(x1 + posX, z1 + posZ, y);
			glVertex3f(x2 + posX, z2 + posZ, y);
		}
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
		for (float alpha = angle; alpha <= partAngle; alpha += GL_PI / 32)
		{
			float x2 = (radius + heigth) * cos(alpha);
			float z2 = (radius + heigth) * sin(alpha);

			glVertex3f(x2 + posX, z2 + posZ, posY);
			glVertex3f(x2 + posX, z2 + posZ, posY + width);
		}
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
		for (float y = posY; y <= width + posY; y++)
		{
			float x1 = radius * cos(partAngle);
			float z1 = radius * sin(partAngle);

			float x2 = (radius + heigth) * cos(partAngle);
			float z2 = (radius + heigth) * sin(partAngle);

			glVertex3f(x1 + posX, z1 + posZ, y);
			glVertex3f(x2 + posX, z2 + posZ, y);
		}
	glEnd();
}

void Wheel::outerObject() const
{
	glColor3f(0.0, 0.0, 0.0);

	for (float y1 = posY ; y1 < width + posY; y1 += 1.0f)
	{
		glBegin(GL_TRIANGLE_STRIP);
			for (float alpha = 0.0f; alpha <= 2 * GL_PI + 1; alpha += GL_PI / 32)
			{
				float x1 = radius * cos(alpha);
				float z1 = radius * sin(alpha);
			
				glVertex3f(x1 + posX, z1 + this->posZ, y1);
				glVertex3f(x1 + posX, z1 + this->posZ, y1 + 1.0f);
			}
		glEnd();
	}
	this->protector();
}

void Wheel::innerObject() const 
{
	glColor3f(0.0f, 0.0f, 0.0f);

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(posX, posZ, posY);
		for (float alpha = 0.0f; alpha <= 2 * GL_PI; alpha += GL_PI / 32) 
		{
			float x1 = 0.1 * radius * cos(alpha);
			float z1 = 0.1 * radius * sin(alpha);

			glVertex3f(posX + x1, z1 + posZ, posY + 10);
		}
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
		for (float alpha = 0.0; alpha <= 2 * GL_PI + 1; alpha += GL_PI / 32)
		{
			float x1 = radius * cos(alpha);
			float z1 = radius * sin(alpha);

			float x2 = (radius - 10.0) * cos(alpha);
			float z2 = (radius - 10.0) * sin(alpha);

			glVertex3f(x1 + posX, z1 + posZ, posY);
			glVertex3f(x2 + posX, z2 + posZ, posY + 5.0f);
		}
	glEnd();

	for (float y1 = posY + 5.0; y1 < width + posY; y1 += 1.0f)
	{
		glBegin(GL_TRIANGLE_STRIP);
			for (float alpha = 0.0f; alpha <= 2 * GL_PI + 1; alpha += GL_PI / 32)
			{
				float x1 = (radius - 10.0) * cos(alpha);
				float z1 = (radius - 10.0) * sin(alpha);

				glVertex3f(x1 + posX, z1 + posZ, y1);
				glVertex3f(x1 + posX, z1 + posZ, y1 + 1.0f);
			}
		glEnd();
	}

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.0,0.0,0.0);
	for (float alpha = 0.0; alpha <= 2 * GL_PI + 1; alpha += GL_PI / 32)
	{
		float x1 = radius * cos(alpha);
		float z1 = radius * sin(alpha);

		float x2 = (radius - 15.0) * cos(alpha);
		float z2 = (radius - 15.0) * sin(alpha);

		glVertex3f(x1 + posX, z1 + posZ, posY);
		glVertex3f(x2 + posX, z2 + posZ, posY + 10.0f);
	}
	glEnd();

	for (float y1 = posY + 10.0; y1 < width + posY; y1 += 1.0f)
	{
		glBegin(GL_TRIANGLE_STRIP);
		for (float alpha = 0.0f; alpha <= 2 * GL_PI + 1; alpha += GL_PI / 32)
		{
			float x1 = (radius - 15.0) * cos(alpha);
			float z1 = (radius - 15.0) * sin(alpha);

			glVertex3f(x1 + posX, z1 + posZ, y1);
			glVertex3f(x1 + posX, z1 + posZ, y1 + 1.0f);
		}
		glEnd();
	}

	for (float y1 = posY + 10.0; y1 < width + posY; y1 += 1.0f)
	{
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.0f, 0.0f, 0.0f);
			for (float alpha = 0.0f; alpha <= 2 * GL_PI + 1; alpha += GL_PI / 32)
			{
				float x1 = (radius - 25.0) * cos(alpha);
				float z1 = (radius - 25.0) * sin(alpha);

				glVertex3f(x1 + posX, z1 + posZ, y1);
				glVertex3f(x1 + posX, z1 + posZ, y1 + 1.0f);
			}
		glEnd();
	}

	for (float alpha = 0.0; alpha <= 2 * GL_PI; alpha += GL_PI / 4)
	{
		this->crochet(alpha);
	}
}

void Wheel::crochet(const float alpha) const
{
	glColor3f(0.0, 0.0, 0.0);
	
	glBegin(GL_TRIANGLE_FAN);

	float x1 = 0.1 * radius * cos(alpha);
	float z1 = 0.1 * radius * sin(alpha);

	glVertex3f(x1 + posX, z1 + posZ, posY + 10);

	float xLeft = (radius - 15.0) * cos(alpha - GL_PI / 32);
	float zLeft = (radius - 15.0) * sin(alpha - GL_PI / 32);

	glVertex3f(xLeft + posX, zLeft + posZ, posY + 10);

	float xRight = (radius - 15.0) * cos(alpha + GL_PI / 32);
	float zRight = (radius - 15.0) * sin(alpha + GL_PI / 32);

	glVertex3f(xRight + posX, zRight + posZ, posY + 10);

	glEnd();
}

void Wheel::protector() const
{
	glColor3f(0.0, 0.0, 0.0);
	const float heigth = 3.0f, width = 5.0f, length = GL_PI / 32, spaceAngle = GL_PI / 64;
	bool pos = 0;

	for (float y = this->posY ; y <= this->width + this->posY; y += width + (this->width - 5 * width) / 4)
	{
		for (float alpha = pos == 0 ? length / 2 : 0.0; alpha <= 2 * GL_PI; alpha += length + spaceAngle)
		{
			this->cuboid(alpha, alpha + length, y, width, heigth);
		}
		pos = !pos;
	}
}


void Wheel::draw() const
{
	this->outerObject();
	this->innerObject();
}