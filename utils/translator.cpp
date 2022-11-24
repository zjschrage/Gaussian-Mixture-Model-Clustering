#include "translator.h"

Matrix2D translationMat(1, 0, 0 , -1);
Vector2D translationVec(DIM_X/2, DIM_Y/2);
float scale = 3;
float zoom = 20;

Vector2D stoh(Vector2D p) {
    return translationMat.inv()*((p - translationVec)*(1.0/zoom)) * -1;
}

Vector2D htos(Vector2D p) {
    return (translationMat*p)*zoom + translationVec;
}

Vector2D htos(Vector2D p, const Vector2D& mean) {
    //scaleVec(p, mean);
    return (translationMat*p)*zoom + translationVec;
}

void scaleVec(Vector2D& p, const Vector2D& mean) {
    p = p + (p - mean)*scale;
}