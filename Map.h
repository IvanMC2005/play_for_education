#pragma once
#include "Header.h"
#define HEIGHT_MAP 48
#define WIDTH_MAP 200
char mapper[HEIGHT_MAP][WIDTH_MAP] = {
	"0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
	"0                                                                                                                                                                                                     0",
	"0                                                                                                                                                                                                     0",
	"0                                                                                                                                                                                                     0",
	"0                                 sssssssssssssssssssssssssssssssssssssssssssssssssssssss             sssssssssssssssssssssssssssssss                                                                 0",
	"0                                 s                   s                                               s                             s                                                                 0",
	"0                                 s         T         s                                               s                      T      s                                                                 0",
	"0                                 s                   s                                               s                             s                                                                 0",
	"0                                 s                   s                                               s                             s                                                                 0",
	"0                                 s         s         s            ssssssssssssssssssssssssssssssssssss          s         s        s                                                                 0",
	"0                                 s         s                      s                                             s         s        s                                                                 0",
	"0                                 s         s                      s                                             s         s        s                                                                 0",
	"0                                 s         s                      s                            T                s         ssssssssss                                                                 0",
	"0                                 s         s                      s                                             s         s   T    s                                                                 0",
	"0                                 s         sssssssssss            s                                             s         s        s                                                                 0",
	"0                                 s         s                      s                ssssssssssssssssssssssssssssss         s        s                                                                 0",
	"0                                 s         s                      s                s                                      s        s                                                                 0",
	"0                                 s         s                      s                s                                      s        s                                                                 0",
	"0                                 s         s                      s                s  T                                   s        s                                                                 0",
	"0                                 s         s                      s                s                                      s        s                                                                 0",
	"0                                 s         ssssssssssssssssssssssss                ssssssssssssssssssssssssssss           s        s                                                                 0",
	"0                                 s                                                                 s                      s        s                                                                 0",
	"0                                 s                                                                 s                      s        s                                                                 0",
	"0                                 s                              T                                  s                      s        s                                                                 0",
	"0                                 s                                                                 s                      s        s                                                                 0",
	"0                                 s         ssssssssssssssssssssssssssssssssssss                    s                               s                                                                 0",
	"0                                 s         s         s                        s                    s             s                 s                                                                 0",
	"0                                 s         s         s       T                s                  	 s             s                 s                                                                 0",
	"0                                 s         s         s                        s                    s             s                 s                                                                 0",
	"0                                 s         s         s                        ssssssssssssssssssssss             sssssssss         s                                                                 0",
	"0                                 s         s         s           s                                               s       s         s                                                                 0",
	"0                                 s                   s           s                                               s       s         s                                                                 0",
	"0                                 s                   s           s                                               s       s         s                                                                 0",
	"0                                 s                   s           s                                               s       s         s                                                                 0",
	"0                                 s                   s           ssssssssssssssssss        T                     s       s         s                                                                 0",
	"0                                 ssssssssss          s                            s                   s          s       s         s                                                                 0",
	"0                                 s                   s                            s                   s          s       s         s                                                                 0",
	"0                                 s                   s                            s                   s          s       s         s                                                                 0",
	"0                                 s                   s                            s                   s          s       s         s                                                                 0",
	"0                                 s                   sssssssssssssssssssssss      s                   ssssssssssss       sssssssssss                                                                 0",
	"0                                 s     T                              s           s                                                s                                                                 0",
	"0                                 s                                    s           s                                           T    s                                                                 0",
	"0                                 s                                    s           s                                                s                                                                 0",
	"0                                 s                                    s           s                                                s                                                                 0",
	"0                                 ssssssssssssssssssssssssssssssssssssss           ssssssssssssssssssssssssssssssssssssssssssssssssss                                                                 0",
	"0                                                                                                                                                                                                     0",
	"0                                                                                                                                                                                                     0",
	"0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
}, buffer_map[HEIGHT_MAP][WIDTH_MAP];

void init_buffermap(char[HEIGHT_MAP][WIDTH_MAP])
{
	for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
			buffer_map[i][j] = mapper[i][j];
}

