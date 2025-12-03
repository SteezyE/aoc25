#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX(X, Y) ( (X) > (Y) ? (X) : (Y) )
#define M 12

int main()
{
  char s[255];
  uint8_t i, j, n;
  uint64_t dp[255][M+1], factor;
  uint64_t res = 0;
  while(scanf(" %s", s) == 1)
  {
    n = strlen(s);
    memset(dp, 0x00, sizeof(dp));
    factor = 1;
    for(j=0; j<=M; ++j)
    {
      for(i=n-j-1; i<UINT8_MAX; --i)
        dp[i][j+1] = MAX(dp[i+1][j+1], (s[i]-'0') * factor + dp[i+1][j]);
      factor *= 10;
    }
    res += dp[0][M];
  }
  printf("The total joltage is %ld.\n", res);
  return EXIT_SUCCESS;
}
