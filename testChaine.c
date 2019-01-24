/* ETUDE DE CAS                                     */
/* programme de test de creation et de manipulation */
/* de chaines  du type ChaineDyn                    */

#include "chaine.h"

void afficherMenu () ;
void saisirChoix (int *) ;
void attente () ;
void saisirChaineC (char *) ;
void afficherChaine (const ChaineDyn) ;
void saisirEntier (int *) ;

void convertir () ;
void longueur () ;
void copier () ;
void coller() ;
void extraire ();
void entrer () ;
void sortir () ;
void comparer () ;

int main()
{
    int choix ;       

    choix = 0 ;
    while (choix != 9)
    {
        afficherMenu () ;
        saisirChoix (&choix) ;
        switch (choix)
        {
            case 1 : 
                convertir () ;
                attente () ;
                break ;
            case 2 : 
                longueur () ;
                attente () ;
                break ;
            case 3 : 
                copier () ;
                attente () ;
                break ;       
            case 4 : 
                extraire () ;
                attente () ;
                break ;         
            case 5 : 
                entrer () ;
                attente () ;
                break ;          
            case 6 : 
                sortir () ;
                attente () ;
                break ;           
            case 7 : 
                comparer () ;
                attente () ;
                break ;
            case 8 : 
                coller () ;
                attente () ;
                break ;					           
            case 9 : 
                printf ("***Termine!!!\n");
                break ;
            default : 
                printf ("***choix invalide!!!\n") ;
                attente () ;
        }   
    }     
}

void afficherMenu ()
{
    printf ("\n   MENU \n") ;
    printf ("   ---- \n\n") ;
    printf (" 1- Convertir une chaine C en type ChaineDyn\n") ;
    printf (" 2- Afficher la longueur d'une chaine du type ChaineDyn\n") ;
    printf (" 3- Copier une chaine du type ChaineDyn dans une autre\n") ;
    printf (" 4- Extraire une sous-chaine du type ChaineDyn dans une autre\n") ; 
    printf (" 5- Entrer une chaine depuis un fichier\n") ;
    printf (" 6- Ecrire une chaine dans un fichier\n") ;	
    printf (" 7- Comparer une chaine du type ChaineDyn avec une autre\n") ;
    printf (" 8- Coller une chaine du type ChaineDyn a une autre\n") ;	
    printf (" ........\n") ;
    printf (" 9- Arret du programme\n\n") ;
}

void saisirChoix (int * choix)
{
    char tampon [256] ;
    int err ;

    printf ("Entrer votre choix: ") ;
    fgets (tampon, 256, stdin) ;
    err = sscanf (tampon, "%d", choix) ;
    if (err == 0)
    {
        * choix = 0 ;
    }       
}

void attente ()
{
    char tampon [256] ;
    
    printf ("\nTaper sur Entree pour continuer:\n") ;
    fgets (tampon, 256, stdin) ;
}

void saisirChaineC (char * tampon)
{
    int dernier ;

    printf ("Entrer une chaine:\n") ;
    fgets (tampon, 256, stdin) ;
    dernier = strlen (tampon) - 1 ;
    if (tampon[dernier] == '\n')
    {
        tampon[dernier] = '\0' ;
    }
}

void afficherChaine (const ChaineDyn ch)
{
    int i ;

    printf ("nbCar= %d   ptrCar= %X\n", ch.nbCar, ch.ptrCar) ;
    printf ("contenu= ") ;
    for (i = 0 ; i < ch.nbCar ; i++)
    {
        putchar (ch.ptrCar[i]) ;
    }
    putchar ('\n') ;   
}

void saisirEntier (int * nbre)
{
    char tampon [256] ;
    int err ;

    printf ("Entrer un nombre entier: ") ;
    fgets (tampon, 256, stdin) ;
    err = sscanf (tampon, "%d", nbre) ;
    if (err == 0) 
    {
        * nbre = 0 ;
    }       
}

/* Convertir une chaine C en type ChaineDyn */    
void convertir ()
{
    int ret ;
    jmp_buf ptRep ;
    char chaineC [256] ;
    ChaineDyn ch ;

    printf ("Choix 1- Convertir une chaine C en type ChaineDyn\n") ;
    creerChaineVide (&ch) ;
    afficherChaine (ch) ;
    saisirChaineC (chaineC) ;
    ret = setjmp (ptRep) ;
    if (ret == 0)
    {
        convertirChaine (&ch, chaineC, ptRep) ;
    } 
    else
    {
        printf ("\n*** %s\n", ret) ;
    }
    afficherChaine (ch) ;
    libererChaine (&ch) ;  
}

