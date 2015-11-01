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
      char choice[ 20 ];
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

      if( input_length == 1 ) {
         if( strncmp( choice, "a", 1 ) == 0 ) {
            create_dockspacer( &where, &amount );
         }
         else
            if( strncmp( choice, "r", 1 ) == 0 ) {
               where = RECYCLE_BIN_AREA;
               create_dockspacer( &where, &amount );
            }
            else
               if( strncmp( choice, "q", 1 ) == 0 ) {
                  printf( "Quitting\n" );
                  exit( 0 );
               }
               else {
                  printf( "Invalid character. Try again. (Enter 'q' to quit.)\n" );
                  goto user_choice;
               }
      }
      else {
         printf( "Invalid input. Try again. (Enter 'q' to quit.)\n" );
         goto user_choice;
      }
   }

   return 0;
}
