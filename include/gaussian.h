#pragma once
#include <random>
#include <math.h>
#include <iostream>
#include "matrix.h"
#include "vector.h"

Vector2D rand_gauss_generator(const Vector2D& mean, const Matrix2D& cov, float gBound);
float gaussian_evaluator(const Vector2D& mean, const Matrix2D& cov, const Vector2D& point);