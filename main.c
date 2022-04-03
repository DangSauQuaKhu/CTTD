#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void tachtu(char *a, char *b[], int *stt)
{
 int d = *stt;
char *p;
p = strtok(a, ",) (");
while(p != NULL&&(int)p[0]!=13)
{

b[d] = (char*) malloc(255*sizeof(char));
if((int)p[strlen(p)-1]==13) p[strlen(p)-1]='\0';
strcpy(b[d],p);
d++;
p = strtok(NULL, ",) (");

}

*stt = d;
}
void loc(char *a[],int b[], int n)
{
   int i;
   for(i=1; i<n; i++)

        if((int)a[i][0]<97&& a[i-1][strlen(a[i-1])-1] !='.')
        b[i]=1;

    for(i=0; i<n; i++)

       { if( a[i][strlen(a[i])-1] =='.')
         a[i][strlen(a[i])-1] ='\0';

        }



}
void loc_trung(char *a[], char *b[], int n, int *d, int c[])
{
    int i;
    int h=0;
    int m;
      for(m=0; m<strlen(a[0]);m++)
       a[0][m]=tolower(a[0][m]);
       b[h] = (char*) malloc(255*sizeof(char));
       strcpy(b[h],a[0]);
        h++;
    for(i=1; i<n; i++)
    if(c[i]!=1)
    {
    {
      for(m=0; m<strlen(a[i]);m++)
       a[i][m]=tolower(a[i][m]);
      int j,k=0;
      for(j=0; j<i;j++)
      {
         if(strcmp(a[i],a[j])==0) {k=1; break;}
      }
      if(k==0)
      {
       b[h] = (char*) malloc(255*sizeof(char));
       strcpy(b[h],a[i]);
        h++;
      }
    }
    }
    *d=h;
}
int main()
{
    FILE *input1, *input2;
    input1 = fopen("vanban.txt","r+");
    input2 = fopen("stopw.txt","r+");
    char tachdong[255][255];
    char dong[255][255];
    char **word= (char **)malloc(100000*sizeof(char*));
    char **word2= (char **)malloc(100000*sizeof(char*));
    char **stop_word= (char **)malloc(100000*sizeof(char*));
    int dem_dong=0;
    int b[1000];
    while(!feof(input1))
    {
            fgets(tachdong[dem_dong], 255, input1);
            if((int)tachdong[dem_dong][strlen(tachdong[dem_dong])-1]==10) tachdong[dem_dong][strlen(tachdong[dem_dong])-1]='\0';
            strcpy(dong[dem_dong],tachdong[dem_dong]);
            int m ;
            for(m=0; m<strlen(dong[dem_dong]); m++)
             dong[dem_dong][m]=tolower(dong[dem_dong][m]);

            dem_dong++;

    }
    fclose(input1);
    int dem_stop=0;
    if(input2==NULL)
    printf("loi\n");
    while(!feof(input2))
    {
            stop_word[dem_stop] = (char*) malloc(255*sizeof(char));
            fscanf(input2,"%s",stop_word[dem_stop]);
            dem_stop++;
    }

    fclose(input2);
    int dem_tu=0;
    int i;
    for(i=0; i<dem_dong; i++)
    {
        tachtu(tachdong[i], word, &dem_tu);
    }
    loc(word,b,dem_tu);




     int demtu2=0;
    loc_trung(word,word2,dem_tu,&demtu2,b);

    for(i=0; i< demtu2; i++)
    {
        int j;
       for(j=0; j< demtu2; j++)
       if(strcmp(word2[i],word2[j])<0)
       {
         char hoanvi[255];
         strcpy(hoanvi,word2[i]);
         strcpy(word2[i], word2[j]);
         strcpy(word2[j], hoanvi);
       }
    }
    int c[1000];
    for(i=0; i< demtu2; i++)
    {
        int j=0;
        for(; j<dem_stop; j++)
        if(strcmp(word2[i],stop_word[j])==0) {c[i]=1; break;}
    }
    int dem=0;
    printf("%-3s %-15s %-7s %s\n","STT", "word","So lan","Vi tri" );
   for(i=0; i< demtu2; i++)
     {
        if(c[i]!=1)
        {
        printf("%-3d %-15s ",++dem, word2[i]);
        int j;
        int day[1000], solg=0;
        for(j=0; j<dem_dong; j++)
        {
          int h;
          int ok=0;
          for(h=0; h<strlen(dong[j]);h++)
           if(dong[j][h]==word2[i][0] && (h==0 || isalpha(dong[j][h-1])==0))
           {
             int k=0;
             int dd=0;
             for(k=0;k<strlen(word2[i]);k++)
             {
                if( word2[i][k]!= dong[j][k+h]) {dd=1; break;}
             }

             if(dd==0 && isalpha(dong[j][h+k])==0) {ok=1; break;}
           }
          if(ok==1) {day[solg]=j+1; solg++;}

        }
        printf(" %-7d %d", solg,day[0]);
        for(j=1; j<solg;j++)
        {
            printf(",%d",day[j]);
        }
        printf("\n");
        }
     }




}
