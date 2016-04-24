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
// struct qr d5[D5_RANGE];
unsigned d5_q[D5_RANGE];
unsigned d5_r[D5_RANGE];

#define D25_RANGE 24*10+9 +1
// struct qr d25[D25_RANGE];
unsigned d25_q[D25_RANGE];
unsigned d25_r[D25_RANGE];

#define D239_RANGE 239*10+9 +1
// struct qr d239[D239_RANGE];
unsigned d239_q[D239_RANGE];
unsigned d239_r[D239_RANGE];



#define divMemo(divMemo_i, divMemo_div, divMemo_q, divMemo_r) {\
    divMemo_q[divMemo_i] = (divMemo_i)/divMemo_div;\
    divMemo_r[divMemo_i] = ((divMemo_i)- divMemo_q[divMemo_i]*divMemo_div)*10;\
}

void pre_init()
{
	int i;
    nCalculates = 0;

	//DIV5
	for (i = 0; i < D5_RANGE-9; i+=10)
	{
		// d5[i].q = i/5;
  //       d5[i].r = (i - d5[i].q*5)*10;
  //       d5[i+1].q = (i+1)/5;
  //       d5[i+1].r = (i+1 - d5[i+1].q*5)*10;
  //       d5[i+2].q = (i+2)/5;
  //       d5[i+2].r = (i+2 - d5[i+2].q*5)*10;
  //       d5[i+3].q = (i+3)/5;
  //       d5[i+3].r = (i+3 - d5[i+3].q*5)*10;
  //       d5[i+4].q = (i+4)/5;
  //       d5[i+4].r = (i+4 - d5[i+4].q*5)*10;
  //       d5[i+5].q = (i+5)/5;
  //       d5[i+5].r = (i+5 - d5[i+5].q*5)*10;
  //       d5[i+6].q = (i+6)/5;
  //       d5[i+6].r = (i+6 - d5[i+6].q*5)*10;
  //       d5[i+7].q = (i+7)/5;
  //       d5[i+7].r = (i+7 - d5[i+7].q*5)*10;
  //       d5[i+8].q = (i+8)/5;
  //       d5[i+8].r = (i+8 - d5[i+8].q*5)*10;
  //       d5[i+9].q = (i+9)/5;
  //       d5[i+9].r = (i+9 - d5[i+9].q*5)*10;
        divMemo(i  ,5,d5_q,d5_r);
        divMemo(i+1,5,d5_q,d5_r);
        divMemo(i+2,5,d5_q,d5_r);
        divMemo(i+3,5,d5_q,d5_r);
        divMemo(i+4,5,d5_q,d5_r);
        divMemo(i+5,5,d5_q,d5_r);
        divMemo(i+6,5,d5_q,d5_r);
        divMemo(i+7,5,d5_q,d5_r);
        divMemo(i+8,5,d5_q,d5_r);
        divMemo(i+9,5,d5_q,d5_r);

	}	
	//DIV25
	for (i = 0; i < D25_RANGE-9; i+=10)
	{
		// d25[i].q = i/25;
  //       d25[i].r = (i - d25[i].q*25)*10;
  //       d25[i+1].q = (i+1)/25;
  //       d25[i+1].r = (i+1 - d25[i+1].q*25)*10;
  //       d25[i+2].q = (i+2)/25;
  //       d25[i+2].r = (i+2 - d25[i+2].q*25)*10;
  //       d25[i+3].q = (i+3)/25;
  //       d25[i+3].r = (i+3 - d25[i+3].q*25)*10;
  //       d25[i+4].q = (i+4)/25;
  //       d25[i+4].r = (i+4 - d25[i+4].q*25)*10;
  //       d25[i+5].q = (i+5)/25;
  //       d25[i+5].r = (i+5 - d25[i+5].q*25)*10;
  //       d25[i+6].q = (i+6)/25;
  //       d25[i+6].r = (i+6 - d25[i+6].q*25)*10;
  //       d25[i+7].q = (i+7)/25;
  //       d25[i+7].r = (i+7 - d25[i+7].q*25)*10;
  //       d25[i+8].q = (i+8)/25;
  //       d25[i+8].r = (i+8 - d25[i+8].q*25)*10;
  //       d25[i+9].q = (i+9)/25;
  //       d25[i+9].r = (i+9 - d25[i+9].q*25)*10;
        divMemo(i  ,25,d25_q,d25_r);
        divMemo(i+1,25,d25_q,d25_r);
        divMemo(i+2,25,d25_q,d25_r);
        divMemo(i+3,25,d25_q,d25_r);
        divMemo(i+4,25,d25_q,d25_r);
        divMemo(i+5,25,d25_q,d25_r);
        divMemo(i+6,25,d25_q,d25_r);
        divMemo(i+7,25,d25_q,d25_r);
        divMemo(i+8,25,d25_q,d25_r);
        divMemo(i+9,25,d25_q,d25_r);
	}	
	//DIV239
	for (i = 0; i < D239_RANGE-9; i+=10)
	{
		// d239[i].q = i/239;
  //       d239[i].r = (i - d239[i].q*239)*10;
  //       d239[i+1].q = (i+1)/239;
  //       d239[i+1].r = (i+1 - d239[i+1].q*239)*10;
  //       d239[i+2].q = (i+2)/239;
  //       d239[i+2].r = (i+2 - d239[i+2].q*239)*10;
  //       d239[i+3].q = (i+3)/239;
  //       d239[i+3].r = (i+3 - d239[i+3].q*239)*10;
  //       d239[i+4].q = (i+4)/239;
  //       d239[i+4].r = (i+4 - d239[i+4].q*239)*10;
  //       d239[i+5].q = (i+5)/239;
  //       d239[i+5].r = (i+5 - d239[i+5].q*239)*10;
  //       d239[i+6].q = (i+6)/239;
  //       d239[i+6].r = (i+6 - d239[i+6].q*239)*10;
  //       d239[i+7].q = (i+7)/239;
  //       d239[i+7].r = (i+7 - d239[i+7].q*239)*10;
  //       d239[i+8].q = (i+8)/239;
  //       d239[i+8].r = (i+8 - d239[i+8].q*239)*10;
  //       d239[i+9].q = (i+9)/239;
  //       d239[i+9].r = (i+9 - d239[i+9].q*239)*10;
        divMemo(i  ,239,d239_q,d239_r);
        divMemo(i+1,239,d239_q,d239_r);
        divMemo(i+2,239,d239_q,d239_r);
        divMemo(i+3,239,d239_q,d239_r);
        divMemo(i+4,239,d239_q,d239_r);
        divMemo(i+5,239,d239_q,d239_r);
        divMemo(i+6,239,d239_q,d239_r);
        divMemo(i+7,239,d239_q,d239_r);
        divMemo(i+8,239,d239_q,d239_r);
        divMemo(i+9,239,d239_q,d239_r);
	}	
}

