#ifndef ROXI_SCREENFRAME_H
#define ROXI_SCREENFRAME_H
/*--------------------------------------------------------------------------*/

#include "types.h"

int ScreenFrameOpen(void);
void ScreenFrameClose(void);

void ScreenFrameSwap(void);

void ScreenFrameProcessSafe(void);
void ScreenFrameProcessDisp(void);


ULONG ScreenFrameGetDispSignal(void);
ULONG ScreenFrameGetSafeSignal(void);

struct RastPort* ScreenFrameGetRastPort(void);
/*--------------------------------------------------------------------------*/
#endif /* ROXI_SCREENFRAME_H */
