#include <stdlib.h>

#include "../constants.h"
#include "dockspacer.h"

void create_dockspacer( int *where, int *amount )
{
   int spacer_count;

   switch( *where ) {
      case APPLICATION_AREA:
         for( spacer_count = 0; spacer_count < *amount; spacer_count++ )
            system ("defaults write com.apple.dock persistent-apps -array-add '{title-data={}; tile-type=\"spacer-tile\";}'");

         system ("killall Dock");

         break;

      case RECYCLE_BIN_AREA:
         for( spacer_count = 0; spacer_count < *amount; spacer_count++ )
            system ("defaults write com.apple.dock persistent-others -array-add '{tile-data={}; tile-type=\"spacer-tile\";}'");

         system ("killall Dock");

         break;
   }
}
