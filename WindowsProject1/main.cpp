#include "includes.h"
#include "Wheel.h"
#include "Top.h"
#include "SideSciana.h"
#include "Front.h"
#include "Back.h"
#include "car.h"
#include "Podloze.h"



// Color Palette handle
HPALETTE hPalette = NULL;

// Application name and instance storeage
static LPCTSTR lpszAppName = "GL Template";
static HINSTANCE hInstance;

// Rotation amounts
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;
SideSciana sciana1 = SideSciana(150, 20, 30, -70, 60, 0);

static GLsizei lastHeight;
static GLsizei lastWidth;

// Opis tekstury
BITMAPINFOHEADER	bitmapInfoHeader;	// nag��wek obrazu
unsigned char* bitmapData;			// dane tekstury
unsigned int		texture[4];			// obiekt tekstury


// Declaration for Window procedure
LRESULT CALLBACK WndProc(HWND    hWnd,
	UINT    message,
	WPARAM  wParam,
	LPARAM  lParam);

// Dialog procedure for about box
BOOL APIENTRY AboutDlgProc(HWND hDlg, UINT message, UINT wParam, LONG lParam);

// Set Pixel Format function - forward declaration
void SetDCPixelFormat(HDC hDC);



// Reduces a normal vector specified as a set of three coordinates,
// to a unit normal vector of length one.
void ReduceToUnit(float vector[3])
{
	float length;

	// Calculate the length of the vector		
	length = (float)sqrt((vector[0] * vector[0]) +
		(vector[1] * vector[1]) +
		(vector[2] * vector[2]));

	// Keep the program from blowing up by providing an exceptable
	// value for vectors that may calculated too close to zero.
	if (length == 0.0f)
		length = 1.0f;

	// Dividing each element by the length will result in a
	// unit normal vector.
	vector[0] /= length;
	vector[1] /= length;
	vector[2] /= length;
}


// Points p1, p2, & p3 specified in counter clock-wise order
void calcNormal(float v[3][3], float out[3])
{
	float v1[3], v2[3];
	static const int x = 0;
	static const int y = 1;
	static const int z = 2;

	// Calculate two vectors from the three points
	v1[x] = v[0][x] - v[1][x];
	v1[y] = v[0][y] - v[1][y];
	v1[z] = v[0][z] - v[1][z];

	v2[x] = v[1][x] - v[2][x];
	v2[y] = v[1][y] - v[2][y];
	v2[z] = v[1][z] - v[2][z];

	// Take the cross product of the two vectors to get
	// the normal vector which will be stored in out
	out[x] = v1[y] * v2[z] - v1[z] * v2[y];
	out[y] = v1[z] * v2[x] - v1[x] * v2[z];
	out[z] = v1[x] * v2[y] - v1[y] * v2[x];

	// Normalize the vector (shorten length to one)
	ReduceToUnit(out);
}

