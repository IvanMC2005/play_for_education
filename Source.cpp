#include "Header.h"

Player::Player(string namefile, double x, double y, double sped, int wid, int ht, string namefile2)
{
	char c;
	dx = dy = 0;
	switch_animation = 0;
	certain_count = 0;
	record_count = 0;
	/*ifstream recording_Count(namefile2);
	if (!recording_Count.is_open())
	{
		cout << "Ошибка открытия файла\n" << endl;
	}
	record_count = 0;
	while ((c = recording_Count.get()))
	{
		record_count *= 10;
		record_count += c;
	}
	recording_Count.close();*/
	//cout << "Проверка работы функции считывания\n";
	//cout << " " << record_count << endl;
	Health = 200;
	speed = sped;
	line_of_health.setSize(Vector2f(100, 20));
	line_of_health.setFillColor(Color::Green);
	coordX = start_coordX = x;
	coordY = start_coordY = y;
	width = wid;
	height = ht;
	Image myimage;
	if (!myimage.loadFromFile("images/" + namefile))
	{
		cout << "Failed to setup picture" << endl;
	}
	for (auto i : { 255 })
	{
		myimage.createMaskFromColor(Color(i, i, i));
	}
	texture.loadFromImage(myimage);
	herosp.setTexture(texture);
	
	herosp.setPosition(coordX, coordY);
}

void Player::show_health(RenderWindow& window)
{
	line_of_health.setPosition(camera.getCenter() - Vector2f(315, 230));
	line_of_health.setScale(Health * 0.01, 1);
	window.draw(line_of_health);
}
void Player::show_record(RenderWindow& window, Font& font)
{
	Text record_text(to_string(record_count), font, 130);
	record_text.setPosition(camera.getCenter() + Vector2f(240, -250));
	window.draw(record_text);
}
void Player::resetView(double x, double y)
{
	camera.setCenter(x + 50, y + 40);
}
View Player::getCamera()
{
	return camera;
}
double Player::getX()
{
	return coordX;
}
double Player::getY()
{
	return coordY;
}
int Player::getHealth()
{
	return Health;
}
Player::~Player()
{
	ofstream in("certain_record.txt");
	if (!in.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
	}
	in << record_count;
	in.close();
}