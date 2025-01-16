//
// Created by Layn on 24-10-16.
//
#include <iostream>
#include <cstring>
#include <cstdio>
    using namespace std;
int main() {
    int T = 0;
    scanf("%d", &T);
    for (int G = 1; G <= T; G++) {
        unsigned long long P = 0, m = 0;
        scanf("%llu%llu", &P, &m);
        /*int res1 = 0;
        for (int j = 0; j <= m; j++)
            if ((j ^ (P - 1)) % P == 1)
                res1++;
        printf("%d ", res1);*/


        unsigned long long d = 0;
        while ((1llu << d) <= P - 1) d++;
        unsigned long long A = ((m >> d) << d);
        unsigned long long res = 0;
        if (A >= 1) res = (A - 1) / P + ((A - 1) % P != 0);
        m &= ((1llu << d) - 1);
        A %= P;
        if (1 - A >= 0 && ((1 - A) ^ (P - 1)) <= m) res++;
        if (((P + 1 - A) ^ (P - 1)) <= m) res++;
        if (((P + P + 1 - A) ^ (P - 1)) <= m) res++;
        printf("%llu\n", res);
    }
    return 0;
}