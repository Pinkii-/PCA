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
//	Templeat empleat;
	Templeat_ID* empleats_NID;
	unsigned int N = 4000000, i, ii;

	if (argc > 1) N = atoi(argv[1]);

//	if (empleats == NULL) { fprintf(stderr, "Out of memory\n"); exit(0); }
//	memset(empleats, 0, N*sizeof(Templeat));

	empleats_NID = (Templeat_ID *) malloc(N*sizeof(Templeat_ID));
//	memset(empleats_NID, 0, N*sizeof(Templeat_ID));

	/* Random generation */
	for (i = 0; i < N; i++) 
	{
		empleats_NID[i].NID = rand();
		empleats_NID[i].i = i;
	}

	qsort(empleats_NID, N, sizeof(Templeat_ID), compare_guays);

	empleats = (Templeat *) malloc(N*sizeof(Templeat));
	memset(empleats, 0, sizeof(Templeat)*N);
	for (i = 0; i < N; i++)
	{
		ii = empleats_NID[i].i;

		empleats[i].NID = empleats_NID[i].NID & 0xFFFFFFFF;
		empleats[i].Nom[0] = 'A' + ((ii>>3) + (ii<<2)) & 0x15;
		empleats[i].Cognoms[0] = 'a' + ((ii>>2) + (ii<<3)) & 0x15;
		empleats[i].horesMes[ii % MAX_DIAS_MES] = ii;
		empleats[i].Categoria[ii % MAX_CATEGORIA] = (ii << 2) * ii;
		empleats[i].ptrClauForaneaDepartament = ii<<10 + ii<<14 + ii>>3;
		empleats[i].ptrClauCategoria = ii<<24 + ii<< 18 + ii<<10 + ii>>2;
#ifdef EXTES     
        empleats[i].Address[0] = 'A' + ((ii>>4) + (ii<<2)) & 0x15;
        empleats[i].Nom_parella[0] = 'a' + ((ii>>5) + (ii<<2)) & 0x15;
  		empleats[i].Cognoms_parella[0] = 'A' + ((ii>>5) + (ii<<3)) & 0x15;
#endif

	}

	write(1, empleats, sizeof(Templeat)*N);

	return 0;
}
