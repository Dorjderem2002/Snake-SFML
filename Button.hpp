//
//  Button.hpp
//  SFGUI
//
//  Created by Dode Pep on 11/24/19.
//  Copyright © 2019 Dode. All rights reserved.
//

#ifndef Button_hpp
#define Button_hpp

#include <SFML/Graphics.hpp>
#include <string.h>
using namespace sf;

class Button {
public:
    Button(float xx,float yx, int width,int height);
    bool OnClick(RenderWindow &window,Event e);
    bool OnRelease(RenderWindow &window,Event e);
    void setColor(Color color);
    void setFont(Font font);
    void setActive(bool condition);
    void setPosition(Vector2f pos);
    void setSize(Vector2i size);
    Vector2f getPosition();
    Vector2i getSize();
    std::string getText();
    void setText(std::string text);
    void draw(RenderWindow &window);
    void setWindow(RenderWindow &window);
    void setTextScale(float xs,float ys);
    
private:
    float x,y;
    int w,h;
    RectangleShape background;
    Text text;
    Font font;
    bool isActive;
    Color color = Color::White;
};

#endif /* Button_hpp */