// Change viewing volume and viewport.  Called when window is resized
void ChangeSize(GLsizei w, GLsizei h)
{
	GLfloat nRange = 90.0f;
	GLfloat fAspect;
	// Prevent a divide by zero
	if (h == 0)
		h = 1;
	
	lastWidth = w;
	lastHeight = h;

	fAspect = (GLfloat)w / (GLfloat)h;
	// Set Viewport to window dimensions
	glViewport(0, 0, w, h);

	// Reset coordinate system
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Establish clipping volume (left, right, bottom, top, near, far)
	if (w <= h)
		glOrtho(-nRange, nRange, -nRange * h / w, nRange * h / w, -nRange, nRange);
	else
		glOrtho(-nRange * w / h, nRange * w / h, -nRange, nRange, -nRange, nRange);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void SetupRC()
{
	glEnable(GL_DEPTH_TEST);	// Hidden surface removal
	glFrontFace(GL_CCW);		// Counter clock-wise polygons face out
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glColor3f(0.0, 0.0, 0.0);
}



// LoadBitmapFile
// opis: �aduje map� bitow� z pliku i zwraca jej adres.
//       Wype�nia struktur� nag��wka.
//	 Nie obs�uguje map 8-bitowych.
unsigned char* LoadBitmapFile(char* filename, BITMAPINFOHEADER* bitmapInfoHeader)
{
	FILE* filePtr;							// wska�nik pozycji pliku
	BITMAPFILEHEADER	bitmapFileHeader;		// nag��wek pliku
	unsigned char* bitmapImage;			// dane obrazu
	int					imageIdx = 0;		// licznik pikseli
	unsigned char		tempRGB;				// zmienna zamiany sk�adowych

	// otwiera plik w trybie "read binary"
	filePtr = fopen(filename, "rb");
	if (filePtr == NULL)
		return NULL;

	// wczytuje nag��wek pliku
	fread(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, filePtr);

	// sprawdza, czy jest to plik formatu BMP
	if (bitmapFileHeader.bfType != BITMAP_ID)
	{
		fclose(filePtr);
		return NULL;
	}

	if (glewInit() != GLEW_OK)
		printf("Error\n");

	// wczytuje nag��wek obrazu
	fread(bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, filePtr);

	// ustawia wska�nik pozycji pliku na pocz�tku danych obrazu
	fseek(filePtr, bitmapFileHeader.bfOffBits, SEEK_SET);

	// przydziela pami�� buforowi obrazu
	bitmapImage = (unsigned char*)malloc(bitmapInfoHeader->biSizeImage);

	// sprawdza, czy uda�o si� przydzieli� pami��
	if (!bitmapImage)
	{
		free(bitmapImage);
		fclose(filePtr);
		return NULL;
	}

	// wczytuje dane obrazu
	fread(bitmapImage, 1, bitmapInfoHeader->biSizeImage, filePtr);

	// sprawdza, czy dane zosta�y wczytane
	if (bitmapImage == NULL)
	{
		fclose(filePtr);
		return NULL;
	}

	// zamienia miejscami sk�adowe R i B 
	for (imageIdx = 0; imageIdx < bitmapInfoHeader->biSizeImage; imageIdx += 3)
	{
		tempRGB = bitmapImage[imageIdx];
		bitmapImage[imageIdx] = bitmapImage[imageIdx + 2];
		bitmapImage[imageIdx + 2] = tempRGB;
	}

	// zamyka plik i zwraca wska�nik bufora zawieraj�cego wczytany obraz
	fclose(filePtr);
	return bitmapImage;
}
void top( float length, float width, float heigth, float posX, const float posY, float posZ){

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.5f, 0.5f, 0.5f);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-15, heigth, 25);
	glVertex3f(25, heigth, 25);
	glVertex3f(-15, heigth, 55);
	glVertex3f(25, heigth, 55);
	glEnd();



	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-15, heigth, 25);
	glVertex3f(-15 - 25 / tan(3.14 / 4), heigth - 25, 25 - 25 / tan(3.14/4));
	glVertex3f(-15, heigth, 25+1);
	glVertex3f(-15 - 25 / tan(3.14 / 4), heigth - 25, 25 - 25 / tan(3.14/4) + 1);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-15, heigth, 25);
	glVertex3f(-15 - 1/tan(3.14/4), heigth - 1, 25 - 1/tan(3.14/4));
	glVertex3f(-15, heigth, 55);
	glVertex3f(-15 - 1/tan(3.14/4), heigth - 1, 55 + 1 / tan(3.14/4));
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-15, heigth, 55);
	glVertex3f( -15 - 25 / tan(3.14 / 4), heigth - 25, 55 + 25 / tan(3.14 / 4));
	glVertex3f(-15, heigth, 55-1);
	glVertex3f(-15 - 25 / tan(3.14/4) , heigth - 25, 55 + 25 / tan(3.14/4) -1 );
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-15 - 25 / tan(3.14 / 4), heigth - 25, 25 - 25 / tan(3.14 / 4));
	glVertex3f(-15 - 24 / tan(3.14 / 4), heigth - 24, 25 - 24 / tan(3.14 / 4));
	glVertex3f(-15 - 25 / tan(3.14 / 4), heigth - 25, 55 + 25 / tan(3.14 / 4));
	glVertex3f(-15 - 24 / tan(3.14 / 4), heigth - 24, 55 + 24 / tan(3.14 / 4));
	glEnd();


	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.f, 0.f, 0.55f);

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-15 - 1 / tan(3.14 / 4), heigth - 1, 25+0.2);
	for (GLfloat i = 2.4; i < 78; i+=1.2)
		glVertex3f(-15 - 23.8 / tan(3.14 / 4), heigth - 23.8, i);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-15 - 1 / tan(3.14 / 4), heigth - 1, 55 - 0.2);
	for (GLfloat i = 2.4; i < 78; i += 1.2)
		glVertex3f(-15 - 23.8 / tan(3.14 / 4), heigth - 23.8, i);
	glEnd();

	
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-15 - 24 / tan(3.14 / 4), heigth - 24, 2.4);
	for (GLfloat i = 25.2; i <= 55.2; i += 1.2)
		glVertex3f(-15 - 1.2/ tan(3.14 / 4), heigth - 1.2, i);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-15 - 24 / tan(3.14 / 4), heigth - 24, 77.6);
	for (GLfloat i = 25.2; i <= 55.2; i += 2.4)
		glVertex3f(-15 - 1.2 / tan(3.14 / 4), heigth - 1.2, i);
	glEnd();


	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.5f, 0.5f, 0.5f);

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(25, heigth, 25);
	glVertex3f(25 + 25 / tan(3.14 / 6), heigth - 25, 25 - 25 / tan(3.14 / 4));
	glVertex3f(25, heigth, 25 + 1);
	glVertex3f(25 + 25 / tan(3.14 / 6), heigth - 25, 25 - 25 / tan(3.14 / 4) + 1);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(25, heigth, 25);
	glVertex3f(25 + 1 / tan(3.14 / 6), heigth - 1, 25 - 1 / tan(3.14 / 4));
	glVertex3f(25, heigth, 55);
	glVertex3f(25 + 1 / tan(3.14 / 6), heigth - 1, 55 + 1 / tan(3.14 / 4));
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(25, heigth, 55);
	glVertex3f(25 + 25 / tan(3.14 / 6), heigth - 25, 55 + 25 / tan(3.14 / 4));
	glVertex3f(25, heigth, 55 - 1);
	glVertex3f(25 + 25 / tan(3.14 / 6), heigth - 25, 55 + 25 / tan(3.14 / 4) - 1);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(25 + 25 / tan(3.14 / 6), heigth - 25, 25 - 25 / tan(3.14 / 4));
	glVertex3f(25 + 24 / tan(3.14 / 6), heigth - 24, 25 - 24 / tan(3.14 / 4));
	glVertex3f(25 + 25 / tan(3.14 / 6), heigth - 25, 55 + 25 / tan(3.14 / 4));
	glVertex3f(25 + 24 / tan(3.14 / 6), heigth - 24, 55 + 24 / tan(3.14 / 4));
	glEnd();


	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.f, 0.f, 0.55f);

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(25 + 1 / tan(3.14 / 6), heigth - 1, 25 + 0.2);
	for (GLfloat i = 2.4; i <= 79.2; i += 1.2)
		glVertex3f(25 + 23.8 / tan(3.14 / 6), heigth - 23.8, i);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(25 + 1 / tan(3.14 / 6), heigth - 1, 55 - 0.2);
	for (GLfloat i = 2.4; i <= 79.2; i += 1.2)
		glVertex3f(25 + 23.8 / tan(3.14 / 6), heigth - 23.8, i);
	glEnd();


	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(25 + 24 / tan(3.14 / 6), heigth - 24, 2.4);
	for (GLfloat i = 25.2; i <= 55.2; i += 1.2)
		glVertex3f(25 + 1.2 / tan(3.14 / 6), heigth - 1.2, i);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(25 + 24 / tan(3.14 / 6), heigth - 24, 77.6);
	for (GLfloat i = 25.2; i <= 55.2; i += 1.2)
		glVertex3f(25 + 1.2 / tan(3.14 / 6), heigth - 1.2, i);
	glEnd();



	// prawaja storona
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.5f, 0.5f, 0.5f);

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-15, heigth, 55);
	glVertex3f(-15 + 1, heigth, 55);
	glVertex3f(-15 - 25 / tan(3.14 / 4), heigth - 25, 55+25);
	glVertex3f(-15 - 25 / tan(3.14 / 4) + 1, heigth - 25 ,55+25);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-15, heigth, 55);
	glVertex3f(25, heigth, 55);
	glVertex3f(-15 - 1 / tan(3.14 / 4), heigth - 1, 55 + 1 / tan(3.14 / 4));
	glVertex3f(25 + 1 / tan(3.14 / 4), heigth -1, 55 + 1 / tan(3.14 / 4));
	glEnd();

	
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(25, heigth, 55);
	glVertex3f(25 - 1, heigth, 55);
	glVertex3f(25 + 25 / tan(3.14 / 6), heigth - 25, 55 + 25 / tan(3.14 / 4));
	glVertex3f(25 + 25 / tan(3.14 / 6) - 1, heigth - 25, 55 + 25 / tan(3.14 / 4));
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-15 - 25 / tan(3.14 / 4), heigth - 25, 55 + 25 / tan(3.14 / 4));
	glVertex3f(25 + 25 / tan(3.14 / 6), heigth - 25, 55 + 25 / tan(3.14 / 4));
	glVertex3f(-15 - 24 / tan(3.14 / 4), heigth - 24, 55 + 24 / tan(3.14 / 4));
	glVertex3f(25 + 24 / tan(3.14 / 6), heigth - 24, 55 + 24 / tan(3.14 / 4));
	glEnd();


	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.f, 0.f, 0.55f);

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-14.6, heigth - 1, 55);
	for (GLfloat i = -15 - 25 / tan(3.14 / 4) + 2.2; i < 66; i += 1.2)
		glVertex3f(i, heigth - 23.8, 79);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(25, heigth - 1, 55);
	for (GLfloat i = -15 - 25 / tan(3.14 / 4) + 2.2; i < 66; i += 1.2)
		glVertex3f(i, heigth - 23.8, 79);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(66, heigth - 24, 79);
	for (GLfloat i = -14.6; i<25; i+=1.2)
		glVertex3f(i, heigth - 1, 55);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-13 - 25/tan(3.14/4), heigth - 24, 79);
	for (GLfloat i = -14.6; i < 25; i += 1.2)
		glVertex3f(i, heigth - 1, 55);
	glEnd();




	// lewaja storona

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glColor3f(0.5f, 0.5f, 0.5f);

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(25, heigth, 25);
	glVertex3f(25 - 1, heigth, 25);
	glVertex3f(25 + 25 / tan(3.14 / 6), heigth - 25, 25 - 25 / tan(3.14 / 4));
	glVertex3f(25 + 25 / tan(3.14 / 6) - 1, heigth - 25, 25 - 25 / tan(3.14 / 4));
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(25, heigth, 25);
	glVertex3f(25 + 1 / tan(3.14 / 6), heigth - 1, 25 - 1 / tan(3.14 / 4));
	glVertex3f(-15, heigth, 25);
	glVertex3f(-15 - 1 / tan(3.14 / 4), heigth - 1, 25 - 1 / tan(3.14 / 4));
	
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-15, heigth, 25);
	glVertex3f(-15 + 1, heigth, 25);
	glVertex3f(-15 - 25 / tan(3.14 / 4), heigth - 25, 0);
	glVertex3f(-15 - 25 / tan(3.14 / 4) + 1, heigth - 25, 0);
	glEnd();


	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-15 - 25 / tan(3.14 / 4), heigth - 25, 0);
	glVertex3f(25 + 25 / tan(3.14 / 6), heigth - 25, 0);
	glVertex3f(-15 - 24 / tan(3.14 / 4), heigth - 24, 0);
	glVertex3f(25 + 24 / tan(3.14 / 6), heigth - 24, 0);
	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(0.f, 0.f, 0.55f);

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-14.6, heigth - 1, 25);
	for (GLfloat i = -15 - 25 / tan(3.14 / 4) + 2.2; i < 66; i += 2.4)
		glVertex3f(i, heigth - 23.8, 1);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(25, heigth - 1, 25);
	for (GLfloat i = -15 - 25 / tan(3.14 / 4) + 2.2; i < 66; i += 2.4)
		glVertex3f(i, heigth - 23.8, 1);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(66, heigth - 24, 1);
	for (GLfloat i = 25; i > -15; i -= 2.4)
		glVertex3f(i, heigth - 1, 25);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-13-25/tan(3.14/4), heigth - 24, 1);
	for (GLfloat i = 25; i > -16; i -= 2.4)
		glVertex3f(i, heigth - 1, 25);
	glEnd();


}
// Called to draw scene
void RenderScene(void)
{
	//Top top = Top(50, 20, 30, 0, 0, 0);
	/*Wheel wheel1 = Wheel(15, 15, 70, 0, 0);
	Wheel wheel2 = Wheel(15, 15, 70, 60, 0);
	Wheel wheel3 = Wheel(15, 15, -40, 0, 0);
	Wheel wheel4 = Wheel(15, 15, -40, 60, 0);
	SideSciana sciana1 = SideSciana(150, 20, 30, -70, 60, 0);
	SideSciana sciana2 = SideSciana(150, 20, 30, -70, 0, 0);
	Front front = Front(60, 75, 20, -70, 5, 0);
	Back back = Back(10, 80, 30, -70, 0, 0);

	GLfloat cameraPos[3] = { 0.0f, 0.0f, 3.0f };
	GLfloat cameraFront[3] = {0.0f, 0.0f, -1.0f};
	GLfloat cameraUp[3] = { 0.0f, 1.0f, 0.0f };

	car cr = car(80, 80, 50);*/

	
	Podloze podloze;
	//float normal[3];	// Storeage for calculated surface normal

	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Save the matrix state and do the rotations
	glPushMatrix();
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);

	/////////////////////////////////////////////////////////////////
	// MIEJSCE NA KOD OPENGL DO TWORZENIA WLASNYCH SCEN:		   //
	/////////////////////////////////////////////////////////////////
	
	//Spos�b na odr�nienie "przedniej" i "tylniej" �ciany wielok�ta:
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	//walec(40, 40);
	/*sciana1.draw();
	sciana2.draw();
	glColor3f(1.0, 0.0, 0.0);
	front.draw();*/
	//gluLookAt(0.f, 10.f, 100.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f);
	/*wheel1.draw();
	wheel2.draw();
	wheel3.draw();
	wheel4.draw();
	sciana1.draw();
	sciana2.draw();
	back.draw();*/
	//front.draw();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glBegin(GL_QUADS);
	glNormal3d(0, 0, 1);
	glTexCoord2d(1.0, 1.0); glVertex3d(60, 10, 20);
	glTexCoord2d(0.0, 1.0); glVertex3d(30, 10, 20);
	glTexCoord2d(0.0, 0.0); glVertex3d(30, 0, 20);
	glTexCoord2d(1.0, 0.0); glVertex3d(60, 0, 20);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	
	//front.draw();

	//back.draw();

	
	//Uzyskanie siatki:
	//glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

	//Wyrysowanie prostokata:
	//glRectd(-10.0,-10.0,20.0,20.0);

	/////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	// Flush drawing commands
	glFlush();
}


