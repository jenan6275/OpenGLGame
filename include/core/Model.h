#pragma once
#include<assimp/Importer.hpp>
#include<assimp/scene.h>
#include<assimp/postprocess.h>
#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_access.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<string>
#include<vector>
#include "graphics/Shader.h"
#include "Mesh.h"




using namespace std;

class Model
{
public:
    Model(string path)
    {
        loadModel(path);
    }
    Model()
    {

    }
    void Draw(Shader& shader);
    void loadModel(string path);
private:
    // model data
    vector<Mesh> meshes;
    string directory;

   
    void processNode(aiNode* node, const aiScene* scene);
    Mesh processMesh(aiMesh* mesh, const aiScene* scene);
    vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type,
        string typeName);
    unsigned int TextureFromFile(const char* path, const string& directory, bool gamma);
};
