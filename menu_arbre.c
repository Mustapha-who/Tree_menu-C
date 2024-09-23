#include <stdio.h>
#include <stdlib.h>

typedef struct noeud
{
    int val;
    struct noeud* suiv;
    struct noeud* prec;
    

}noeud;
typedef noeud* liste;


//===================================================================================================//



liste remplir(liste tete,int x)  //remplir un liste doublement chainer
{
   
liste nvl;
  
    nvl=(struct noeud*)malloc(sizeof(struct noeud));
    nvl->val=x;
    nvl->suiv=NULL;
         

     if(tete==NULL) 
    {
    nvl->prec=NULL;
    return nvl;
    }

    else
    {
        liste tmp;
        tmp=tete;
        
        while(tmp->suiv!=NULL)
        {
            tmp=tmp->suiv;    
        }

            tmp->suiv=nvl;
            nvl->prec=tmp;
            return(tete);   
    }
}

//===================================================================================================//

liste ajout_debut(liste nvl,int k) // ajouter un valeur au debut de la liste
{
    liste tmp;

    tmp=nvl;
    nvl=(struct noeud*)malloc(sizeof(struct noeud));
    nvl->val=k;
    nvl->prec=NULL;
    nvl->suiv=tmp;
    tmp->prec=nvl;
    
return(nvl);
}



//===================================================================================================//


liste ajout_fin(liste nvl,int k) // ajouter un valeur au fin de la liste
{
 liste tmp;
 liste deb;
 deb=nvl;
 while (nvl->suiv!=NULL)
 {
    nvl=nvl->suiv;
 }

   tmp=nvl;
   nvl=(struct noeud*)malloc(sizeof(struct noeud));
    nvl->val=k;
   nvl->suiv=NULL;
   nvl->prec=tmp;
   tmp->suiv=nvl;

   nvl=deb;// zidtt hadhi 5atr il pointure fillkkherr donc wallit istahfdht bil (nvl) fil (deb) bich najem nrj3 il pointure miloul 

    return(nvl);
}



//===================================================================================================//

liste supprime_tete(liste tete) //supprimer un valeur au debut de la liste 
{
    liste temp;

    temp=tete;
    
    tete=tete->suiv;
    tete->prec=NULL;
    free(temp);
return (tete);
}



//===================================================================================================//

liste supprime_fin(liste tete) //supprimer un valeur au fin de la liste 
{
    liste tmp;
    liste deb;
    deb=tete;
    
while (tete->suiv!=NULL)
{
    tete=tete->suiv;
}
    tmp=tete->prec;
    
    tmp->suiv=NULL;
    free(tete);

    tmp=deb;// zidtt hadhi 5atr il pointure fillkkherr donc wallit istahfdht bil (tete) fil (deb) bich najem nrj3 il pointure miloul 

return (tmp);
}



//===================================================================================================//

liste recherche(liste tete,int c)// recherche d'une valeur 
{ 
    liste nvl;
    int i;
    i=0;
    nvl=tete;
 while (nvl!=NULL)
    {
        if (nvl->val==c)
        {
            i=i+1;

        }
        nvl=nvl->suiv;
    }
    
  

    if (i!=0)
    {
        printf("the number: %i got repeated: %i time",c,i);
    }
    else 
      {
        printf("this number does not existe");
      }
}



//===================================================================================================//


void affichage(liste nvl){  // affichage

int i;

while (nvl->suiv!=NULL) {                 
    printf("%i || ",nvl->val);
    nvl=nvl->suiv;
}
printf("%i || ",nvl->val);  // yousel lilkherrr w mayfichiagge donc zeddt il starr hadha
}



//===================================================================================================//


void affichage_inverse(liste nvl){  // affichage de sense inverse


while (nvl->suiv!=NULL) 
{
    nvl=nvl->suiv;
}

while (nvl->prec!=NULL) {                 
    printf("%i || ",nvl->val);
    nvl=nvl->prec;
}
printf("%i || ",nvl->val);  // yousel lilkherrr w mayfichiagge donc zeddt il starr hadha bich yaffichi a5rerr valeur
}




//===================================================================================================//
//===================================================================================================//

int main()
{  
     
    int k,i,c;
     liste tete;
     liste nvl;
    int x;
    char y;
    tete=NULL;

    do
    {
    printf("\n\n");
    printf("1/ remplir ton liste doublement chainer \n");
    printf("2/ ajouter un valeur au debut de la liste\n");
    printf("3/ ajouter un valeur au fin de la liste\n");
    printf("4/ supprimer un valeur au debut de la liste\n");
    printf("5/ supprimer un valeur au fin de la liste\n");
    printf("6/ recherche un valeur d'un liste doublement chainer\n");
    printf("7/ affiche la liste doublement chainer\n");
    printf("8/ affiche la liste doublement chainer de sense inverse\n");
    printf("9/ EXIT\n");
     scanf("%i",&x);


    if (x==1)
    {
       for (int i=0;i<3;i++)
    {
        printf("donner une valeur a inserer");
        scanf("%d",&k);
        tete=remplir(tete,k);
    }

    }

    else if(x==2)
    {
        nvl=tete; // bich yarj3 il pointure il awel il liste makench yabda ye7seb milkherrr or tnajem t7ot tete f 3oudh nvl
        printf("donner un valeur que tu veux lajouter au debut de la liste: ");
        scanf("%d",&k);
        tete=ajout_debut(nvl,k);

    }

    else if(x==3)
    {
        nvl=tete; // bich yarj3 il pointure il awel il liste makench yabda ye7seb milkherrr or tnajem t7ot tete f 3oudh nvl
        printf("donner un valeur que tu veux lajouter au fin de la liste: ");
        scanf("%d",&k);
        tete=ajout_fin(nvl,k);
    }


    else if(x==4)
    {
        tete=supprime_tete(tete);
    }
   

    else if(x==5)
    {
    tete=supprime_fin(tete);    
    }


    else if(x==6)
    {
        printf("donner le number que tu veux le recherche");
        scanf("%i",&c);
        recherche(tete,c);
    }
     else if(x==7)
    {
        nvl=tete; // bich yarj3 il pointure il awel il liste makench yabda ye7seb milkherrr or tnajem t7ot tete f 3oudh nvl
        affichage(nvl);
    }

    else if(x==8)
    {
        nvl=tete; // bich yarj3 il pointure il awel il liste makench yabda ye7seb milkherrr or tnajem t7ot tete f 3oudh nvl
        affichage_inverse(nvl);
    }

    
     else if(x==9)
    {
        printf("you exited the program");
    }


    }while (x!=9);



}