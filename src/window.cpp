#include<glad/glad.h>

#include<GLFW/glfw3.h>
#include<iostream>

/*
  GLFW_RELEASE doesnt work cuz the ESC is always released if it isn't pressed so it auto exits
*/
void processInput(GLFWwindow *window){
  if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
    glfwSetWindowShouldClose(window, true);
    
  }
}
int main(){
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* window= glfwCreateWindow(800,600, "LearnOpenGL", NULL, NULL);
  if (window == NULL){
    std::cout<< "Failed to create GLFW window" << std::endl;
    return -1;
  }

  glfwMakeContextCurrent(window);

  if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout<<"Failed to initailize GLAD" << std::endl;
    return -1;
  }
 // glViewport(0,0,800,600); this is redundent cuz we have a framebuffer size callback function that checks for size every frame

  void framebuffer_size_callback (GLFWwindow* window, int width, int height);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
  
  while(!glfwWindowShouldClose(window)){
    //input stuff here
    processInput(window);
    
    //render stuff here
    glClearColor(0.1f,0.1f,0.7f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    //swap buffer and check for events here
    glfwSwapBuffers(window);

    glfwPollEvents();

  }
  glfwTerminate();

  return 0;
}
void  framebuffer_size_callback(GLFWwindow* window, int width, int height){
  glViewport(0,0,width,height);
}
