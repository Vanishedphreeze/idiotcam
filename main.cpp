#include <iostream>
#include <fstream>
//using namespace std;

#include "include/RenderManager.h"

GLchar* vertexShaderSource;
GLchar* fragmentShaderSource;

int loadshader (GLchar* &targetShader, const char* shaderFile) {
    // this function is not finished yet.
    // "try catch" is required.

    // load shader files
    std::filebuf *pbuf;
    std::ifstream filestr;
    int fileLength;

    filestr.open (shaderFile, std::ios::binary);
    pbuf=filestr.rdbuf();
    fileLength=pbuf->pubseekoff(0, std::ios::end, std::ios::in);
    pbuf->pubseekpos(0, std::ios::in);
    targetShader=new char[fileLength + 1];
    targetShader[fileLength] = '\0';
    pbuf->sgetn (targetShader,fileLength);
    filestr.close();
    //std::cout.write (targetShader,fileLength);
}

int main() {
    //CameraObject haha;
    //printf("%d", haha.layer);

    /*
    RenderManager* ptr_Render = new RenderManager;
    BaseManager* ptr_Base = ptr_Render;
    ptr_Base->startUp();
    */

    RenderManager* ptr_Render = new RenderManager;
    SceneManager* ptr_Scene = new SceneManager;

    ptr_Render->startUp();
    ptr_Scene->startUp();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

    loadshader(vertexShaderSource, "shaders/simpleVS.vert");
    loadshader(fragmentShaderSource, "shaders/simpleFS.frag");

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Build and compile our shader program
    // Vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // Check for compile time errors
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // Fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // Check for compile time errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // Link shaders
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // Check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);


    // Set up vertex data (and buffer(s)) and attribute pointers
    GLfloat vertices[] = {
         0.5f,  0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f
    };
    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind

    glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)

    // Gameloop
    while (!glfwWindowShouldClose(ptr_Render->gameWindowHandle)) {
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();

        // Render
        // Clear the colorbuffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw our first triangle
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4); // why not triangle_fan?
        glBindVertexArray(0);

        // Swap the screen buffers
        glfwSwapBuffers(ptr_Render->gameWindowHandle);
    }
    // Properly de-allocate all resources once they've outlived their purpose
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    // Terminate GLFW, clearing any resources allocated by GLFW.

///////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*
    ptr_Base->shutDown();
    delete ptr_Base;
    */

    ptr_Scene->shutDown();
    ptr_Render->shutDown();

    delete ptr_Scene;
    delete ptr_Render;
    return 0;
}
