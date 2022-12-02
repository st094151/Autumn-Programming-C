#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow win(VideoMode(900, 900), "SFML Window");

	CircleShape circ1;
	circ1.setRadius(50);
	circ1.setPosition(300, 300);
	circ1.setFillColor(Color(25, 100, 90));

	CircleShape circ2;
	circ2.setRadius(50);
	circ2.setPosition(600, 600);
	circ2.setFillColor(Color(0, 0, 255));

	Vertex line[] =
	{
		Vertex(Vector2f(300, 300)),
		Vertex(Vector2f(600, 600))
	};


	while (win.isOpen())
	{
		Event ev;

		while (win.pollEvent(ev))
		{
			if (ev.type == Event::Closed)
			{
				win.close();
			}
		}

		win.clear();

		win.draw(circ1);

		win.draw(line, 2, Lines);
		
		win.draw(circ2);

		win.display();
	}

	return EXIT_SUCCESS;
}