/* mountain.c - Generate the memory mountain. */
/* $begin mountainmain */
#include <stdlib.h>
#include <stdio.h>
#include "fcyc2.h" /* K-best measurement timing routines */
#include "clock.h" /* routines to access the cycle counter */

#define MINBYTES (1 << 10)  /* Working set size ranges from 1 KB */
#define MAXBYTES (1<< 25)  /* ... up to 16 MB */

#define MAXSTRIDE 64        /* Strides range from 1 to 32 */
#define MAXELEMS MAXBYTES/sizeof(int) 

int data[MAXELEMS];         /* The array we'll be traversing */

/* $end mountainmain */
void init_data(int *data, int n);
void test(int elems, int stride);
double run(int size, int stride, double Mhz);

/* $begin mountainmain */
int main()
{
    int size;        /* Working set size (in bytes) */
    int stride;      /* Stride (in array elements) */
    double Mhz;      /* Clock frequency */
    int i;

    init_data(data, MAXELEMS); /* Initialize each element in data to 1 */
    Mhz = mhz(0);  /*             Estimate the clock frequency */
/* $end mountainmain */
    /* Not shown in the text */
    printf("Clock frequency is approx. %.1f MHz\n", Mhz);
    printf("Memory mountain (MB/sec)\n");

    printf("\t");
    for (stride = 1; stride <= MAXSTRIDE; stride++)
	printf("%d\t", stride);
    printf("\n");


    unsigned int sizes[24] = {32*1024*1024, 24*1024*1024, 16*1024*1024, 12*1024*1024, 8*1024*1024, 6*1024*1024, 1024*512+5*1024*1024, 1024*256+5*1024*1024, 5*1024*1024, 4*1024*1024, 2*1024*1024, 1024*1024, 512*1024, 256*1024, (128+64)*1024, 128*1024, 64*1024, 32*1024, 16*1024};

 /* $begin mountainmain */
    for (i=0; i<19; i++){
       size = sizes[i];
	/* Not shown in the text */
	if (size >= (1 << 20))
	    printf("%.1fM  ", (float)size / (float)(1 << 20));
	else
	    printf("%.1fK   ", (float)size / (float)1024);

/* $begin mountainmain */
	for (stride = 1; stride <= MAXSTRIDE; stride++) {
	    printf("%.1f    ", run(size, stride, Mhz));
	}
	printf("\n");
    }
    exit(0);
}
/* $end mountainmain */

/* init_data - initializes the array */
void init_data(int *data, int n)
{
    int i;

    for (i = 0; i < n; i++)
	data[i] = 1;
}

/* $begin mountainfuns */
void test(int elems, int stride) /* The test function */
{
    int i, result = 0; 
    volatile int sink; 

    for (i = 0; i < elems; i += stride)
	result += data[i];
    sink = result; /* So compiler doesn't optimize away the loop */
}

/* Run test(elems, stride) and return read throughput (MB/s) */
double run(int size, int stride, double Mhz)
{
    double cycles;
    int elems = size / sizeof(int); 

    test(elems, stride);                     /* warm up the cache */
    cycles = fcyc2(test, elems, stride, 0);  /* call test(elems,stride) */
    return (size / stride) / (cycles / Mhz); /* convert cycles to MB/s */
}
/* $end mountainfuns */


