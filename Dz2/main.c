#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matr.h"

int main(int argc, char* argv[])
{
	if(argc!=2){
		printf("Wrong data\n");
		return -1;
	}

	FILE *ptrfile = fopen(argv[1], "r");
	if(ptrfile==NULL){
		printf("Wrong name file\n");
		return -1;
	}
	double** mass;
	int row=0,col=0,num=0;
	mass=(double**) malloc(row*sizeof(double*));
	for(int i=0;i<row;i++){
		mass[i]=(double*)malloc(col*sizeof(double));
	}
	mass=FillMass(mass,ptrfile,&row, &col,&num);
	NormMatr(mass,row,col);
	fclose(ptrfile);
	for(int i=0;i<row;i++)
		free(mass[i]);
	free(mass);
	return 0;
}
