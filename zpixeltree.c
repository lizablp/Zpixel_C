#include "zpixeltree.h"
#include "zpixel.h"




void construireArbreZpixel( int x, int y, int taille)
{
int r, g, b;
 if (x>taille || y>taille) return null;
 GNode * g1;
 zpixels * zp;
 zp=creationP(taille, x, y);
 initialisation(zp,254,245,235,0);
 g1=g_node_new(p1);
 
 if(taille=1)
 {
   
   initialiserZpixelNoeud(g1,pixel);
 }
 else
 {
    filsGaucheHaut=construireArbreZpixel(x,y,taille/2);
    ajouterFils(g1,filsGaucheHaut);
    
    filsDroiteHaut=construireArbreZpixel(x+taille/2,y,taille/2);
    ajouterFils(g1,filsDroiteHaut); 
    
    filsGaucheBas=construireArbreZpixel(x,y+taille/2,taille/2);
    ajouterFils(g1,filsGaucheBas); 
    
    filsDroiteBas=construireArbreZpixel(x+taille/2,y+taille/2,taille/2);
    ajouterFils(g1,filsDroiteBas);
    
    calculerCouleurEtDegradationZpixel(zp, x, y, taille);
 } 
 return g1;
} 
 
 
