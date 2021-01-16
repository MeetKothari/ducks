/***********************************************/
/* interface.c                                 */
/***********************************************/

#include <stdio.h>
#include <stdlib.h>

#include "circular.h"
#include "globals.h"

status circ_append_duck( list *p_L , int n ){
    
  int *ducks ;
    
  ducks = ( int * ) malloc( sizeof(int) ) ;
    
  if( ducks == NULL ) return ERROR ; 
    
  if( circ_append( p_L , (generic_ptr) ducks ) == ERROR ){
        
    free( ducks ) ; 
        
    return ERROR ; 

  }
    
  *ducks = n ;
    
  return OK ;

}

status write_node( generic_ptr n ){
    
  printf( " %d ", *( int * ) n ) ;
    
  return OK ;

}

list getnextduck( list ducks , list nextduck ){
    
  list duck ; 
    
  duck = circ_list_iterator( ducks, nextduck ) ; 
    
  if( duck == NULL ) return circ_list_iterator( ducks, duck ) ;
    
  else return duck ; 

}
