#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

bool is_copy(uint64_t id)
{
  uint64_t old_id = id;
  uint8_t len = (uint8_t)log10(id) + 1;
  uint8_t i, j, splits;
  uint32_t a[64];
  for(splits=2; splits<=len; ++splits)
  {
    if(len % splits)
      continue;
    id = old_id;
    memset(a, 0, sizeof(a));
    for(j=0; j<splits; ++j)
    {
      for(i=0; i<len/splits; ++i)
      {
        a[j] = a[j] * 10 + id % 10;
        id /= 10;
      }
    }
    bool flag = 1;
    for(j=0; j<splits-1; ++j)
    {
      if(a[j] != a[j+1])
      {
        flag = 0;
        break;
      }
    }
    if(flag)
      return 1;
  }
  return 0;
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
