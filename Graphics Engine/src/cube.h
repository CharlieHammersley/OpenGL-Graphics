#ifndef CUBE_H
#define CUBE_H

#include <glad/glad.h>

class Cube {
public:
    unsigned int VAO, VBO;

    Cube() {
        float vertices[] = {
            // Positions         // Colors
            -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f, // Red
             0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, // Green
             0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f, // Blue
            -0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f, // Yellow

            -0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 1.0f, // Magenta
             0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 1.0f, // Cyan
             0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f, // White
            -0.5f,  0.5f,  0.5f,  0.5f, 0.5f, 0.5f  // Gray
        };

        unsigned int indices[] = {
            0, 1, 2, 2, 3, 0, // Back
            4, 5, 6, 6, 7, 4, // Front
            0, 1, 5, 5, 4, 0, // Bottom
            2, 3, 7, 7, 6, 2, // Top
            0, 3, 7, 7, 4, 0, // Left
            1, 2, 6, 6, 5, 1  // Right
        };

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
    }

    void draw() {
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }
};

#endif
