#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>


typedef struct proc proc;
struct proc
{
    char  code;
    int AT;
    int priority;
    int length;
    int lewel;
    int exe;
    int *schedule;
    proc *next;
};
typedef struct liste
{
    int taille;
    proc *first;
    proc *last;
} liste;

void FCFS(liste *BCP);
typedef proc* llist;

void initialisation(liste *list)
{
    list->first = NULL;
    list->last = NULL;
    list->taille = 0;
}
void initialiser_proc(proc *p)
{
    p->AT=0;
    p->length=0;
    p->next=NULL;
    p->lewel=0;
    p->exe = 0;
    p->priority=0;
    p->schedule=NULL;
}
void insereenfin(liste *list,proc nouveauproc)
{

    proc *newproc = (proc*)malloc(sizeof(proc));
    if(list->taille == 0)
    {
        *newproc=nouveauproc;
        list->first = newproc;
        list->last = newproc;
        list->taille++;
    }
    else
    {
        *newproc=nouveauproc;
        list->last->next = newproc;
        list->last = newproc;
        list->taille++;
        newproc->next=NULL;
    }
}
//void afficher(liste list)
//{
//    proc *parcours=NULL;
//    for(parcours=list.first; parcours!=NULL; parcours=parcours->next)
//    {
//        printf("  %c  -",parcours->code);
//        printf("  %d -",parcours->AT);
//        printf("  %d\n",parcours->priority);
//    }
//    printf("\n");
//}
proc supprimer(liste *list)
{
    if (list->taille == 1 )
    {
        proc oldproc;
        //proc *oldproc = (proc*)malloc(sizeof(proc));
        oldproc = *list->first;
        initialisation(list);
        return oldproc;
    }
    else
    {
//        proc *oldproc = (proc*)malloc(sizeof(proc));
        proc oldproc;
        oldproc = *list->first;
        list->first = list->first->next;
        list->taille--;
        return oldproc;
    }
}
void FIFO(liste *list);
void SRT(liste *list);
void SJF(liste *list);
void REQ(liste *list);

void ATsort(liste *list)
{
    int i;
    char j;
    int *f;
    proc *foo,*bar;
    for(foo = list->first; foo != list->last; foo=foo->next)
    {

        for(bar = list->first; bar != list->last; bar=bar->next)
        {
            if(bar->AT > bar->next->AT)
            {

                j=bar->next->code;
                i=bar->next->AT;
                bar->next->code = bar->code;
                bar->next->AT = bar->AT;
                bar->code = j;
                bar->AT = i;
                i=bar->next->length;
                bar->next->length = bar->length;
                bar->length= i;
                i=bar->next->priority;
                bar->next->priority = bar->priority;
                bar->priority= i;
                f = bar->next->schedule;
                bar->next->schedule = bar->schedule;
                bar->schedule= f;

            }
        }
    }
}
void JOBsort(liste *list)
{
    int i;
    char j;
    int *f;
    proc *foo,*bar;
    for(foo = list->first; foo != list->last; foo=foo->next)
    {

        for(bar = list->first; bar != list->last; bar=bar->next)
        {
            if(bar->schedule[0] > bar->next->schedule[0])
            {
                j=bar->next->code;
                i=bar->next->AT;
                bar->next->code = bar->code;
                bar->next->AT = bar->AT;
                bar->code = j;
                bar->AT = i;
                i=bar->next->length;
                bar->next->length = bar->length;
                bar->length= i;
                i=bar->next->priority;
                bar->next->priority = bar->priority;
                bar->priority= i;
                f = bar->next->schedule;
                bar->next->schedule = bar->schedule;
                bar->schedule= f;

            }
        }
    }
}void PRIOsort(liste *list)
{
    int i;
    char j;
    int *f;
    proc *foo,*bar;
    for(foo = list->first; foo != list->last; foo=foo->next)
    {

        for(bar = list->first; bar != list->last; bar=bar->next)
        {
            if(bar->priority > bar->next->priority)
            {
                j=bar->next->code;
                i=bar->next->AT;
                bar->next->code = bar->code;
                bar->next->AT = bar->AT;
                bar->code = j;
                bar->AT = i;
                i=bar->next->length;
                bar->next->length = bar->length;
                bar->length= i;
                i=bar->next->priority;
                bar->next->priority = bar->priority;
                bar->priority= i;
                f = bar->next->schedule;
                bar->next->schedule = bar->schedule;
                bar->schedule= f;

            }
        }
    }
}
void afterJOBsort(liste*list)
{
    int i,choix;
    char j;
    int *f;
    proc *foo,*bar;
    for(foo = list->first; foo != list->last; foo=foo->next)
    {

        for(bar = list->first; bar != list->last; bar=bar->next)
        {
            if(bar->AT == bar->next->AT)
            {
                if(bar->schedule[0] > bar->next->schedule[0])
                {
                    j=bar->next->code;
                    i=bar->next->AT;
                    bar->next->code = bar->code;
                    bar->next->AT = bar->AT;
                    bar->code = j;
                    bar->AT = i;
                    i=bar->next->length;
                    bar->next->length = bar->length;
                    bar->length= i;
                    i=bar->next->priority;
                    bar->next->priority = bar->priority;
                    bar->priority= i;
                    f = bar->next->schedule;
                    bar->next->schedule = bar->schedule;
                    bar->schedule= f;

                }
            }
        }
    }
}
int main ()
{
    liste list;
    FILE *P;
    char nomf[20];
    char *p, s[20];
    int i;
    char c;
    FILE *intro;
    int choix;
    proc nouveauproc;
    initialisation(&list);
    initialiser_proc(&nouveauproc);
    system("mode 184,90");
    intro = fopen("intro_SE.txt", "r");
    while ((c = getc(intro)) != EOF)
    {
        putchar(c);
    }
    fclose(intro);
    system("pause");
    system("cls");
    printf("Veuillez donner le nom du fichier a tester :");
//    gets(nomf);
    P=fopen("proc.txt","rt");
    if (P==NULL)
        printf("can't find the file");
    else
    {
        int car=0;
        while (car!=EOF)
        {
            i=1;
            fscanf(P,"%c;%d;%d;",&nouveauproc.code,&nouveauproc.AT,&nouveauproc.priority); // read 3 first
            nouveauproc.schedule = (int*) malloc(sizeof(int));   //malloci 1 int pour exe
            fscanf(P,"%d", &nouveauproc.schedule[0]); //9ra wa7d
            while (((car=fgetc(P))!='\n') && (car!=EOF)) //ilakan wa7d akhor reallocih et 3mer
            {
                nouveauproc.schedule=(int*)realloc(nouveauproc.schedule,(i+1)*sizeof(int));
                fscanf(P,"%d",&nouveauproc.schedule[i]);
                i++;
            }
            nouveauproc.length=i;
            if (car!=EOF)
            {
                insereenfin(&list,nouveauproc);
            }
        }
        system("cls");
        printf("\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MENU PRINCIPAL~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\n\n\n\n\n                                                                               choix de l'algorithme : \n");
        printf("                                                                                   1 - FIFO \n");
        printf("                                                                                   2 - SRT\n");
        printf("                                                                                   3 - SJF\n");
        printf("                                                                                   4 - REQUISITION (prochainement) \n");
        printf("\n\n\n\n                                                                                  votre choix : ");
        while (fgets(s, sizeof(s), stdin))
        {
            choix = strtol(s, &p, 10);
            if (p == s || *p != '\n' || choix<1 || choix>4)
            {
                printf("\n                                                                                  reessayez: ");
            }
            else
            {
                break;
            }
        }
        system("cls");
        if (choix == 1)
        {
            printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  FIFO  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\n\n");
            ATsort(&list);
            FIFO(&list);
            system("fileFIFO.txt");
        }
        else if(choix == 2)
        {
            printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  SRT   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\n\n");
            ATsort(&list);
            afterJOBsort(&list);
            SRT(&list);
            system("fileSRT.txt");
        }
        else if (choix == 3)
        {
            printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  SJF   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\n\n");
            SJF(&list);
            system("fileSJF.txt");
        }
        else
        {
            printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  REQUISITION   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\n\n");
            REQ(&list);
            system("fileREQ.txt");
        }
        fclose(P);
    }
    return 0;
}

