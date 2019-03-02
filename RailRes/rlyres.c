#include<stdio.h>
#include"conio2.h"
#include"rlyres.h"
#include<ctype.h>
#include<string.h>
int enterchoice()
{
    int choice;
    textcolor(YELLOW);
    gotoxy(28,1);
    printf("RAILWAY RESERVATION SYSTEM\n");
    int i;
    for(i=0;i<120;i++)
        printf("-");

    printf("\n1. View Trains\n");
    printf("2. Book Ticket\n");
    printf("3. View Ticket\n");
    printf("4. Search Ticket\n");
    printf("5. View all Bookings\n");
    printf("6. View Train Bookings\n");
    printf("7. Cancel Ticket\n");
    printf("8. Cancel Train\n");
    printf("9. Quit\n");
    printf("Enter your Choice:");
    scanf("%d",&choice);
    return choice;

}

void add_trains()
{
    Train t[]={{"100","BPL","DEL",2500,1500},
                {"200","HBJ","IND",1500,1100},
                {"300","MUM","HBJ",3000,2100},
                {"400","GUNA","USA",40000,32000}};


    FILE* fp=fopen("alltrains.dat","rb");
    if(fp==NULL)
    {
        fp=fopen("alltrains.dat","wb");
        fwrite(t,sizeof(Train),4,fp);
        fclose(fp);

    }
    else
    {
        fclose(fp);
    }

}

