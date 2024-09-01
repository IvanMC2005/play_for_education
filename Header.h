#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <cmath>
#include <string>
using namespace sf;
using namespace std;

class Player    
{
    double speed, width, height;
    int dx, dy;
    int Health;
    double switch_animation;
    int record_count;
    int certain_count;
    View camera;
    RectangleShape line_of_health;
    double coordX, start_coordX;
    double coordY, start_coordY;
    Texture texture;
    Vector2f direction;
public:
    Player(string, double, double, double, int, int, string);
    void show_record(RenderWindow&, Font &);
    Vector2f& is_collide(char, double);
    void update(RenderWindow &, double, Sound &, Sound &);
    int getHealth();
    Sprite herosp;
    void show_health(RenderWindow&);
    void resetView(double , double );
    double getX();
    double getY();
    View getCamera();
    ~Player();
};