#include "Vec3.h"
#include <iostream>

#include <iostream>
int main(){
    Vec3 g = Vec3(0, 0, -9.8);
    Vec3 pos = Vec3();
    float v0x;
    float v0y;
    float v0z;
    std::cout << "Ingrese la velocidad inicial en x: ";
    std::cin >> v0x;
    std::cout << "Ingrese la velocidad inicial en y: ";
    std::cin >> v0y;
    std::cout << "Ingrese la velocidad inicial en z: ";
    std::cin >> v0z;
    Vec3 v = Vec3(v0x, v0y, v0z);
    float dt;
    std::cout << "Ingrese el intervalo de tiempo: ";
    std::cin >> dt;
    //x = v0x * t
    //y = v0y * t
    //z = v0z * t - 0.5 * g * t^2
    float t = 0;
    std::cout << "Posicion: " << pos << " |Velocidad:" << v  <<" |Tiempo: " << t << std::endl;
    while ( pos.getZ() >= 0)   {
        v = v + g * dt; //revisar
        pos = pos + v * dt;
        t += dt;
        // pos = v * t;
        // pos.setZ(pos.getZ() + 0.5 * g.getZ() * t * t);

        std::cout << "Posicion: " << pos << " |Velocidad:" << v  <<" |Tiempo: " << t << std::endl;
    }
    
    return 0;
}