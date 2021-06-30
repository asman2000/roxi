#include "init.h"

#include "libs.h"

#include <dos/dos.h>

/*--------------------------------------------------------------------------*/

int InitOpen(void)
{
	int result = LibsOpen();

	if (RETURN_OK != result)
	{
		return result;
	}

	return result;
}

/*--------------------------------------------------------------------------*/

void InitClose(void)
{
	LibsClose();
}

/*--------------------------------------------------------------------------*/
