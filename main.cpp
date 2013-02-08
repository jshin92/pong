/* main pseudo code
 * 
 * create main window
 * start game loop
 * process events
 * clear screen
 * draw
 * display
 *
 */
#include <SFML/Graphics.hpp>
#include <iostream>
#define WIDTH 800
#define HEIGHT 600
#define START_X_VELO 5
#define START_Y_VELO 2
int main()
{
	// create main window
	sf::RenderWindow App(sf::VideoMode(WIDTH, HEIGHT), "Pong!");	
	int xVel = START_X_VELO;
	int yVel = START_Y_VELO;
	int x = WIDTH/2;
	int y = HEIGHT/2;

	// start game loop
	while (App.IsOpened())
	{
		// process events
		sf::Event e;
		while (App.GetEvent(e))
			if (e.Type == sf::Event::Closed)
				App.Close();

		App.Clear();
		App.Draw(sf::Shape::Circle(x, y, 50, sf::Color::Yellow, 10, 
						 sf::Color::Blue));
		App.Display();
		x += xVel;
		y += yVel;
		if ( x > WIDTH || x < 0)
			xVel = -xVel;
		if ( y > HEIGHT || y < 0)
			yVel = -yVel;

	}

	return 0;
}

 /*  Draw:
  * draw ball in middle [X]
	* TODO:
	* draw left paddle    []
	* draw right paddle   []
  *
	*/

