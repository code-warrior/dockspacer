#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "trim.h"

char* trim( char* untrimmed_string )
{
   bool found_first_char = false;
   bool found_last_char = false;

   int forward, reverse;

   int index_of_first_char = 0;
   int index_of_last_char;

   for( forward = 0, reverse = strlen( untrimmed_string ) - 2; forward <= reverse; ) {
      // If a non-space char is found at the beginning...
      if( !( isblank( untrimmed_string[ forward ] ) ) ) {
         index_of_first_char = forward;
         found_first_char = true;
      }

      if( !( isblank( untrimmed_string[ reverse ] ) ) ) {
         index_of_last_char = reverse;
         found_last_char = true;
      }

      if( true == found_first_char )
         reverse--;
      else
         if( true == found_last_char )
            forward++;
         else {
            forward++;
            reverse--;
         }

      // If both are found...
      if( ( true == found_first_char ) && ( true == found_last_char ) ) {
         int trimmed_string_size = index_of_last_char - index_of_first_char;

         char *trimmed_string = malloc( sizeof( char ) * ( trimmed_string_size + 1 ) );

         int index_of_trimmed_string;

         for( index_of_trimmed_string = 0; index_of_trimmed_string <= trimmed_string_size; index_of_trimmed_string++ ) {
            trimmed_string[ index_of_trimmed_string ] = untrimmed_string[ index_of_first_char++ ];
         }

         trimmed_string[ index_of_trimmed_string ] = '\0';

         return trimmed_string;

         break;
      }

   }

   return NULL;
}
