#include <glad/glad.h>  //glad should always be on top cuz glad uses glfw??
#include <GLFW/glfw3.h>

#include <iostream>
void processInput(GLFWwindow *wd);

 // changing size if the size of window changes
void framebuffer_size_callback(GLFWwindow *wd, int width, int height) {
  glViewport(0, 0, width, height); 
}

int main() {
  glfwInit();
  if (!glfwInit()) {
    return -1;
  }
  // glfwWindowHint will give hints on what to expect out of the window ig
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  // making  a pointer to a window
  GLFWwindow *wd = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL);

  if (wd == NULL) {
    std::cout << "Failed to create GLFW wondow" << std::endl;
    glfwTerminate();
    return -3;
  }
  glfwMakeContextCurrent(wd);  // if we dont do this, compiler throws a tantrum
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -2;
  }
  glViewport(0, 0, 800, 600);  // telling OpenGL the size of the window

  glfwSetFramebufferSizeCallback(wd, framebuffer_size_callback);//so that window gets resized every frame
    while (!glfwWindowShouldClose(wd)) {  // loops every frame
    processInput(wd);
    //render here

    
    glfwSwapBuffers(wd);  // swaps the buffer so that we can work on it and displays the one we already finished writing to
    glfwPollEvents();   // checks for events activations like key pressed
    
  }

  //the general format is 
  //inputs
  //render
  //pollEvents
  //swapBuffer

  glfwTerminate();
  return 0;
}
void processInput(GLFWwindow *wd) {
  if (glfwGetKey(wd, GLFW_KEY_ESCAPE)) glfwSetWindowShouldClose(wd, true);
}














