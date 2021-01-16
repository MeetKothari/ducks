/***********************************************/
/* interface.h                                 */
/***********************************************/

#ifndef _interface
#define _interface

#include "globals.h"
#include "circular.h"

extern status circ_append_duck( list *p_L , int n ) ; 
extern status write_node( generic_ptr n ) ;

extern list getnextduck( list ducks, list nextduck ) ;

#endif
