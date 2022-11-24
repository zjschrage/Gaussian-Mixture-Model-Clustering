#pragma once
#include <SFML/Graphics.hpp>
#include "k_means.h"
#include "em.h"
#include "gaussian_vis.h"
#include "viewmode.h"

void handleKMeansEvents(sf::RenderWindow& window, sf::Event& event);
void handleEMEvents(sf::RenderWindow& window, sf::Event& event);
void switchViewMode(sf::RenderWindow& window, ViewMode& mode, const std::vector<Point*>& points1, const std::vector<Point*>& points2);
void handleEvents(sf::RenderWindow& window, ViewMode& mode, const std::vector<Point*>& points1, const std::vector<Point*>& points2);