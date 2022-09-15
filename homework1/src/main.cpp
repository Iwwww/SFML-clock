#include "models/Watch/Watch.h"
#include <SFML/Graphics.hpp>

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML Clock", sf::Style::Default, settings);

    Watch watch(300);
    watch.setPos(100, 100);
    // watch.setTime(3, 48, 24); // preview

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    
        sf::Time elapsed = clock.getElapsedTime();

        watch.setTimeInSeconds(elapsed.asSeconds());
    
        window.clear(sf::Color::Black);
        watch.draw(window);
        window.display();
    }

    return 0;
}

