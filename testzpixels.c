#include "zpixels.h"

int main(void){
	int compteur =0;
	double d=0;
	double light=0;
 double sat=0;
 double dist=0;
	unsigned int red, green, blue, x, y, size;
	red=113;
	green=168;
	blue=247;
	x=123;
	y=1;
	size=3;
	
	int x2=2;
	int y2=0;
	int size2=2;
	zpixels * zpc;
	zpixels * zpp;
	zpixels * zpp2;
	
	zpc = creationP(size,x,y);
	
	printf("Test 01.0 :Fonction creation\n input : x=%d\n y=%d\n size=%d\n Expected output : x=%d\n y=%d\n size=%d\n output: axe des x :%d\naxe des y :%d\ntaille :%d\n",x,y,size,x,y,size,zpc->position.x,zpc->position.y,zpc->taille);
	
	printf("------------------------------------------------\n");
	
	/*zpc = creationP(-4,3,0);
	printf("Test 01.1 :Fonction creation\n input : x=%d\n y=%d\n size=%d\n Expected output : x=%d\n y=%d\n size=%d\n output: axe des x :%d\naxe des y :%d\ntaille :%d\n",3,0,-4,0,0,0,zpc->position.x,zpc->position.y,zpc->taille);*/
	
	printf("------------------------------------------------\n");
	
	zpp = creationP(size2,x2,y2);
	printf("Test 02.0 :Fonction creation\n input : x=%d\n y=%d\n size=%d\n Expected output : x=%d\n y=%d\n size=%d\n output: axe des x :%d\naxe des y :%d\ntaille :%d\n",x2,y2,size2,x2,y2,size2,zpp->position.x,zpp->position.y,zpp->taille);
	
	printf("------------------------------------------------\n");
	
/*zpp = creationP(4,-7,8);
printf("Test 02.1 :Fonction creation\n input : x=%d\n y=%d\n size=%d\n Expected output : x=%d\n y=%d\n size=%d\n output: axe des x :%d\naxe des y :%d\ntaille :%d\n",-7,8,4,0,8,4,zpp->position.x,zpp->position.y,zpp->taille);*/
	
	printf("------------------------------------------------\n");
	
	initialisationWhite(zpp);
	printf("Test 03 :Fonction initialisation blanc\n input : x=%d\n y=%d\n size=%d\n Expected output : x=%d\n y=%d\n size=%d\n r=%d\n g=%d\n b=%d\n output: axe des x :%d\naxe des y :%d\ntaille :%d\nr=%d\ng=%d\nb=%d\n",x,y,size,x,y,size,255,255,255,zpp->position.x,zpp->position.y,zpp->taille,zpp->couleur.r,zpp->couleur.g,zpp->couleur.b);
	
	printf("------------------------------------------------\n");
	
	initialisationBlack(zpc);
	printf("Test 04 :Fonction initialisation noir\n input : x=%d\n y=%d\n size=%d\n Expected output : x=%d\n y=%d\n size=%d\n r=%d\n g=%d\n b=%d\n output: axe des x :%d\naxe des y :%d\ntaille :%d\nr=%d\ng=%d\nb=%d\n",x,y,size,x,y,size,0,0,0,zpc->position.x,zpc->position.y,zpc->taille,zpc->couleur.r,zpc->couleur.g,zpc->couleur.b);
	
	printf("------------------------------------------------\n");
	
	initialisation(zpp,red,green,blue,d); 
printf("Test 05.0 :Fonction initialisation couleur\n input : x=%d\n y=%d\n size=%d\n Expected output : x=%d\n y=%d\n size=%d\n r=%d\n g=%d\n b=%d\n output: axe des x :%d\naxe des y :%d\ntaille :%d\nr=%d\ng=%d\nb=%d\n",x,y,size,x,y,size,113,168,247,zpp->position.x,zpp->position.y,zpp->taille,zpp->couleur.r,zpp->couleur.g,zpp->couleur.b);
	
	printf("------------------------------------------------\n");
		initialisation(zpc,-104,green,blue,d); 
	printf("Test 05.1 :Fonction initialisation couleur\n input : x=%d\n y=%d\n size=%d\nr=%d\ng=%d\nb=%d\n Expected output : none\n output: axe des x :%d\naxe des y :%d\ntaille :%d\nr=%d\ng=%d\nb=%d\n",x,y,size,-104,green,blue,zpc->position.x,zpc->position.y,zpc->taille,zpc->couleur.r,zpc->couleur.g,zpc->couleur.b);
	
	printf("------------------------------------------------\n");
	
			initialisation(zpc,248,green,blue,d); 
	printf("Test 05.2 :Fonction initialisation couleur\n input : x=%d\n y=%d\n size=%d\nr=%d\ng=%d\nb=%d\n Expected output : none\n output: axe des x :%d\naxe des y :%d\ntaille :%d\nr=%d\ng=%d\nb=%d\n",x,y,size,258,green,blue,zpc->position.x,zpc->position.y,zpc->taille,zpc->couleur.r,zpc->couleur.g,zpc->couleur.b);
	
	printf("------------------------------------------------\n");
	
	light=lightness(zpp);
	printf("Test 06.0 :Fonction de calcul de la luminosité\ninput: r=%d\ng=%d\nb=%d\nExpected output: %f\nOutput:%f\n",zpp->couleur.r,zpp->couleur.g,zpp->couleur.b,180.0,light);
	
	printf("------------------------------------------------\n");
	
	light=lightness(zpc);
	printf("Test 06.1 :Fonction de calcul de la luminosité\ninput: r=%d\ng=%d\nb=%d\nExpected output: %f\nOutput:%f\n",zpp->couleur.r,zpp->couleur.g,zpp->couleur.b,208.0,light);
	
	printf("------------------------------------------------\n");
	
	sat=saturation(zpp);
	printf("Test 07.0 :Fonction de calcul de la saturation\ninput: r=%d\ng=%d\nb=%d\nExpected output: %f\nOutput:%f\n",zpp->couleur.r,zpp->couleur.g,zpp->couleur.b,226.29,sat);
	
	printf("------------------------------------------------\n");
	zpp2 = creationP(3,0,0);
	initialisation(zpp2,156,95,13,d);
	sat=saturation(zpp2);
	
	printf("Test 07.1:Fonction de calcul de la saturation\ninput: r=%d\ng=%d\nb=%d\nExpected output: %f\nOutput:%f\n",zpp->couleur.r,zpp->couleur.g,zpp->couleur.b,215.76,sat);
	
	printf("------------------------------------------------\n");
	
	dist=distance(zpp,zpc);
	printf("Test 08.0:Fonction de calcul de la distance\ninput:zpixel1 : r=%d\ng=%d\nb=%d\nzpixel2 : r=%d\ng=%d\nb=%d\n Expected output: %f\nOutput:%f\n",zpp->couleur.r,zpp->couleur.g,zpp->couleur.b,zpc->couleur.r,zpc->couleur.g,zpc->couleur.b,135.0,dist);
	
	printf("------------------------------------------------\n");
	
	dist=distance(zpp,zpp2);
	printf("Test 08.1:Fonction de calcul de la distance\ninput:zpixel1 : r=%d\ng=%d\nb=%d\nzpixel2 : r=%d\ng=%d\nb=%d\n Expected output: %f\nOutput:%f\n",zpp->couleur.r,zpp->couleur.g,zpp->couleur.b,zpp2->couleur.r,zpp2->couleur.g,zpp2->couleur.b,248.86,dist);
	
	printf("------------------------------------------------\n");
	/* preparation du zpixel et de l'image*/
	int index=0,j=0;
	int format[18][3];
	int i=0, projection;
	zpixels * zpp3;
	zpp3 = creationP(2,0,0);
	initialisation(zpp3,156,95,13,d);
	
	image *img;
	img = malloc(sizeof(image));
	img->largeur=3;
	img->hauteur=2;
	img->rowstride=9;
	unsigned char imgbuffer[18];
	printf("image initiale\n");
	while(i<18)
	{
	    imgbuffer[i]=i++;
	}
	img->pixelbuffer=imgbuffer;
	printf("Img : largeur %d,hauteur %d,rowstride %d \n", img->largeur, img->hauteur, img->rowstride);
 
 for (index=0,i=0;i<18;index++)
	  {
	    for(j=0;j<img->rowstride;j++)
	    {
	    format[index][j]=img->pixelbuffer[i];
	    printf("%d, ",img->pixelbuffer[i++]);
	    }
	    printf("\n");
	  }	

	/*for (i=0; i<18;i++)
	{
	    printf("%d\n",img->pixelbuffer[i]);
	}*/
	/* debut de la phase de test */
	
	projection=zpixelsProjection(zpp3,img);
	printf("Test 09.0 : Fonction d'enregistrement d'un zpixel sur un un tableau de pixels image\ninput : voir ci dessus pour l'image\n pour le zixels : x=%d\n y=%d\n size=%d\n r=%d\ng=%d\nb=%d\n Expected output : %d\n output : %d\n",zpp3->position.x, zpp3->position.y, zpp3->taille, zpp3->couleur.r, zpp3->couleur.g, zpp3->couleur.b,4,projection); 
 i=0;
	printf("image après projection\n");
		/*Creation d'un tableau a 2 dimensions pour l'affichage */
	 if(projection !=0)
  {
	  for (index=0,i=0;i<18;index++)
	  {
	    for(j=0;j<img->rowstride;j++)
	    {
	    format[index][j]=img->pixelbuffer[i];
	    printf("%d, ",img->pixelbuffer[i++]);
	    }
	    printf("\n");
	  }
	 }
	
 /*for(i=0;i<18;i+=3)
 {
				printf("%d, %d, %d\n",img->pixelbuffer[i],img->pixelbuffer[i+1],img->pixelbuffer[2]);
	}*/
	printf("------------------------------------------------\n");
	/* test avec debordement */
	index=0;
	zpixels * zpp4;
	image *img2;
	img2 = malloc(sizeof(image));
	img2->largeur=3;
	img2->hauteur=2;
	img2->rowstride=9;
	unsigned char imagebuffer[18];
	while(index<18)
	{
	    imagebuffer[index]=index++;
	}
	img2->pixelbuffer=imagebuffer;
	printf("Img : largeur %d,hauteur %d,rowstride %d \n", img2->largeur, img2->hauteur, img2->rowstride);


	/* lancement du test */
	zpp4 = creationP(2,4,0);
	initialisation(zpp4,156,95,13,d);
	projection=zpixelsProjection(zpp4,img);
	printf("Test 09.1 : Fonction d'enregistrement d'un zpixel sur un un tableau de pixels image\ninput : voir ci dessus pour l'image\n pour le zixels : x=%d\ny=%d\nsize=%d\n r=%d\ng=%d\nb=%d\nExpected output : %d\noutput : %d\n",zpp4->position.x, zpp4->position.y, zpp4->taille, zpp4->couleur.r, zpp4->couleur.g, zpp4->couleur.b,0,projection); 
	
		/*Creation d'un tableau a 2 dimensions pour l'affichage */
	 if(projection !=0)
  {
	  for (index=0,i=0;i<18;index++)
	  {
	    for(j=0;j<img->rowstride;j++)
	    {
	    format[index][j]=img->pixelbuffer[i];
	    printf("%d, ",img->pixelbuffer[i++]);
	    }
	    printf("\n");
	  }
	 }
	
	
	printf("------------------------------------------------\n");
	
	liberation(zpp);
	printf("zone mémoire libérée\n");
	printf("------------------------------------------------\n");
	
	liberation(zpc);
	printf("zone mémoire libérée\n");
		
	return 0;
}











