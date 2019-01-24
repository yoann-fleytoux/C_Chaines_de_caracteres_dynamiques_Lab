/* procedure comparerChaine */

#include "chaine.h"

int comparerChaine (const ChaineDyn ch1, const ChaineDyn ch2)
{
    char * ptrCh1;
    char * ptrCh2;
    int i;
    int res = 0;

    ptrCh1 = ch1.ptrCar;
    ptrCh2 = ch2.ptrCar;
    /* deplacement dans les 2 chaines */
    for (i=0 ; i <= ch1.nbCar && i <= ch2.nbCar && res == 0 ; i++)
    {
        /* comparaison de l'element pointe en cours */
        if ((*ptrCh1)>(*ptrCh2))
        {
            res=1;
        }
        else 
        {
            if ((*ptrCh1)<(*ptrCh2))
            {
                res=-1;
            }
            else
            { 
                ptrCh2++;
                ptrCh1++;
            }	
        }
    }
    return (res);
}
