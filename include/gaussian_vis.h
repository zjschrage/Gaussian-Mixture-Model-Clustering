#pragma once
#include <SFML/Graphics.hpp>
#include "vector.h"
#include "point.h"
#include "gaussian.h"
#include "translator.h"
#include "draw_utils.h"
#include "constants.h"

class GaussianVis {
public:
    static void init(std::vector<Point*>& points1, std::vector<Point*>& points2, const Vector2D& mean1, const Vector2D& mean2, const Matrix2D& cov1, const Matrix2D& cov2, float pi1, float pi2, int n);
    static void render(sf::RenderWindow& window, const std::vector<Point*>& points1, const std::vector<Point*>& points2);
};