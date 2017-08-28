#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "file.h"

int main(int argc, char *argv[])
{
    if(argc!=3){ printf("Wrong data\n"); return -1;}

    FILE *ptrfile = fopen(argv[2], "r");
    if(ptrfile==NULL){ printf("Wrong name file\n"); return -1;}
	//FILE *ptrfile = fopen("E:\\text.txt", "r");
    int size=1;                                     //������ ����� ������� ���-��
    int* arr=(int*)malloc(size* sizeof(int));       //��������� ����� � ����� � ������� i
    arr[0]=0;

    char* token=(char*)malloc(1* sizeof(char));     //������, ������� ����� �������                                       //����� ��������� ����� �� �����
    //���� ���� ������� ������� ��� ����� ����������� � ������ ������
   /* printf("Results: ");
    int k=0;
    for(; k<size; k++)
    {  printf("%d", arr[k]);   printf(" ");}
*/
    arr=FileReader(arr, token, &size,ptrfile,argv[1]);
	//FileReader(arr, token, &size,ptrfile,"the");
    Dispers(arr, &size);
    free( arr );
   // free(token);
    fclose(ptrfile);

    return 0;
}
