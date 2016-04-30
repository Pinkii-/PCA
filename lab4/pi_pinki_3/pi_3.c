#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

int N, N4;
char a[25480], b[25480], c[25480];
char string[100];
int nCalculates;

struct qr {
    unsigned q;
    unsigned r;
};

#define D5_RANGE 4*10+9 +1
struct qr d5[D5_RANGE];
// unsigned d5_q[D5_RANGE];
// unsigned d5[].r[D5_RANGE];

#define D25_RANGE 24*10+9 +1
struct qr d25[D25_RANGE];
// unsigned d25_q[D25_RANGE];
// unsigned d25_r[D25_RANGE];

#define D239_RANGE 239*10+9 +1
struct qr d239[D239_RANGE];
// unsigned d239_q[D239_RANGE];
// unsigned d239_r[D239_RANGE];



void pre_init()
{
	int i;
    nCalculates = 0;

	//DIV5
	for (i = 0; i < D5_RANGE; ++i)
	{
		d5[i].q = i/5;
		d5[i].r = (i - d5[i].q*5)*10;
	}	
	//DIV25
	for (i = 0; i < D25_RANGE; ++i)
	{
		d25[i].q = i/25;
        d25[i].r = (i - d25[i].q*25)*10;
	}	
	//DIV239
	for (i = 0; i < D239_RANGE; ++i)
	{
		d239[i].q = i/239;
        d239[i].r = (i - d239[i].q*239)*10;
	}	
}

#define DIVIDE5_INN(divide5_inn_k,divide5_x){\
    divide5_u = divide5_r + divide5_x[divide5_inn_k];\
    divide5_r = d5[divide5_u].r;\
    divide5_x[divide5_inn_k] = d5[divide5_u].q;\
}

#define DIVIDE5(divide5_x)\
{\
	int divide5_k;\
	unsigned divide5_r, divide5_u;\
	\
	divide5_r = 0;\
	for (divide5_k = 0; divide5_k <= N4-4; divide5_k += 5)\
	{\
        DIVIDE5_INN(divide5_k  ,divide5_x);\
        DIVIDE5_INN(divide5_k+1,divide5_x);\
        DIVIDE5_INN(divide5_k+2,divide5_x);\
        DIVIDE5_INN(divide5_k+3,divide5_x);\
        DIVIDE5_INN(divide5_k+4,divide5_x);\
	}\
    for (;divide5_k <= N4; ++divide5_k) { DIVIDE5_INN(divide5_k,divide5_x);}\
}

#define DIVIDE25_INN(divide25_inn_k,divide25_x){\
    divide25_u = divide25_r + divide25_x[divide25_inn_k];\
    divide25_r = d25[divide25_u].r;\
    divide25_x[divide25_inn_k] = d25[divide25_u].q;\
}

#define DIVIDE25(divide25_x)\
{\
    int divide25_k;\
    unsigned divide25_r, divide25_u;\
    \
    divide25_r = 0;\
    for (divide25_k = 0; divide25_k <= N4-4; divide25_k += 5)\
    {\
        DIVIDE25_INN(divide25_k  ,divide25_x);\
        DIVIDE25_INN(divide25_k+1,divide25_x);\
        DIVIDE25_INN(divide25_k+2,divide25_x);\
        DIVIDE25_INN(divide25_k+3,divide25_x);\
        DIVIDE25_INN(divide25_k+4,divide25_x);\
    }\
    for (;divide25_k <= N4; ++divide25_k) { DIVIDE25_INN(divide25_k,divide25_x);}\
}

#define DIVIDE239_INN(divide239_inn_k,divide239_x){\
    divide239_u = divide239_r  + divide239_x[divide239_inn_k];\
    divide239_r = d239[divide239_u].r;\
    divide239_x[divide239_inn_k] = d239[divide239_u].q;\
}

#define DIVIDE239(divide239_x)\
{\
    int divide239_k;\
    unsigned divide239_r, divide239_u;\
    \
    divide239_r = 0;\
    for (divide239_k = 0; divide239_k <= N4-4; divide239_k += 5)\
    {\
        DIVIDE239_INN(divide239_k  ,divide239_x);\
        DIVIDE239_INN(divide239_k+1,divide239_x);\
        DIVIDE239_INN(divide239_k+2,divide239_x);\
        DIVIDE239_INN(divide239_k+3,divide239_x);\
        DIVIDE239_INN(divide239_k+4,divide239_x);\
    }\
    for (;divide239_k <= N4; ++divide239_k) { DIVIDE239_INN(divide239_k,divide239_x);}\
}