// Select the pixel format for a given device context
void SetDCPixelFormat(HDC hDC)
{
	int nPixelFormat;

	static PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),  // Size of this structure
		1,                                                              // Version of this structure    
		PFD_DRAW_TO_WINDOW |                    // Draw to Window (not to bitmap)
		PFD_SUPPORT_OPENGL |					// Support OpenGL calls in window
		PFD_DOUBLEBUFFER,                       // Double buffered
		PFD_TYPE_RGBA,                          // RGBA Color mode
		24,                                     // Want 24bit color 
		0,0,0,0,0,0,                            // Not used to select mode
		0,0,                                    // Not used to select mode
		0,0,0,0,0,                              // Not used to select mode
		32,                                     // Size of depth buffer
		0,                                      // Not used to select mode
		0,                                      // Not used to select mode
		PFD_MAIN_PLANE,                         // Draw in main plane
		0,                                      // Not used to select mode
		0,0,0 };                                // Not used to select mode

	// Choose a pixel format that best matches that described in pfd
	nPixelFormat = ChoosePixelFormat(hDC, &pfd);

	// Set the pixel format for the device context
	SetPixelFormat(hDC, nPixelFormat, &pfd);
}



// If necessary, creates a 3-3-2 palette for the device context listed.
HPALETTE GetOpenGLPalette(HDC hDC)
{
	HPALETTE hRetPal = NULL;	// Handle to palette to be created
	PIXELFORMATDESCRIPTOR pfd;	// Pixel Format Descriptor
	LOGPALETTE* pPal;			// Pointer to memory for logical palette
	int nPixelFormat;			// Pixel format index
	int nColors;				// Number of entries in palette
	int i;						// Counting variable
	BYTE RedRange, GreenRange, BlueRange;
	// Range for each color entry (7,7,and 3)


// Get the pixel format index and retrieve the pixel format description
	nPixelFormat = GetPixelFormat(hDC);
	DescribePixelFormat(hDC, nPixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pfd);

	// Does this pixel format require a palette?  If not, do not create a
	// palette and just return NULL
	if (!(pfd.dwFlags & PFD_NEED_PALETTE))
		return NULL;

	// Number of entries in palette.  8 bits yeilds 256 entries
	nColors = 1 << pfd.cColorBits;

	// Allocate space for a logical palette structure plus all the palette entries
	pPal = (LOGPALETTE*)malloc(sizeof(LOGPALETTE) + nColors * sizeof(PALETTEENTRY));

	// Fill in palette header 
	pPal->palVersion = 0x300;		// Windows 3.0
	pPal->palNumEntries = nColors; // table size

	// Build mask of all 1's.  This creates a number represented by having
	// the low order x bits set, where x = pfd.cRedBits, pfd.cGreenBits, and
	// pfd.cBlueBits.  
	RedRange = (1 << pfd.cRedBits) - 1;
	GreenRange = (1 << pfd.cGreenBits) - 1;
	BlueRange = (1 << pfd.cBlueBits) - 1;

	// Loop through all the palette entries
	for (i = 0; i < nColors; i++)
	{
		// Fill in the 8-bit equivalents for each component
		pPal->palPalEntry[i].peRed = (i >> pfd.cRedShift) & RedRange;
		pPal->palPalEntry[i].peRed = (unsigned char)(
			(double)pPal->palPalEntry[i].peRed * 255.0 / RedRange);

		pPal->palPalEntry[i].peGreen = (i >> pfd.cGreenShift) & GreenRange;
		pPal->palPalEntry[i].peGreen = (unsigned char)(
			(double)pPal->palPalEntry[i].peGreen * 255.0 / GreenRange);

		pPal->palPalEntry[i].peBlue = (i >> pfd.cBlueShift) & BlueRange;
		pPal->palPalEntry[i].peBlue = (unsigned char)(
			(double)pPal->palPalEntry[i].peBlue * 255.0 / BlueRange);

		pPal->palPalEntry[i].peFlags = (unsigned char)NULL;
	}


	// Create the palette
	hRetPal = CreatePalette(pPal);

	// Go ahead and select and realize the palette for this device context
	SelectPalette(hDC, hRetPal, FALSE);
	RealizePalette(hDC);

	// Free the memory used for the logical palette structure
	free(pPal);

	// Return the handle to the new palette
	return hRetPal;
}