void Player::update(RenderWindow& window, double time, Sound& shock, Sound& receive_tressure)
{
	camera.reset(FloatRect(0, 0, 640, 480));
	Vector2f pos = window.mapPixelToCoords(Mouse::getPosition(window)), heropos = herosp.getPosition();
	direction = pos - heropos;
	if (direction.x)
		if (direction.x > 0)
			dx = 1;
		else
			dx = -1;
	else
		dx = 0;
	if (direction.y)
		if (direction.y > 0)
			dy = 1;
		else
			dy = -1;
	else
		dy = 0;
	
	if (int(switch_animation) > 2) switch_animation = 0;
	if (dx > 0)
	{
		herosp.setTextureRect(IntRect(538 + int(switch_animation) * 176, 0, 140, 280));
	}
	if (!dx && dy < 0)
	{
		herosp.setTextureRect(IntRect(int(switch_animation) * 170, 287, 170, 287));
	}
	if (!dx && dy > 0)
	{
		herosp.setTextureRect(IntRect(int(switch_animation) * 170, 0, 170, 287));
	}
	if (dx < 0)
	{
		herosp.setTextureRect(IntRect(538 + int(switch_animation) * 176, 287, 140, 280));
	}
	herosp.setScale(64 / width, 96 / height);
	/*cout << "intersection - " << mapper[int((coordY + direction.y * speed * time) / 32)][int((coordX + direction.x * speed * time) / 32)] << endl;*/
	if ((heropos = is_collide('0', time)).x != -1 || (heropos = is_collide('s', time)).x != -1)
	{
		shock.play();
		//sleep(seconds(1));
		Health -= 1;
		if (Health == 0)
		{
			init_buffermap(mapper);
			certain_count = 0;
			herosp.setPosition(start_coordX, start_coordY);
			coordX = start_coordX;
			coordY = start_coordY;
			resetView(coordX, coordY);
			Health = 200;
		}
		time = 0;
	}
	if ((heropos = is_collide('T', time)).x != -1)
	{
		int i, j;
		certain_count++;
		if (certain_count > record_count)
		{
			record_count = certain_count;
		}
		receive_tressure.play();
		buffer_map[int(heropos.y)][int(heropos.x)] = ' ';
	}
	herosp.move(direction.x * speed * time, direction.y * speed * time);
	coordX = herosp.getPosition().x;
	coordY = herosp.getPosition().y;
	resetView(coordX, coordY);
	switch_animation += 0.01 * time;
}

Vector2f& Player::is_collide(char symbol, double time)
{
	Vector2f intercept;
	if (buffer_map[int((coordY + direction.y * speed * time) / 32)][int((coordX + direction.x * speed * time) / 32) + 2] == symbol)
	{
		intercept.y = int((coordY + direction.y * speed * time) / 32);
		intercept.x = int((coordX + direction.x * speed * time) / 32) + 2;
		return intercept;
	}
	if (buffer_map[int((coordY + direction.y * speed * time) / 32) + 3][int((coordX + direction.x * speed * time) / 32) + 2] == symbol)
	{
		intercept.y = int((coordY + direction.y * speed * time) / 32) + 3;
		intercept.x = int((coordX + direction.x * speed * time) / 32) + 2;
		return intercept;
	}
	if (buffer_map[int((coordY + direction.y * speed * time) / 32) + 3][int((coordX + direction.x * speed * time) / 32) + 1] == symbol)
	{
		intercept.y = int((coordY + direction.y * speed * time) / 32) + 3;
		intercept.x = int((coordX + direction.x * speed * time) / 32) + 1;
		return intercept;
	}
	if (buffer_map[int((coordY + direction.y * speed * time) / 32) + 1][int((coordX + direction.x * speed * time) / 32)] == symbol)
	{
		intercept.y = int((coordY + direction.y * speed * time) / 32) + 1;
		intercept.x = int((coordX + direction.x * speed * time) / 32);
		return intercept;
	}
	if (buffer_map[int((coordY + direction.y * speed * time) / 32) + 2][int((coordX + direction.x * speed * time) / 32) + 2] == symbol)
	{
		intercept.y = int((coordY + direction.y * speed * time) / 32) + 2;
		intercept.x = int((coordX + direction.x * speed * time) / 32) + 2;
		return intercept;
	}
	if (buffer_map[int((coordY + direction.y * speed * time) / 32) + 1][int((coordX + direction.x * speed * time) / 32) + 2] == symbol)
	{
		intercept.y = int((coordY + direction.y * speed * time) / 32) + 1;
		intercept.x = int((coordX + direction.x * speed * time) / 32) + 2;
		return intercept;
	}
	if (buffer_map[int((coordY + direction.y * speed * time) / 32)][int((coordX + direction.x * speed * time) / 32)] == symbol)
	{
		intercept.y = int((coordY + direction.y * speed * time) / 32);
		intercept.x = int((coordX + direction.x * speed * time) / 32);
		return intercept;
	}
	if (buffer_map[int((coordY + direction.y * speed * time) / 32) + 3][int((coordX + direction.x * speed * time) / 32)] == symbol)
	{
		intercept.y = int((coordY + direction.y * speed * time) / 32) + 3;
		intercept.x = int((coordX + direction.x * speed * time) / 32);
		return intercept;
	}
	if (buffer_map[int((coordY + direction.y * speed * time) / 32) + 2][int((coordX + direction.x * speed * time) / 32)] == symbol)
	{
		intercept.y = int((coordY + direction.y * speed * time) / 32) + 2;
		intercept.x = int((coordX + direction.x * speed * time) / 32);
		return intercept;
	}
	if (buffer_map[int((coordY + direction.y * speed * time) / 32)][int((coordX + direction.x * speed * time) / 32) + 1] == symbol)
	{
		intercept.y = int((coordY + direction.y * speed * time) / 32);
		intercept.x = int((coordX + direction.x * speed * time) / 32) + 1;
		return intercept;
	}
	intercept.y = -1;
	intercept.x = -1;
	return intercept;
}

