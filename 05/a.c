#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint64_t ranges[200][2];
uint64_t ids[1000];
uint64_t n, m;

uint64_t valid_ids(void)
{
  uint32_t i, j;
  uint64_t res = 0;
  for(i=0; i<m; ++i)
    for(j=0; j<n; ++j)
      if(ranges[j][0] <= ids[i] && ids[i] <= ranges[j][1])
      {
        res++;
        break;
      }
  return res;
}


int main()
{
  uint64_t a, b; n = m = 0;
  while(scanf("%ld", &a) == 1)
  {
    if(scanf("-%ld ", &b) == 1)
    {
      ranges[n][0] = a;
      ranges[n++][1] = b;
    }
    else
      ids[m++] = a;
  }
  printf("number of IDs in atleast one valid range: %ld\n", valid_ids());
  return EXIT_SUCCESS;
}
