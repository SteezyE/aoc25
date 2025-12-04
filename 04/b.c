#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int dx[8] = {1,  1,  0, -1, -1, -1, 0, 1};
int dy[8] = {0, -1, -1, -1,  0,  1, 1, 1};

char grid[255][255];

void print_grid(int n)
{
  int i;
  for(i=0; i<n; ++i)
    printf("%s\n", grid[i]);
}

int inside(int i, int j, int n, int m)
{
  return 0 <= i && i < n && 0 <= j && j < m;
}

void read_grid(int *n, int *m)
{
  *n = *m = 0;
  while(scanf(" %s", grid[*n]) == 1)
    *m = strlen(grid[(*n)++]);
}

uint8_t count_neighbors(int i, int j, int n, int m)
{
  uint8_t ncnt = 0;
  int k, x, y;
  for(k=0; k<8; ++k)
  {
    x = i + dx[k]; y = j + dy[k];
    if(inside(x, y, n, m) && grid[x][y] != '.')
      ncnt++;
  }
  return ncnt;
}

uint64_t iteration(int n, int m)
{
  uint64_t res = 0;
  int i, j;
  for(i=0; i<n; ++i)
    for(j=0; j<m; ++j)
      if(grid[i][j] != '.' && count_neighbors(i, j, n, m) < 4)
      {
        res++;
        grid[i][j] = 'x';
      }
  for(i=0; i<n; ++i)
    for(j=0; j<m; ++j)
      if(grid[i][j]=='x')
        grid[i][j]='.';
  return res;
}

uint64_t gold(int n, int m)
{
  uint64_t cur, res = 0;
  while(cur = iteration(n, m))
    res += cur;
  return res;
}

int main()
{
  int n, m;
  read_grid(&n, &m);
  printf("%ld cells can be removed in total\n", gold(n, m));
  return EXIT_SUCCESS;
}