void view_trains()
{
    clrscr();
    FILE* fp;
    fp=fopen("alltrains.dat","rb");

    printf("\tTrain No\tFROM\tTO\tF_AC_FARE\tS_AC_FARE\n");
    int i;
    for(i=0;i<120;i++)
        printf("-");

    Train t;
    while(fread(&t,sizeof(Train),1,fp)==1)
    {
        printf("\n\t%s\t\t%s\t%s\t%d\t\t%d",t.train_no,t.from,t.to,t.fac_fare,t.sac_fare);

    }
    fclose(fp);

    getch();
}
int check_train_no(char* p)
{   Train t;
    FILE* fp = fopen("alltrains.dat","rb");
    while(fread(&t,sizeof(Train),1,fp)==1)
    {
        if(strcmp(t.train_no,p)==0)
        {   fclose(fp);
            return 1;
        }

    }
    fclose(fp);
    return 0;
}
int check_mob_no(char* m)
{
    if(strlen(m)!=10)
    {
        return 0;
    }

   while(*m!='\0')
   {
       if(isdigit(*m)==0)
       {
           return 0;
       }
       m++;
   }
    return 1;
}
Passenger* get_pass_details()
{   clrscr();
     static Passenger psn;
    gotoxy(80,1);
    textcolor(LIGHTGREEN);
    printf("Press 0 to exit");
    gotoxy(1,1);
    textcolor(YELLOW);
    printf("Enter Passenger Name :");
    fflush(stdin);
    fgets(psn.p_name,20,stdin);
    char* pos= strchr(psn.p_name,'\n');
    *pos = '\0';
    if(strcmp(psn.p_name,"0")==0)
    {
        gotoxy(1,25);
        textcolor(LIGHTRED);
        printf("Reservation cancelled");
        getch();
        return NULL;
    }

    printf("Enter Gender (M/F) :");
    while(1)
    {   textcolor(YELLOW);
        fflush(stdin);
        fgets(&psn.gender,2,stdin);
        if(strcmp(&psn.gender,"0")==0)
        {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Reservation cancelled");
            getch();
            return NULL;
        }

        if(strcmp(&psn.gender,"M")!=0 && strcmp(&psn.gender,"F")!=0 )
            {
                gotoxy(1,25);
                textcolor(LIGHTRED);
                printf("Gender Should Be Either M or F!!!");
                getch();
                gotoxy(21,2);
                printf(" ");
                gotoxy(21,2);

            }
            else
            {
                break;
            }

    }


    gotoxy(1,25);
    printf("\t\t\t\t\t");
    gotoxy(1,3);
    printf("Enter Train No. :");
    while(1)
    {   fflush(stdin);
        textcolor(YELLOW);
        fgets(psn.train_no,10,stdin);
         char* pos= strchr(psn.train_no,'\n');
        *pos = '\0';
         if(strcmp(&psn.train_no,"0")==0)
            {
                gotoxy(1,25);
                textcolor(LIGHTRED);
                printf("Reservation cancelled");
                getch();
                return NULL;
            }

        int a = check_train_no(psn.train_no);

        if(a==0)
        {
                    gotoxy(1,25);
                    textcolor(LIGHTRED);
                    printf("Invalid Train No. ");
                    getch();
                    gotoxy(18,3);
                    printf("\t\t\t\t");
                    gotoxy(18,3);


        }
        else
        {
                break;
        }
    }


    gotoxy(1,25);
    printf("\t\t\t\t\t");
    gotoxy(1,4);
    printf("Enter Reservation Class (F/S):");
     while(1)
    {
        textcolor(YELLOW);
        fflush(stdin);
        scanf("%c",&psn.p_class);

        if(strcmp(&psn.p_class,"0")==0)
        {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Reservation cancelled");
            getch();
            return NULL;
        }

        if(strcmp(&psn.p_class,"S")!=0 && strcmp(&psn.p_class,"F")!=0 )
            {
                gotoxy(1,25);
                textcolor(LIGHTRED);
                printf("Invalid Class!!!");
                getch();
                gotoxy(31,4);
                printf(" ");
                gotoxy(31,4);

            }
            else
            {
                break;
            }

    }

    gotoxy(1,25);
    printf("\t\t\t\t\t");
    gotoxy(1,5);
    printf("Enter Age:");
    while(1)
    {
        textcolor(YELLOW);
        gotoxy(11,5);
        printf("   \t\t\t");
         gotoxy(11,5);
        scanf("%d",&psn.age);
        if(psn.age<0)
        {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Enter Valid Age!!!");

        }
        if(psn.age==0)
        {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Reservation cancelled");
            return NULL;
        }

       if(psn.age>0)
        {
            break;
        }
    }


     gotoxy(1,25);
    printf("\t\t\t\t\t");
    gotoxy(1,6);
    printf("Enter Mobile No.:");
    int val;
    do
        {
            textcolor(YELLOW);
            fflush(stdin);
            fgets(psn.mob_no,11,stdin);
            char* pos1= strchr(psn.mob_no,'\n');
                if(pos1!=NULL)
                {
                    *pos1 = '\0';

                }

             if(strcmp(&psn.mob_no,"0")==0)
                {
                    gotoxy(1,25);
                    textcolor(LIGHTRED);
                    printf("Reservation cancelled");
                    getch();
                    return NULL;
                }
                 val = check_mob_no(psn.mob_no);
                if(val==0)
                {
                gotoxy(1,25);
                textcolor(LIGHTRED);
                printf("Invalid Mobile no.!!!");
                getch();
                    gotoxy(18,6);
                    printf("\t\t\t\t");
                    gotoxy(18,6);
                }
        }while(val==0);
           gotoxy(1,25);
        printf("\t\t\t\t\t");

    return &psn;
    }

  int chk_seat(char* Tno,char cls)
  {
      FILE* fp=fopen("passenger.dat","rb");
      if(fp==NULL)
      {
        fclose(fp);
        return 1;
     }
        Passenger ps;
      int count=0;
      while(fread(&ps,sizeof(Passenger),1,fp)==1)
      {
          if(strcmp(ps.train_no,Tno)==0 && ps.p_class==cls)
            count++;
      }
       fclose(fp);
      if(count<30)
        return 1;
      else
        return 0;
  }
  int tkt_no()
  {
       Passenger pssn;
      FILE* fp=fopen("passenger.dat","rb");
      if(fp==NULL || fread(&pssn,sizeof(Passenger),1,fp)!=1)
      {

        fclose(fp);
        return 1;
      }
     rewind(fp);
      fseek(fp,-1*sizeof(Passenger),SEEK_END);
      fread(&pssn,sizeof(Passenger),1,fp);

      fclose(fp);
      return (pssn.ticketno+1);
  }

  int book_ticket(Passenger P)
  {
      int a=chk_seat(P.train_no,P.p_class);
      if(a==0)
      {
                gotoxy(1,25);
                textcolor(LIGHTRED);
                printf("Seats Not Available.....!!!");
                getch();
                return -1;

      }
      int b=tkt_no();
      P.ticketno=b;

      FILE* fp=fopen("passenger.dat","ab+");
      fwrite(&P,sizeof(Passenger),1,fp);
      fclose(fp);

      gotoxy(1,25);
                textcolor(LIGHTGREEN);
                printf("Congratulations,TICKET BOOKED\n");
                printf("Your Ticket No. is %d",P.ticketno);
                getch();
                return 1;


  }

  void search_tkt()
  {
      clrscr();
      textcolor(YELLOW);
      printf("ENTER MOBILE NUMBER :");
      Passenger psn;
      char mob[20];
            fflush(stdin);
            fgets(mob,11,stdin);
            char* pos1= strchr(mob,'\n');
                if(pos1!=NULL)
                {
                    *pos1 = '\0';

                }
      int i=1;
      gotoxy(1,21);
      FILE* fp=fopen("passenger.dat","rb");
      while(fread(&psn,sizeof(Passenger),1,fp)==1)
      {
          if(strcmp(mob,psn.mob_no)==0)
          {
              textcolor(LIGHTGREEN);
              printf("\nYOUR TICKET NO.%d IS :%d",i++,psn.ticketno);



          }
      }
      if(i==1)
      {
      textcolor(LIGHTRED);
      gotoxy(1,25);
      printf("\nTICKET NOT FOUND WITH %s",mob);
      getch();
      fclose(fp);

      }
      else
      {
       getch();
       fclose(fp);
      }
  }

  void view_tkt()
  {
      clrscr();
      Passenger psn;
      Train trn;
      FILE* tr=fopen("alltrains.dat","rb");
      FILE* pr=fopen("passenger.dat","rb");

      int tkt;
      textcolor(YELLOW);
      printf("ENTER TICKET NUMBER :");
      scanf("%d",&tkt);
      int flag=0;
      while(fread(&psn,sizeof(Passenger),1,pr)==1)
      {
          if(tkt==psn.ticketno)
          {
              printf("\n\n\n\t\tTICKET NO.                  :\t\t%d",psn.ticketno);
              printf("\n\t\tPASSENGER NAME              :\t\t%s",psn.p_name);
              printf("\n\t\tPASSENGER GENDER            :\t\t%c",psn.gender);
              printf("\n\t\tPASSENGER AGE               :\t\t%d",psn.age);
              printf("\n\t\tPASSENGER MOB NO.           :\t\t%s",psn.mob_no);
              printf("\n\t\tPASSENGER TRAIN NUMBER      :\t\t%s",psn.train_no);
              printf("\n\t\tPASSENGER JOURNEY CLASS     :\t\t%c",psn.p_class);


              while(fread(&trn,sizeof(Train),1,tr)==1)
              {
                  if(strcmp(psn.train_no,trn.train_no)==0)
                  {
                   printf("\n\t\tTRAIN FROM                  :\t\t%s",trn.from);
                   printf("\n\t\tTRAIN TO                    :\t\t%s",trn.to);
                   if(psn.p_class=='F')
                    printf("\n\t\tFARE                        :\t\t%d",trn.fac_fare);
                   else
                    printf("\n\t\tFARE                        :\t%d",trn.sac_fare);
                    getch();
                    flag=1;
                    break;
                  }

              }
              if(flag==1)
                break;
          }



      }
        if(flag==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("TICKET NOT FOUND.......!!!!");
            getch();
        }
        fclose(pr);
        fclose(tr);
  }
