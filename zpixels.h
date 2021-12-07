#include<stdio.h>
#include <malloc.h>
#include<math.h>
#include <string.h>
#include<error.h>
#ifndef ZPIXELS_H
#define ZPIXELS_H
#define couleur_MAX 255
 typedef struct{
 unsigned int taille;
 double d;
 struct  {unsigned int x; unsigned int y;}position;
 struct { unsigned int r; unsigned int g; unsigned int b;}couleur;
 
}zpixels;

 typedef struct {
 int largeur, hauteur;
 int rowstride;
 unsigned char * pixelbuffer;
}image;

//zpixels * creationC(unsigned int r,unsigned int g,unsigned int b);
zpixels * creationP( int x, int y, int size);
void liberation(zpixels *p);

void  initialisation(zpixels * p, int r, int g, int b, double d);
void initialisationWhite(zpixels * p);
void initialisationBlack(zpixels * p);
double lightness( const zpixels * p);
double saturation(const zpixels * p);
double distance(const zpixels * p1,const zpixels * p2);

int zpixelsProjection(const zpixels * p1, image *img); 
#endif
