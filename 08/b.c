#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

typedef struct
{
  int x, y, z;
} Point;

typedef struct
{
  int first, second;
  int64_t dist;
} Pair;

// number of points
#define M 1000 

// top closest points
#define N 1000 

int n;
Point v[M];
Pair h[M*(M-1)/2];

int parent[M];
int rank[M];
int size[M];
int vis[M] = {0};

void make_set(int m)
{
  int i;
  for(i=0; i<m; ++i)
  {
    parent[i] = i;
    rank[i] = 0;
    size[i] = 1;
  }
}

int find_set(int v)
{
  if(v == parent[v])
    return v;
  return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
  a = find_set(a);
  b = find_set(b);
  if(a != b)
  {
    if(rank[a] < rank[b])
    {
      parent[a] = b;
      size[b] += size[a];
    }
    else if (rank[a] > rank[b])
    {
      parent[b] = a;
      size[a] += size[b];
    }
    else
    {
      parent[b] = a;
      size[a] += size[b];
      rank[a]++;
    }
  }
}

int cmp(const void *a, const void *b)
{
  Pair *x = (Pair *)a;
  Pair *y = (Pair *)b;
  if(x->dist < y->dist) 
    return -1;
  else if(x->dist > y->dist)
    return 1;
  return 0;
}

int comp(const void *a, const void *b)
{
  return *(int *)b - *(int *)a;
}

int64_t distance(int i, int j)
{
  return (int64_t)(v[j].x - v[i].x) * (int64_t)(v[j].x - v[i].x) + 
         (int64_t)(v[j].y - v[i].y) * (int64_t)(v[j].y - v[i].y) +
         (int64_t)(v[j].z - v[i].z) * (int64_t)(v[j].z - v[i].z);
}

int main()
{
  int a, b, c;
  while(scanf("%d,%d,%d\n", &a, &b, &c) == 3)
    v[n++] = (Point) {.x = a, .y = b, .z = c};

  int i, j, k = 0;
  for(i=0; i<n; ++i)
    for(j=i+1; j<n; ++j)
      h[k++] = (Pair) {.first = i, .second = j, .dist = distance(i, j)}; 

  assert(k == M*(M-1)/2);
  qsort(h, M*(M-1)/2, sizeof(Pair), cmp);

  make_set(M);
  i=0;
  int x, y;
  while(size[find_set(0)] != M) 
  {
    x = h[i].first;
    y = h[i].second;
    union_sets(x, y);
    i++;
  }

  printf("gold: %d*%d = %ld\n", v[x].x, v[y].x, (int64_t)v[x].x * v[y].x);
  
  return EXIT_SUCCESS;
}
