#pragma once
#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_access.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<string>
#include<vector>
#include "Shader.h"
#include "Common.h"


class Mesh {
public:
    // mesh data
    vector<Vertex>       vertices;
    vector<unsigned int> indices;
    vector<Texture>      textures;

    Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);
    void Draw(Shader& shader);
private:
    //  render data
    unsigned int VAO, VBO, EBO;

    void setupMesh();
};