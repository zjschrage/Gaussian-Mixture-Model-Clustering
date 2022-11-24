#pragma once
#include "vector.h"
#include "matrix.h"
#include "constants.h"

Vector2D stoh(Vector2D p);
Vector2D htos(Vector2D p);
Vector2D htos(Vector2D p, const Vector2D& mean);
void scaleVec(Vector2D& p, const Vector2D& mean);