#define DIVIDE5_INN(divide5_inn_k,divide5_x){\
    divide5_u = divide5_r + divide5_x[divide5_inn_k];\
    divide5_r = d5_r[divide5_u];\
    divide5_x[divide5_inn_k] = d5_q[divide5_u];\
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

#define DIVIDE25_INN(divide25_inn_k){\
    divide25_u = divide25_r + a[divide25_inn_k];\
    divide25_r = d25_r[divide25_u];\
    a[divide25_inn_k] = d25_q[divide25_u];\
}

#define DIVIDE25()\
{\
    int divide25_k;\
    unsigned divide25_r, divide25_u;\
    \
    divide25_r = 0;\
    for (divide25_k = 0; divide25_k <= N4-4; divide25_k += 5)\
    {\
        DIVIDE25_INN(divide25_k  );\
        DIVIDE25_INN(divide25_k+1);\
        DIVIDE25_INN(divide25_k+2);\
        DIVIDE25_INN(divide25_k+3);\
        DIVIDE25_INN(divide25_k+4);\
    }\
    for (;divide25_k <= N4; ++divide25_k) { DIVIDE25_INN(divide25_k);}\
}

#define DIVIDE239_INN(divide239_inn_k){\
    divide239_u = divide239_r  + b[divide239_inn_k];\
    divide239_r = d239_r[divide239_u];\
    b[divide239_inn_k] = d239_q[divide239_u];\
}

