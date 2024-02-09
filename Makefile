CFLAGS     = -Ofast
CSRC       = crab.c
INCLUDES   = -I .
INSTALL   ?= install
MKDIR     ?= $(INSTALL) -d
BINDIR    ?= $(PREFIX)/bin
DESTDIR   ?=

all: crab

rebuild: clean all

crab: $(CSRC) $(LIBS)
	$(CC) ${INCLUDES} -o crab $^ ${CFLAGSEXE}

install: crab
	$(MKDIR) $(DESTDIR)$(BINDIR)
	$(INSTALL) crab $(DESTDIR)$(BINDIR)

clean:
	rm -f crab
	find . -name '*~' -delete;
	find . -name '#*#' -delete;
