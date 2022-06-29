#include <stdio.h>

#include "init.h"
#include "input.h"
#include "screenFrame.h"
#include "window.h"
#include "tiles.h"

#include <proto/exec.h>
#include <dos/dos.h>

#include <proto/graphics.h>
#include <proto/intuition.h> 

void DrawFrame(void);
/*--------------------------------------------------------------------------*/

int main(void)
{
	int result = InitOpen();

	if (RETURN_OK == result)
	{
		InputInit();

		ScreenFrameSwap();

		//TilesDraw();


		while (TRUE)
		{
			const ULONG windowSignal = WindowGetSignal();
			const ULONG safeSignal = ScreenFrameGetSafeSignal();
			const ULONG dispSignal = ScreenFrameGetDispSignal();

			const ULONG signals = Wait(windowSignal|safeSignal|dispSignal);

			if (signals & windowSignal)
			{
				WindowProcessInputs();
			}

			if (signals & dispSignal)
			{
				ScreenFrameProcessDisp();
			}

			if (signals & safeSignal)
			{
				ScreenFrameProcessSafe();
				DrawFrame();
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

UWORD xx = 100; 

void DrawFrame(void)
{
	struct RastPort* rp = ScreenFrameGetRastPort();

	SetAPen(rp, 0);
	Move(rp, xx, 100);
	Text(rp, "asm", 3);

	if (xx == 200)
	{
		xx = 99;
	}

	xx++;

	SetAPen(rp, 1);
	Move(rp, xx, 100);
	Text(rp, "asm", 3); 
}

/*--------------------------------------------------------------------------*/
