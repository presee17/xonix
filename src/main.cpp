#include <SFML/Graphics.hpp>
#include <time.h>

#include "config.h"
#include "InputHandler.h"

using namespace sf;

const int M = 80;
const int N = 160;

int grid[M][N] = {0};
int ts = 5; //tile size

struct Enemy
{int x,y,dx,dy;

  Enemy()
   {
	x=y=300;
    dx=4-rand()%8;
    dy=4-rand()%8;
   }

  void move()
   { 
    x+=dx; if (grid[y/ts][x/ts]==1) {dx=-dx; x+=dx;}
    y+=dy; if (grid[y/ts][x/ts]==1) {dy=-dy; y+=dy;}
   }
};

void drop(int y,int x)
{
  if (grid[y][x]==0) grid[y][x]=-1;
  if (grid[y-1][x]==0) drop(y-1,x);
  if (grid[y+1][x]==0) drop(y+1,x);
  if (grid[y][x-1]==0) drop(y,x-1);
  if (grid[y][x+1]==0) drop(y,x+1);
}

int main()
{
    InputHandler handler;
    Ship2* ship = new Ship2();
    srand(time(0));

	RenderWindow window(VideoMode(N*ts, M*ts), "Xonix Game!");
	window.setFramerateLimit(60);

	Texture t1,t2,t3;
	t1.loadFromFile(RESOURCE_PATH + "images/tiles.png");
    t2.loadFromFile(RESOURCE_PATH + "images/gameover.png");
    t3.loadFromFile(RESOURCE_PATH + "images/enemy.png");

	Sprite sTile(t1), sGameover(t2), sEnemy(t3);
	sGameover.setPosition(100,100);
	sEnemy.setOrigin(20,20);

	int enemyCount = 4;
    Enemy a[10];

	bool Game=true;
	int x=0, y=0, dx=0, dy=0;
    float timer=0, delay=0.07; 
    Clock clock;

	for (int i=0;i<M;i++)
	 for (int j=0;j<N;j++)
      if (i==0 || j==0 || i==M-1 || j==N-1)  grid[i][j]=1;


    while (window.isOpen())
    {
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer+=time;

        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
			   
			if (e.type == Event::KeyPressed)
             if (e.key.code==Keyboard::Escape)
               {
                for (int i=1;i<M-1;i++)
	             for (int j=1;j<N-1;j++)
                   grid[i][j]=0;

                x=10;y=0;
                Game=true;
               }
		}
        handler.handleInput(ship);
        dx = ship->getx();
        dy = ship->gety();
        ship->refresh();
		if (!Game) continue;

		if (timer>delay)
		{
            int x_flag = 1;
            if (dx < 0) x_flag = -1;
            for (; dx != 0; x += x_flag, dx -= x_flag) {
                if (x < 0) {
                    x = 0;
                    dx += x_flag;
                    break;
                }
                if (x > N - 1) {
                    x = N - 1;
                    dx += x_flag;
                    break;
                }
                if (grid[y][x] == 2) Game = false;
                if (grid[y][x] == 0) grid[y][x] = 2;
                timer = 0;
            }

            int y_flag = 1;
            if (dy < 0) y_flag = -1;
            for (; dy != 0; y += y_flag, dy -= y_flag) {
                if (y < 0) {
                    y = 0;
                    dy += y_flag;
                    break;
                }
                if (y > M - 1) {
                    y = M - 1;
                    dy += y_flag;
                    break;
                }
                if (grid[y][x] == 2) Game = false;
                if (grid[y][x] == 0) grid[y][x] = 2;
                timer = 0;
            }

		}

		for (int i=0;i<enemyCount;i++) a[i].move();

		if (grid[y][x]==1)
          {
           dx=dy=0;

           for (int i=0;i<enemyCount;i++)
                drop(a[i].y/ts, a[i].x/ts);

           for (int i=0;i<M;i++)
	 	    for (int j=0;j<N;j++)
              if (grid[i][j]==-1) grid[i][j]=0;
              else grid[i][j]=1;
          }

        for (int i=0;i<enemyCount;i++)
           if  (grid[a[i].y/ts][a[i].x/ts]==2) Game=false;

      /////////draw//////////
      window.clear();

	  for (int i=0;i<M;i++)
		for (int j=0;j<N;j++)
		 {
            if (grid[i][j]==0) continue;
            if (grid[i][j]==1) sTile.setTextureRect(IntRect( 0,0,ts,ts));
            if (grid[i][j]==2) sTile.setTextureRect(IntRect(54,0,ts,ts));
			sTile.setPosition(j*ts,i*ts);
			window.draw(sTile);
		 }

      sTile.setTextureRect(IntRect(36,0,ts,ts));
	  sTile.setPosition(x*ts,y*ts);
	  window.draw(sTile);

	  sEnemy.rotate(10);
      for (int i=0;i<enemyCount;i++)
       {
	    sEnemy.setPosition(a[i].x,a[i].y);
	    window.draw(sEnemy);
       }

      if (!Game) window.draw(sGameover);

 	  window.display();
	}

    return 0;
}
