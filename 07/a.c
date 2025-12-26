#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define REAL 1

#if REAL
#define N 141
#define M 141
#else
#define N 15
#define M 15
#endif

char v[N+2][M+2];
int splits[N+2][M+2] = {0};

void descend(int i, int j)
{
  if(splits[i][j] == 1)
    return;
  if(i==N+1 || j<0 || j>=M)
    return;
  if(v[i][j] == '^')
  {
    splits[i][j] = 1;
    descend(i, j-1);
    descend(i, j+1);
  }
  else
    descend(i+1, j);
  if(v[i][j] == '.')
    v[i][j] = '|';
}

int main()
{
  int i=0, j;
  while(scanf("%s", (char*) v[i++]) == 1); 

  for(j=0; j<M; ++j)
  {
    if(v[0][j] == 'S')
      descend(0, j);
  }
  for(i=0; i<N+1; ++i)
    printf("%s\n", v[i]);

  int res = 0;
  for(int i=0; i<N+1; ++i)
    for(int j=0; j<M+1; ++j)
      res += (splits[i][j] == 1);
  printf("res: %d\n", res); 
    
	return EXIT_SUCCESS;
}
