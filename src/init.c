#include "init.h"

#include "bitmap.h"
#include "cfg.h"
#include "libs.h"
#include "screen.h"
#include "screenFrame.h"
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

	result = BitmapsAllocate();

	if (RETURN_OK != result)
	{
		return result;
	}

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

	result = ScreenFrameOpen();

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

	ScreenFrameClose();
	WindowClose();
	ScreenClose();
	BitmapsFree();
	LibsClose();
}

/*--------------------------------------------------------------------------*/
