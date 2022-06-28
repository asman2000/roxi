#ifndef ROXI_WINDOW_H
#define ROXI_WINDOW_H
/*--------------------------------------------------------------------------*/
#include "types.h"

int WindowOpen(void);
void WindowClose(void);

void WindowProcessInputs(void);

ULONG WindowGetSignal(void);

/*--------------------------------------------------------------------------*/
#endif /* ROXI_WINDOW_H */
