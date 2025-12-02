#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

bool is_copy(uint64_t id)
{
  uint8_t len = (uint8_t)log10(id) + 1;
  if(len & 1)
    return 0;
  uint8_t i;
  uint32_t a = 0, b = 0;
  for(i=0; i<len; ++i)
  {
    if(i < len / 2)
      a = a * 10 + id % 10;
    else
      b = b * 10 + id % 10;
    id /= 10;
  }
  return a == b;
}

int main()
{
  uint64_t start, end, res = 0;
  while(scanf("%ld-%ld,", &start, &end) == 2 ||
        scanf("%ld-%ld",  &start, &end) == 2)
  {
    uint64_t id;
    for(id=start; id<=end; ++id)
    {
      res += is_copy(id) * id;
    }
  }
  printf("The sum of all invalid product IDs is %ld.", res);
  return EXIT_SUCCESS;
}
