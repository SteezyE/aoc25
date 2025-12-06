#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#if 0
  #define N 4
  #define M 15
#else
  #define N 5
  #define M 3745
#endif

char in[N][M+2];

uint64_t gold(void)
{
  in[N-1][M+1] = '!';
  uint64_t res = 0, cur, factor, t;
  int ops_ptr = 0, prev_ptr, end_ptr, i, j;
  do 
  {
    prev_ptr = ops_ptr++;
    while(in[N-1][ops_ptr] != '*' && 
          in[N-1][ops_ptr] != '+' && 
          in[N-1][ops_ptr] != '!')
      ops_ptr++;
    end_ptr = ops_ptr - 2;
    cur = in[N-1][prev_ptr] == '*';
    for(j=end_ptr; j>=prev_ptr; --j)
    {
      t = 0;
      factor = 1;
      for(i=N-2; i>=0; --i)
      {
        if(in[i][j]!=' ')
        {
          t += (in[i][j]-'0')*factor; 
          factor *= 10;
        }
      }
      cur = in[N-1][prev_ptr] == '+' ? cur + t : cur * t;
    }
    res += cur;
  } while(in[N-1][ops_ptr] != '!');
  return res;
}

int main()
{
  int i, j;
  for(i=0; i<N; ++i)
    fgets((void *)&in[i], M+2, stdin);
  printf("gold: %ld\n", gold());
  return EXIT_SUCCESS;
}
