//
//  Button.cpp
//  SFGUI
//
//  Created by Dode Pep on 11/24/19.
//  Copyright © 2019 Dode. All rights reserved.
//

#include "Button.hpp"

Button::Button(float xx,float yx, int width,int height) {
    x = xx;
    y = yx;
    w = width;
    h = height;
    isActive = true;
    font.loadFromFile("arial.ttf");
    text.setFont(font);
    text.setString("Button");
    background.setSize(Vector2f(w,h));
    background.setPosition(x, y);
    background.setFillColor(color);
    background.setOrigin(width/2, height/2);
    text.setOrigin(text.getLocalBounds().width/2.0f,text.getLocalBounds().height/2.0f);
    text.setPosition(x, y);
    text.setFillColor(Color::Black);

}
bool Button::OnClick(RenderWindow &window,Event e) {
    Vector2i mousePos = Mouse::getPosition(window);
    auto trans = window.mapPixelToCoords(mousePos);
    if(background.getGlobalBounds().contains(trans) && e.type == Event::MouseButtonReleased) {
        color = Color(255,255,255);
        background.setFillColor(color);
    }
    if(background.getGlobalBounds().contains(trans) && e.type == Event::MouseButtonPressed) {
        color = Color(150,150,150);
        background.setFillColor(color);
        return true;
    }
    else {
        return false;
    }
}
void Button::draw(RenderWindow &window) {
    window.draw(background);

    window.draw(text);
}
void Button::setText(std::string t) {
    text.setString(t);
    text.setOrigin(text.getLocalBounds().width/2.0f,text.getLocalBounds().height/2.0f);
    text.setPosition(x, y);
}
bool Button::OnRelease(RenderWindow &window,Event e) {
    Vector2i mousePos = Mouse::getPosition(window);
    auto trans = window.mapPixelToCoords(mousePos);
    if(background.getGlobalBounds().contains(trans) && e.type == Event::MouseButtonReleased) {
        return true;
    }
    else {
        return false;
    }
}
void Button::setTextScale(float xs, float ys) {
    text.setScale(xs, ys);
}
Vector2f Button::getPosition() {
    return background.getPosition();
}
std::string Button::getText() {
    return text.getString();
}
