
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



double get_elem(double** matr, int row, int col)
{
	return matr[row][col];
}
void set_elem(double** matr, int row, int col, double elem)
{
	matr[row][col]=elem;
}
void NormMatr(double** matr,int row,int col)
{
	double* arr = (double*)malloc(col*sizeof(double*));
	for(int i=0;i<col;i++){
		arr[i]=0;
		for(int j=0;j<row;j++){
			arr[i]+=get_elem(matr,j,i);
		}

	}
	double norma=arr[0];
	for(int i=1;i<col;i++)
	{
		if(norma<arr[i])norma=arr[i];
	}

	printf("Norma=   %lf" ,norma);
	free(arr);
}
double** FillMass(double** mass,FILE* ptrfile,int* row,int* col,int* num)
{
	fscanf(ptrfile, "%d%d%d", &(*row), &(*col), &(*num));
	if(*row>0 && *col>0 ){
		mass=(double**)realloc((void *) mass,(*row)*sizeof(double*));
		for(int i=0;i<*row;i++)
		{
			mass[i]=(double*)malloc((*col)*sizeof(double));
			for(int j=0;j<*col;j++){
				mass[i][j]=0;}
		}
	}
	else {
		printf("Uncorrect row/col/nulldata in file!\n");
		return NULL;
	}
	double key;
	int row1, col1;
	int count=0;
	while( !feof(ptrfile) )
	{

		fscanf(ptrfile, "%d%d%lf", &row1, &col1, &key);
		if(row1<=*row && col1<=*col){
			set_elem(mass,row1,col1,key);
		}
		else{
			printf("Indexes are not correct \n");
			return NULL;
		}
		count++;
		//звщита от большего кол-ва записей, чем указано в шапке
		if(count>=(*row)*(*col)) {
			printf("Incorrect file contents:\n");
			printf("Incorrect number of records\n");
			mass=NULL;
			return NULL;
		}
	}

	//проверка массивчика
	for(int i=0;i<*row;i++){
		for(int j=0;j<*col;j++){
			printf("   %lf" ,get_elem(mass,i,j));
		}
		printf("\n" );
	}

	return mass;


}
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
