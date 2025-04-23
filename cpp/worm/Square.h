#pragma once  

class Square  
{  
private:  
   float x, y; // Posici�n del cuadrado  
   float size; // Tama�o del cuadrado  

public:  
   // Constructor  
   Square(float x, float y, float s);  

   void render() const; // Agregar 'const' para que sea compatible con objetos constantes
   float getX();
   float getY();
   float getSize();
   void setX(float newX);
   void setY(float newY);
   void setSize(float newSize);
};

