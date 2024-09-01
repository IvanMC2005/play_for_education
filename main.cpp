#include "Map.h"
int main()
{
    srand(time(nullptr));
    RenderWindow window(VideoMode::getDesktopMode(), "SFML works!");
    int i = 0;
    Player mouse_brain("animate.png", 2350, 1358, 0.002, 170, 287, "certain_record.txt");
    Font font;
    font.loadFromFile("Montblanc Regular.ttf");
    Sprite map;
    Texture text;
    text.loadFromFile("images/map.png");
    map.setTexture(text);
    Image m;
    Texture texture;
    Sprite tressure;
    double time = 0;
    SoundBuffer electric_shock, receive_tressure;
    receive_tressure.loadFromFile("sounds/receive_tressure.wav");
    electric_shock.loadFromFile("sounds/udar_tokom.wav");
    Sound shock(electric_shock), receive(receive_tressure);
    m.loadFromFile("images/pirate-clipart-treasure-chest-2.png");
    m.createMaskFromColor(Color(255, 255, 255));
    m.createMaskFromColor(Color(254, 254, 254));
    texture.loadFromImage(m);
    tressure.setTexture(texture);
    tressure.setScale(0.1077441077441077f, 0.1138790035587189f);
    menu(window, "images/Menu_background.jpg");
    Clock clock;
    Sprite tressures[4];
    Texture texture_tressure;
    for (i = 0; i < 4; i++)
        tressures[i].setTexture(texture_tressure);
    text.loadFromFile("images/map.png");
    tressures[0].setTextureRect(IntRect(96, 0, 32, 32));
    tressures[1].setTextureRect(IntRect(128, 0, 32, 32));
    tressures[2].setTextureRect(IntRect(160, 0, 32, 32));
    tressures[3].setTextureRect(IntRect(192, 0, 32, 32));
    init_buffermap(mapper);
    while (window.isOpen())
    {   
        if (time == -1)
            time = clock.getElapsedTime().asMicroseconds() - 1000000;
        else
            time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;  
        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)    
                window.close();
        }
        
        window.setView(mouse_brain.getCamera());
        window.clear();
        // Установка позиции и размера объекта line_of_health
        /*cout << "x = " << (mouse_brain.getCamera().getCenter() - Vector2f(500, 500)).x << " y = " << (mouse_brain.getCamera().getCenter() - Vector2f(500, 500)).y << endl;
        line_of_health.setPosition(mouse_brain.getCamera().getCenter() - Vector2f(500, 500));*/

        drawmap(window, map, tressure);
        mouse_brain.update(window, time, shock, receive);
        mouse_brain.show_health(window);
        mouse_brain.show_record(window, font);
        window.draw(mouse_brain.herosp);
        window.display();
    }
    return 0;
}