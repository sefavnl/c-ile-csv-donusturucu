#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


    void main(int argc, char* argv[]){

    char deger='*',dosyaninAdi[20];
    char dosya[5000][20];
    int virgulSayisi=0,satir=0;
    int i,j;

    printf("Dosya adi giriniz:");
    scanf("%s",dosyaninAdi);

    FILE *fp;
    fp=fopen(dosyaninAdi,"r");

    if(fp==NULL)
      {
        puts("dosya acilamadi");
        getch();
        exit(1);
      }
    while(deger!='\n')
        {
        deger=fgetc(fp);
        if(deger==',')
            {
            virgulSayisi++;
            }
        }
    rewind(fp);
     while(deger!=EOF)
     {
        deger=fgetc(fp);
        if(deger=='\n')
            satir++;
     }
     rewind(fp);
            printf("\nDonusturmek icin bir tusa basin: ");
            getch();
  printf("[\n");
        for(j=1;j<satir;j++)
            {
            printf("\t{\n");
            for(i=1;i<=virgulSayisi;i++)
                {
                if(fgetc(fp) != ',')
                {
                fscanf(fp, "%s", &dosya[i]);
                printf("\t\t\"Adres Bilgileri%d\":\"%s\",\n",i,dosya[i]);
                }
                }
             for(i=virgulSayisi+1;i<virgulSayisi+2;i++)
                {
                fscanf(fp, "%s", &dosya[i]);
                printf("\t\t\"Adres Bilgileri%d\":\"%s\"\n",i,dosya[i]);
                }
            printf("\t},\n\n");

            }
            printf("\t{\n");
            for(j=0;j<1;j++){
                for(i=1;i<=virgulSayisi;i++)
                    {
                    fscanf(fp,"%s",dosya[i]);
                    printf("\t\t\"Adres Bilgileri%d\":\"%s\",\n",i,dosya[i]);
                    }
                for(i=virgulSayisi+1;i<virgulSayisi+2;i++)
                    {
                    fscanf(fp,"%s",dosya[i]);
                    printf("\t\t\"Adres Bilgileri%d\":\"%s\"\n",i,dosya[i]);
                    }
            }
            printf("\t}\n\n");
  printf("]");
  fclose(fp);
   getch();
}