#define DIVIDE_INN(divide_inn_k,divide_inn_x,divide_inn_n){\
    divide_u = divide_r * 10 + divide_inn_x[divide_inn_k];\
    divide_q = divide_u / divide_inn_n;\
    divide_r = divide_u - divide_q * divide_inn_n;\
    divide_inn_x[divide_inn_k] = divide_q;\
}

#define DIVIDE(divide_x, divide_n) {\
    int divide_k;\
    unsigned divide_q, divide_r, divide_u;\
\
    divide_r = 0;\
    for( divide_k = 0; divide_k <= N4-4; divide_k += 5 )\
    {\
        DIVIDE_INN(divide_k,divide_x,divide_n);\
        DIVIDE_INN(divide_k+1,divide_x,divide_n);\
        DIVIDE_INN(divide_k+2,divide_x,divide_n);\
        DIVIDE_INN(divide_k+3,divide_x,divide_n);\
        DIVIDE_INN(divide_k+4,divide_x,divide_n);\
    }\
    for(;divide_k <= N4; ++divide_k) {DIVIDE_INN(divide_k,divide_x,divide_n);}\
}\

#define MULTIPLY_INN(multiply_inn_k,multiply_inn_x) {\
    multiply_q = (multiply_inn_x[multiply_inn_k] << 2) + multiply_r;\
    multiply_r = multiply_q / 10;\
    multiply_inn_x[multiply_inn_k] = multiply_q - multiply_r * 10;\
}

#define MULTIPLY4(multiply_x)\
{\
    int multiply_k;\
    unsigned multiply_q, multiply_r;\
    multiply_r = 0;\
    for( multiply_k = N4; multiply_k >= 4; multiply_k -= 5 )\
    {\
        MULTIPLY_INN(multiply_k, multiply_x);\
        MULTIPLY_INN(multiply_k-1, multiply_x);\
        MULTIPLY_INN(multiply_k-2, multiply_x);\
        MULTIPLY_INN(multiply_k-3, multiply_x);\
        MULTIPLY_INN(multiply_k-4, multiply_x);\
    }\
    for(; multiply_k >= 0; multiply_k-- ) {MULTIPLY_INN(multiply_k, multiply_x);}\
}

void SET( char *x, int n )                              
{                                                
    memset( x, 0, N4 + 1 );                      
    x[0] = n;                                    
}


#define SUBTRACT_INN(sub_inn_k,sub_inn_x, sub_inn_y, sub_inn_z) {\
    sub_inn_x[sub_inn_k] = sub_inn_y[sub_inn_k] - sub_inn_z[sub_inn_k];\
    sub_mask = sub_inn_x[sub_inn_k] >> 31;\
    sub_inn_x[sub_inn_k] += 10&sub_mask;\
    sub_inn_z[sub_inn_k-1] -= sub_mask;\
}


#define SUBTRACT(sub_x, sub_y, sub_z )\
{\
    int sub_k;\
    int sub_mask;\
    for( sub_k = N4; sub_k >= 7; sub_k -= 8 )\
    {\
        SUBTRACT_INN(sub_k, sub_x, sub_y, sub_z);\
        SUBTRACT_INN(sub_k-1, sub_x, sub_y, sub_z);\
        SUBTRACT_INN(sub_k-2, sub_x, sub_y, sub_z);\
        SUBTRACT_INN(sub_k-3, sub_x, sub_y, sub_z);\
        SUBTRACT_INN(sub_k-4, sub_x, sub_y, sub_z);\
        SUBTRACT_INN(sub_k-5, sub_x, sub_y, sub_z);\
        SUBTRACT_INN(sub_k-6, sub_x, sub_y, sub_z);\
        SUBTRACT_INN(sub_k-7, sub_x, sub_y, sub_z);\
    }\
    for(; sub_k >= 0; sub_k-- ) {SUBTRACT_INN(sub_k, sub_x, sub_y, sub_z);}\
}


//Mul4(a);
//sub(a,a,b);
//mul4(a);

