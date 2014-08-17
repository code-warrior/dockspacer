#include <stdlib.h>

#include "dockspacer.h"

void create_dockspacer( int *amount )
{
   int spacer_count;

   for( spacer_count = 0; spacer_count < *amount; spacer_count++ )
      system ("defaults write com.apple.dock persistent-apps -array-add '{title-data={}; tile-type=\"spacer-tile\";}'");

   system ("killall Dock");
}
