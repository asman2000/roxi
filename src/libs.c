#include "libs.h"


#include <dos/dos.h>

#include <proto/exec.h> 

/*--------------------------------------------------------------------------*/

struct IntuitionBase* IntuitionBase = NULL;
struct DosLibrary* DOSBase = NULL;
struct GfxBase* GfxBase = NULL;
struct Library* UtilityBase = NULL; 

static const char* dosName = "dos.library";
static const char* gfxName = "graphics.library";
static const char* itnName = "intuition.library";
static const char* utlName = "utility.library";

/*--------------------------------------------------------------------------*/

int LibsOpen(void)
{
	DOSBase = (struct DosLibrary*)OpenLibrary(dosName, 36);

	if (0 == DOSBase)
	{
		return RETURN_FAIL;
	}

	GfxBase = (struct GfxBase*)OpenLibrary(gfxName, 36);

	if (NULL == GfxBase)
	{
		return RETURN_FAIL;
	}

	IntuitionBase = (struct IntuitionBase*)OpenLibrary(itnName, 36);

	if (NULL == IntuitionBase)
	{
		return RETURN_FAIL;
	}

	UtilityBase = OpenLibrary(utlName, 0);

	if (NULL == UtilityBase)
	{
		return RETURN_FAIL;
	}

	return RETURN_OK;
}

/*--------------------------------------------------------------------------*/

void LibsClose(void)
{
	CloseLibrary(UtilityBase);
	CloseLibrary((struct Library*)IntuitionBase);
	CloseLibrary((struct Library*)GfxBase);
	CloseLibrary((struct Library*)DOSBase);
}

/*--------------------------------------------------------------------------*/
