#include "Watch.h"

Watch::Watch(int watchRadius) {
    m_watchRadius = watchRadius;
    m_watchBorder = sf::CircleShape(m_watchRadius);
    m_watchBorder.setPointCount(100);
    m_watchBorder.setFillColor(sf::Color::Transparent);
    m_watchBorder.setOutlineThickness(3);
    m_watchBorder.setOutlineColor(sf::Color::White);
    m_watchBorder.setPosition(m_posX, m_posY);

    // init marks on watch every 90 degrees
    for (int i = 0; i < 4; i+=2) {
        m_marks[i] = sf::RectangleShape(sf::Vector2f(m_marksWidth, m_marksHeight));
    }
    for (int i = 1; i < 4; i+=2) {
        m_marks[i] = sf::RectangleShape(sf::Vector2f(m_marksHeight, m_marksWidth));
    }
    // init clock arrow
    m_secondArrow = sf::RectangleShape(sf::Vector2f(m_watchRadius * 0.9, m_secondArrowWidth));
    m_secondArrow.setRotation(-90);
    m_minuteArrow = sf::RectangleShape(sf::Vector2f(m_watchRadius * 0.8, m_minuteArrowWidth));
    m_minuteArrow.setRotation(-90);
    m_hourArrow = sf::RectangleShape(sf::Vector2f(m_watchRadius * 0.4, m_hourArrowWidth));
    m_hourArrow.setRotation(-90);

    m_secondArrow.setFillColor(sf::Color(227, 39, 39));

    m_centralDot = sf::CircleShape(m_centralDotRadius);
    m_centralDot.setFillColor(sf::Color::White);

    setPos(m_posX, m_posY);
};

void Watch::setPos(int posX, int posY) {
    m_posX = posX;
    m_posY = posY;

    m_watchBorder.setPosition(m_posX, m_posY);

    m_marks[0].setPosition(m_posX + m_watchRadius - m_marksWidth/2, m_posY - m_marksHeight/2);
    m_marks[1].setPosition(m_posX + 2*m_watchRadius - m_marksHeight/2, m_posY + m_watchRadius);
    m_marks[2].setPosition(m_posX + m_watchRadius - m_marksWidth/2, m_posY + 2*m_watchRadius - m_marksHeight/2);
    m_marks[3].setPosition(m_posX - m_marksHeight/2, m_posY + m_watchRadius - m_marksHeight/2);

    m_secondArrow.setPosition(m_posX + m_watchRadius - m_minuteArrowWidth/2, m_posY + m_watchRadius);
    m_minuteArrow.setPosition(m_posX + m_watchRadius - m_minuteArrowWidth/2, m_posY + m_watchRadius);
    m_hourArrow.setPosition(m_posX + m_watchRadius - m_hourArrowWidth/2, m_posY + m_watchRadius);

    m_centralDot.setPosition(m_posX + m_watchRadius - m_centralDotRadius, m_posY + m_watchRadius - m_centralDotRadius);
}

void Watch::setTime(int hour, int minute, int second) {
    if ((hour >= 0 && hour <= 12) && (minute >= 0 && minute <= 60) && (second >= 0 && second <= 60)) {
        m_hourArrow.setRotation(360/12 * hour - 90);
        m_minuteArrow.setRotation(360/60 * minute - 90);
        m_secondArrow.setRotation(360/60 * second - 90);
    }
}

void Watch::setTimeInSeconds(int second) {
    m_hourArrow.setRotation(second * 360/60/60/12 - 90);
    m_minuteArrow.setRotation(second * 360/60/60 - 90);
    m_secondArrow.setRotation(second * 360/60 - 90);
}

void Watch::setWatchColor(sf::Color color) {
    m_watchBorder.setOutlineColor(color);
}

void Watch::draw(sf::RenderWindow& window) {
    window.draw(m_watchBorder);
    for (int i = 0; i < 4; i++) {
        window.draw(m_marks[i]);
    }

    window.draw(m_secondArrow);
    window.draw(m_minuteArrow);
    window.draw(m_hourArrow);

    window.draw(m_centralDot);
}