void FIFO(liste *list)
{
    int nbr; // nombre de processus dans la liste
    int i=0; //temps
    int etatCPU1 = 0;
    int  etatCPU2 = 0;
    int etatIO = 0;
    int t=0,pret=0;
    int cpt = 0;
    proc *ptr;
    FILE * handler = fopen("fileFIFO.txt","wt");
    proc *parcours=NULL;
    proc *par=NULL;
    proc procinCPU1 , procinCPU2, procinIO;
    liste *ready =(liste*)malloc(sizeof(liste));
    liste *block =(liste*)malloc(sizeof(liste));
    liste *done =(liste*)malloc(sizeof(liste));
    initialiser_proc(&procinCPU1);
    initialiser_proc(&procinCPU2);
    initialiser_proc(&procinIO);
    initialisation(ready);
    initialisation(block);
    initialisation(done);
    nbr = list->taille ;
    while(done->taille != nbr)
    {
        printf("    T = %2d :    ",t);
//        if (list->taille>0)
//        {
//
//            for(parcours=list->first; parcours!=NULL; parcours=parcours->next)
//            {
//                if (t==parcours->AT)
//                {
//                    if (etatCPU1 == 0 && ready->taille == 0)
//                    {
//                        procinCPU1 = supprimer(list);
//                        etatCPU1 = 1;
//                        fprintf(handler,"T = %d : P%d est elu dans le CPU 1\n",t,procinCPU1.code);
//                    }
//                    else if (etatCPU2 == 0 && ready->taille == 0)
//                    {
//                        procinCPU2 = supprimer(list);
//                        etatCPU2 = 1;
//                        fprintf(handler,"T = %d : P%d est elu dans le CPU 2\n",t,procinCPU2.code);
//                    }
//                    else
//                    {
//                        if (etatCPU1 == 1 && etatCPU2 == 1)
//                        {
//                            insereenfin(ready,supprimer(list));
//                            fprintf(handler,"T = %d : P%d est pret \n",t,parcours->code);
//                        }
//                    }
//                }
//            }
//        }




        if ( etatIO == 1 )
        {
            if (procinIO.schedule[0]==0)
            {
                int i;
                for(i=0; i<procinIO.length; i++)
                {
                    procinIO.schedule[i] = procinIO.schedule[i+1];
                }
                procinIO.length --;

                if (procinIO.length==0)
                {

                    fprintf(handler,"T = %d : %c a termine\n",t,procinIO.code);
                    insereenfin(done,procinIO);
                    etatIO = 0;
                }
                else
                {
                    if (etatCPU1 == 0 && ready->taille == 0)
                    {
                        fprintf(handler,"T = %d : %c est elu dans le CPU 1\n",t,procinIO.code);
                        procinCPU1 = procinIO;
                        etatCPU1 = 1;
                        etatIO= 0;
                    }
                    else if (etatCPU2 == 0 && ready->taille == 0)
                    {
                        fprintf(handler,"T = %d : %c est elu dans le CPU 2\n",t,procinIO.code);
                        procinCPU2 = procinIO;
                        etatCPU2 = 1;
                        etatIO= 0;
                    }
                    else
                    {
                        fprintf(handler,"T = %d : %c est pret\n",t,procinIO.code);
                        insereenfin(ready,procinCPU1);
                        etatIO= 0;
                    }
                }
            }
        }
        if ( etatCPU1==1 )
        {
            if (procinCPU1.schedule[0]==0)
            {
                int i;
                for(i=0; i<procinCPU1.length; i++)
                {
                    procinCPU1.schedule[i] = procinCPU1.schedule[i+1];
                }
                procinCPU1.length --;

                if (procinCPU1.length==0)
                {
                    fprintf(handler,"T = %d : %c a termine\n",t,procinCPU1.code);
                    insereenfin(done,procinCPU1);
                    etatCPU1 = 0;
                }
                else
                {
                    if (etatIO == 0 && block->taille == 0)
                    {

                        fprintf(handler,"T = %d : %c passe en E/S\n",t,procinCPU1.code);
                        procinIO = procinCPU1;
                        etatIO = 1;
                        etatCPU1= 0;
                    }
                    else
                    {
                        fprintf(handler,"T = %d : %c est bloque\n",t,procinCPU1.code);
                        insereenfin(block,procinCPU1);
                        etatCPU1= 0;
                    }
                }
            }
        }
        if ( etatCPU2==1 )
        {

            if (procinCPU2.schedule[0]==0)
            {
                int i;
                for(i=0; i<procinCPU2.length; i++)
                {
                    procinCPU2.schedule[i] = procinCPU2.schedule[i+1];
                }
                procinCPU2.length --;

                if (procinCPU2.length==0)
                {
                    fprintf(handler,"T = %d : %c a termine\n",t,procinCPU2.code);
                    insereenfin(done,procinCPU2);
                    etatCPU2 = 0;
                }
                else
                {
                    if (etatIO == 0 && block->taille == 0)
                    {
                        fprintf(handler,"T = %d : %c passe en E/S\n",t,procinCPU2.code);
                        procinIO = procinCPU2;
                        etatIO = 1;
                        etatCPU2= 0;
                    }
                    else
                    {
                        fprintf(handler,"T = %d : %c est bloque\n",t,procinCPU2.code);
                        insereenfin(block,procinCPU2);
                        etatCPU2= 0;
                    }
                }
            }
        }
        if(etatIO==0 && block->taille > 0)
        {
            etatIO=1;
            procinIO = supprimer(block);
            fprintf(handler,"T = %d : %c passe a e/s\n",t,procinIO.code);

        }
        if(etatCPU1==0 && ready->taille > 0)
        {
            etatCPU1 = 1;
            procinCPU1 = supprimer(ready);
            fprintf(handler,"T = %d : %c est elu CPU 1\n",t,procinCPU1.code);
        }
        if(etatCPU2==0 && ready->taille > 0)
        {
            etatCPU2 = 1;
            procinCPU2 = supprimer(ready);
            fprintf(handler,"T = %d : %c est elu CPU 2\n",t,procinCPU2.code);
        }
        if (list->taille>0)
        {

            for(parcours=list->first; parcours!=NULL; parcours=parcours->next)
            {
                if (t==parcours->AT)
                {
                    if (etatCPU1 == 0 && ready->taille == 0)
                    {
                        procinCPU1 = supprimer(list);
                        etatCPU1 = 1;
                        fprintf(handler,"T = %d : %c est elu dans le CPU 1\n",t,procinCPU1.code);
                    }
                    else if (etatCPU2 == 0 && ready->taille == 0)
                    {
                        procinCPU2 = supprimer(list);
                        etatCPU2 = 1;
                        fprintf(handler,"T = %d : %c est elu dans le CPU 2\n",t,procinCPU2.code);
                    }
                    else
                    {
                        if (etatCPU1 == 1 && etatCPU2 == 1)
                        {
                            insereenfin(ready,supprimer(list));
                            fprintf(handler,"T = %d : %c est pret \n",t,parcours->code);
                        }
                    }
                }
            }
        }
        textcolor(BLUE);
        if (ready->taille > 0)
        {
            par = ready->first;
            while(par!=NULL)
            {
                if (par == ready->first)
                {
                    printf("    %c  =   ",par->code);
                    cprintf("PRET       ");
                    printf("|");
                }
                else
                {
                    if(par->lewel == 1)
                    {
                        printf("    %c  =   ",par->code);
                        cprintf("PRET       ");
                        printf("|");
                    }
                    par->lewel = 1;
                }
                par = par->next;
            }
        }
        textcolor(RED);
        if(block->first!=NULL)
        {
            printf("    %c  =  ",block->first->code,t);
            cprintf("BLOQUE      ");
            printf("|");
            if(block->last!=block->first)
            {
                printf("    %c  =  ",block->last->code,t);
                cprintf("BLOQUE      ");
                printf("|");
            }


        }
               t++;

        if (etatIO == 1 && procinIO.schedule[0] > 0)
        {
            textcolor(YELLOW);
            printf("    %c  =  ",procinIO);
            cprintf("E/S         ");
            printf("|");
            procinIO.schedule[0]--;
        }
        else
        {
            printf("                       |");
        }
        if (etatCPU1 == 1 && procinCPU1.schedule[0] > 0)
        {
            textcolor(GREEN);
            printf("    %c  =  ",procinCPU1);
            cprintf("ELU  (CPU1) ");
            printf("|");
            procinCPU1.schedule[0]--;
        }
        else
        {
            printf("                       |");
        }

        if (etatCPU2 == 1 && procinCPU2.schedule[0] > 0)
        {
            textcolor(GREEN);
            printf("    %c  =  ",procinCPU2);
            cprintf("ELU  (CPU2) ");
            printf("|");
            procinCPU2.schedule[0]--;
        }
        else
        {
            printf("                       |");
        }

        printf("\n\n------------------------------------------------------------------------------------------------------------------------------------------\n");
    }
    fclose(handler);
}
void SJF(liste *list)
{
    int nbr; // nombre de processus dans la liste
    int i=0; //temps
    int etatCPU1 = 0;
    int  etatCPU2 = 0;
    int etatIO = 0;
    int t=0,pret=0;
    proc *ptr;
    FILE * handler = fopen("fileSJF.txt","wt");
    proc *parcours=NULL;
    proc *par=NULL;
    proc procinCPU1 , procinCPU2, procinIO;
    liste *ready =(liste*)malloc(sizeof(liste));
    liste *block =(liste*)malloc(sizeof(liste));
    liste *done =(liste*)malloc(sizeof(liste));
    initialiser_proc(&procinCPU1);
    initialiser_proc(&procinCPU2);
    initialiser_proc(&procinIO);
    initialisation(ready);
    initialisation(block);
    initialisation(done);
    nbr = list->taille ;
    afterJOBsort(list);
    while(done->taille != nbr)
    {
        printf("    T = %d : ",t);

        if (list->taille>0)
        {

            for(parcours=list->first; parcours!=NULL; parcours=parcours->next)
            {
                if (t==parcours->AT)
                {
                    if (etatCPU1 == 0 && ready->taille == 0)
                    {
                        procinCPU1 = supprimer(list);
                        etatCPU1 = 1;
                        fprintf(handler,"T = %d : P%d est elu dans le CPU 1\n",t,procinCPU1.code);
                    }
                    else if (etatCPU2 == 0 && ready->taille == 0)
                    {
                        procinCPU2 = supprimer(list);
                        etatCPU2 = 1;
                        fprintf(handler,"T = %d : P%d est elu dans le CPU 2\n",t,procinCPU2.code);
                    }
                    else
                    {
                        if (etatCPU1 == 1 && etatCPU2 == 1)
                        {
                            insereenfin(ready,supprimer(list));
                            fprintf(handler,"T = %d : P%d est pret \n",t,parcours->code);
                        }
                    }
                }
            }
        }



        if ( etatIO == 1 )
        {
            if (procinIO.schedule[0]==0)
            {
                int i;
                for(i=0; i<procinIO.length; i++)
                {
                    procinIO.schedule[i] = procinIO.schedule[i+1];
                }
                procinIO.length --;

                if (procinIO.length==0)
                {

                    fprintf(handler,"T = %d : %c a termine\n",t,procinIO.code);
                    insereenfin(done,procinIO);
                    etatIO = 0;
                }
                else
                {
                    if (etatCPU1 == 0)
                    {
                        fprintf(handler,"T = %d : %c est elu dans le CPU 1\n",t,procinIO.code);
                        procinCPU1 = procinIO;
                        etatCPU1 = 1;
                        etatIO= 0;
                    }
                    else if (etatCPU2 == 0)
                    {
                        fprintf(handler,"T = %d : %c est elu dans le CPU 2\n",t,procinIO.code);
                        procinCPU2 = procinIO;
                        etatCPU2 = 1;
                        etatIO= 0;
                    }
                    else
                    {
                        fprintf(handler,"T = %d : %c est pret\n",t,procinIO.code);
                        insereenfin(ready,procinCPU1);
                        etatIO= 0;
                    }
                }
            }
        }
        if(etatIO==0 && block->taille!=0)
        {
            etatIO=1;
            procinIO = supprimer(block);
            fprintf(handler,"T = %d : %c passe a e/s\n",t,procinIO.code);
        }
        if ( etatCPU1==1 )
        {
            if (procinCPU1.schedule[0]==0)
            {
                int i;
                for(i=0; i<procinCPU1.length; i++)
                {
                    procinCPU1.schedule[i] = procinCPU1.schedule[i+1];
                }
                procinCPU1.length --;

                if (procinCPU1.length==0)
                {
                    fprintf(handler,"T = %d : %c a termine\n",t,procinCPU1.code);
                    insereenfin(done,procinCPU1);
                    etatCPU1 = 0;
                }
                else
                {
                    if (etatIO == 0)
                    {
                        fprintf(handler,"T = %d : %c passe en E/S\n",t,procinCPU1.code);
                        procinIO = procinCPU1;
                        etatIO = 1;
                        etatCPU1= 0;
                    }
                    else
                    {
                        fprintf(handler,"T = %d : %c est bloque\n",t,procinCPU1.code);
                        insereenfin(block,procinCPU1);
                        etatCPU1= 0;
                    }
                }
            }
        }


        if ( etatCPU2==1 )
        {

            if (procinCPU2.schedule[0]==0)
            {
                int i;
                for(i=0; i<procinCPU2.length; i++)
                {
                    procinCPU2.schedule[i] = procinCPU2.schedule[i+1];
                }
                procinCPU2.length --;

                if (procinCPU2.length==0)
                {
                    fprintf(handler,"T = %d : %c a termine\n",t,procinCPU2.code);
                    insereenfin(done,procinCPU2);
                    etatCPU2 = 0;
                }
                else
                {
                    if (etatIO == 0)
                    {
                        fprintf(handler,"T = %d : %c passe en E/S\n",t,procinCPU2.code);
                        procinIO = procinCPU2;
                        etatIO = 1;
                        etatCPU2= 0;
                    }
                    else
                    {
                        fprintf(handler,"T = %d : %c est bloque\n",t,procinCPU2.code);
                        insereenfin(block,procinCPU2);
                        etatCPU2= 0;
                    }
                }
            }
        }




        if(etatCPU1==0 && ready->taille!=0)
        {
            etatCPU1 = 1;
            procinCPU1 = supprimer(ready);           // Le Processus vien d'etre elu dans le CPU1
            fprintf(handler,"T = %d : %c est elu CPU 1\n",t,procinCPU1.code);
        }
        if(etatCPU2==0 && ready->taille!=0)
        {
            etatCPU2 = 1;
            procinCPU2 = supprimer(ready);           // Le Processus vien d'etre elu dans le CPU1
            fprintf(handler,"T = %d : %c est elu dans CPU 2\n",t,procinCPU2.code);
        }
        if (list->taille>0)
        {

            for(parcours=list->first; parcours!=NULL; parcours=parcours->next)
            {
                if (t==parcours->AT)
                {
                    if (etatCPU1 == 0 && ready->taille == 0)
                    {
                        procinCPU1 = supprimer(list);
                        etatCPU1 = 1;
                        fprintf(handler,"T = %d : %c est elu dans le CPU 1\n",t,procinCPU1.code);
                    }
                    else if (etatCPU2 == 0 && ready->taille == 0)
                    {
                        procinCPU2 = supprimer(list);
                        etatCPU2 = 1;
                        fprintf(handler,"T = %d : %c est elu dans le CPU 2\n",t,procinCPU2.code);
                    }
                    else
                    {
                        if (etatCPU1 == 1 && etatCPU2 == 1)
                        {
                            insereenfin(ready,supprimer(list));
                            fprintf(handler,"T = %d : %c est pret \n",t,parcours->code);
                        }
                    }
                }
            }
        }
        JOBsort(ready);
        textcolor(BLUE);
        if (ready->taille > 0)
        {
            par = ready->first;
            while(par!=NULL)
            {
                if (par == ready->first)
                {
                    printf("     %c  =   ",par->code);
                    cprintf("PRET       ");
                    printf("|");
                }
                else
                {
                    if(par->lewel == 1)
                    {
                        printf("     %c  =   ",par->code);
                        cprintf("PRET       ");
                        printf("|");
                    }
                    par->lewel = 1;
                }
                par = par->next;
            }
        }
        textcolor(RED);
        if(block->first!=NULL)
        {
            printf("     %c  =  ",block->first->code,t);
            cprintf("BLOQUE      ");
            printf("|");
            if(block->last!=block->first)
            {
                printf("     %c  =  ",block->last->code,t);
                cprintf("BLOQUE      ");
                printf("|");
            }


        }


        if (etatIO == 1 && procinIO.schedule[0] > 0)
        {
            textcolor(YELLOW);
            printf("     %c  =  ",procinIO.code);
            cprintf("E/S         ");
            printf("|");
            procinIO.schedule[0]--;
        }


        if (etatCPU1 == 1 && procinCPU1.schedule[0] > 0)
        {
            textcolor(GREEN);
            printf("     %c  =  ",procinCPU1.code);
            cprintf("ELU  (CPU1) ");
            printf("|");
            procinCPU1.schedule[0]--;
        }

        if (etatCPU2 == 1 && procinCPU2.schedule[0] > 0)
        {
            textcolor(GREEN);
            printf("     %c  =  ",procinCPU2.code);
            cprintf("ELU  (CPU1) ");
            printf("|");
            procinCPU2.schedule[0]--;
        }
        t++;
        printf("\n\n------------------------------------------------------------------------------------------------------------------------------------------\n");

    }
    fclose(handler);
}

