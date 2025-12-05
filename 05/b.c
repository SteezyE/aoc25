#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX(X, Y) ( (X) > (Y) ? (X) : (Y) )
#define MIN(X, Y) ( (X) < (Y) ? (X) : (Y) )

typedef struct
{
  uint64_t start; 
  uint64_t end;
} range_t;

range_t ranges[200];
uint64_t ids[1000];
int n, m;

int cmp(const void *a, const void *b)
{
  range_t *ra = (range_t*)a;
  range_t *rb = (range_t*)b;
  if(ra->start < rb->start)
    return -1;
  else if(ra->start == rb->start)
    return 0;
  return 1;
}

uint64_t valid_ids(void)
{
  uint64_t res = 0, i;
  qsort(ranges, n, sizeof(ranges[0]), cmp);
  for(i=0; i<n-1; ++i)
  {
    if(ranges[i].end + 1 < ranges[i+1].start)
      res += ranges[i].end - ranges[i].start + 1;
    else
    {
      ranges[i+1].start = MIN(ranges[i].start, ranges[i+1].start);
      ranges[i+1].end = MAX(ranges[i].end, ranges[i+1].end);
    }
  }
  res += ranges[n-1].end - ranges[n-1].start + 1;
  return res;
}

int main()
{
  uint64_t a, b; n = m = 0;
  while(scanf("%ld", &a) == 1)
  {
    if(scanf("-%ld ", &b) == 1)
      ranges[n++] = (range_t){MIN(a, b), MAX(a, b)};
    else
      ids[m++] = a;
  }
  printf("total number of valid IDs: %ld\n", valid_ids());
  return EXIT_SUCCESS;
}
