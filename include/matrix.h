#pragma once
#include <cstdlib>
#include "vector.h"

struct Matrix2D {
    float a, b;
    float c, d;

    Matrix2D(float a, float b, float c, float d) : a(a), b(b), c(c), d(d) {}
    Matrix2D(const Matrix2D& m) : a(m.a), b(m.b), c(m.c), d(m.d) {}
    Matrix2D operator+(const Matrix2D& m) const { return Matrix2D(a + m.a, b + m.b, c + m.c, d + m.d);}
    Vector2D operator*(const Vector2D& v) const { return Vector2D(a*v.a + b*v.b, c*v.a + d*v.b);}
    Matrix2D operator*(float s) const { return Matrix2D(a*s, b*s, c*s, d*s);}
    Matrix2D operator*(const Matrix2D& m) const { return Matrix2D(a*m.a + b*m.c, a*m.b + b*m.d, c*m.a + d*m.c, c*m.b + d*m.d);}

    float det() const { return (a*d - b*c);}
    Matrix2D transpose() const { return Matrix2D(a, c, b, d); }
    Matrix2D inv() const { return Matrix2D(d, -b, -c, a)*(1.0/abs(this->det())); }
    
    void set(float a, float b, float c, float d) {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }

    static Vector2D mult(const Vector2D v, const Matrix2D& m) { 
        return Vector2D(v.a*m.a + v.b*m.c, v.a*m.b + v.b*m.d);
    }

    static Matrix2D mult(const Vector2D& v, const Vector2D& t) {
        return Matrix2D(v.a * t.a, v.b * t.a, v.a * t.b, v.b * t.b);
    }
};