void SRT(liste *list)
{
    int nbr; // nombre de processus dans la liste
    // int i=0;
    int etatCPU1 = 0;
    int  etatCPU2 = 0;
    int etatIO = 0;
    int t=0,pret=0;
    proc *par=NULL;
    FILE * handler = fopen("fileSRT.txt","wt");
    proc *parcours=NULL;
    proc *ptr;
    proc procinCPU1 , procinCPU2, procinIO;
    liste *ready =(liste*)malloc(sizeof(liste));
    liste *block =(liste*)malloc(sizeof(liste));
    liste *done =(liste*)malloc(sizeof(liste));
    initialiser_proc(&procinCPU1);
    initialiser_proc(&procinCPU2);
    initialiser_proc(&procinIO);
    initialisation(ready);
    initialisation(block);
    initialisation(done);
    nbr = list->taille ;
    while(done->taille != nbr)
    {
        printf("    T = %d : ",t);

        if (list->taille>0)
        {
            for(parcours=list->first; parcours!=NULL; parcours=parcours->next)
            {
                if (t==parcours->AT)
                {
                    if (etatCPU1 == 0 && ready->taille == 0)
                    {
                        procinCPU1 = supprimer(list);
                        etatCPU1 = 1;
                        fprintf(handler,"T = %d : %c est elu dans le CPU 1\n",t,procinCPU1.code);

                    }
                    else if (etatCPU2 == 0 && ready->taille == 0)
                    {
                        procinCPU2 = supprimer(list);
                        etatCPU2 = 1;
                        fprintf(handler,"T = %d : %c est elu dans le CPU 2\n",t,procinCPU2.code);
                    }
                    else
                    {
                        if (etatCPU1 == 1 && etatCPU2 == 1)
                        {
                            if (procinCPU1.schedule[0] >= procinCPU2.schedule[0])
                            {
                                if (list->first->schedule[0] < procinCPU1.schedule[0])
                                {
                                    fprintf(handler,"T = %d : %c est requisitionné du cpu1\n",t,procinCPU1.code);

                                    insereenfin(ready,procinCPU1);
                                    procinCPU1=supprimer(list);
                                    fprintf(handler,"T = %d : %c est elu dans le CPU 1\n",t,procinCPU1.code);
                                }
                            }
                            if(procinCPU1.schedule[0] < procinCPU2.schedule[0])
                            {
                                if (list->first->schedule[0] < procinCPU2.schedule[0])
                                {
                                    fprintf(handler,"T = %d : %c est requisitionné du cpu2\n",t,procinCPU2.code);
                                    insereenfin(ready,procinCPU2);
                                    procinCPU2=supprimer(list);
                                    fprintf(handler,"T = %d : %c est elu dans le CPU 2\n",t,procinCPU2.code);
                                }
                            }
                        }
                    }
                }
            }
        }






        if ( etatIO == 1 )
        {

            if (procinIO.schedule[0]==0)
            {
                int i;
                for(i=0; i<procinIO.length; i++)
                {
                    procinIO.schedule[i] = procinIO.schedule[i+1];
                }
                procinIO.length --;

                if (procinIO.length==0)
                {

                    fprintf(handler,"T = %d : %c a termine\n",t,procinIO.code);
                    insereenfin(done,procinIO);

                    etatIO = 0;
                }
                else
                {
                    if (etatCPU1 == 0)
                    {
                        fprintf(handler,"T = %d : %c est elu dans le CPU 1\n",t,procinIO.code);
                        procinCPU1 = procinIO;

                        etatCPU1 = 1;
                        etatIO= 0;
                    }
                    else if (etatCPU2 == 0)
                    {
                        fprintf(handler,"T = %d : %c est elu dans le CPU 2\n",t,procinIO.code);
                        procinCPU2 = procinIO;

                        etatCPU2 = 1;
                        etatIO= 0;
                    }
                    else
                    {
                        fprintf(handler,"T = %d : %c est pret\n",t,procinIO.code);
                        insereenfin(ready,procinCPU1);
                        etatIO= 0;
                    }
                }
            }
        }

        if(etatIO==0 && block->taille!=0)
        {
            etatIO=1;
            procinIO = supprimer(block);
            fprintf(handler,"T = %d : %c passe a e/s\n",t,procinIO.code);
        }
        if ( etatCPU1==1 )
        {
            if (procinCPU1.schedule[0]==0)
            {
                int i;
                for(i=0; i<procinCPU1.length; i++)
                {
                    procinCPU1.schedule[i] = procinCPU1.schedule[i+1];
                }
                procinCPU1.length --;

                if (procinCPU1.length==0)
                {
                    fprintf(handler,"T = %d : %c a termine\n",t,procinCPU1.code);
                    insereenfin(done,procinCPU1);
                    etatCPU1 = 0;
                }
                else
                {
                    if (etatIO == 0)
                    {
                        fprintf(handler,"T = %d : %c passe en E/S\n",t,procinCPU1.code);
                        procinIO = procinCPU1;
                        etatIO = 1;
                        etatCPU1= 0;
                    }
                    else
                    {
                        fprintf(handler,"T = %d : %c est bloque\n",t,procinCPU1.code);
                        insereenfin(block,procinCPU1);
                        etatCPU1= 0;
                    }
                }
            }
        }


        if ( etatCPU2==1 )
        {

            if (procinCPU2.schedule[0]==0)
            {
                int i;
                for(i=0; i<procinCPU2.length; i++)
                {
                    procinCPU2.schedule[i] = procinCPU2.schedule[i+1];
                }
                procinCPU2.length --;

                if (procinCPU2.length==0)
                {
                    fprintf(handler,"T = %d : %c a termine\n",t,procinCPU2.code);
                    insereenfin(done,procinCPU2);
                    etatCPU2 = 0;
                }
                else
                {
                    if (etatIO == 0)
                    {
                        fprintf(handler,"T = %d : %c passe en E/S\n",t,procinCPU2.code);
                        procinIO = procinCPU2;
                        etatIO = 1;
                        etatCPU2= 0;
                    }
                    else
                    {
                        fprintf(handler,"T = %d : %c est bloque\n",t,procinCPU2.code);
                        insereenfin(block,procinCPU2);
                        etatCPU2= 0;
                    }
                }
            }
        }


        if(etatCPU1==0 && ready->taille!=0)
        {
            etatCPU1 = 1;
            procinCPU1 = supprimer(ready);           // Le Processus vien d'etre elu dans le CPU1
            fprintf(handler,"T = %d : %c est elu CPU 1\n",t,procinCPU1.code);
        }
        if(etatCPU2==0 && ready->taille!=0)
        {
            etatCPU2 = 1;
            procinCPU2 = supprimer(ready);           // Le Processus vien d'etre elu dans le CPU1
            fprintf(handler,"T = %d : %c sera elu dans CPU2\n",t,procinCPU2.code);
        }
        if (list->taille>0)
        {

            for(parcours=list->first; parcours!=NULL; parcours=parcours->next)
            {
                if (t==parcours->AT)
                {
                    if (etatCPU1 == 0 && ready->taille == 0)
                    {
                        procinCPU1 = supprimer(list);
                        etatCPU1 = 1;
                        fprintf(handler,"T = %d : %c est elu dans le CPU 1\n",t,procinCPU1.code);
                    }
                    else if (etatCPU2 == 0 && ready->taille == 0)
                    {
                        procinCPU2 = supprimer(list);
                        etatCPU2 = 1;
                        fprintf(handler,"T = %d : %c est elu dans le CPU 2\n",t,procinCPU2.code);
                    }
                    else
                    {
                        if (etatCPU1 == 1 && etatCPU2 == 1)
                        {
                            insereenfin(ready,supprimer(list));
                            fprintf(handler,"T = %d : %c est pret \n",t,parcours->code);
                        }
                    }
                }
            }
        }

        JOBsort(ready);

        textcolor(BLUE);
        if (ready->taille > 0)
        {
            par = ready->first;
            while(par!=NULL)
            {
                if (par == ready->first)
                {
                    printf("    %c  =   ",par->code);
                    cprintf("PRET       ");
                    printf("|");
                }
                else
                {
                    if(par->lewel == 1)
                    {
                        printf("    %c  =   ",par->code);
                        cprintf("PRET       ");
                        printf("|");
                    }
                    par->lewel = 1;
                }
                par = par->next;
            }
        }
        textcolor(RED);
        if(block->first!=NULL)
        {
            printf("    %c  =  ",block->first->code,t);
            cprintf("BLOQUE      ");
            printf("|");
            if(block->last!=block->first)
            {
                printf("    %c  =  ",block->first->code,t);
                cprintf("BLOQUE      ");
                printf("|");
            }


        }
        if (etatIO == 1 && procinIO.schedule[0] > 0)
        {
            textcolor(YELLOW);
            printf("    %c  =  ",procinIO.code);
            cprintf("E/S         ");
            printf("|");
            procinIO.schedule[0]--;
        }

        if (etatCPU1 == 1 && procinCPU1.schedule[0] > 0)
        {
            textcolor(GREEN);
            printf("    %c  =  ",procinCPU1.code);
            cprintf("ELU  (CPU1) ");
            printf("|");
            procinCPU1.schedule[0]--;
        }


        if (etatCPU2 == 1 && procinCPU2.schedule[0] > 0)
        {
            textcolor(GREEN);
            printf("    %c  =  ",procinCPU2.code);
            cprintf("ELU  (CPU2) ");
            printf("|");
            procinCPU2.schedule[0]--;
        }
        printf("\n\n------------------------------------------------------------------------------------------------------------------------------------------\n");
        t++;
    }
    fclose(handler);
}

