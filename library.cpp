#include "library.h"
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;
const int MAX_N = 50;
char s[51];
int dp[MAX_N][MAX_N];
int rec(int l, int r)
{
  if (l >= r) return 0;
  int& ret = dp[l][r];
  if(ret != -1) return ret;
  ret = 1e9;
  if(s[l] == s[r])
      ret = rec(l+1, r-1);
  ret = min({ ret, rec(l+t, r)+1, rec(l,r-1)+1});
  return ret;


}

int main()
{
    scanf("%s", s);
    int L = strlen(s), i, j, answer;

    memset(dp,-1, sizeof dp);
    answer = rec(0,L - 1);

    for (i = 0; i < L; i++) for (j = i + 1; j < L; j++){

        swap(s[i], s[j]);
        memset(dp, -1, sizeof dp);
        answer = min(answer. rec(0,L -1) + 1);
        swap(s[i], s[j]);

    }
    printf("%d", answer);
    return 0;

}