// Entry point of all Windows programs
int APIENTRY WinMain(HINSTANCE       hInst,
	HINSTANCE       hPrevInstance,
	LPSTR           lpCmdLine,
	int                     nCmdShow)
{
	MSG                     msg;            // Windows message structure
	WNDCLASS        wc;                     // Windows class structure
	HWND            hWnd;           // Storeage for window handle

	hInstance = hInst;

	// Register Window style
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	// No need for background brush for OpenGL window
	wc.hbrBackground = NULL;

	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU);
	wc.lpszClassName = lpszAppName;

	// Register the window class
	if (RegisterClass(&wc) == 0)
		return FALSE;


	// Create the main application window
	hWnd = CreateWindow(
		lpszAppName,
		lpszAppName,

		// OpenGL requires WS_CLIPCHILDREN and WS_CLIPSIBLINGS
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,

		// Window position and size
		50, 50,
		800, 800,
		NULL,
		NULL,
		hInstance,
		NULL);

	// If window was not created, quit
	if (hWnd == NULL)
		return FALSE;


	// Display the window
	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	// Process application messages until the application closes
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}




// Window procedure, handles all messages for this program
LRESULT CALLBACK WndProc(HWND    hWnd,
	UINT    message,
	WPARAM  wParam,
	LPARAM  lParam)
{
	static HGLRC hRC;               // Permenant Rendering context
	static HDC hDC;                 // Private GDI Device context

	switch (message)
	{
		// Window creation, setup for OpenGL
	case WM_CREATE:
		// Store the device context
		hDC = GetDC(hWnd);

		// Select the pixel format
		SetDCPixelFormat(hDC);

		// Create palette if needed
		hPalette = GetOpenGLPalette(hDC);

		// Create the rendering context and make it current
		hRC = wglCreateContext(hDC);
		wglMakeCurrent(hDC, hRC);
		SetupRC();
		glGenTextures(4, &texture[0]);                  // tworzy obiekt tekstury			

		// �aduje pierwszy obraz tekstury:
		bitmapData = LoadBitmapFile((char*)"thumbnail.dib", &bitmapInfoHeader);

		glBindTexture(GL_TEXTURE_2D, texture[0]);       // aktywuje obiekt tekstury

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

		// tworzy obraz tekstury
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bitmapInfoHeader.biWidth,
			bitmapInfoHeader.biHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, bitmapData);

		if (bitmapData)
			free(bitmapData);

		// �aduje drugi obraz tekstury:
		bitmapData = LoadBitmapFile((char*)"Bitmapy\\crate.bmp", &bitmapInfoHeader);
		glBindTexture(GL_TEXTURE_2D, texture[1]);       // aktywuje obiekt tekstury

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

		// tworzy obraz tekstury
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bitmapInfoHeader.biWidth,
			bitmapInfoHeader.biHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, bitmapData);

		if (bitmapData)
			free(bitmapData);

		// ustalenie sposobu mieszania tekstury z t�em
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		break;

		// Window is being destroyed, cleanup
	case WM_DESTROY:
		// Deselect the current rendering context and delete it
		wglMakeCurrent(hDC, NULL);
		wglDeleteContext(hRC);

		// Delete the palette if it was created
		if (hPalette != NULL)
			DeleteObject(hPalette);

		// Tell the application to terminate after the window
		// is gone.
		PostQuitMessage(0);
		break;

		// Window is resized.
	case WM_SIZE:
		// Call our function which modifies the clipping
		// volume and viewport
		ChangeSize(LOWORD(lParam), HIWORD(lParam));
		break;


		// The painting function.  This message sent by Windows 
		// whenever the screen needs updating.
	case WM_PAINT:
	{
		// Call OpenGL drawing code
		RenderScene();

		SwapBuffers(hDC);

		// Validate the newly painted client area
		ValidateRect(hWnd, NULL);
	}
	break;

	// Windows is telling the application that it may modify
	// the system palette.  This message in essance asks the 
	// application for a new palette.
	case WM_QUERYNEWPALETTE:
		// If the palette was created.
		if (hPalette)
		{
			int nRet;

			// Selects the palette into the current device context
			SelectPalette(hDC, hPalette, FALSE);

			// Map entries from the currently selected palette to
			// the system palette.  The return value is the number 
			// of palette entries modified.
			nRet = RealizePalette(hDC);

			// Repaint, forces remap of palette in current window
			InvalidateRect(hWnd, NULL, FALSE);

			return nRet;
		}
		break;


		// This window may set the palette, even though it is not the 
		// currently active window.
	case WM_PALETTECHANGED:
		// Don't do anything if the palette does not exist, or if
		// this is the window that changed the palette.
		if ((hPalette != NULL) && ((HWND)wParam != hWnd))
		{
			// Select the palette into the device context
			SelectPalette(hDC, hPalette, FALSE);

			// Map entries to system palette
			RealizePalette(hDC);

			// Remap the current colors to the newly realized palette
			UpdateColors(hDC);
			return 0;
		}
		break;

		// Key press, check for arrow keys to do cube rotation.
	case WM_KEYDOWN:
	{
		if (wParam == VK_UP)
			xRot -= 5.0f;

		if (wParam == VK_DOWN)
			xRot += 5.0f;

		if (wParam == VK_LEFT)
			yRot -= 5.0f;

		if (wParam == VK_RIGHT)
			yRot += 5.0f;

		xRot = (const int)xRot % 360;
		yRot = (const int)yRot % 360;

		InvalidateRect(hWnd, NULL, FALSE);
	}
	break;

	// A menu command
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
			// Exit the program
		case ID_FILE_EXIT:
			DestroyWindow(hWnd);
			break;

			// Display the about box
		case ID_HELP_ABOUT:
			DialogBox(hInstance,
				MAKEINTRESOURCE(IDD_DIALOG_ABOUT),
				hWnd,
				(DLGPROC)AboutDlgProc);
			break;
		}
	}
	break;


	default:   // Passes it on if unproccessed
		return (DefWindowProc(hWnd, message, wParam, lParam));

	}

	return (0L);
}

