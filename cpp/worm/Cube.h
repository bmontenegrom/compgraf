#pragma once
class Cube {
private:
    float x, y, z;    // Posici�n del cubo
    float size;       // Tama�o del cubo
public:
    Cube(float x , float y, float z, float size);

    void render() const;

    float getX();
    float getY();
    float getZ();
    float getSize();
    void setX(float newX);
    void setY(float newY);
    void setZ(float newZ);
    void setSize(float newSize);
};

