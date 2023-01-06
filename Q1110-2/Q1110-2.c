#include <stdio.h>

int main(void)
{
        int N = 0, Ncopy = 0, nCycle = 0, nSum = 0, nNew = 100;

        scanf_s("%d", &N);

        Ncopy = N;

        while (N != nNew)
 
        {
                nSum = ((Ncopy / 10) + (Ncopy % 10)) % 10;
                nNew = ((Ncopy % 10) * 10) + nSum;
                Ncopy = nNew;
                ++nCycle;
        }

        printf("%d\n", nCycle);

        return 0;
}
