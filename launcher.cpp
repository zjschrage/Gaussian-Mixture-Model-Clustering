#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include "constants.h"
#include "point.h"
#include "gaussian.h"
#include "translator.h"
#include "draw_utils.h"
#include "gaussian_vis.h"
#include "k_means.h"
#include "em.h"
#include "viewmode.h"
#include "event_handler.h"

ViewMode mode = GAUSS;

Vector2D mean1(0, 8);
Matrix2D cov1(4, 0, 0, 4);
float pi1 = 0.5;

Vector2D mean2(2, 4);
Matrix2D cov2(3, 1, 1, 3);
float pi2 = 0.5;

int n = 3000;

std::vector<Point*> points1;
std::vector<Point*> points2;

int main() {
    sf::RenderWindow window(sf::VideoMode(DIM_X, DIM_Y), TITLE);
    window.setFramerateLimit(60);
    
    GaussianVis::init(points1, points2, mean1, mean2, cov1, cov2, pi1, pi2, n);
    GaussianVis::render(window, points1, points2);
    KMeans::init(points1, points2);
    EM::init(points1, points2);

    while (window.isOpen()) {
        handleEvents(window, mode, points1, points2);
    }
    return 0;
}