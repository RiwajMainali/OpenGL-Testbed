3#include <glad/glad.h>
#include <GLFW/glfw3.h>


#include <iostream>

// code to run vertices
float vertices[] = {-0.5f, -0.5f, 0.0f,
                    0.5f, -0.3f, 0.0f,
                    0.1f, 0.7f, 0.0f
                   };


const char *vertexShaderSource = "#version 330 core\n"
   "layout (location = 0) in vec3 aPos;\n"
   "void main()\n"
   "{\n"
   "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
   "}\0";

const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

void processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, true);
  }
}
int main() {
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

  unsigned int vertexShader;
  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);
  int success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if(!success) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATIOIN_FAILED\n" << infoLog << std::endl;

  }
  unsigned int fragmentShader;
  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);
  unsigned int shaderProgram;
  shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if(!success){
    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    std::cout<< "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" << infoLog <<std::endl;
  }

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
  glEnableVertexAttribArray(0);
  unsigned int VBO, VAO;

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3* sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  glBindVertexArray(0);
  while(!glfwWindowShouldClose(window)){
    //input stuff here
    processInput(window);

    //render stuff here
    glClearColor(0.5f,0.3f,0.56f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    //swap buffer and check for events here
    glfwSwapBuffers(window);

    glfwPollEvents();

  }
  glfwTerminate();

  return 0;
}
void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}
