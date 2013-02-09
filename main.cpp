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
#define BALL_BORDER_SIZE 10
#define START_X_VELO 5
#define START_Y_VELO 2
#define BOUNCE_OFFSET 20

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
		App.Draw(sf::Shape::Circle(ballX, ballY, BALL_SIZE, sf::Color::Yellow, BALL_BORDER_SIZE,
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
	int ball_right_edge  = ballX + BALL_SIZE/2 + BALL_BORDER_SIZE + BOUNCE_OFFSET;
	int ball_left_edge   = ballX - BALL_SIZE/2 - BALL_BORDER_SIZE - BOUNCE_OFFSET;
	int ball_bottom_edge = ballY + BALL_SIZE/2 + BALL_BORDER_SIZE + BOUNCE_OFFSET;
	int ball_top_edge    = ballY - BALL_SIZE/2 - BALL_BORDER_SIZE - BOUNCE_OFFSET;

	if ( ball_right_edge > WIDTH || ball_left_edge < 0 || (ball_left_edge <= left.x2 && 
	     ball_top_edge >= left.y1 && ball_bottom_edge <= left.y2)) 
		xVel = -xVel;
	if ( ball_bottom_edge > HEIGHT || ball_top_edge < 0 ) 
		yVel = -yVel;
}

