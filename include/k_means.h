#pragma once
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <random>
#include <algorithm>
#include "constants.h"
#include "point.h"
#include "gaussian.h"
#include "translator.h"
#include "draw_utils.h"

class KMeans {
public:
    static void init(const std::vector<Point*>& points1, const std::vector<Point*>& points2);
    static void reset();
    static void assignClusters();
    static void updateCentroids();
    static void tickKmeans();
    static void render(sf::RenderWindow& window);
    static void redrawCentroid1(float x, float y);
    static void redrawCentroid2(float x, float y);
};