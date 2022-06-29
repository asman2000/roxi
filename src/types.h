#ifndef ROXO_TYPES_H
#define ROXO_TYPES_H
/*--------------------------------------------------------------------------*/
#include <exec/types.h>

#include <dos/dos.h>
#include <utility/tagitem.h>

#define ARRAY_SIZE(array)  sizeof (array) / sizeof (array[0]) 

struct Dimension
{
	ULONG width;
	ULONG height;
	ULONG depth;
};

/*--------------------------------------------------------------------------*/
#endif /* ROXO_TYPES_H */
