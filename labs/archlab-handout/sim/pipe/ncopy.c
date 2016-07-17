#include <stdio.h>

typedef word_t word_t;

word_t src[8], dst[8];

/* $begin ncopy */
/*
 * ncopy - copy src to dst, and count number of positive,
 * negative and zero ints contained in src array.
 */
void ncopy(word_t *src, word_t *dst, word_t len)
{
    word_t count_pos = 0, count_neg = 0, count_zero = 0;
    word_t val;

    while (len > 0) {
	val = *src++;
	*dst++ = val;
	if (val > 0)
	    count_pos++;
	else if(val < 0)
	    count_neg++;
        else 
	    count_zero++;	
	len--;
    }
}
/* $end ncopy */

int main()
{
    word_t i, count;

    for (i=0; i<8; i++)
	src[i]= i+1;
    ncopy(src, dst, 8);
    exit(0);
}


