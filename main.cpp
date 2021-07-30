// Game created by Karthik, inspired by 'NVitanovic'
#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;
// FOREVER VARIABLES DO NOT CHANGE!!
enum eDir
{
	STOP = 0,
	LEFT = 1,
	UPLEFT = 2,
	DOWNLEFT = 3,
	RIGHT = 4,
	UPRIGHT = 5,
	DOWNRIGHT = 6
};
// Class "cBall", contains core code for the ball.
class cBall
{
private:
	int x, y;
	int originalX, originalY;
	eDir direction;

public:
	cBall(int posX, int posY)
	{
		originalX = posX;
		originalY = posY;
		x = posX;
		y = posY;
		direction = STOP;
	}
	void Reset()
	{
		x = originalX;
		y = originalY;
		direction = STOP;
	}
	void changeDirection(eDir d)
	{
		direction = d;
	}
	void randomDirection()
	{
		direction = (eDir)((rand() % 6) + 1);
	}
	inline int getX() { return x; }
	inline int getY() { return y; }
	inline eDir getDirection() { return direction; }
	// Functionality
	void Move()
	{
		switch (direction)
		{
		case STOP:
			break;
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UPLEFT:
			x--;
			y--;
			break;
		case DOWNLEFT:
			x--;
			y++;
			break;
		case UPRIGHT:
			x++;
			y--;
			break;
		case DOWNRIGHT:
			x++;
			y++;
			break;
		default:
			break;
		}
	}
	friend ostream &operator<<(ostream &o, cBall c)
	{
		o << "Ball [" << c.x << "," << c.y << "][" << c.direction << "]" << endl;
		return o;
	}
};
// Class cPaddle is the core class for the paddles contains, code for paddle
class cPaddle
{
private:
	int x, y;
	int originalX, originalY;

public:
	cPaddle()
	{
		x = y = 0;
	}
	cPaddle(int posX, int posY) : cPaddle()
	{
		originalX = posX;
		originalY = posY;
		x = posX;
		y - posY;
	}
	inline void Reset()
	{
		x = originalX;
		y = originalY;
	}
	inline int getX() { return x; }
	inline int getY() { return y; }
	inline void moveUp() { y--; }
	inline void moveDown() { y++; }
	friend ostream &operator<<(ostream &o, cPaddle c)
	{
		o << "Paddle [" << c.x << "," << c.y << "]["
												"]";

		return o;
	}
};
// This is the cGameManger class, !! IMPORTANT DO NOT CHANGE, IS RESPONSIBLE FOR ALL FUNCTIONS BEING CALLED!!
class cGameManger
{
private:
	int width, height;
	int score1, score2;
	char up1, down1, up2, down2;
	bool quit;
	cBall *ball;
	cPaddle *player1;
	cPaddle *player2;

public:
	cGameManger(int w, int h)
	{
		srand(time(NULL));
		quit = false;
		up1 = 'w';
		up2 = 'i';
		down1 = 's';
		down2 = 'k';
		score1 = score2 = 0;
		width = w;
		height = h;
		ball = new cBall(w / 2, h / 2);
		player1 = new cPaddle(1, h / 2 - 3);
		player2 = new cPaddle(w - 2, h / 2 - 3);
	}
	~cGameManger()
	{
		delete ball, player1, player2;
	}
	void ScoreUp(cPaddle *player)
	{
		if (player == player1)
			score1++;
		else if (player == player2)
			score2++;

		ball->Reset();
		player1->Reset();
		player2->Reset();
	}
	// Draw function. !! IMPORTANT DO NOT CHANGE THE X AND Y CORDINATES, THESE ARE CORE FUNCTIONS !!
	void Draw()
	{
		system("cls");
		for (int i = 0; i < width + 2; i++)
			cout << "#";
		cout << endl;

		for(int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				int ballx = ball->getX();
				int bally = ball->getY();
				int player1x = player1->getX();
				int player2x = player2->getX();
				int player1y = player1->getY();
				int player2y = player2->getY(); 

				if (j == 0)
					cout << "#";
				if (ballx = j && bally == i)
					cout << "O";
				else if (player1x == j && player1y == i)
					cout << "#"; // Player 1 paddle 

				if (j == width -1)
					cout << "#";	
			}

		}

		for (int i = 0; i < width + 2; i++)
			cout << "#";
		cout << endl;

	}
};
// Main loop, !! IMPORTANT DO NOT CHANGE, IF CHANGED, THE FUNCTIONS WILL NOT BE TAKEN INTO ACCOUT BY THE SYSTEM !!
int main()
{
	cGameManger c(40, 20);
	c.Draw();
	return 0;
}
// Hope you liked the game, and again special shout out to 'NVitanovic'.