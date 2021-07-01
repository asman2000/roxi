#ifndef ROXI_SCREEN_H
#define ROXI_SCREEN_H
/*--------------------------------------------------------------------------*/

#include <exec/types.h>

int ScreenOpen(void);
void ScreenClose(void);

ULONG ScreenGetAddress(void);
ULONG ScreenGetWidth(void);
ULONG ScreenGetHeight(void);
ULONG ScreenGetDepth(void);

struct RastPort* ScreenGetRastPort(void);

/*--------------------------------------------------------------------------*/
#endif /* ROXI_SCREEN_H */
