/**************************************************/
/* main.c                                         */
/**************************************************/

#include <stdio.h> 
#include <stdlib.h> 

#include "circular.h" 
#include "globals.h"
#include "interface.h"

int main( int argc , char *argv[] ){

  int i, m, n ;

  list allducks , position , nextduck = NULL ;

  do printf( "\nPlease input n and m: " ) ; while( scanf("%d %d",&n ,&m ) != 2 ) ; 
    
  init_circ_list( &allducks ) ; 
    
  for( i = 1 ;  i <= n ; i++ ) circ_append_duck( &allducks , i ) ; 
    
  printf( "\nThe circular list of ducks is: " ) ; 
    
  circ_traverse( allducks, write_node ) ; 
    
  printf( "\n" ) ; 
    
  nextduck = getnextduck( allducks , NULL ) ; 
    
  printf( "\nThe alligator ate the ducks in the following order: " ) ; 
    
  while( empty_circ_list(allducks) != TRUE ){ 
        
    for( i = 1 ; i < m ; i++ ) nextduck = getnextduck( allducks , nextduck ) ; 
        
    position = nextduck ; 
        
    nextduck = getnextduck( allducks , nextduck ) ; 
        
    write_node( DATA(nextduck)) ; 
        
    circ_delete_node( &allducks , nextduck ) ; 
        
    nextduck = position ; 

  }
    
  printf( "\n" ) ; 
    
  return 0 ; 

}
