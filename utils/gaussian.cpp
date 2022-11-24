#include "gaussian.h"
#include "translator.h"

Vector2D rand_gauss_generator(const Vector2D& mean, const Matrix2D& cov, float gBound) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> prob(0, 1.0/abs(sqrt(2*M_PI*cov.det())));
    std::uniform_real_distribution<double> x_dist(mean.a - gBound, mean.a + gBound);
    std::uniform_real_distribution<double> y_dist(mean.b - gBound, mean.b + gBound);
    Vector2D randPoint(0, 0);
    while (true) {
        randPoint.set(x_dist(gen), y_dist(gen));
        float p = gaussian_evaluator(mean, cov, randPoint);
        if (prob(gen) <= p) return randPoint;
    }
    return randPoint;
}

float gaussian_evaluator(const Vector2D& mean, const Matrix2D& cov, const Vector2D& point) {
    float p = 1.0/abs(sqrt(2*M_PI*cov.det()));
    float exp = -0.5 * (Matrix2D::mult(point-mean, cov.inv())*(point-mean));
    p *= pow(M_E, exp);
    return p;
}