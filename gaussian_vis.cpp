#include "gaussian_vis.h"

void GaussianVis::init(std::vector<Point*>& points1, std::vector<Point*>& points2, const Vector2D& mean1, const Vector2D& mean2, const Matrix2D& cov1, const Matrix2D& cov2, float pi1, float pi2, int n) {
    float gBound = 50;
    for (int i = 0; i < n*pi1; i++) {
        Vector2D p = rand_gauss_generator(mean1, cov1, gBound);
        Vector2D transP = htos(p, mean1);
        points1.push_back(new Point(transP));
    }
    for (int i = 0; i < n*pi2; i++) {
        Vector2D p = rand_gauss_generator(mean2, cov2, gBound);
        Vector2D transP = htos(p, mean2);
        points2.push_back(new Point(transP));
    }
}

void GaussianVis::render(sf::RenderWindow& window, const std::vector<Point*>& points1, const std::vector<Point*>& points2) {
    window.clear();
    for (Point* p : points1) {
        drawPoint(window, p->a(), p->b(), CLUST_A_COLOR);
    }
    for (Point* p : points2) {
        drawPoint(window, p->a(), p->b(), CLUST_B_COLOR);
    }
    window.display();
}