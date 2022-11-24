#include <vector>
#include "em.h"
#include "gaussian.h"

static std::vector<Point*> allPoints_EM;
static std::vector<std::vector<float>> responsability(2);

static Vector2D* meanA;
static Matrix2D* covA;
static float piA;

static Vector2D* meanB;
static Matrix2D* covB;
static float piB;

static float alphaA = 0;
static float alphaB = 0;

void EM::init(const std::vector<Point*>& points1, const std::vector<Point*>& points2) {
    auto pushLambda = [](Point* p){allPoints_EM.push_back(new Point(*p));};
    std::for_each(points1.begin(), points1.end(), pushLambda);
    std::for_each(points2.begin(), points2.end(), pushLambda);
    int c1 = rand() % allPoints_EM.size();
    int c2 = rand() % allPoints_EM.size();
    meanA = new Vector2D(stoh(allPoints_EM[c1]->point)); covA = new Matrix2D(1, 0, 0 ,1); piA = 0.5;
    meanB = new Vector2D(stoh(allPoints_EM[c2]->point)); covB = new Matrix2D(1, 0, 0, 1); piB = 0.5;
}

void EM::reset() {
    for (Point* p : allPoints_EM) {
        p->color = NO_CLUST_COLOR;
    }
    covA->set(1, 0, 0, 1);
    covB->set(1, 0, 0, 1);
    piA = 0.5;
    piB = 0.5;
}

void EM::expectation() {
    responsability[0].clear();
    responsability[1].clear();
    for (Point* p : allPoints_EM) {
        float rA = gaussian_evaluator(*meanA, *covA, stoh(p->point)) * piA;
        float rB = gaussian_evaluator(*meanB, *covB, stoh(p->point)) * piB;
        float sum = rA + rB;
        responsability[0].push_back(rA/sum);
        responsability[1].push_back(rB/sum);
        if (rA > rB) p->color = CLUST_A_COLOR;
        else p->color = CLUST_B_COLOR;
    }
    alphaA = 0;
    alphaB = 0;
    for (int i = 0; i < allPoints_EM.size(); i++) {
        alphaA += responsability[0][i];
        alphaB += responsability[1][i];
    }
    float totalAlpha = alphaA + alphaB;
    piA = alphaA / totalAlpha;
    piB = alphaB / totalAlpha;
}

void EM::maximization() {
    meanA->set(0, 0);
    meanB->set(0, 0);
    for (int i = 0; i < allPoints_EM.size(); i++) {
        Vector2D p = stoh(allPoints_EM[i]->point);
        *meanA = *meanA + (p * responsability[0][i]);
        *meanB = *meanB + (p * responsability[1][i]);
    }
    *meanA = *meanA * (1.0/alphaA);
    *meanB = *meanB * (1.0/alphaB);

    covA->set(0, 0, 0, 0);
    covB->set(0, 0, 0, 0);
    for (int i = 0; i < allPoints_EM.size(); i++) {
        Vector2D p = stoh(allPoints_EM[i]->point);
        *covA = *covA + (Matrix2D::mult(p - *meanA, p - *meanA) * responsability[0][i]);
        *covB = *covB + (Matrix2D::mult(p - *meanB, p - *meanB) * responsability[1][i]);
    }
    *covA = *covA * (1.0/alphaA);
    *covB = *covB * (1.0/alphaB);
}

void EM::tickEM() {
    printf("meanA (%.3f, %.3f) meanB (%.3f, %.3f)\n", meanA->a, meanA->b, meanB->a, meanB->b);
    printf("covA (%.3f %.3f %.3f %.3f)\n", covA->a, covA->b, covA->c, covA->d);
    printf("covB (%.3f %.3f %.3f %.3f)\n", covB->a, covB->b, covB->c, covB->d);
    expectation();
    maximization();
}

void EM::render(sf::RenderWindow& window) {
    window.clear();
    for (Point* p : allPoints_EM) {
        drawPoint(window, p->a(), p->b(), p->color);
    }
    Vector2D screenMeanA = htos(*meanA);
    Vector2D screenMeanB = htos(*meanB);
    drawPoint(window, screenMeanA.a, screenMeanA.b, CLUST_A_CENTROID);
    drawPoint(window,  screenMeanB.a, screenMeanB.b, CLUST_B_CENTROID);
    window.display();
}

void EM::redrawMean1(float x, float y) {
    *meanA = stoh(Vector2D(x, y));
}

void EM::redrawMean2(float x, float y) {
    *meanB = stoh(Vector2D(x, y));
}