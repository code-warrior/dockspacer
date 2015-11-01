#include <stdio.h>
#include <ctype.h>  // for isdigit
#include <stdlib.h> // for strtol

#include "../constants.h"
#include "stoi.h"

/* =========={ STOI - STRING TO INTEGER }========================================
   Take an array of characters as a number and return its integer equivalent.
   ============================================================================== */
int stoi( char string[] )
{
   int length = -1;
   int index;

   while( string[ ++length ] != '\0' )
      ;

   /* ============================================================================
      Check that each character in the string has a valid integer equivalent. If
      it does, move on to the next character. If it does not, return -1
      (INVALID_INPUT).
      ============================================================================ */
   for( index = 0; index < length - 1; index++ )
      if( ( isdigit( string[ index ] ) ) != 0 )
         continue;
      else
         return INVALID_INPUT;

   /* ============================================================================
      If program control reaches this point, a valid number in the form of a
      string was fed to this function. Thus, it is safe to convert the string to
      an integer, then return the conversion.
      ============================================================================ */
   return ( int ) strtol( string, (char**) NULL, 10 );
}
