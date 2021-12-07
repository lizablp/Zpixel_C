#include "zpixels.h"

/*zpixels * creationC(unsigned int red,unsigned int green,unsigned int blue){
 zpixels * zp;
 zp=(zpixels *) malloc(sizeof(zpixels));
 printf(" Couleur max : %d",couleur_MAX);
 if(red<=couleur_MAX && green<=couleur_MAX && blue<=couleur_MAX)
 {
  zp->couleur.r=red;
  zp->couleur.g=green;
  zp->couleur.b=blue;
 
  zp->taille=0;
  zp->position.x=0;
  zp->position.y=0;
 }
   else
 {
  printf("les composantes red %d\n green %d\n blue %d\n doivent être entre 0 et %d\n", red, green, blue, couleur_MAX);
 }
 return zp;
}*/
zpixels * creationP(  int size,  int x,  int y){
 zpixels * zp;
 if(size>0 && x>=0 && y>=0)
 {
  zp=malloc(sizeof(zpixels));
  zp->taille=size;
  zp->position.x=x;
  zp->position.y=y;
 }
 else
 {
  printf("Erreur, les valeurs saisies sont invalides, elles doivent être supérieures à 0");
  zp=NULL;
 }
 return zp; 
}
void initialisationWhite(zpixels * p){
 
 p->couleur.r=255;
 p->couleur.g=255;
 p->couleur.b=255;
 }
 
void initialisationBlack(zpixels * p){
 p->couleur.r=0;
 p->couleur.g=0;
 p->couleur.b=0;
}
void initialisation(zpixels * p, int red, int green, int blue, double d){
 if(red<=couleur_MAX && green<=couleur_MAX && blue<=couleur_MAX && red>0 && green>0 && blue>0)
 {
  p->couleur.r=red;
  p->couleur.g=green;
  p->couleur.b=blue;
  p->d=d; }
 else
 {
  printf("les composantes red %d\n green %d\n blue %d\n doivent être entre 0 et %d\n", red, green, blue, couleur_MAX);
 }
}

double lightness(const zpixels * p){
 double max;
 double min;
 max=(p->couleur.r > p->couleur.g)? p->couleur.r : p->couleur.g;
 max=(p->couleur.b > max)? p->couleur.b : max;
 
 min=(p->couleur.r < p->couleur.g)? p->couleur.r : p->couleur.g;
 min=(p->couleur.b < min)? p->couleur.b : min;
 return ((max) + (min))/2;
}

double saturation(const zpixels * p){
 double sat=0.0;
 double max;
 double min;
 max=(p->couleur.r > p->couleur.g)? p->couleur.r : p->couleur.g;
 max=(p->couleur.b > max)? p->couleur.b : max;
 
 min=(p->couleur.r < p->couleur.g)? p->couleur.r : p->couleur.g;
 min=(p->couleur.b < min)? p->couleur.b : min;
 
 double light=lightness(p);
 if(light<128)
 {
  sat=255*((max-min)/(max+min));
 }
 else
 {
  sat=255*((max-min)/(511-(max+min)));
 }
 return sat;
}
double distance(const zpixels * p1,const zpixels * p2){
    
    double red=0;
    double green=0;
    double blue=0;
    red=(p1->couleur.r-p2->couleur.r)*(p1->couleur.r-p2->couleur.r);
    green=(p1->couleur.g-p2->couleur.g)*(p1->couleur.g-p2->couleur.g);
    blue=(p1->couleur.b-p2->couleur.b)*(p1->couleur.b-p2->couleur.b);
    
    return sqrt(red+green+blue);
}

int zpixelsProjection(const zpixels * p1, image *img)
{
    int nbpixels=0;
    int x=0,y=0,index=0;
   if(((p1->position.x)+(p1->taille))>(img->largeur))
    {
        printf("le zpixels deborde sur l'axe des x\n");
        return 0;
    }
    else
    {
        if(((p1->position.y)+(p1->taille))>(img->hauteur))
        {
            printf("le zpixels deborde sur l'axe des y\n");
            return 0;
        }
        else
        {
            if((p1->taille*3)>(img->rowstride))
            {
                printf("zpixel trop grand\n");
                return 0;
            }
        }
    } 
   
    while(y<p1->position.y+p1->taille)
    {
        x=p1->position.x;
        while(x<p1->position.x+p1->taille)
        {   
            index=x*3+(y*img->rowstride);
            img->pixelbuffer[index]=(p1->couleur.r);
            img->pixelbuffer[index+1]=(p1->couleur.g);
            img->pixelbuffer[index+2]=(p1->couleur.b);
            x++;
            nbpixels++;
        }
    y++;
    }
    return nbpixels;
    
}

void liberation(zpixels *p)
{
    free(p);
    
}
 
  
  

 
 
 
 
