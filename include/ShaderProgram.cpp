#include "ShaderProgram.h"


void ShaderProgram::loadAndCompileShader (GLuint &targetShader, const char* shaderFile, const GLuint shaderType) {
    // this function is used to load shader from a shader file and compile it.
    // shaderType could be GL_VERTEX_SHADER or GL_FRAGMENT_SHADER

    // load shader files
    std::filebuf *pbuf;
    std::ifstream filestr;
    int fileLength;
    GLchar* buffer;

    // load the shader file into a buffer
    filestr.open(shaderFile, std::ios::binary);
    if (!filestr) {
        std::cout << "ERROR: File \"" << shaderFile << "\" not found \n" << std::endl;
        return;
    }
    pbuf=filestr.rdbuf();
    fileLength = pbuf->pubseekoff(0, std::ios::end, std::ios::in);
    pbuf->pubseekpos(0, std::ios::in);
    buffer = new char[fileLength + 1];
    buffer[fileLength] = '\0';
    pbuf->sgetn (buffer, fileLength);
    filestr.close();

    // compile the shader
    targetShader = glCreateShader(shaderType);
    glShaderSource(targetShader, 1, &buffer, NULL);
    glCompileShader(targetShader);

    // Check for compile time errors
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(targetShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(targetShader, 512, NULL, infoLog);
        std::cout << "ERROR: Failed to compile \"" << shaderFile << "\" \n" << infoLog << std::endl;
    }
}


ShaderProgram::ShaderProgram (const char* vertexShaderFile, const char* fragmentShaderFile) {
    // Build and compile shader
    // Vertex shader
    GLuint vertexShader;
    loadAndCompileShader(vertexShader, vertexShaderFile, GL_VERTEX_SHADER);

    // Fragment shader
    GLuint fragmentShader;
    loadAndCompileShader(fragmentShader, fragmentShaderFile, GL_FRAGMENT_SHADER);

    // Link shaders
    mShaderProgramLocation = glCreateProgram();
    glAttachShader(mShaderProgramLocation, vertexShader);
    glAttachShader(mShaderProgramLocation, fragmentShader);
    glLinkProgram(mShaderProgramLocation);
    // Check for linking errors
    GLint success;
    GLchar infoLog[512];
    glGetProgramiv(mShaderProgramLocation, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(mShaderProgramLocation, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}


void ShaderProgram::activate() {
    glUseProgram(mShaderProgramLocation);
}


GLuint ShaderProgram::getShaderProgramLocation() {
    return mShaderProgramLocation;
}

