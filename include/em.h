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

class EM {
public:
    static void init(const std::vector<Point*>& points1, const std::vector<Point*>& points2);
    static void reset();
    static void expectation();
    static void maximization();
    static void tickEM();
    static void render(sf::RenderWindow& window);
    static void redrawMean1(float x, float y);
    static void redrawMean2(float x, float y);
};