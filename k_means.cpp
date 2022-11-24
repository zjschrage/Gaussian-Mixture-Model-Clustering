#include "k_means.h"

static std::vector<Point*> allPoints;
static Point* centroid1;
static Point* centroid2;

void KMeans::init(const std::vector<Point*>& points1, const std::vector<Point*>& points2) {
    auto pushLambda = [](Point* p){allPoints.push_back(new Point(*p));};
    std::for_each(points1.begin(), points1.end(), pushLambda);
    std::for_each(points2.begin(), points2.end(), pushLambda);
    int c1 = rand() % allPoints.size();
    int c2 = rand() % allPoints.size();
    centroid1 = new Point(allPoints[c1]->point, CLUST_A_CENTROID);
    centroid2 = new Point(allPoints[c2]->point, CLUST_B_CENTROID);
}

void KMeans::reset() {
    for (Point* p : allPoints) {
        p->color = NO_CLUST_COLOR;
    }
}

void KMeans::assignClusters() {
    for (Point* p : allPoints) {
        if (p->l2norm(*centroid1) < p->l2norm(*centroid2)) {
            p->color = CLUST_A_COLOR;
        } else {
            p->color = CLUST_B_COLOR;    
        }
    }
}

void KMeans::updateCentroids() {
    float c1a = 0; float c1b = 0; float c1n = 0;
    float c2a = 0; float c2b = 0; float c2n = 0;
    for (Point* p : allPoints) {
        if (p->color == CLUST_A_COLOR) {
            c1a += p->a();
            c1b += p->b();
            c1n++;
        } else {
            c2a += p->a();
            c2b += p->b();
            c2n++;
        }
    }
    centroid1->setLocation(c1a/c1n, c1b/c1n);
    centroid2->setLocation(c2a/c2n, c2b/c2n);
}

void KMeans::tickKmeans() {
    assignClusters();
    updateCentroids();
}

void KMeans::render(sf::RenderWindow& window) {
    window.clear();
    for (Point* p : allPoints) {
        drawPoint(window, p->a(), p->b(), p->color);
    }
    drawPoint(window, centroid1->a(), centroid1->b(), centroid1->color);
    drawPoint(window, centroid2->a(), centroid2->b(), centroid2->color);
    window.display();
}

void KMeans::redrawCentroid1(float x, float y) {
    centroid1->setLocation(x, y);
}

void KMeans::redrawCentroid2(float x, float y) {
    centroid2->setLocation(x, y);
}