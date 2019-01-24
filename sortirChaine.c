/* procedure sortirChaine */

#include "chaine.h"

void sortirChaine (const ChaineDyn ch, FILE * f, jmp_buf ptRep)
{
    static char * ERR_FIC = "Erreur d'ecriture du fichier" ;    
    int nBloc;

    nBloc = fwrite( ch.ptrCar, ch.nbCar, 1, f ) ;
    if ( nBloc != 1 )
    {
        longjmp (ptRep, (int)ERR_FIC) ;        
    }
}
