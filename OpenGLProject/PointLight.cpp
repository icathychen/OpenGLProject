//
//  PointLight.cpp
//  OpenGLProject
//
//  Created by Cathy Chen on 2022-06-06.
//

#include "PointLight.hpp"

PointLight::PointLight() : Light() {
    position = glm::vec3(0.0f, 0.0f,0.0f);
    constant = 1.0f;
    linear = 0.0f;
    exponent = 0.0f;
}

PointLight::PointLight(GLfloat red, GLfloat green, GLfloat blue, GLfloat aIntensity,GLfloat dIntensity,
                       GLfloat xPos, GLfloat yPos,GLfloat zPos, GLfloat con, GLfloat lin, GLfloat exp): Light(red, green, blue, aIntensity, dIntensity){
    position = glm::vec3(xPos, yPos, zPos);
    constant = con;
    linear = lin;
    exponent = exp;
}

void PointLight::UseLight(GLuint ambientIntensityLocation, GLuint ambientColourLocation,
                          GLuint diffuseIntensityLocation, GLuint positionLocation,
                          GLuint constantLocation, GLuint linearLocation, GLuint exponentLocation){
    //Attach ambient light
    glUniform3f(ambientColourLocation, colour.x, colour.y, colour.z);
    glUniform1f(ambientIntensityLocation, ambientIntensity);
    glUniform1f(diffuseIntensityLocation, diffuseIntensity);
    
    //Bind them to their locations
    glUniform3f(positionLocation, position.x, position.y, position.z);
    glUniform1f(constantLocation, constant);
    glUniform1f(linearLocation, linear);
    glUniform1f(exponentLocation, exponent);
}

PointLight::~PointLight(){
    
}
