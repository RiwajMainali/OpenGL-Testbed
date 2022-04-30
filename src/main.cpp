#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  GLFWwindow *wd = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL);
  if (wd == NULL) {
    std::cout << "Failed to create GLFW wondow" << std::endl;
    glfwTerminate();
    return -1;
  }
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
    std::cout<<"failed to initialize GLAD"<<std::endl;
  }
    glViewport(0, 0, 800, 600);

  while (!glfwWindowShouldClose(wd)) {

    glfwSwapBuffers(wd);
    glfwPollEvents();
  }
 
  glfwTerminate(); return 0;
}
