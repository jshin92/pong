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
int main()
{
	// create main window
	sf::RenderWindow App(sf::VideoMode(WIDTH, HEIGHT), "Pong!");	

	// start game loop
	while (App.IsOpened())
	{
		// process events
		sf::Event e;
		while (App.GetEvent(e))
			if (e.Type == sf::Event::Closed)
				App.Close();

		App.Clear();
		App.Draw(sf::Shape::Circle(WIDTH/2, HEIGHT/2, 100, sf::Color::Yellow, 10, 
						 sf::Color::Blue));
		App.Display();

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

