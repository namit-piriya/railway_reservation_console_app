#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include "rlyres.h"

int main()
{

    add_trains();
    Passenger* pass;
    int k;
    while(1)
    {
        clrscr();
        k=enterchoice();

        switch(k)
        {

        case 1:
            view_trains();
            break;

        case 2:
            pass=get_pass_details();
            if(pass!=NULL)
            {
             book_ticket(*pass);
            }

            break;

        case 3:
            view_tkt();
            break;

        case 4:
             search_tkt();
            break;

        case 5:
           view_bkng();
            break;

        case 6:
           view_trn_bkng();
            break;

        case 7:
           cancel_tkt();
            break;

        case 8:
           cancel_trn();
            break;

        case 9:

            exit(0);

        default:
            printf("Invalid Choice");
        }
    }

    return 0;
}
