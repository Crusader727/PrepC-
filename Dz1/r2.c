#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
void Dispers(int* arr, int* size)
{
  int  j=0;
  double middle=0;
  for(; j<*size; j++)
      middle=middle+(arr)[j];
     if(middle==0){
        printf("No such words\n");
        return;
    }
    else
        middle=middle/(*size);
  j=0;
  double disp=0;
  for(; j<*size; j++)
    disp=disp+(((arr)[j]-middle)*((arr)[j]-middle));
  disp=disp/(*size-1);
  disp=sqrt(disp);

  printf("Dispersia = %f", disp);
  printf("\n");
}

int* FileReader(int* arr, char* token, int* size, FILE* ptrfile, char arg[])
{
    int i=0;
    while( !feof(ptrfile) )
    {
        char ch[2]={'-', '\0'};
        fgets(ch, 2, ptrfile);
		 if( isspace(ch[0]) || ispunct(ch[0]) )
		 {
            token[i]='\0';
            if( !strcmp(token, arg) )
				arr[*size-1]++;
			if(ch[0]=='.' || ch[0]=='!' || ch[0]=='?')
            {
                arr=(int*)realloc(arr, sizeof(int)*(++*size));
                if(arr==NULL){
                  printf("Error with the release of memory 1. Program can't work\n");
                  return NULL;
                }

                arr[*size-1]=0;
            }
			i=0; //занулили i
			//token=(char*)realloc(token, sizeof(char)*2);
  			  free(token);
 			token=malloc(2*sizeof(char));
			token[1]='\0';
            if(token==NULL){
               printf("Error with the release of memory 2. Program can't work\n");
               return NULL;
            }
		}
		else
		{
            token=(char*)realloc(token, (strlen(token)+1)*sizeof(char)+1);
			token[strlen(token)+1]='\0';
            if(token==NULL){
                printf("Error with the release of memory 3. Program can't work\n");
                return NULL;
            }

			token[i]=ch[0];
			i++;
		}
    };
free(token);
    arr=(int *)realloc(arr,--*size*sizeof(int));
return arr;
}


int main(int argc, char *argv[])
{
    if(argc!=3){ printf("Wrong data\n"); return -1;}

    FILE *ptrfile = fopen(argv[2], "r");
    if(ptrfile==NULL){ printf("Wrong name file\n"); return -1;}
	//FILE *ptrfile = fopen("E:\\text.txt", "r");
    int size=1;                                     //массив будет хранить кол-во
    int* arr=(int*)malloc(size* sizeof(int));       //вхождений слова в абзац с номером i
    arr[0]=0;

    char* token=(char*)malloc(1* sizeof(char));     //массив, который будет хранить                                       //любое отдельное слово из файла
    //Этот блок выведет сколько раз слово встретилось в каждом абзаце
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
