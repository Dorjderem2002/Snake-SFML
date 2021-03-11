#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include "Sfgui.hpp"
using namespace sf;

int main()
{
    start:
    srand(time(NULL));
    RenderWindow app(VideoMode(600,480),"Snake++");
    int sLength = 1,dir = 5;
    float xPos = 300,yPos = 240;
    std::vector<RectangleShape> snake;
    Button resetButton(300,240,200,140);
    bool paused = false;
    resetButton.setText("Play Again?");
    RectangleShape head,last,fruit;
    fruit.setPosition(Vector2f(rand()%580,rand()%460));
    fruit.setSize(Vector2f(20.f,20.f));
    fruit.setFillColor(Color::Red);
    head.setPosition(xPos,yPos);
    head.setFillColor(Color::Green);
    head.setSize(Vector2f(20,20));
    snake.push_back(head);
    for(int i=1;i<=3;i++) {
        RectangleShape t;
        t.setPosition(xPos,yPos + i*20);
        t.setFillColor(Color::Green);
        t.setSize(Vector2f(20,20));
        snake.push_back(t);
        sLength++;
    }
    last = head;
    app.setFramerateLimit(20);
    while(app.isOpen()) {
        Event e;
        while(app.pollEvent(e)) {
            if(e.type == Event::Closed) {
                app.close();
            }
            if(resetButton.OnRelease(app,e)) {
                paused = false;
                goto start;
            }
        }
        if(!paused) {
            if(Keyboard::isKeyPressed(Keyboard::A) && dir != 2) {
                dir = 1;
            }
            if(Keyboard::isKeyPressed(Keyboard::D)  && dir != 1) {
                dir = 2;
            }
            if(Keyboard::isKeyPressed(Keyboard::W) && dir != 4) {
                dir = 3;
            }
            if(Keyboard::isKeyPressed(Keyboard::S) && dir != 3) {
                dir = 4;
            }
            switch(dir) {
            case 1:
                last = snake.at(sLength-1);
                snake.pop_back();
                last.setPosition(Vector2f(head.getPosition().x - 20.0f,head.getPosition().y));
                snake.insert(snake.begin(),last);
                head = last;
                last = snake.at(sLength-1);
                break;
            case 2:
                last = snake.at(sLength-1);
                snake.pop_back();
                last.setPosition(Vector2f(head.getPosition().x + 20.0f,head.getPosition().y));
                snake.insert(snake.begin(),last);
                head = last;
                last = snake.at(sLength-1);
                break;
            case 3:
                last = snake.at(sLength-1);
                snake.pop_back();
                last.setPosition(Vector2f(head.getPosition().x,head.getPosition().y - 20));
                snake.insert(snake.begin(),last);
                head = last;
                last = snake.at(sLength-1);
                break;
            case 4:
                last = snake.at(sLength-1);
                snake.pop_back();
                last.setPosition(Vector2f(head.getPosition().x,head.getPosition().y + 20));
                snake.insert(snake.begin(),last);
                head = last;
                last = snake.at(sLength-1);
                break;
            case 0:
                break;
            }
            if(head.getGlobalBounds().intersects(fruit.getGlobalBounds())) {
                fruit.setPosition(Vector2f(rand()%580,rand()%460));
                sLength++;
                RectangleShape t;
                t.setPosition(last.getPosition());
                t.setFillColor(Color::Green);
                t.setSize(Vector2f(20,20));
                snake.push_back(t);
                last = snake.at(sLength-1);
            }
            for(int i=1;i<sLength;i++) {
                if(head.getPosition() == snake.at(i).getPosition()) {
                    dir = 0;
                    paused = true;
                }
            }
            if(head.getPosition().x > 580 || head.getPosition().x < 0 ||
               head.getPosition().y > 460 || head.getPosition().y < 0) {
                    dir = 0;
                    paused = true;
            }
        }
        app.clear();
        app.draw(fruit);
        for(int i=0;i<sLength;i++) {
            app.draw(snake.at(i));
        }
        if(dir == 0) {
            resetButton.draw(app);
        }
        app.display();
    }
    return 0;
}
