#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#if 1
  #define N 4000
  #define M 1000
  #define R 4
#else
  #define N 12
  #define M 4
  #define R 3
#endif

uint64_t nums[N];
char ops[M];

uint64_t silver(void)
{
  uint64_t res = 0, cur, i, j;
  for(i=0; i<M; ++i)
  {
    switch(ops[i])
    {
      case '+':
        for(j=0, cur=0; j<R; ++j)
          cur += nums[j * M + i];
        break;
      default: // '*'
        for(j=0, cur=1; j<R; ++j)
          cur *= nums[j * M + i];
    }
    res += cur;
  }
  return res;
}

int main()
{
  uint16_t i;
  for(i=0; i<N; ++i)
    scanf("%ld", &nums[i]);
  for(i=0; i<M; ++i)
    scanf(" %c", &ops[i]);
  printf("total of computations is: %ld\n", silver());
  return EXIT_SUCCESS;
}
