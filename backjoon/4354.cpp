#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    while (1)
    {
        char S[1000001];
        scanf("%s", S);
        if (S[0] == '.')
            break;
        int N = strlen(S);

        // pi 배열을 구함
        int pi[1000000] = {0}, j = 0;
        for (int i = 1; i < N; i++)
        {
            while (j > 0 && S[i] != S[j])
                j = pi[j - 1];
            if (S[i] == S[j])
                pi[i] = ++j;
        }
        int q = pi[N - 1], r = N - q;

        // 반복되는 문자열이 없는 경우
        if (q == 0 || q % r != 0)
            puts("1");
        // 반복되는 문자열이 있는 경우
        else
            printf("%d\n", q / r + 1);
    }
}