/* Afficher la longueur d'une chaine du type ChaineDyn */
void longueur ()
{
    int ret ;
    jmp_buf ptRep ;
    char chaineC [256] ;
    ChaineDyn ch ;

    printf("Choix 2- Afficher la longueur d'une chaine du type ChaineDyn\n") ;
    creerChaineVide (&ch) ;
    saisirChaineC (chaineC) ;
    ret = setjmp (ptRep) ;
    if (ret == 0)
    {
        convertirChaine (&ch, chaineC, ptRep) ;
    } 
    else
    {
        printf ("\n*** %s\n", ret) ;
    }
    printf ("longueur= %d\n", longueurChaine (ch)) ;        
    afficherChaine (ch) ;
    libererChaine (&ch) ; 
}

/*Copier une chaine du type ChaineDyn dans une autre */
void copier ()
{
    int ret ;
    jmp_buf ptRep ;
    char chaineC [256] ;
    ChaineDyn ch1, ch2 ;

    printf ("Choix 3- Copier une chaine du type ChaineDyn dans une autre\n") ;
    creerChaineVide (&ch1) ;
    creerChaineVide (&ch2) ;
    saisirChaineC (chaineC) ;    
    ret = setjmp (ptRep) ;
    if (ret == 0)
    {
        convertirChaine (&ch1, chaineC, ptRep) ;
    } 
    else
    {
        printf ("\n*** %s\n", ret) ;
    }       	
    afficherChaine (ch1) ; 	
    saisirChaineC (chaineC) ;		
    ret = setjmp (ptRep) ;
    if (ret == 0)
    {
        convertirChaine (&ch2, chaineC, ptRep) ;
    } 
    else
    {
        printf ("\n*** %s\n", ret) ;
    }       	
    afficherChaine (ch2) ; 	
    ret = setjmp (ptRep) ;
    if (ret == 0)
    {
        copierChaine (&ch1, ch2, ptRep) ;
    } 
    else
    {
        printf ("\n*** %s\n", ret) ;
    }        
    afficherChaine (ch1) ;
    libererChaine (&ch1) ;
    libererChaine (&ch2) ;	
}

/*Extraire une sous-chaine du type ChaineDyn dans une autre */
void extraire ()
{
    int ret ;
    jmp_buf ptRep ;
    char chaineC [256] ;
    ChaineDyn ch1, ch2 ;
    int n, p ;

    printf ("Choix 4- Extraire une sous-chaine du type ChaineDyn dans une autre\n") ;
    creerChaineVide (&ch1) ;
    creerChaineVide (&ch2) ;
    saisirChaineC (chaineC) ;    
    ret = setjmp (ptRep) ;
    if (ret == 0)
    {
        convertirChaine (&ch1, chaineC, ptRep) ;
    } 
    else
    {
        printf ("\n*** %s\n", ret) ;
    }       	
    afficherChaine (ch1) ; 	
    saisirChaineC (chaineC) ;		
    ret = setjmp (ptRep) ;
    if (ret == 0)
    {
        convertirChaine (&ch2, chaineC, ptRep) ;
    } 
    else
    {
        printf ("\n*** %s\n", ret) ;
    }       	
    afficherChaine (ch2) ; 	
    printf ("Donner la position du 1er caractere a extraire\n") ;
    saisirEntier(&p) ;
    printf ("Donner le nombre de caractere a extraire\n") ;
    saisirEntier(&n) ;
    ret = setjmp (ptRep) ;
    if (ret == 0)
    {
        extraireSousChaine (&ch1, ch2, p, n, ptRep) ;
    } 
    else
    {
        printf ("\n*** %s\n", ret) ;
    }
    afficherChaine (ch1) ;
    libererChaine (&ch1) ;
    libererChaine (&ch2) ;	
}