void REQ(liste *list)
{
    int nbr; // nombre de processus dans la liste
    int i=0; //temps
    int etatCPU1 = 0;
    int  etatCPU2 = 0;
    int etatIO = 0;
    int t=0,pret=0;
    int cpt = 0;
    int plus1=0;
    int plus2=0;
    int bool1=0,bool2=0;
    proc *ptr;
    FILE * handler = fopen("fileREQ.txt","wt");
    proc *parcours=NULL;
    proc *par=NULL;
    proc procinCPU1 , procinCPU2, procinIO;
    liste *ready =(liste*)malloc(sizeof(liste));
    liste *block =(liste*)malloc(sizeof(liste));
    liste *done =(liste*)malloc(sizeof(liste));
    initialiser_proc(&procinCPU1);
    initialiser_proc(&procinCPU2);
    initialiser_proc(&procinIO);
    initialisation(ready);
    initialisation(block);
    initialisation(done);
    nbr = list->taille ;
    while(done->taille != nbr)
    {
        printf("    T = %2d :    ",t);
        if (list->taille>0)
        {

            for(parcours=list->first; parcours!=NULL; parcours=parcours->next)
            {
                if (t==parcours->AT)
                {
                    if (etatCPU1 == 0 && ready->taille == 0)
                    {
                        procinCPU1 = supprimer(list);
                        etatCPU1 = 1;
                        fprintf(handler,"T = %d : P%d est elu dans le CPU 1\n",t,procinCPU1.code);
                    }
                    else if (etatCPU2 == 0 && ready->taille == 0)
                    {
                        procinCPU2 = supprimer(list);
                        etatCPU2 = 1;
                        fprintf(handler,"T = %d : P%d est elu dans le CPU 2\n",t,procinCPU2.code);
                    }
                    else
                    {
                        if (etatCPU1 == 1 && etatCPU2 == 1)
                        {
                            insereenfin(ready,supprimer(list));
                            fprintf(handler,"T = %d : P%d est pret \n",t,parcours->code);
                        }
                    }
                }
            }
        }




        if ( etatIO == 1 )
        {
            if (procinIO.schedule[0]==0)
            {
                int i;
                for(i=0; i<procinIO.length; i++)
                {
                    procinIO.schedule[i] = procinIO.schedule[i+1];
                }
                procinIO.length --;

                if (procinIO.length==0)
                {

                    fprintf(handler,"T = %d : %c a termine\n",t,procinIO.code);
                    insereenfin(done,procinIO);
                    etatIO = 0;
                }
                else
                {
                    if (etatCPU1 == 0 && ready->taille == 0)
                    {
                        fprintf(handler,"T = %d : %c est elu dans le CPU 1\n",t,procinIO.code);
                        procinCPU1 = procinIO;
                        etatCPU1 = 1;
                        etatIO= 0;
                    }
                    else if (etatCPU2 == 0 && ready->taille == 0)
                    {
                        fprintf(handler,"T = %d : %c est elu dans le CPU 2\n",t,procinIO.code);
                        procinCPU2 = procinIO;
                        etatCPU2 = 1;
                        etatIO= 0;
                    }
                    else
                    {
                        fprintf(handler,"T = %d : %c est pret\n",t,procinIO.code);
                        insereenfin(ready,procinCPU1);
                        etatIO= 0;
                    }
                }
            }
        }
        if ( etatCPU1==1 )
        {
            if (procinCPU1.schedule[0]==0)
            {
                int i;
                for(i=0; i<procinCPU1.length; i++)
                {
                    procinCPU1.schedule[i] = procinCPU1.schedule[i+1];
                }
                procinCPU1.length --;

                if (procinCPU1.length==0)
                {
                    fprintf(handler,"T = %d : %c a termine\n",t,procinCPU1.code);
                    insereenfin(done,procinCPU1);
                    etatCPU1 = 0;
                      bool1=1;
                }
                else
                {
                    if (etatIO == 0 && block->taille == 0)
                    {

                        fprintf(handler,"T = %d : %c passe en E/S\n",t,procinCPU1.code);
                        procinIO = procinCPU1;
                        etatIO = 1;
                        etatCPU1= 0;
                          bool1=1;
                    }
                    else
                    {
                        fprintf(handler,"T = %d : %c est bloque\n",t,procinCPU1.code);
                        insereenfin(block,procinCPU1);
                        etatCPU1= 0;
                        bool1=1;
                    }
                }
            }
            if(procinCPU1.exe == 3 && ready->taille > 0 && bool1!=1)
            {
                fprintf(handler,"T = %d  %c requisitionne apres 3\n",t,procinCPU1);
                procinCPU2.exe=0;
                insereenfin(ready,procinCPU1);
                procinCPU1=supprimer(ready);
                fprintf(handler,"T = %d  %c est elu\n",t,procinCPU1);
            }
        }

        if ( etatCPU2==1 )
        {

            if (procinCPU2.schedule[0]==0)
            {
                int i;
                for(i=0; i<procinCPU2.length; i++)
                {
                    procinCPU2.schedule[i] = procinCPU2.schedule[i+1];
                }
                procinCPU2.length --;

                if (procinCPU2.length==0)
                {
                    fprintf(handler,"T = %d : %c a termine\n",t,procinCPU2.code);
                    insereenfin(done,procinCPU2);
                    etatCPU2 = 0;
                    bool2=1;
                }
                else
                {
                    if (etatIO == 0 && block->taille == 0)
                    {
                        fprintf(handler,"T = %d : %c passe en E/S\n",t,procinCPU2.code);
                        procinIO = procinCPU2;
                        etatIO = 1;
                        etatCPU2= 0;
                        bool2=1;
                    }
                    else
                    {
                        fprintf(handler,"T = %d : %c est bloque\n",t,procinCPU2.code);
                        insereenfin(block,procinCPU2);
                        etatCPU2= 0;
                        bool2=1;
                    }
                }
            }
            if(procinCPU2.exe == 3 && ready->taille > 0 && bool2!=1)
            {

                fprintf(handler,"T = %d  %c requisitionne apres 3\n",t,procinCPU2);
                procinCPU2.exe=0;
                insereenfin(ready,procinCPU2);
                procinCPU2=supprimer(ready);
                fprintf(handler,"T = %d  %c est elu\n",t,procinCPU2);
            }

        }
        if(etatIO==0 && block->taille > 0)
        {
            etatIO=1;
            procinIO = supprimer(block);
            fprintf(handler,"T = %d : %c passe a e/s\n",t,procinIO.code);

        }
        if(etatCPU1==0 && ready->taille > 0)
        {
            etatCPU1 = 1;
            procinCPU1 = supprimer(ready);
            fprintf(handler,"T = %d : %c est elu CPU 1\n",t,procinCPU1.code);
        }
        if(etatCPU2==0 && ready->taille > 0)
        {
            etatCPU2 = 1;
            procinCPU2 = supprimer(ready);
            fprintf(handler,"T = %d : %c est elu CPU 2\n",t,procinCPU2.code);
        }
        if (list->taille>0)
        {

            for(parcours=list->first; parcours!=NULL; parcours=parcours->next)
            {
                if (t==parcours->AT)
                {
                    if (etatCPU1 == 0 && ready->taille == 0)
                    {
                        procinCPU1 = supprimer(list);
                        etatCPU1 = 1;
                        fprintf(handler,"T = %d : %c est elu dans le CPU 1\n",t,procinCPU1.code);
                    }
                    else if (etatCPU2 == 0 && ready->taille == 0)
                    {
                        procinCPU2 = supprimer(list);
                        etatCPU2 = 1;
                        fprintf(handler,"T = %d : %c est elu dans le CPU 2\n",t,procinCPU2.code);
                    }
                    else
                    {
                        if (etatCPU1 == 1 && etatCPU2 == 1)
                        {
                            insereenfin(ready,supprimer(list));
                            fprintf(handler,"T = %d : %c est pret \n",t,parcours->code);
                        }
                    }
                }
            }
        }
        //PRIOsort(list);
        textcolor(BLUE);
        if (ready->taille > 0)
        {
            par = ready->first;
            while(par!=NULL)
            {
                if (par == ready->first)
                {
                    printf("    %c  =   ",par->code);
                    cprintf("PRET       ");
                    printf("|");
                }
                else
                {
                    if(par->lewel == 1)
                    {
                        printf("    %c  =   ",par->code);
                        cprintf("PRET       ");
                        printf("|");
                    }
                    par->lewel = 1;
                }
                par = par->next;
            }
        }

        textcolor(RED);
        if(block->first!=NULL)
        {
            printf("    %c  =  ",block->first->code,t);
            cprintf("BLOQUE      ");
            printf("|");
            if(block->last!=block->first)
            {
                printf("    %c  =  ",block->last->code,t);
                cprintf("BLOQUE      ");
                printf("|");
            }


        }

        if (etatIO == 1 && procinIO.schedule[0] > 0)
        {
            textcolor(YELLOW);
            printf("    %c  =  ",procinIO.code);
            cprintf("E/S         ");
            printf("|");
            procinIO.schedule[0]--;
        }
        if (etatCPU1 == 1 && procinCPU1.schedule[0] > 0)
        {
            textcolor(GREEN);
            printf("    %c  =  ",procinCPU1.code);
            cprintf("ELU  (CPU1) ");
            printf("|");
            procinCPU1.schedule[0]--;
            procinCPU1.exe++;
        }

        if (etatCPU2 == 1 && procinCPU2.schedule[0] > 0)
        {
            textcolor(GREEN);
            printf("    %c  =  ",procinCPU2.code);
            cprintf("ELU  (CPU2) ");
            printf("|");
            procinCPU2.schedule[0]--;
            procinCPU2.exe++;
        }


        bool1=0;bool2=0;
        printf("\n\n------------------------------------------------------------------------------------------------------------------------------------------\n");
        t++;
    }
    fclose(handler);
}
