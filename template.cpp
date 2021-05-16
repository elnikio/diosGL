/*
Linking Notes:
 - GPP is a part of mingw64 so it searches the mingw64 libs and include folders, located in D:/code/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/
Running Notes:
 - Windows libraries are in .dll format. When you run a .exe, Windows looks for those libraries in folders added to your PATH environment variable.
 - So the best thing to do is to put the .dll's next to the .lib's in the mingw lib folder and add that folder to PATH.
*/

#include <iostream>
#include <GL\glew.h>	// Extension Library
#include <GLFW\glfw3.h>	// Windowing Library

/*
#include "include\GL\glew.h"	// Extension Library
#include "include\GLFW\glfw3.h"	// Windowing Library
*/
using namespace std;

// Initialize Window with GLFW
void init (GLFWwindow* window) {}

// Draw to back buffer
void display (GLFWwindow* window, double currentTime) {
	glClearColor (1.0, 0.0, 0.0, 1.0);	// Set 'clear' color.
	glClear (GL_COLOR_BUFFER_BIT);		// Clear all buffers.
	// glDrawArrays (GL_TRIANGLES, 0, 3);
}

int main (void) {
	// Test message to see if console is working:
	cout << "Wtf, is this even working?";

	// Initialize GLFW. Exit on failure:
	if (!glfwInit ())
		exit (EXIT_FAILURE);

	// Set hints (properties) for next call to glfwCreateWindow.
	// GLFW_CONTEXT_VERSION_ hints set which version of OpenGL this instance must be compatible with. In this case OpenGL 4.3.
	// If client version of OpenGL < 4.3 then failure occurs:
	glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 3);

	// Create GLFW window:
	GLFWwindow* window = glfwCreateWindow (1280, 720, "Chapter2 - program1", NULL, NULL);

	// Makes the context of 'window' current on the calling thread. Now OpenGL commands will manipulate this context:
	glfwMakeContextCurrent (window);

	// Initialize extension library. Exit on failure:
	if (glewInit () != GLEW_OK)
		exit (EXIT_FAILURE);
	glfwSwapInterval (1);

	// I don't think this does anything other than cast window to *GLFWwindow, which it already is:
	init (window);

	// Loop until GLFW sends a signal to application to close the window:
	while (!glfwWindowShouldClose (window)) {
		// Update off-screen buffer:
		display (window, glfwGetTime ());
		// Swap visible buffer & off-screen buffer:
		glfwSwapBuffers (window);
		// Ask GLFW for window event signals (process call-back functions):
		glfwPollEvents ();
	}

	// Initiate exit sequence:
	glfwDestroyWindow (window);
	glfwTerminate ();
	exit (EXIT_SUCCESS);
}
