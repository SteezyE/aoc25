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
uint64_t splits[N+2][M+2] = {0};

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

  for(j=0; j<M; ++j)
    splits[N][j] = 1;
  for(i=N-1; i>=0; --i)
  {
    for(j=0; j<M; ++j)
    {
      if(v[i][j] == '.')
        continue;
      else if(v[i][j] == '|')
        splits[i][j] = splits[i+1][j];
      else if(v[i][j] == '^')
        splits[i][j] = splits[i+1][j+1] + splits[i+1][j-1];
      else if(v[i][j] == 'S')
        printf("%ld\n", splits[i+1][j]);
    }
  }
    
	return EXIT_SUCCESS;
}
