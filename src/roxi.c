#include "init.h"

#include <dos/dos.h>

/*--------------------------------------------------------------------------*/

int main(void)
{
	int result = InitOpen();

	if (RETURN_OK == result)
	{

	}

	InitClose();

	return result;
}

/*--------------------------------------------------------------------------*/