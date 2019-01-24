/* procedure entrerChaine */

#include "chaine.h"

void entrerChaine (ChaineDyn * ch, FILE* f, const int n, jmp_buf ptRep)
{
    static char * ERR_PARAM = "Erreur parametre invalide" ;
    static char * ERR_FIC = "Erreur de lecture du fichier" ;
    static char * ERR_ALLOC = "Erreur Allocation" ;
    char * ptrAlloc ;
    char * err ;

    if (n < 0)
    {
        longjmp (ptRep, (int)ERR_PARAM) ;
    }
    if (n == 0)
    {
        libererChaine (ch) ;
    }
    else
    {
        ptrAlloc = (char *)malloc (n+1) ;
        if (ptrAlloc == NULL)
        {
            longjmp (ptRep, (int)ERR_ALLOC) ;
        }
        err = fgets (ptrAlloc, n+1, f) ;
        if (err == NULL)
        {
            free( ptrAlloc ) ;
            longjmp (ptRep, (int)ERR_FIC) ;
        }
        convertirChaine (ch, ptrAlloc, ptRep) ;
        free (ptrAlloc) ;
    }
}
