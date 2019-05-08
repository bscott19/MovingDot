#include <MeggyJrSimple.h>

int x, y, enemyX, enemyY, color;

void setup() 
{
  MeggyJrSimpleSetup();
  x = 3;
  y = 3;
  color=1;
  enemyX = random(8);
  enemyY = random(8);
}

void loop()
{
  DrawObstacles();
  DrawPx(x,y,color);
  DrawPx(enemyX,enemyY,1);
  CheckButtonsDown();
  delay(150);
  MoveEnemy();
  MovePlayer();
  check();
  changecolor();
  DisplaySlate();
  ClearSlate();
}

void MovePlayer()
{
  if(Button_Left)
  {
    x--;
  }
  if(Button_Right)
  {
    x++;
  }
  if(Button_Up)
  {
    y++;
  }
  if(Button_Down)
  {
    if(ReadPx(x,y-15)!=15)
      y--;
    else
    {
      Tone_Start(18150,150);
    }
  }
}

void MoveEnemy()
{
  if(x>enemyX)
  {
    enemyX++;
  }
  if(x<enemyX)
  {
    enemyX--;
  }
  if(y>enemyY)
  {
    enemyY++;
  }
  if(y<enemyY)
  {
    enemyY--;
  }
}

void check()
{
  if(x < 0)
  {
    x = 0;
  }
  if(x > 7)
  {
  x = 7;
  }
  if (y > 7)
  {
    y = 7;
  }
  if (y < 0)
  {
    y = 0;
  }
}

void changecolor()
{
  if (Button_A)
  {
    color--;
  }
  if (Button_B)
  {
    color++;
  }
  if (color>14)
  {
    color=3;
  }
  if (color<3)
  {
    color=14;
  }
}

void DrawObstacles()
{
  DrawPx(1,0,15);
  DrawPx(2,1,15);
}
