#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libs/stoi.h"
#include "libs/create_dockspacer.h"
#include "constants.h"

int main( int argc, char **argv )
{
   char input[ MAX_STRING ];
   int amount;                   // The amount of dockspacer(s) the user enters.
   int where = APPLICATION_AREA; // The default area in The Dock where the
                                 // dockspacer(s) will be added.

   printf( "\n\n%s How many spacers would you like? %s ", BLACK, BLACK );

   fgets( input, sizeof( input ), stdin );

   input[ strlen( input ) ] = '\0';

   // If the user’s input contains only one character (the null character assigned in
   // the previous statement), then nothing was entered at the prompt.
   if( 1 == strlen( input ) ) {
      printf( "\n%s Empty entry. Please run this program again...%s\n\n",
         RED, BLACK );
      exit( -1 );
   }

   if( INVALID_INPUT == ( amount = stoi( input ) ) ) {
      printf("\n%s Invalid entry. Please run this program again...%s\n\n",
             RED, BLACK);
      exit( -1 );
   }
   else {
      if( 0 == amount ) {
         printf("\n%s You entered 0. Please run this program again...%s\n\n",
                RED, BLACK);
         exit( -1 );
      }
      printf("%d\n", amount);
      char choice[ 20 ];
      char first_character_in_choice;
      int input_length;

      // The User Input Menu
      user_choice:
      printf( "\n%s Where would you like to add your spacers? (Enter your choice as "
                    "the highlighted character below.) %s \n\n"
                    " — In the %sa%spplication section"
                    " (on the left, if your Dock is on the bottom)\n"
                    " — Near the %sr%secycle bin"
                    " (on the right, if your Dock is on the bottom)\n"
                    " — (Enter %sq%s or %sQ%s to quit)\n",
              BLACK, BLACK,   // First line
              BOLDRED, BLACK, // Second line
              BOLDRED, BLACK, // Third line
              BOLDRED, BLACK, // Fourth line
              BOLDRED, BLACK );

      scanf( "%s", choice );

      input_length = strlen( choice );

      if( 1 == input_length ) {
         // Copy the first character in the user’s choice for use in the switch
         // statement.
         first_character_in_choice = choice[ 0 ];
         switch (first_character_in_choice) {
            case 'a': // The application area of The Dock
               create_dockspacer( &where, &amount );

               break;

            case 'r': // The recycle bin area of The Dock
               where = RECYCLE_BIN_AREA;
               create_dockspacer( &where, &amount );

               break;

            case 'q':
            case 'Q':
               printf( "\n%s Quitting%s\n\n", RED, BLACK );
               exit( 0 );

               break;

            default:
               printf( "\n%s Invalid character. Try again. "
                             "(Enter 'q' or 'Q' to quit.)%s\n\n", BOLDRED, BLACK );
               goto user_choice;

               break;
         }
      }
      else {
         printf( "\n%s Invalid input. Try again. "
                       "(Enter 'q' or 'Q' to quit.)%s\n\n", BOLDRED, BLACK );
         goto user_choice;
      }
   }

   return 0;
}
