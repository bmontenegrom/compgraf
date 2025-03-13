#include <iostream>

class Vec3{
    public:
        Vec3();
        Vec3(float x, float y, float z);
        float getNorm() const;
        void setX(float x);
        float getX() const;
        void setY(float y);
        float getY() const;
        void setZ(float z);
        float getZ() const;
        float dot(const Vec3& v);
        Vec3 cross(const Vec3& v);
        Vec3 normalize();
        Vec3 simetrize(const Vec3& v);
        Vec3 operator=(const Vec3& v);
        Vec3 operator+(const Vec3& v);
        Vec3 operator-(const Vec3& v);
        Vec3 operator*(float f) const;
        Vec3 operator/(float f) const;
        Vec3 operator-();
        float angle(const Vec3& v);
        float squareNorm() const;

        friend std::ostream& operator<<(std::ostream& os, const Vec3& v);


    private:
        float x, y, z, norma;

};