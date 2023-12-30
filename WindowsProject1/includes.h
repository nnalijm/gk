#pragma once

// Gl_template.c
//Wy³šczanie b³êdów przed "fopen"
#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

// £adowanie bibliotek:

#ifdef _MSC_VER                         // Check if MS Visual C compiler
#  pragma comment(lib, "opengl32.lib")  // Compiler-specific directive to avoid manually configuration
#  pragma comment(lib, "glu32.lib")     // Link libraries
#endif




// Ustalanie trybu tekstowego:
#ifdef _MSC_VER        // Check if MS Visual C compiler
#   ifndef _MBCS
#      define _MBCS    // Uses Multi-byte character set
#   endif
#   ifdef _UNICODE     // Not using Unicode character set
#      undef _UNICODE 
#   endif
#   ifdef UNICODE
#      undef UNICODE 
#   endif
#endif
#include <windows.h>            // Window defines              // OpenGL
            // GLU library
#include <math.h>				// Define for sqrt
#include <stdio.h>
#include <stdlib.h>
#include "GL\glew.h"
//#include <gl\glu.h> 
//#include <gl\gl.h>
//#include "GLFW/glfw3.h"

#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
using namespace glm;
#include "common/shader.hpp"
#include "common/texture.hpp"
#include "common/controls.hpp"

#include "Resource.h"           // About box resource identifiers.

#define glRGB(x, y, z)	glColor3ub((GLubyte)x, (GLubyte)y, (GLubyte)z)
#define BITMAP_ID 0x4D42		// identyfikator formatu BMP
#define GL_PI 3.14