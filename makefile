#--- Roxi ---

BIN = roxi

CC = vc

VBCCINCLUDE = C:/vbcc/targets/m68k-amigaos/include/
OSINCLUDE = C:/vbcc/include_h/

CFLAGS =-quiet -c -O1 -sc -c99 -I$(VBCCINCLUDE) -I$(OSINCLUDE)
START = C:/vbcc/targets/m68k-amigaos/lib/minstart.o

SRCDIR = src
OBJDIR = obj

OBJECTS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(wildcard $(SRCDIR)/*.c))
HEADERS = $(wildcard $(SRCDIR)/*.h)

LIBS =
LINK = vlink -nostdlib -bamigahunk -Bstatic -Cvbcc -s -x $(START)

RM = rm

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

$(BIN): $(OBJECTS)
	$(LINK) $(OBJECTS) -o $@ $(LIBS)

.PHONY: game cls

game:	$(BIN)

cls:
	$(RM) $(OBJECTS) $(TESTOBJECTS) $(BIN) $(TESTBIN)
