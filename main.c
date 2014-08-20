#include <stdio.h>
#include <stdlib.h>

#include "libs/trim.h"
#include "libs/stoi.h"
#include "libs/dockspacer.h"
#include "constants.h"

/*
   Build command: gcc main.c libs/dockspacer.c libs/trim.c libs/stoi.c -o dockspacer
*/

int main( int argc, char **argv )
{
   char input[ MAX_STRING ];
   int amount;
   int where = APPLICATION_AREA;
   char *copy_of_input;

   printf( "\n\n%s How many spacers would you like? %s ", BGGRAY, NORMAL );

   // Get the user’s input, inside a container MAX_STRING in length
   fgets( input, sizeof( input ), stdin );

   // Replace the newline char with the null character
   input[ strlen( input ) ] = '\0';

   // If the user’s input contains only one character (the null character
   // assigned in the previous statement), then nothing was entered at the
   // prompt. Exit.
   if( strlen( input ) == 1 ) {
      printf( "%s%s Empty entry. %s%s Please run this program again... %s\n", RED, BGYELLOW, NORMAL, RED, NORMAL );
      exit( -1 );
   }

   // Set memory aside in order to make a copy of the user’s input
   copy_of_input = malloc( strlen( input ) * sizeof( char ) );

   // Copy the user input
   strncpy( copy_of_input, trim( input ), strlen( input ) );

   // If stoi returns -1, then generate an error. Otherwise, create the spacers.
   if( -1 == ( amount = stoi( copy_of_input ) ) )
      printf( "%s%s Invalid entry. %s%s Please run this program again...%s\n", RED, BGYELLOW, NORMAL, RED, NORMAL );
   else {
      char choice[ 20 ];
      int input_length;

      /* THE USER MENU */
   user_choice:
      printf( "\n%s Where would you like to add your spacers? %s \n"
             " — In the %s a %s pplication section (typically on the left, if your Dock is on the bottom)\n"
             " — Near the %s r %s ecycle bin (typically on the right, if your Dock is on the bottom)\n"
             " — (Enter %s q %s to quit)\n", BGGRAY, NORMAL, BGGRAY, NORMAL, BGGRAY, NORMAL, BGGRAY, NORMAL );

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

   // Free the memory set aside for the copy
   free( copy_of_input );
   copy_of_input = NULL;

   return 0;
}
