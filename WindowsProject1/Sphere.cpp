#include "Sphere.h"

void Sphere::sphere(GLfloat v[3], float radius, float color)
{
    float angle = GL_PI / 20;  float R = 0;
    float H = 0;  float pR = 0;
    float pH = 0;
    float x1, y1, z1;  float x2, y2, z2;

    for (float a = -GL_PI / 2 + angle; a <= GL_PI / 2 + angle / 10; a += angle)
    {
        R = cos(a) * radius;
        H = sin(a) * radius;   pR = cos(a - angle) * radius;
        pH = sin(a - angle) * radius;
        glColor3f(color, 0, 0);   glBegin(GL_TRIANGLE_STRIP);
        for (float b = 0.0f - angle; b <= 2 * GL_PI; b += angle)
        {
            x1 = v[0] + cos(b) * radius;
            y1 = v[1];
            z1 = v[2] + sin(b) * radius;
            x2 = x1 - cos(b) * (radius - R);
            y2 = y1 + H;    
            z2 = z1 - sin(b) * (radius - R);
            glVertex3f(x2, y2, z2);
            x2 = x1 - cos(b) * (radius - pR);    
            y2 = y1 + pH;
            z2 = z1 - sin(b) * (radius - pR);    
            glVertex3f(x2, y2, z2);
        }
        glEnd();
    }
}
