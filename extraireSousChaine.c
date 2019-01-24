/* procedure extraireSousChaine */

#include "chaine.h"

void extraireSousChaine(ChaineDyn * ch1, const ChaineDyn ch2,
                        const int p, const int n, jmp_buf ptRep)
{
    static char * ERR_ALLOC = "Erreur Allocation" ;
    static char * ERR_PARAM = "Erreur Parametres p et/ou n Invalides" ;
    int lgCh2 ;
    int lgSousCh2 ;
    char * ptrAlloc ;

    lgCh2 = ch2.nbCar ;
    if (( p < 1 ) || ( p > lgCh2 ) || ( n < 0 ))
    {
        longjmp(ptRep, (int)ERR_PARAM) ;
    }
    lgSousCh2 = lgCh2-p+1 ;
    if ( lgSousCh2 > n )
    {
       	lgSousCh2 = n ;
    }
    if ( lgSousCh2 == 0 )
    {
        ptrAlloc=NULL ;
    }
    else
    {
        ptrAlloc = (char *)malloc(lgSousCh2) ;
        if (ptrAlloc == NULL)
        {
            longjmp(ptRep, (int)ERR_ALLOC) ;
        }
        memcpy (ptrAlloc, ch2.ptrCar+p-1, lgSousCh2) ; 
    }
    if (ch1->ptrCar != NULL)
    {
        free (ch1->ptrCar) ;
    } 
    ch1->nbCar = lgSousCh2 ;
    ch1->ptrCar = ptrAlloc ;
}
