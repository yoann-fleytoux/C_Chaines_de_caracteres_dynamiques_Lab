/* procedure collerChaine */

#include "chaine.h"

void collerChaine(ChaineDyn * ch1, const ChaineDyn ch2, jmp_buf ptRep)
{
    static char * ERR_ALLOC = "Erreur Allocation" ;
    int lgCh1, lgCh2 ;
    char * ptrAlloc ;

    lgCh2 = ch2.nbCar ;
    if (lgCh2 > 0)
    {
        lgCh1 = ch1->nbCar ;
        ptrAlloc = (char *)malloc (lgCh1 + lgCh2) ;
        if (ptrAlloc == NULL)
        {
            longjmp(ptRep, (int)ERR_ALLOC) ;
        }
        memcpy (ptrAlloc, ch1->ptrCar, lgCh1) ;
        memcpy (ptrAlloc + lgCh1, ch2.ptrCar, lgCh2) ;  
    }
    if (ch1->ptrCar != NULL)
    {
        free (ch1->ptrCar) ;
    } 
    ch1->nbCar = lgCh1 + lgCh2 ;
    ch1->ptrCar = ptrAlloc ;
}
