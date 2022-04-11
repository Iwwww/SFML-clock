#pragma once
#include <SFML/Graphics.hpp>

class Watch {
    public:
        Watch(int watchRadius);
        void setPos(int posX, int posY);
        
        void setTime(int hour, int minute, int second);

        void setTimeInSeconds(int second);

        void setWatchColor(sf::Color color);

        void draw(sf::RenderWindow& window);

    private:
        int m_posX = 0;
        int m_posY = 0;

        sf::CircleShape m_watchBorder;
        sf::RectangleShape m_marks[4];
        int m_marksWidth = 6;
        int m_marksHeight = 10;
        int m_watchRadius;

        sf::RectangleShape m_secondArrow;
        sf::RectangleShape m_minuteArrow;
        sf::RectangleShape m_hourArrow;
        int m_secondArrowWidth = 2;
        int m_minuteArrowWidth = 2;
        int m_hourArrowWidth = 4;

        sf::CircleShape m_centralDot;
        int m_centralDotRadius = 10;
};