void view_bkng()
{
    clrscr();
    textcolor(YELLOW);
    Passenger psn;

    FILE* fp = fopen("passenger.dat","rb");
    printf("\n\tTicket No. \tName\t\tGender\tMob.no\t\tAge\tTrain No.\tClass");
     textcolor(LIGHTGREEN);
    while(fread(&psn,sizeof(Passenger),1,fp)==1)
    {
       printf("\n\t\t%d\t%s\t\t%c\t%s\t%d\t%s\t\t%c",psn.ticketno,psn.p_name,psn.gender,psn.mob_no,psn.age,psn.train_no,psn.p_class);

    }
    getch();
    fclose(fp);

}
void view_trn_bkng()
{   clrscr();
    textcolor(YELLOW);
    char trnNo[20];
     printf("Enter Train No. :");
    while(1)
    {   fflush(stdin);
        textcolor(YELLOW);
        fgets(trnNo,10,stdin);
        char* pos= strchr(trnNo,'\n');
        *pos = '\0';
        int a = check_train_no(trnNo);

        if(a==0)
        {
                    gotoxy(1,25);
                    textcolor(LIGHTRED);
                    printf("Invalid Train No. ");
                    getch();
                    gotoxy(18,1);
                    printf("\t\t\t\t");
                    gotoxy(18,1);


        }
        else
        {
                break;
        }
    }
    gotoxy(1,25);

    printf("\t\t\t\t");
    gotoxy(1,3);
    textcolor(LIGHTGREEN);
    FILE* fp = fopen("passenger.dat","rb");

    Passenger psn;
    int flag=0;
    while(fread(&psn,sizeof(Passenger),1,fp)==1)
    {
        if(strcmp(trnNo,psn.train_no)==0)
        {
            if(flag==0)
                 printf("\n\tName\t\tGender\tMob.no\t\tAge\t\tClass");

             printf("\n\t%s\t\t%c\t%s\t%d\t\t%c",psn.p_name,psn.gender,psn.mob_no,psn.age,psn.p_class);
             flag=1;
        }
    }
    textcolor(LIGHTRED);
    if(flag==0)
    {
        gotoxy(1,25);
        printf("No bookings in this Train");

    }
    fclose(fp);
    getch();
}
void cancel_tkt()
{
    clrscr();
    int tkt;
      textcolor(YELLOW);
      printf("ENTER TICKET NUMBER :");
      scanf("%d",&tkt);
        if(tkt==0)
        {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Operation cancelled");
            getch();
            return ;
        }
      Passenger psn;
      FILE* fp;
      FILE* temp;
      fp=fopen("passenger.dat","rb");
      if(fp==NULL)
      { textcolor(LIGHTRED);
        gotoxy(1,25);
       printf("No bookings done yet!!!");
       return;
      }
      temp = fopen("temp.dat","wb");
      int flag=0;
      while(fread(&psn,sizeof(Passenger),1,fp)==1)
      {
          if(psn.ticketno!=tkt)
            fwrite(&psn,sizeof(Passenger),1,temp);
           else
          {
              flag=1;
          }

      }
      fclose(fp);
      fclose(temp);
      if(flag==1)
      {
          remove("passenger.dat");
          rename("temp.dat","passenger.dat");
          gotoxy(1,25);
          textcolor(LIGHTGREEN);
          printf("Cancelled Successfully");
          getch();

          return;
      }
      if(flag==0)
      {
          remove("temp.dat");
            gotoxy(1,25);
          textcolor(LIGHTRED);
          printf("No Bookings with ticket no. %d!!!",tkt);

      }
      getch();
}

