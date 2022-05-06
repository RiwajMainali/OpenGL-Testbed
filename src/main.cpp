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
  glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
  unsigned int VBO;
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

float vertices[]={
  -0.5f, -0.5f,1.0f,
  0.5f,  0.5f,1.0f,
  0.0f, 0.5f, 1.0f,
};

  glGenBuffers(1,&VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),vertices,GL_STATIC_DRAW);

  //vertexShaderSource is GLSL code that will run in gpu
  //it is 
  const char *vertexShaderSource = "#version 330 core\n"
  "layout (location = 0) in vec3 aPos"        //location means you use this specific location for this datatype aka aPos
  "void main()\n"
  "{gl_Position = vec4(aPos.x,aPos.y,aPos.z, 1.0);}\0";
  unsigned int vertexShader;    //creating a shader
  vertexShader = glCreateShader(GL_VERTEX_SHADER);    //inititalize shader, tag vertexShader as a shader 
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  //takes shader, no of variables in vertexShaderSource and the vertexShaderSource, NULL
  
  int success; 
  glfwSetFramebufferSizeCallback(wd, framebuffer_size_callback);//so that window gets resized every frame
    while (!glfwWindowShouldClose(wd)) {  // loops every frame
    processInput(wd);
    //render here
    glClearColor(0.2f, 0.4f, 1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

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














