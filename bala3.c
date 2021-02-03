#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX =100;

int no_bus=0;
int tos=0;

struct time{
int hour;
int min;
//int sec;
};

struct bus{
    char start_location[20];
    char end_location[20];
    struct time stime;
    struct time etime;
    char bus_name[20];
    int skip;
};

struct stack{
    char start_location[20];
    char end_location[20];
    struct time stime;
    struct time etime;
    char bus_name[20];
};

struct bus bus[100];
struct stack route[100];

void setup();
struct time set_time(int hour,int min);
void set_value(char *name,char *from, char *to, struct time stime, struct time etime);
void isbus(char *from, char *to,struct time time);
void push(struct bus pushbus);
void pop(struct bus popbus);
int match(char *from, char *to,struct time time);
int find(char *from, char *to,struct time time);

int main()
{
    char from[20],to[20];
    struct time time;
    setup();
    printf("\n from:");
    gets(from);
    printf("\n to:");
    gets(to);
    printf("\nat:");
    scanf("%d",&time.hour);
    scanf("%d",&time.min);
    isbus(from,to,time);

    int t=0;
    printf("\n Optimal solution");
    printf("\n%d ",no_bus);
    while(t<no_bus){
        /*printf("\nstart in %s ",route[t].start_location);
        printf("\nstart at %d:%d",route[t].stime.hour,route[t].stime.min);
        printf("\nstop in %s ",route[t].end_location);
        printf("\nstop at %d:%d",route[t].etime.hour,route[t].etime.min);*/

        printf("\nstart in %s ",bus[t].start_location);
        printf("\nstart at %d:%d",bus[t].stime.hour,bus[t].stime.min);
        printf("\nstop in %s ",bus[t].end_location);
        printf("\nstop at %d:%d",bus[t].etime.hour,bus[t].etime.min);
        t++;
    }

    return 0;
}

struct time set_time(int hour,int min){
 struct time time;
 time.hour=hour;
 time.min=min;
 return time;
};

void setup()
{   printf("\n in setup()");
   set_value("25c","karamadai","dayanur",set_time(5,20),set_time(5,40));
   set_value("25c","dayanur","tudiyalur",set_time(6,00),set_time(6,40));
   set_value("25c","tudiyalur","coimbatore",set_time(7,00),set_time(8,00));
   set_value("25c","coimbatore","perur",set_time(8,15),set_time(8,45));
   set_value("25c","perur","coimbatore",set_time(9,00),set_time(9,30));
   set_value("25c","tudiyalur","coimbatore",set_time(7,00),set_time(8,00));

}

void set_value(char *name,char *from, char *to, struct time stime, struct time etime){
    printf("\n in setvalue()");
    if(no_bus<100){
        strcpy(bus[no_bus].start_location,from);
        strcpy(bus[no_bus].end_location,to);
        bus[no_bus].stime=stime;
        bus[no_bus].etime=etime;
        bus[no_bus].skip=0;
        strcpy(bus[no_bus].bus_name,name);
    }
}

void isbus(char *from, char *to,struct time time){
    printf("\n in isbus()");
    char anywhere[20];
    struct bus popbus;
    if(match(from,to,time))
    {
        return ;
    }

    if(find(from,anywhere,time))
    {
        isbus(anywhere,to,time);
    }
    else if(tos>0){
        pop(popbus);
        isbus(popbus.start_location,popbus.end_location,popbus.stime);
    }

}

int match(char *from, char *to, struct time time){
    int t;
    printf("\n in match()");
    for(int t=no_bus-1;t>-1;t--)
    {
        char start_location=bus[t].start_location;
        if((!strcmp(start_location,from)&&!strcmp(bus[t].end_location,to))&&((bus->stime.hour>time.hour)&&(bus->stime.hour<time.hour-1)))
           {
           push(bus[t]);
           return 1;
           }
    }
    return 0;
}


void push(struct bus pushbus){
    printf("\n in push()");
    if(tos<MAX){
    strcpy(route[tos].bus_name,pushbus.bus_name);
    strcpy(route[tos].start_location,pushbus.start_location);
    strcpy(route[tos].end_location,pushbus.end_location);
    route[tos].stime=pushbus.stime;
    route[tos].etime=pushbus.etime;
        tos++;
    }
    else{
        printf("\n stack overflow");
    }
}

void pop(struct bus popbus){
    printf("\n in pop()");
    if(tos>0){
        tos--;
    strcpy(popbus.bus_name,route[tos].bus_name);
    strcpy(popbus.start_location,route[tos].start_location);
    strcpy(popbus.end_location,route[tos].end_location);
    popbus.stime=route[tos].stime;
    popbus.etime=route[tos].etime;

    }
}

int find(char *from, char *anywhere,struct time time){
    printf("\n in find()");
    int find_pos=0;
    while(find_pos<no_bus){
            if((!strcmp(bus[find_pos].start_location,from))&&((bus->stime.hour<time.hour)&&(bus->stime.hour+1>time.hour))&&!(bus[find_pos].skip))
           {
            strcpy(anywhere,bus[find_pos].end_location);
            time=bus[find_pos].etime;
            bus->skip=1;
            push(bus[find_pos]);
            return 1;
           }
            find_pos++;

    }
    return 0;
}
