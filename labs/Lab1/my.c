#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

void print(int n)
{
    //printf("%d\n", n);
    int i;
    for (i = sizeof(n)*8 - 1; i >= 0; i--){
        printf("%d", n & (1 << i)  ? 1 : 0);
        if (i == 31 || i == 23) printf(" ");
    }
    printf("\n");
}

unsigned float_times_four(unsigned uf) {
    int frac = uf & 0x007FFFFF;
    int exp = (uf >> 23) & 0xFF;
    int sign = uf & (1<<31);

    if (exp == 255 || (exp == 0 && frac == 0))
        return uf;
      
    if (exp != 0)
        if (exp + 2 >= 0xFF) 
            return (sign|(0xFF<<23));
        else 
            exp += 2;
    else
        if (frac >= 1<<21) {
            frac = (frac << 1) & 0x007FFFFF;
            exp += 2;
        }
        else 
            frac = (frac << 2);
    return (sign|(exp<<23)|frac);
}

int main(int argc, char const *argv[])
{
    print((1<<7) + 1);
    print(float_times_four(0x7fffff));
    return 0;
}