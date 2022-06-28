#include "init.h"

#include "cfg.h"
#include "libs.h"
#include "screen.h"
#include "tiles.h"
#include "window.h"


#include <dos/dos.h>

/*--------------------------------------------------------------------------*/

int InitOpen(void)
{
	int result = LibsOpen();

	if (RETURN_OK != result)
	{
		return result;
	}

	CfgInit();

	result = ScreenOpen();

	if (RETURN_OK != result)
	{
		return result;
	}

	result = WindowOpen();

	if (RETURN_OK != result)
	{
		return result;
	}

	result = TilesOpen();

	if (RETURN_OK != result)
	{
		return result;
	}


	return result;
}

/*--------------------------------------------------------------------------*/

void InitClose(void)
{
	TilesClose();

	WindowClose();
	ScreenClose();
	LibsClose();
}

/*--------------------------------------------------------------------------*/
