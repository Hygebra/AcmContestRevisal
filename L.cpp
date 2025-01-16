//
// Created by Layn on 24-12-15.
//
#include <iostream>
#include <cstdio>
#include <cstring>
    using namespace std;
    const int N = 1005;
    char s[N];
    int lenA = 0, lenB = 0, ans = 0;
    int A[N], B[N], tmp[N];
    pair<int, int> res[N];
void calc(int l, int r) {
    //cout << l << " " << r << endl;
    //cout << "-----------\n";
    res[++ans] = make_pair(l, r);
    long long w = 0;
    for (int i = l; i <= r; i++)
        w = w * 3 + A[i];
    int k = 0;
    for (int i = lenA; i >= r + 1; i--)
        tmp[++k] = A[i];
    //cout << "$$$$$$$$$\n" << k << " " << w << endl;
    if (w == 0) tmp[++k] = 0;
    else {
        while (w) {
            tmp[++k] = w & 1;
            w >>= 1;
        }
    }
    //cout << l << " " << r << " " << "k: " << k << "-----\n";
    lenA = l + k - 1;
    for (int i = l; i <= lenA; i++)
        A[i] = tmp[k--];
}
int main() {
    int T = 0;
    scanf("%d", &T);
    for (int G = 1; G <= T; G++) {
        lenA = 0, lenB = 0, ans = 0;
        scanf("%s", s + 1);
        lenA = strlen(s + 1);
        for (int i = 1; i <= lenA; i++)
            A[i] = s[i] - '0';
        scanf("%s", s + 1);
        lenB = strlen(s + 1);
        for (int i = 1; i <= lenB; i++)
            B[i] = s[i] - '0';

        if (lenA == 1 || lenB == 1) {
            if (lenA == 1 && lenB == 1)
                printf("0\n");
            else printf("-1\n");
            continue;
        }

        //cout << "---\n";
        int cntA = 0;
        for (int i = 1; i <= lenA; i++)
            if (A[i] == 1) cntA++;
        int cntB = 0;
        for (int i = 1; i <= lenB; i++)
            if (B[i] == 1) cntB++;

        if (cntA == 1)
            calc(1, 2);
        //printf("sdfjakl\n");
        int lst = 1;
        for (int i = 2; i <= lenA; i++) {
            //printf("lenA: %d ", lenA);
            //for (int i = 1; i <= lenA; i++)
            //     printf("%d", A[i]);
            //printf("\n");
            if (A[i] == 1) {
                if (lst + 1 < i)
                    calc(lst + 1, i);
                lst++; i = lst;
            }
        }


        if (A[lenA] == 0) {
            if (lst + 1 < lenA) calc(lst + 1, lenA);
            calc(lenA - 1, lenA);
        }

        //cout << lenA << "---\n";
        //for (int i = 1; i <= lenA; i++)
        //            printf("%d", A[i]);
        //        printf("\n");

        if (lenA == 2 && lenB == 1) {
            printf("-1\n");
            continue;
        }

        while (lenA < cntB) {
            calc(lenA - 1, lenA);
            calc(lenA - 2, lenA - 1);
            calc(lenA - 1, lenA);
        }

        if (B[2] == 0 && lenA <= cntB) {
            calc(lenA - 1, lenA);
            calc(lenA - 2, lenA - 1);
            calc(lenA - 1, lenA);
        }

        while (lenA > cntB + 1) {
            calc(lenA - 2, lenA - 1);
            calc(lenA - 2, lenA);
        }
        if (B[2] == 1 && lenA >= cntB + 1) {
            //cout << lenA << " jntm \n";
            calc(lenA - 2, lenA - 1);
            //cout << "##############################\n";
            //for (int i = 1; i <= lenA; i++)
            //    printf("%d", A[i]);
            //printf("\n");
            //printf("%d %d\n", lenA - 2, lenA);
            calc(lenA - 2, lenA);
        }


        //for (int i = 1; i <= lenA; i++)
        //    printf("%d", A[i]);
        //printf("\n");

        int pA = lenA;
        for (int i = lenB; i >= 1; i--) {
            if (B[i] == 0) {
                if (i == 2) {
                    calc(pA - 1, pA);
                    calc(pA, pA + 1);
                    pA--;
                } else {
                    calc(pA - 1, pA);
                    calc(pA - 1, pA);
                }
            } else pA--;
        }

        //for (int i = 1; i <= lenA; i++) printf("%d", A[i]); printf("\n");

        printf("%d\n", ans);
        for (int i = 1; i <= ans; i++)
            printf("%d %d\n", res[i].first, res[i].second);
    }
    return 0;
}