Sprite Loadmap(string namefile, Sprite& sprite)
{
	Texture text;
	text.loadFromFile(namefile);
	sprite.setTexture(text);
	return sprite;
}

void drawmap(RenderWindow& window, Sprite& temp, Sprite tressure)
{
	int i, j;
	for (i = 0; i < HEIGHT_MAP; i++)
		for (j = 0; j < WIDTH_MAP; j++)
		{
			if (buffer_map[i][j] == ' ')
				temp.setTextureRect(IntRect(0, 0, 32, 32));
			if (buffer_map[i][j] == 's')
				temp.setTextureRect(IntRect(32, 0, 32, 32));
			if (buffer_map[i][j] == '0')
				temp.setTextureRect(IntRect(64, 0, 32, 32));
			if (buffer_map[i][j] == 'T')
			{
				tressure.setPosition(j * 32, i * 32);
				window.draw(tressure);
				continue;
			}
			temp.setPosition(j * 32, i * 32);
			window.draw(temp);
		}
}
void menu(RenderWindow & window, string filename)
{
	Texture texture;
	Font font;
	font.loadFromFile("Montblanc Regular.ttf");
	Text reference1("Задача игрока собрать максимальное количество призов за один проход", font, 130);
	reference1.setPosition(60, 300);
	Text quitfromside("Выход", font, 130);
	quitfromside.setFillColor(Color::Red);
	quitfromside.setStyle(Text::Bold);
	quitfromside.setPosition(850, 650);
	Text reference2("Мышонок Брейн следует за курсором мыши - так им можно управлять", font, 130);
	reference2.setPosition(60, 500);
	Text text3("Справка по управлению", font, 180);
	text3.setPosition(540, 300);
	Text text2("Начать игру", font, 180);
	text2.setFillColor(Color::Red);
	text2.setPosition(750, 850);
	Text text("Студент Михайловский Иван, группа О737Б", font, 180);
	text.setPosition(250, -30);
	text.setFillColor(Color::Green);
	text.setStyle(Text::Bold);
	texture.loadFromFile(filename);
	Sprite background(texture);
	background.setScale(1.7, 1.2);
	int main_menu = 1, side_menu = 1;
	while (main_menu)
	{
		side_menu = 1;
		text.setFillColor(Color::Green);
		text2.setFillColor(Color::Red);
		text3.setFillColor(Color::White);
		if (Mouse::getPosition().x > 760 && Mouse::getPosition().x < 1150 && Mouse::getPosition().y > 920 && Mouse::getPosition().y < 1075)
			text2.setFillColor(Color::Blue);
		if (Mouse::getPosition().x > 550 && Mouse::getPosition().x < 1350 && Mouse::getPosition().y > 385 && Mouse::getPosition().y < 535)
			text3.setFillColor(Color::Blue);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (Mouse::getPosition().x > 760 && Mouse::getPosition().x < 1150 && Mouse::getPosition().y > 920 && Mouse::getPosition().y < 1075)
				main_menu = 0;
			if (Mouse::getPosition().x > 550 && Mouse::getPosition().x < 1350 && Mouse::getPosition().y > 385 && Mouse::getPosition().y < 535)
			{
				while (side_menu)
				{
					quitfromside.setFillColor(Color::Red);
					if (Mouse::getPosition().x > 850 && Mouse::getPosition().x < 1010 && Mouse::getPosition().y > 720 && Mouse::getPosition().y < 815)
						quitfromside.setFillColor(Color::Blue);
					if (Mouse::isButtonPressed(Mouse::Left))
						if (Mouse::getPosition().x > 850 && Mouse::getPosition().x < 1010 && Mouse::getPosition().y > 720 && Mouse::getPosition().y < 815)
							side_menu = 0;
					window.clear();
					window.draw(background);
					window.draw(text);
					window.draw(reference1);
					window.draw(reference2);
					window.draw(quitfromside);
					window.display();
				}
			}
		}
		window.clear();
		window.draw(background);
		window.draw(text);
		window.draw(text2);
		window.draw(text3);
		window.display();
	}
}