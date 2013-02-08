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
#define BALL_SIZE 50
#define START_X_VELO 5
#define START_Y_VELO 2

typedef struct {
	float x1, y1, x2, y2;
} Paddle;

void handle_collisions(int, int, int&, int&, Paddle);

int main()
{
	// create main window
	sf::RenderWindow App(sf::VideoMode(WIDTH, HEIGHT), "Pong!");	
	int xVel = START_X_VELO;
	int yVel = START_Y_VELO;
	int ballX = WIDTH/2;
	int ballY = HEIGHT/2;

	float leftPaddle_x1 = 20;
	float leftPaddle_y1 = 50;
	float leftPaddle_x2 = 50;
	float leftPaddle_y2 = 250;

	Paddle leftP;
	leftP.x1 = leftPaddle_x1;
	leftP.y1 = leftPaddle_y1;
	leftP.x2 = leftPaddle_x2;
	leftP.y2 = leftPaddle_y2;

	// start game loop
	while (App.IsOpened())
	{
		// process events
		sf::Event e;
		while (App.GetEvent(e))
			if (e.Type == sf::Event::Closed)
				App.Close();

		App.Clear();
		// draw the ball
		App.Draw(sf::Shape::Circle(ballX, ballY, BALL_SIZE, sf::Color::Yellow, 10, 
						 sf::Color::Blue));
		// draw the left paddle (x1, y1, x2, y2)
		App.Draw(sf::Shape::Rectangle(leftPaddle_x1, leftPaddle_y1, leftPaddle_x2, leftPaddle_y2, sf::Color::Red));
		// draw the right paddle

		App.Display();
		ballX += xVel;
		ballY += yVel;

		handle_collisions(ballX, ballY, xVel, yVel, leftP);

	}

	return 0;
}

 /*  Draw:
  * draw ball in middle [X]
	* handle collision with walls [X]
	* TODO:
	* draw left paddle    []
	* draw right paddle   []
  *
	*/


void handle_collisions(int ballX, int ballY, int& xVel, int& yVel, Paddle left) 
{
	if ( ballX > WIDTH || ballX < 0)
		xVel = -xVel;
	if ( ballY > HEIGHT || ballY < 0)
		yVel = -yVel;
}

