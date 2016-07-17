typedef struct ELE {
    long val;
    struct ELE *next;
} *list_ptr;

/* max_list - Find the maximum element in a linked list */
long max_list(list_ptr ls)
{
    long max_element = 0;
    while (ls) {
        if(ls->val > max_element) {
            max_element = ls->val;
        }
        ls = ls->next;
    }
    return max_element;
}

/* matrix_and_xor - Bitwise AND corresponding elements of two matrices and take XOR*/
long matrix_and_xor(long size, long A[size][size], long B[size][size], 
                    long C[size][size])
{
    long i,j, result=0;
    for(i=0; i<size; i++) {
        for(j=0; j<size; j++) {
            C[i][j] = A[i][j] & B[i][j];
        }
    }
    for(i=0; i<size; i++) {
        for(j=0; j<size; j++) {
            result ^= C[i][j];
        }
    }
    return result;
}

 /* copy_block - Copy src to dest and return xor checksum of src */
long copy_block(long *src, long *dest, long len)
{
    long result = 0;
    while (len > 0) {
        long val = *src++;
        *dest++ = val;
        result ^= val;
        len--;
    }
    return result;
}
