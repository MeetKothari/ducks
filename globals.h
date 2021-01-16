/***********************************************/
/* globals.h                                   */
/***********************************************/

#ifndef _globals
#define _globals

#define DATA( L ) ( ( L ) -> datapointer )
#define NEXT( L ) ( ( L ) -> next )

typedef enum { OK, ERROR } status ;
typedef enum { FALSE=0 , TRUE=1 } bool ;
typedef void *generic_ptr ;

#define E_EXIT -1
#define E_EOF 1
#define E_SPACE 2
#define E_SYNTAX 3
#define E_EVAL 4
#define MAXERROR 5

#endif
