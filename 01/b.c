#include <stdio.h>
#include <stdint.h>

// assumption: rotations in 0 to BIAS - 1
#define MOD         100
#define BIAS   (10*MOD)
#define START        50

#define MAX(X, Y) ( (X) > (Y) ? (X) : (Y) )

enum 
{
  LEFT = 'L',
  RIGHT = 'R'
};


int main()
{
  uint16_t rotations, position = START;
  char direction;
  uint16_t zero_counts = 0; 
  while(scanf(" %c%hu", &direction, &rotations) == 2)
  {
      switch(direction)
      {
        case LEFT:
          zero_counts += MAX(0, (rotations - position) / MOD + (rotations >= position && position));
          position = (position + BIAS - rotations) % MOD; 
          break;
        case RIGHT:
          zero_counts += rotations / MOD + (rotations % MOD + position >= MOD);
          position = (position + rotations) % MOD;
      }
  }
  printf("Position 0 was reached %hu times.\n", zero_counts);
  return 0;
}
