#include <SFML/Graphics.hpp>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <vector>

int num_vertBox = 30, num_horzBox = 20;  
int size = 16;                          
int w = size * num_horzBox;              
int h = size * num_vertBox;             

int lives = 2;
int points = 0;
bool start = true;
int direction; 
constexpr int paddle_length = 4;

struct Block {
    int x, y;       
}p[paddle_length];

void initializePaddle(){
    int x = (num_horzBox - paddle_length) / 2; 
    for(int i = 0; i < paddle_length; i++){
        p[i].x = x + i;
        p[i].y = num_vertBox - 2;
    }
}

void setPaddle(int offset){
    if(p[0].x > 0 && offset == -1 || p[paddle_length-1].x < num_horzBox-1 && offset == 1){
        for(int i = 0; i < paddle_length; i++){
            p[i].x += offset;
        }
    }
}

void movePaddle(int direction){
    if(direction == -1){
        setPaddle(-1);
    }
    else if (direction == 1){
        setPaddle(1);
    }
}

struct Ball{
    int x, y;
    int xD, yD; 
}b;

void initializeBall(){
    b.x = num_horzBox/2;
    b.y = num_vertBox/2;

    b.xD = (rand() % 2 == 0)?(-1):(1);
    b.yD = (rand() % 2 == 0)?(-1):(1);
}

struct Coin{
    int x, y;
}c;

void moveBall(){
    if (b.x == 0 || b.x == num_horzBox - 1){
        b.xD *= -1;
    }
    if (b.y == 0){
        b.yD *= -1;
    }
    else if(b.y == p[0].y - 1){
        if(b.xD == 1 && (b.x >= p[0].x - 1 && b.x <= p[paddle_length-1].x - 1)){
            b.yD *= -1;
        }
        else if(b.xD == -1 && (b.x >= p[0].x + 1 && b.x <= p[paddle_length-1].x + 1)){
            b.yD *= -1;
        }
    }
    else if (b.y > num_vertBox){
        if(lives != 0){
            start = true;
            lives--;
        }
        else{
            start = true;
            lives = 2;
            points = 0;
        }
        initializeBall();
        return;
    }
    if(b.x == c.x || b.x == c.x + 1){
        if(b.y == c.y || b.y == c.y + 1){
            points++;
        }
    }
    b.x += b.xD;
    b.y += b.yD;
}

int main() {
    sf::Event e;

    sf::RenderWindow window(sf::VideoMode(w, h), "Paddle Ball"); 

    sf::Font font;
    font.loadFromFile("font/OpenSans.ttf");

    sf::Text lText;
    lText.setCharacterSize(20);
    lText.setFont(font);
    lText.setStyle(sf::Text::Bold);
    lText.setFillColor(sf::Color::White);
    lText.setPosition(10,10);

    sf::Text pText;
    pText.setCharacterSize(20);
    pText.setFont(font);
    pText.setStyle(sf::Text::Bold);
    pText.setFillColor(sf::Color::White);
    pText.setPosition(num_horzBox*size - 100, 10);

    sf::Texture t1, t2, t3;
    t1.loadFromFile("image/white.png");
    t2.loadFromFile("image/red.png");
    t3.loadFromFile("image/coin.png");

    sf::Sprite sprite1(t1);
    sf::Sprite sprite2(t2);
    sf::Sprite sprite3(t3);

    initializeBall();
    initializePaddle();

    int currentPoints = -1;

    sf::Clock clock;
    float paddleTimer = 0.0f; 
    float ballTimer = 0.0f; 
    while (window.isOpen()) {
        float paddleDelay = 0.05f/(points/10.0 + 1);
        float ballDelay;
        if(start){ ballDelay = 2.0f; }
        else{ ballDelay = 0.07f/(points/10.0 + 1); }
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        paddleTimer += time;
        ballTimer += time;
        
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();             
                        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { direction = -1; }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { direction = 1; }
        else { direction = 2; }
        
        if (paddleTimer > paddleDelay) {
            paddleTimer = 0; 
            movePaddle(direction);
        }
        
        for (int i = 0; i < paddle_length; i++) {
            sprite1.setPosition(p[i].x * size, p[i].y * size);
            window.draw(sprite1);
        }

        if (ballTimer > ballDelay) {
            ballTimer = 0; 
            start = false;
            moveBall();
        }
        sprite2.setPosition(b.x * size, b.y * size);
        window.draw(sprite2);

        if (currentPoints != points){
            currentPoints = points;
            c.x = rand() % (num_horzBox-1 -1 + 1) + 1;
            c.y = rand() % (num_vertBox-20 -20 + 1) + 1;
        }
        sprite3.setPosition(c.x * size, c.y * size);
        window.draw(sprite3);

        lText.setString("lives: " + std::to_string(lives));
        pText.setString("points: " + std::to_string(points));
        window.draw(lText);
        window.draw(pText);
        window.display(); 
    }
    return 0;
}