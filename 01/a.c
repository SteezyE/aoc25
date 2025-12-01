#include <stdio.h>
#include <stdint.h>

// assumptions: 
//              rotations in 0 to BIAS - 1
#define BIAS 1000
#define MOD   100
#define START  50

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
          position = (position + BIAS - rotations) % MOD; 
          break;
        case RIGHT:
          position = (position + rotations) % MOD;
      }
      zero_counts += !position;
  }
  printf("Position 0 was reached %hu times.\n", zero_counts);
  return 0;
}
