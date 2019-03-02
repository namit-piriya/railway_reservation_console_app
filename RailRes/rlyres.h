#ifndef RLYRES_H_INCLUDED
#define RLYRES_H_INCLUDED
#include<stdio.h>
struct Train
{
    char train_no[10];
    char from[10];
    char to[10];
    int fac_fare;
    int sac_fare;
};
struct Passenger
{
    char p_name[20];
    char gender;
    char mob_no[10];
    int age;
    char train_no[10];
    char p_class;
    int ticketno;
};

typedef struct Train Train;
typedef struct Passenger Passenger;

void add_trains();
int enterchoice();
void view_trains();
int check_train_no(char*);
int check_mob_no(char*);
Passenger* get_pass_details();
int chk_seat(char*,char);
int tkt_no();
int book_ticket(Passenger);
void search_tkt();
void view_tkt();
void view_bkng();
void view_trn_bkng();
void cancel_tkt();
void cancel_trn();
#endif // RLYRES_H_INCLUDED
