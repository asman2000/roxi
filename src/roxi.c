
#include "init.h"
#include "input.h"
#include "window.h"
#include "tiles.h"

#include <proto/exec.h>
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
			const ULONG windowSignal = WindowGetSignal();

			const ULONG signals = Wait(windowSignal);

			if (signals & windowSignal)
			{
				WindowProcessInputs();
			}

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