/* Entrer une chaine depuis un fichier */
void entrer ()
{
    int ret ;
    int lg ;
    FILE * fic ;
    jmp_buf ptRep ;
    char chaineC [256] ;
    ChaineDyn ch ;

    printf ("Choix 5- Entrer une chaine depuis un fichier\n") ;
    printf ("\nentrer le nom du fichier\n") ;
    saisirChaineC (chaineC) ;
    fic = fopen( chaineC, "r") ; 
    if (fic == NULL)
    {
        perror("echec fopen") ;
        exit(5) ;
    }
    creerChaineVide (&ch) ;
    printf ("Donner le nombre de caractere a lire\n") ;
    saisirEntier(&lg) ;
    ret = setjmp (ptRep) ;
    if (ret == 0)
    {
       	entrerChaine (&ch, fic, lg, ptRep) ;
    } 
    else
    {
        printf ("\n*** %s\n", ret) ;
    }        
    afficherChaine (ch) ;    
    libererChaine (&ch) ;
}

/* Ecrire une chaine dans un fichier */
void sortir ()
{
    int ret ;
    FILE * fic ;
    jmp_buf ptRep ;
    char chaineC [256] ;
    ChaineDyn ch ;

    printf ("Choix 6- Ecrire une chaine dans un fichier\n") ;
    printf ("\nentrer le nom du fichier\n") ;
    saisirChaineC (chaineC) ;
    fic = fopen (chaineC, "w") ;
    creerChaineVide (&ch) ;
    saisirChaineC (chaineC) ;    
    ret = setjmp (ptRep) ;
    if (ret == 0)
    {
        convertirChaine (&ch, chaineC, ptRep) ;
    } 
    else
    {
        printf ("\n*** %s\n", ret) ;
    }       	
    afficherChaine (ch) ;
    ret = setjmp (ptRep) ;
    if (ret == 0)
    {
        sortirChaine (ch, fic, ptRep) ;
    } 
    else
    {
        printf ("\n*** %s\n", ret) ;
    }        
    libererChaine (&ch) ;   
}

/*Comparer une chaine du type ChaineDyn avecs une autre */
void comparer ()
{
    int ret ;
    jmp_buf ptRep ;
    char chaineC [256] ;
    ChaineDyn ch1, ch2 ;
    int result;

    printf ("Choix 7- Comparer une chaine du type ChaineDyn avecs une autre\n") ;
    creerChaineVide (&ch1) ;
    creerChaineVide (&ch2) ;
    saisirChaineC (chaineC) ;    
    ret = setjmp (ptRep) ;
    if (ret == 0)
    {
        convertirChaine (&ch1, chaineC, ptRep) ;
    } 
    else
    {
        printf ("\n*** %s\n", ret) ;
    }       	
    afficherChaine (ch1) ; 	
    saisirChaineC (chaineC) ;		
    ret = setjmp (ptRep) ;
    if (ret == 0)
    {
        convertirChaine (&ch2, chaineC, ptRep) ;
    } 
    else
    {
        printf ("\n*** %s\n", ret) ;
    }       	
    afficherChaine (ch2) ; 	
    result=comparerChaine (ch1, ch2) ;
    printf("resultat= %d\n", result);
    libererChaine (&ch1) ;
    libererChaine (&ch2) ;	
}

/*Coller une chaine du type ChaineDyn a une autre */
void coller ()
{
    int ret ;
    jmp_buf ptRep ;
    char chaineC [256] ;
    ChaineDyn ch1, ch2 ;

    printf ("Choix 8- Coller une chaine du type ChaineDyn a une autre\n") ;
    creerChaineVide (&ch1) ;
    creerChaineVide (&ch2) ;
    saisirChaineC (chaineC) ;    
    ret = setjmp (ptRep) ;
    if (ret == 0)
    {
        convertirChaine (&ch1, chaineC, ptRep) ;
    } 
    else
    {
        printf ("\n*** %s\n", ret) ;
    }       	
    afficherChaine (ch1) ; 	
    saisirChaineC (chaineC) ;		
    ret = setjmp (ptRep) ;
    if (ret == 0)
    {
        convertirChaine (&ch2, chaineC, ptRep) ;
    } 
    else
    {
        printf ("\n*** %s\n", ret) ;
    }       	
    afficherChaine (ch2) ; 	
    ret = setjmp (ptRep) ;
    if (ret == 0)
    {
        collerChaine (&ch1, ch2, ptRep) ;
    } 
    else
    {
        printf ("\n*** %s\n", ret) ;
    }        
    afficherChaine (ch1) ;
    libererChaine (&ch1) ;
    libererChaine (&ch2) ;	
}
