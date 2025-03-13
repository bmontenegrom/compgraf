#include "Vec3.h"
#include <cmath>

Vec3::Vec3(){
    x = 0;
    y = 0;
    z = 0;
    norma = 0;
}

Vec3::Vec3(float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z;
    norma = sqrt(x*x + y*y + z*z);
}

float Vec3::getNorm() const {
    return norma;
}

void Vec3::setX(float x){
    this->x = x;
    norma = sqrt(x*x + y*y + z*z);
}

float Vec3::getX() const{
    return x;
}

void Vec3::setY(float y){
    this->y = y;
    norma = sqrt(x*x + y*y + z*z);
}

float Vec3::getY() const{
    return y;
}

void Vec3::setZ(float z){
    this->z = z;
    norma = sqrt(x*x + y*y + z*z);
}

float Vec3::getZ() const{
    return z;
}

float Vec3::dot(const Vec3& v){
    return x*v.x + y*v.y + z*v.z;
}

Vec3 Vec3::cross(const Vec3& v){
    return Vec3(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
}

Vec3 Vec3::simetrize(const Vec3& v){
    return v * (2 * dot(v) / v.getNorm()) - *this;
}

Vec3 Vec3::operator=(const Vec3& v){
    x = v.x;
    y = v.y;
    z = v.z;
    norma = v.norma;
    return *this;
}


Vec3 Vec3::normalize(){
    return *this / norma;
}

Vec3 Vec3::operator+(const Vec3& v){
    return Vec3(x + v.x, y + v.y, z + v.z);
}

Vec3 Vec3::operator-(const Vec3& v){
    return Vec3(x - v.x, y - v.y, z - v.z);
}

Vec3 Vec3::operator*(float f) const {
    return Vec3(x*f, y*f, z*f);
}

Vec3 Vec3::operator/(float f) const {
    return Vec3(x/f, y/f, z/f);
}

Vec3 Vec3::operator-(){
    return Vec3(-x, -y, -z);
}

float Vec3::angle(const Vec3& v){
    return acos(dot(v) / (norma * v.norma));
}

float Vec3::squareNorm() const{
    return norma * norma;
}

std::ostream& operator<<(std::ostream& os, const Vec3& v){
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}