#define DIVIDE239()\
{\
    int divide239_k;\
    unsigned divide239_r, divide239_u;\
    \
    divide239_r = 0;\
    for (divide239_k = 0; divide239_k <= N4-4; divide239_k += 5)\
    {\
        DIVIDE239_INN(divide239_k  );\
        DIVIDE239_INN(divide239_k+1);\
        DIVIDE239_INN(divide239_k+2);\
        DIVIDE239_INN(divide239_k+3);\
        DIVIDE239_INN(divide239_k+4);\
    }\
    for (;divide239_k <= N4; ++divide239_k) { DIVIDE239_INN(divide239_k);}\
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
        DIVIDE_INN(divide_k  ,divide_x,divide_n);\
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
        MULTIPLY_INN(multiply_k  , multiply_x);\
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
        SUBTRACT_INN(sub_k  , sub_x, sub_y, sub_z);\
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

#define SUBTRACT_A_C_INN(sub_inn_k) {\
    a[sub_inn_k] = c[sub_inn_k] - a[sub_inn_k];\
    sub_mask = a[sub_inn_k] >> 31;\
    a[sub_inn_k] += 10&sub_mask;\
    a[sub_inn_k-1] -= sub_mask;\
}


#define SUBTRACT_A_C()\
{\
    int sub_k;\
    int sub_mask;\
    for( sub_k = N4; sub_k >= 7; sub_k -= 8 )\
    {\
        SUBTRACT_A_C_INN(sub_k  );\
        SUBTRACT_A_C_INN(sub_k-1);\
        SUBTRACT_A_C_INN(sub_k-2);\
        SUBTRACT_A_C_INN(sub_k-3);\
        SUBTRACT_A_C_INN(sub_k-4);\
        SUBTRACT_A_C_INN(sub_k-5);\
        SUBTRACT_A_C_INN(sub_k-6);\
        SUBTRACT_A_C_INN(sub_k-7);\
    }\
    for(; sub_k >= 0; sub_k-- ) {SUBTRACT_A_C_INN(sub_k);}\
}

#define SUBTRACT_B_C_INN(sub_inn_k) {\
    b[sub_inn_k] = c[sub_inn_k] - b[sub_inn_k];\
    sub_mask = b[sub_inn_k] >> 31;\
    b[sub_inn_k] += 10&sub_mask;\
    b[sub_inn_k-1] -= sub_mask;\
}


#define SUBTRACT_B_C()\
{\
    int sub_k;\
    int sub_mask;\
    for( sub_k = N4; sub_k >= 7; sub_k -= 8 )\
    {\
        SUBTRACT_B_C_INN(sub_k  );\
        SUBTRACT_B_C_INN(sub_k-1);\
        SUBTRACT_B_C_INN(sub_k-2);\
        SUBTRACT_B_C_INN(sub_k-3);\
        SUBTRACT_B_C_INN(sub_k-4);\
        SUBTRACT_B_C_INN(sub_k-5);\
        SUBTRACT_B_C_INN(sub_k-6);\
        SUBTRACT_B_C_INN(sub_k-7);\
    }\
    for(; sub_k >= 0; sub_k-- ) {SUBTRACT_B_C_INN(sub_k);}\
}

#define SUBTRACT_A_B_C()\
{\
    int sub_k;\
    int sub_mask;\
    for( sub_k = N4; sub_k >= 3; sub_k -= 4 )\
    {\
        SUBTRACT_A_C_INN(sub_k  );\
        SUBTRACT_B_C_INN(sub_k  );\
        SUBTRACT_A_C_INN(sub_k-1);\
        SUBTRACT_B_C_INN(sub_k-1);\
        SUBTRACT_A_C_INN(sub_k-2);\
        SUBTRACT_B_C_INN(sub_k-2);\
        SUBTRACT_A_C_INN(sub_k-3);\
        SUBTRACT_B_C_INN(sub_k-3);\
    }\
    for(; sub_k >= 0; sub_k-- ) {SUBTRACT_A_C_INN(sub_k);SUBTRACT_B_C_INN(sub_k);}\
}





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
	

        SUBTRACT_A_B_C();
        // SUBTRACT2(a,a,b,b,c);
        DIVIDE25();//DIVIDE( a, 25 );

        // SUBTRACT_B_C();
        DIVIDE239();//DIVIDE( b, 239 );
        DIVIDE239();//DIVIDE( b, 239 );

        progress();
    }

    SET( c, 1 );

    // SUBTRACT( a, c, a );
    SUBTRACT_A_C();
	DIVIDE5(a);	//DIVIDE( a, 5 );

    // SUBTRACT( b, c, b );
    SUBTRACT_B_C();
    DIVIDE239();//DIVIDE( b, 239 );

    MULTIPLY4( a);
    SUBTRACT( a, a, b );
    MULTIPLY4( a);

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

