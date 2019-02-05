#include "main.h"
#include "v5setup.h"
#include<cmath>
#include<string>
#include<cstdlib>

void turn(int dir, int target, float factor)
{

}

void left(int target, float factor = 1)
{
  turn(LEFT, target, factor);
}

void right(int target, float factor = 1)
{
  turn(RIGHT, target, factor);
}
