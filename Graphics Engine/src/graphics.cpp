#include "graphics.h"
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Vertex and fragment shaders
const char* vertexShaderPath = "shaders/vertex_shader.glsl";
const char* fragmentShaderPath = "shaders/fragment_shader.glsl";

float vertices[] = {
    -0.5f, -0.5f, 0.0f,  // Bottom-left
     0.5f, -0.5f, 0.0f,  // Bottom-right
     0.0f,  0.5f, 0.0f   // Top
};

unsigned int VAO, VBO, shaderProgram;

void initGraphics() {
    // Generate buffers
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // Bind VAO and VBO
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Define vertex attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Load shaders
    shaderProgram = loadShaders(vertexShaderPath, fragmentShaderPath);
}

void render() {
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
