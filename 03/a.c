#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX(X, Y) ( (X) > (Y) ? (X) : (Y) )

int main()
{
  char s[255];
  uint8_t suffix[255], i, n, maxi;
  uint64_t res = 0;
  while(scanf(" %s", s) == 1)
  {
    n = strlen(s);
    memset(suffix, 0x00, n);
    suffix[n-1] = s[n-1] - '0';
    for(i=n-2; i<UINT8_MAX; i--)
      suffix[i] = MAX(suffix[i+1], s[i] - '0');
    maxi = 0;
    for(i=0; i<n-1; ++i)
      maxi = MAX(maxi, (s[i]-'0') * 10 + suffix[i+1]);
    res += maxi;
  }
  printf("The total joltage is %ld.\n", res);
  return EXIT_SUCCESS;
}
