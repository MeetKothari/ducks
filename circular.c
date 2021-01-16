/***********************************************/
/* circular.c                                  */
/***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "circular.h"

void free_node( list *p_L ){

  free( *p_L ) ;

  *p_L = NULL ;

}

status allocate_node( list *p_L, generic_ptr data ){

  list L = (list) malloc( sizeof( node ) ) ;

  if ( L == NULL ) return ERROR ;

  *p_L = L ;

  DATA(L) = data ;

  NEXT(L) = NULL ;

  return ( OK ) ;
}


status init_circ_list( list *p_L ){

  *p_L = NULL ;

  return OK ;

}

bool empty_circ_list( list L ){

  return ( L == NULL ) ? TRUE : FALSE ;

}

status circ_insert( list *p_L , generic_ptr data ){

  list L ;

  if ( allocate_node( &L , data ) == ERROR ) return ERROR ;

  if ( empty_circ_list( *p_L ) == TRUE ){

    NEXT(L) = L ;

    *p_L = L ;

  } else {

    NEXT(L) = NEXT( *p_L ) ;

    NEXT( *p_L ) = L ;

  }

  return OK ;

}

status circ_append( list *p_L , generic_ptr data ){

  if ( circ_insert( p_L , data ) == ERROR ) return ERROR ;

  *p_L = NEXT( *p_L ) ;

  return OK ;

}

status circ_delete( list *p_L , generic_ptr *p_data ){

  if ( empty_circ_list( *p_L ) == TRUE ) return ERROR ;

  *p_data = NEXT(*p_L) ;

  return circ_delete_node( p_L , NEXT(*p_L )) ;

}

status circ_delete_node( list *p_L , list node ){

  list L ;

  if ( empty_circ_list( *p_L ) == TRUE ) return ERROR ;

  if ( node == NEXT(node)) *p_L = NULL ;

  else {

    for ( L = NEXT( *p_L ) ; L != *p_L && NEXT(L) != node ; L = NEXT(L) ) ;

    if ( NEXT(L) != node ) return ERROR ;

    NEXT(L) = NEXT(node) ;

    if ( node == *p_L ) *p_L = L ;

  }

  free_node( &node ) ;

  return OK ;

}

list circ_list_iterator( list L , list lastreturn ){

  if ( lastreturn == NULL ) return (L) ? NEXT(L) : NULL ;

  else return ( lastreturn == L ) ? NULL : NEXT( lastreturn ) ;

}

int circ_length( list L ){

  list lastreturn ;

  int length ;

  length = 0 ;

  lastreturn = NULL ;

  while( ( lastreturn = circ_list_iterator( L , lastreturn ) ) != NULL ) length++ ;

  return length ;

}

list nth_node( list L , int number ){

  list tmp ;

  if( empty_circ_list(L) == TRUE ) return NULL ;

  if( number == -1 ) return L ;

  tmp = L ;

  do {

    tmp = NEXT( tmp ) ;

    number-- ;

  } while( number > 0 && tmp != L ) ;

  return ( number != 0 ) ? NULL : tmp ;

}

status circ_traverse( list L , status ( *p_func_f ) () ){

  list tmp ;

  if( empty_circ_list(L) == TRUE ) return OK ;

  tmp = L ;

  do {

    tmp = NEXT(tmp) ;

    if ((*p_func_f)(DATA(tmp)) == ERROR ) return ERROR ;

  } while ( tmp != L ) ;

  return OK ;

}
				     
