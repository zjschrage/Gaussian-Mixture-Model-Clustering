#include "event_handler.h"

void handleKMeansEvents(sf::RenderWindow& window, sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Key::Space) {
            KMeans::tickKmeans();
            KMeans::render(window);
        }
        if (event.key.code == sf::Keyboard::Key::R) {
            KMeans::reset();
            KMeans::render(window);
        }
    }
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Button::Left) KMeans::redrawCentroid1(event.mouseButton.x, event.mouseButton.y);
        if (event.mouseButton.button == sf::Mouse::Button::Right) KMeans::redrawCentroid2(event.mouseButton.x, event.mouseButton.y);
        KMeans::assignClusters();
        KMeans::render(window);
    }
}

void handleEMEvents(sf::RenderWindow& window, sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Key::Space) {
            EM::tickEM();
            EM::render(window);
        }
        if (event.key.code == sf::Keyboard::Key::R) {
            EM::reset();
            EM::render(window);
        }
    }
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Button::Left) EM::redrawMean1(event.mouseButton.x, event.mouseButton.y);
        if (event.mouseButton.button == sf::Mouse::Button::Right) EM::redrawMean2(event.mouseButton.x, event.mouseButton.y);
        EM::reset();
        EM::render(window);
    }
}

void switchViewMode(sf::RenderWindow& window, ViewMode& mode, const std::vector<Point*>& points1, const std::vector<Point*>& points2) {
    switch(mode) {
        case GAUSS:
            mode = KMEANS;
            KMeans::reset();
            KMeans::render(window);
            break;
        case KMEANS:
            mode = EM;
            EM::reset();
            EM::render(window);
            break;
        case EM:
            mode = GAUSS;
            GaussianVis::render(window, points1, points2);
            break;
    }
}

void handleEvents(sf::RenderWindow& window, ViewMode& mode, const std::vector<Point*>& points1, const std::vector<Point*>& points2) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) window.close();
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::Enter) {
            switchViewMode(window, mode, points1, points2);
        }
        switch (mode) {
            case KMEANS: handleKMeansEvents(window, event);
                break;
            case EM: handleEMEvents(window, event);
                break;
            default:
                break;
        }
    }
}