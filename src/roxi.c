
#include "init.h"
#include "input.h"
#include "window.h"
#include "tiles.h"

#include <dos/dos.h>

/*--------------------------------------------------------------------------*/

int main(void)
{
	int result = InitOpen();

	if (RETURN_OK == result)
	{
		InputInit();

		TilesDraw();

		while (TRUE)
		{
			WindowProcessInputs();

			if (InputIsExitToOsPressed())
			{
				break;
			}
		}
	}

	InitClose();

	return result;
}

/*--------------------------------------------------------------------------*/
