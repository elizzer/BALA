#include <stdio.h>
#include <stdlib.h>
const int MAX =100;


struct time{
int hour;
int min;
int sec;
};

struct bus{
    char start_location[20];
    struct time time;
    char bus_name[20];
    int skip;
};



int f_pos=0;
int find_pos=0;

struct stack{
char start_location[20];
struct time time;
char bus_name[20];
};



void setup();
void data_entry();
void isbus(char *from, char *to);
FILE *fin,*fin1;
int main()
{
    char from[20],to[20];
    setup();
    printf("\n from:");
    gets(from);
    printf("\n to:");
    gets(to);

    if(!strcmp(from,"QQQ")&&!strcmp(to,"QQQ"))
    {
    data_entry();
    }
    fclose(fin);
    fclose(fin1);
    return 0;
}


void setup()
{   //FILE *fin,*fin1;
    fin=fopen("bus data base.txt","a+");
    fin1=fopen("next point date.txt","a+");

}

void data_entry()
{   char data[100];
    printf("\n Enter the new data:");
    gets(data);
    fputs(data,fin);
    fprintf(fin,"\n");
    fseek(fin,-sizeof(data),tell(fin));

    struct bus ptop;
    while(!eof){
        fscanf("%s",)
    }
}