// Dialog procedure.
BOOL APIENTRY AboutDlgProc(HWND hDlg, UINT message, UINT wParam, LONG lParam)
{

	switch (message)
	{
		// Initialize the dialog box
	case WM_INITDIALOG:
	{
		int i;
		GLenum glError;

		// glGetString demo
		SetDlgItemText(hDlg, IDC_OPENGL_VENDOR, (LPCSTR)glGetString(GL_VENDOR));
		SetDlgItemText(hDlg, IDC_OPENGL_RENDERER, (LPCSTR)glGetString(GL_RENDERER));
		SetDlgItemText(hDlg, IDC_OPENGL_VERSION, (LPCSTR)glGetString(GL_VERSION));
		SetDlgItemText(hDlg, IDC_OPENGL_EXTENSIONS, (LPCSTR)glGetString(GL_EXTENSIONS));

		// gluGetString demo
		SetDlgItemText(hDlg, IDC_GLU_VERSION, (LPCSTR)gluGetString(GLU_VERSION));
		SetDlgItemText(hDlg, IDC_GLU_EXTENSIONS, (LPCSTR)gluGetString(GLU_EXTENSIONS));


		// Display any recent error messages
		i = 0;
		do {
			glError = glGetError();
			SetDlgItemText(hDlg, IDC_ERROR1 + i, (LPCSTR)gluErrorString(glError));
			i++;
		} while (i < 6 && glError != GL_NO_ERROR);


		return (TRUE);
	}
	break;

	// Process command messages
	case WM_COMMAND:
	{
		// Validate and Make the changes
		if (LOWORD(wParam) == IDOK)
			EndDialog(hDlg, TRUE);
	}
	break;

	// Closed from sysbox
	case WM_CLOSE:
		EndDialog(hDlg, TRUE);
		break;
	}

	return FALSE;
}
