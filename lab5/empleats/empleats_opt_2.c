#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOM 40
#define MAX_DIAS_MES 31 
#define MAX_CATEGORIA 40 
#define MAX_ADDRESS 100

typedef struct 
{
  long long int NID;              /* Número d'identificació: clau d'ordenació */
  char Nom[MAX_NOM];  
  char Cognoms[MAX_NOM];  
  int  horesMes[MAX_DIAS_MES]; 
  char Categoria[MAX_CATEGORIA];
  unsigned int ptrClauForaneaDepartament;
  unsigned int ptrClauCategoria;
#ifdef EXTES     
  char Address[MAX_ADDRESS];
  char Nom_parella[MAX_NOM];
  char Cognoms_parella[MAX_NOM];
#endif
} Templeat;

typedef struct
{
	int NID;
	int i;
} Templeat_ID;

int compare(const void *p1, const void *p2)
{
    if (((Templeat*) p1)->NID > ((Templeat*) p2)->NID) return(1);
    else if (((Templeat*) p1)->NID < ((Templeat*) p2)->NID) return(-1);
    else return(0);
}

int compare_guays(const void *p1, const void *p2)
{
    if (((Templeat_ID*) p1)->NID > ((Templeat_ID*) p2)->NID) return(1);
    else if (((Templeat_ID*) p1)->NID < ((Templeat_ID*) p2)->NID) return(-1);
    else return(0);
}

int main(int argc, char *argv[])
{
	Templeat *empleats;
	Templeat_ID* empleats_NID;
	unsigned int N = 4000000, i;

	if (argc > 1) N = atoi(argv[1]);

	empleats = (Templeat *) malloc(N*sizeof(Templeat));
	if (empleats == NULL) { fprintf(stderr, "Out of memory\n"); exit(0); }
	memset(empleats, 0, N*sizeof(Templeat));

	empleats_NID = (Templeat_ID *) malloc(N*sizeof(Templeat_ID));
	memset(empleats_NID, 0, N*sizeof(Templeat_ID));

	/* Random generation */
	for (i = 0; i < N; i++) 
	{
		empleats[i].NID = rand();
		empleats_NID[i].NID = empleats[i].NID & 0xFFFFFFFF;
		empleats_NID[i].i = i;
		empleats[i].Nom[0] = 'A' + ((i>>3) + (i<<2)) & 0x15;
		empleats[i].Cognoms[0] = 'a' + ((i>>2) + (i<<3)) & 0x15;
		empleats[i].horesMes[i % MAX_DIAS_MES] = i;
		empleats[i].Categoria[i % MAX_CATEGORIA] = (i << 2) * i;
		empleats[i].ptrClauForaneaDepartament = i<<10 + i<<14 + i>>3;
		empleats[i].ptrClauCategoria = i<<24 + i<< 18 + i<<10 + i>>2;
#ifdef EXTES     
        empleats[i].Address[0] = 'A' + ((i>>4) + (i<<2)) & 0x15;
        empleats[i].Nom_parella[0] = 'a' + ((i>>5) + (i<<2)) & 0x15;
  		empleats[i].Cognoms_parella[0] = 'A' + ((i>>5) + (i<<3)) & 0x15;
#endif
	}

	qsort(empleats_NID, N, sizeof(Templeat_ID), compare_guays);
//	qsort(empleats, N, sizeof(Templeat), compare);
	for (i=0; i<N; i++)
	{
		write(1, &empleats[ empleats_NID[i].i ], sizeof(Templeat));
	}

	return 0;
}
