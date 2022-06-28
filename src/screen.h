#ifndef ROXI_SCREEN_H
#define ROXI_SCREEN_H
/*--------------------------------------------------------------------------*/

#include "types.h"


int ScreenOpen(void);
void ScreenClose(void);

ULONG ScreenGetAddress(void);

struct RastPort* ScreenGetRastPort(void);

/*--------------------------------------------------------------------------*/
#endif /* ROXI_SCREEN_H */
