#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include "vector.h"
#include "constants.h"

struct Point {
    Vector2D point;
    sf::Color color;

    Point(Vector2D point) : point(point) {
        this->color = NO_CLUST_COLOR;
    }

    Point(Vector2D point, sf::Color color) : point(point), color(color) {}

    Point(const Point& p) {
        this->point = Vector2D(p.point.a, p.point.b);
        this->color = p.color;
    }

    float l2norm(const Point& p) {
        return sqrt(pow(point.a - p.point.a, 2) + pow(point.b - p.point.b,2));
    }

    void setColor(sf::Color color) {
        this->color = color;
    }

    void setLocation(float x, float y) {
        this->point.a = x;
        this->point.b = y;
    }

    float a() {return point.a;}
    float b() {return point.b;}
};