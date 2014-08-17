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
   char *copy_of_input;

   printf( "\n\nThis program creates empty items in your Dock that you can use as spacers. After you enter the amount of spacers you want, the Dock will flash and you will have your new spacers near the Recycle Bin. You can then move them as you would any other Dock item.\n\n%s%s Note %s This program does not remove any Dock items. You’ll need to remove unwanted Dock spacers manually.\n\nYou may cancel this program with the keyboard sequence CNTRL + C, or enter the number 0.\n\nHow many spacers would you like? ", RED, BGYELLOW, NORMAL );

   // Get user input
   fgets( input, sizeof( input ), stdin );

   // Replace the newline char with the null character
   input[ strlen( input ) ] = '\0';

   // If user input contains only one character (the null character), then nothing was entered at the prompt. Exit.
   if( strlen( input ) == 1 ) {
      printf( "%s%s Empty entry. %s%s Please run this program again... %s\n", RED, BGYELLOW, NORMAL, RED, NORMAL );
      exit( -1 );
   }

   // Copy the user input
   copy_of_input = malloc( strlen( input ) * sizeof( char ) );
   strncpy( copy_of_input, trim( input ), strlen( input ) );

   ( -1 == ( amount = stoi( copy_of_input ) ) ) ?
      printf( "%s%s Invalid entry. %s%s Please run this program again...%s\n", RED, BGYELLOW, NORMAL, RED, NORMAL ) :
      create_dockspacer( &amount );

   free( copy_of_input );
   copy_of_input = NULL;

   return 0;
}
