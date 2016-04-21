#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

int N, N4;
char a[25480], b[25480], c[25480];
char string[100];

#define D5_RANGE 4*10+9 +1
unsigned d5_q[D5_RANGE];
unsigned d5_r[D5_RANGE];

#define D25_RANGE 24*10+9 +1
unsigned d25_q[D25_RANGE];
unsigned d25_r[D25_RANGE];

#define D239_RANGE 239*10+9 +1
unsigned d239_q[D239_RANGE];
unsigned d239_r[D239_RANGE];



void pre_init()
{
	int i;

	//DIV5
	for (i = 0; i < D5_RANGE; ++i)
	{
		d5_q[i] = i/5;
		d5_r[i] = i - d5_q[i]*5;
	}	
	//DIV25
	for (i = 0; i < D25_RANGE; ++i)
	{
		d25_q[i] = i/25;
		d25_r[i] = i - d25_q[i]*25;
	}	
	//DIV239
	for (i = 0; i < D239_RANGE; ++i)
	{
		d239_q[i] = i/239;
		d239_r[i] = i - d239_q[i]*239;
	}	
}


#define DIV5_INN(k) {\
u = r*10+x[k];\
r=d5_r[u];\
x[k]=d5_q[u];\
}
void DIVIDE5(char *x)
{
	int j, k;
	unsigned q, r, u;
	

	r = 0;
	for (k = 0; k <= (N4-7); k+=7)
	{
	DIV5_INN(k);
	DIV5_INN(k+1);
	DIV5_INN(k+2);
	DIV5_INN(k+3);
	DIV5_INN(k+4);
	DIV5_INN(k+5);
	DIV5_INN(k+6);
	}
	for (;k<=N4;++k){DIV5_INN(k)};
}

#define DIV25_INN(k) {\
u = r*10+x[k];\
r=d25_r[u];\
x[k]=d25_q[u];\
}

void DIVIDE25(char *x)
{
	int j, k;
	unsigned q, r, u;
	
	r = 0;
	for (k = 0; k <= (N4); k+=1)
	{
	DIV25_INN(k);
	}
	for (;k<=N4;++k){DIV25_INN(k)};
}
void DIVIDE239(char *x)
{
	int j, k;
	unsigned q, r, u;
	
	r = 0;
	for (k = 0; k <= N4; ++k)
	{
        u = r * 10 + x[k];                       
        r = d239_r[u];
        x[k] = d239_q[u];
	}
}

#define DIVIDE_INNER(___x, ___k, ___n) {\
	u = r * 10 + ___x[___k];\
        q = u / ___n;\
        r = u - q * ___n;\
        ___x[___k] = q;\
}

#define DIVIDE(__x, __n) ({\
int k;\
unsigned q, r, u;\
long v;\
r = 0;\
for( k = 0; k <= (N4-5); k+=5){\
DIVIDE_INNER(__x,k,__n);\
DIVIDE_INNER(__x,k+1,__n);\
DIVIDE_INNER(__x,k+2,__n);\
DIVIDE_INNER(__x,k+3,__n);\
DIVIDE_INNER(__x,k+4,__n);\
}\
for(;k <= N4;++k) {DIVIDE_INNER(__x,k,__n);}\
})


/*
#define K_UNROLL_DIVIDE 5

inline void DIVIDE( char *x, int n ) __attribute__((always_inline));
void DIVIDE( char *x, int n )                           
{                 
                               
    int j, k;
    unsigned q, r, u;
    long v;

    r = 0;                                       
    for( k = 0; k <= (N4-K_UNROLL_DIVIDE); k += K_UNROLL_DIVIDE)                  
    {                                            
	DIVIDE_INNER(k);
	DIVIDE_INNER(k+1);
	DIVIDE_INNER(k+2);
	DIVIDE_INNER(k+3);
	DIVIDE_INNER(k+4);
    }

    for(;k <= N4;++k) DIVIDE_INNER(k);
}
*/

void MULTIPLY( char *x, int n )                        
{                                            
    int j, k;
    unsigned q, r, u;
    long v;
    r = 0;                                   
    for( k = N4; k >= 0; k-- )               
    {                                        
        q = n * x[k] + r;                    
        r = q / 10;                          
        x[k] = q - r * 10;                   
    }                                        
}

void SET( char *x, int n )                              
{                                                
    memset( x, 0, N4 + 1 );                      
    x[0] = n;                                    
}


void SUBTRACT( char *x, char *y, char *z )                      
{                                                
    int j, k;
    unsigned q, r, u;
    long v;
    for( k = N4; k >= 0; k-- )                   
    {                                            
        if( (x[k] = y[k] - z[k]) < 0 )           
        {                                        
            x[k] += 10;                          
            z[k-1]++;                            
        }                                        
    }                                            
}


void calculate( void );
void progress( void );
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

    MULTIPLY( a, 4 );
    SUBTRACT( a, a, b );
    MULTIPLY( a, 4 );

    progress();
}

/*

 N = 10000                      
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
    printf(".");
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