#define MUL4_SUB_MUL4(msm_x, msm_y, msm_z) {\
	int msm_k;\
	unsigned msm_q,msm_r;\
	msm_r=0;\
	int sub_mask;\
	unsigned multiply_q,multiply_r;\
	for(msm_k=N4;msm_k>=4;msm_k-=5){\
	MULTIPLY_INN(msm_k,msm_x);\
	SUBTRACT_INN(msm_k,msm_x,msm_y,msm_z);\
	MULTIPLY_INN(msm_k,msm_x);\
	MULTIPLY_INN(msm_k-1,msm_x);\
	SUBTRACT_INN(msm_k-1,msm_x,msm_y,msm_z);\
	MULTIPLY_INN(msm_k-1,msm_x);\
	MULTIPLY_INN(msm_k-2,msm_x);\
	SUBTRACT_INN(msm_k-2,msm_x,msm_y,msm_z);\
	MULTIPLY_INN(msm_k-2,msm_x);\
	MULTIPLY_INN(msm_k-3,msm_x);\
	SUBTRACT_INN(msm_k-3,msm_x,msm_y,msm_z);\
	MULTIPLY_INN(msm_k-3,msm_x);\
	MULTIPLY_INN(msm_k-4,msm_x);\
	SUBTRACT_INN(msm_k-4,msm_x,msm_y,msm_z);\
	MULTIPLY_INN(msm_k-4,msm_x);\
	}\
	for(msm_k=N4;msm_k>=0;msm_k--){\
	MULTIPLY_INN(msm_k,msm_x);\
	SUBTRACT_INN(msm_k,msm_x,msm_y,msm_z);\
	MULTIPLY_INN(msm_k,msm_x);\
	}\
}

/*
	for (k=N4;k>=0;k--)
	{
		q=n*x[k]+r;
		r=q/10;
		x[k]=q-r*10;
		if ((x[k]=y[k]-z[k])<0)
		{
			x[k]+=10;
			z[k-1]++;
		}
		q=n*x[k]+r;
		r=q/10;
		x[k]=q-r*10;
	}*/
//}

void calculate( void );
void progress( void );
void printProgress( void );
void epilog( void );


int main( int argc, char *argv[] )
{
    N = 10000;

    if( argc > 1 )
        N = atoi(argv[1]);

    setbuf(stdout, NULL);


	//Memoization 
	pre_init();

    calculate();

    epilog();

    return 0;
}

void calculate( void )
{
    int j;

    N4 = N + 4;

    SET( a, 0 );
    SET( b, 0 );

    for( j = 2 * N4 + 1; j >= 3; j -= 2 )
    {
        SET( c, 1 );
        DIVIDE( c, j );
	

        SUBTRACT( a, c, a );
        DIVIDE25(a);//DIVIDE( a, 25 );

        SUBTRACT( b, c, b );
        DIVIDE239(b);//DIVIDE( b, 239 );
        DIVIDE239(b);//DIVIDE( b, 239 );

        progress();
    }

    SET( c, 1 );

    SUBTRACT( a, c, a );
	DIVIDE5(a);	//DIVIDE( a, 5 );

    SUBTRACT( b, c, b );
    DIVIDE239(b);//DIVIDE( b, 239 );

//    MULTIPLY4( a);
//    SUBTRACT( a, a, b );
//    MULTIPLY4( a);

	// MUL4_SUB_MUL4(a,a,b);

    progress();
    printProgress();
}

/*

 N = 10000                      printf
 A = 0                          
 B = 0                          
 J = 2 * (N + 4) + 1            
 FOR J = J TO 3 STEP -2         
     A = (1 / J - A) / 5 ^ 2    
     B = (1 / J - B) / 239 ^ 2  
 NEXT J                         
 A = (1 - A) / 5                
 B = (1 - B) / 239              
 PI = (A * 4 - B) * 4           

*/

void progress( void )
{
    ++nCalculates;
}

void printProgress( void ) {
    char progresBuffer[nCalculates];
    memset(progresBuffer,'.',nCalculates);
    printf(progresBuffer);
}

void epilog( void )
{
    int j;
    {
        fprintf( stdout, " \n3.");
        for( j = 1; j <= N; j++ )
        {
            fprintf( stdout, "%d", a[j]);
            if( j % 5  == 0 )
                if( j % 50 == 0 )
                    if( j % 250  == 0 )
                        fprintf( stdout, "    <%d>\n\n   ", j );
                    else
                        fprintf( stdout, "\n   " );
                else
                    fprintf( stdout, " " );
        }
    }
}

