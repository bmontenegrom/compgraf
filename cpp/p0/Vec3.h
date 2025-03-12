class Vec3{
    public:
        Vec3();
        Vec3(float x, float y, float z);
        float getNorm();
        void setX(float x);
        float getX();
        void setY(float y);
        float getY();
        void setZ(float z);
        float getZ();
        void renorm();
        Vec3 simetrize(const Vec3& v);
        Vec3 operator+(const Vec3& v);
        Vec3 operator-(const Vec3& v);
        Vec3 operator*(float f);
        Vec3 operator/(float f);
        Vec3 operator-();
        float dot(const Vec3& v);
        Vec3 cross(const Vec3& v);
        


    private:
        float x, y, z, norm;

};