//CANCEL TRAIN
void cancel_trn()
{
    clrscr();
      Passenger psn;
    char trnNo[10];
    textcolor(YELLOW);
    printf("Enter Train no. to cancel: ");
    while(1)
    {
        fflush(stdin);
        textcolor(YELLOW);
        fgets(trnNo,10,stdin);

        char* pos= strchr(trnNo,'\n');
        *pos = '\0';
         if(strcmp(trnNo,"0")==0)
        {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Operation cancelled");
            getch();
            return ;
        }
        int a = check_train_no(trnNo);

        if(a==0)
        {
                    gotoxy(1,25);
                    textcolor(LIGHTRED);
                    printf("Invalid Train No. ");
                    getch();
                    gotoxy(28,1);
                    printf("\t\t\t\t");
                    gotoxy(28,1);


        }
        else
        {
                break;
        }
    }

    FILE* fp = fopen("alltrains.dat","rb");
    FILE* tmp = fopen("temp.dat","wb");
    Train tr;
    while(fread(&tr,sizeof(Train),1,fp)==1)
    {
        if(strcmp(tr.train_no,trnNo)!=0)
        {
            fwrite(&tr,sizeof(Train),1,tmp);

        }

    }
    fclose(fp);
    fclose(tmp);
    remove("alltrains.dat");
    rename("temp.dat","alltrains.dat");


      fp=fopen("passenger.dat","rb");

      if(fp==NULL)
      {
          textcolor(LIGHTGREEN);
          gotoxy(1,25);
        printf("Train Cancelled successfully");
        return;
      }
      tmp = fopen("temp.dat","wb");
      while(fread(&psn,sizeof(Passenger),1,fp)==1)
      {
          if(strcmp(trnNo,psn.train_no)!=0)
            fwrite(&psn,sizeof(Passenger),1,tmp);

      }
      fclose(fp);
      fclose(tmp);


          remove("passenger.dat");
          rename("temp.dat","passenger.dat");
          gotoxy(1,25);
          textcolor(LIGHTGREEN);
          printf("Train Cancelled Successfully");
          getch();

}

