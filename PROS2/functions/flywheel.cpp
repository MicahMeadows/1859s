#include "main.h"
#include "v5setup.h"

void fly(int voltage)
{
  flyWheel1.move(voltage);
  flyWheel2.move(voltage);
}
