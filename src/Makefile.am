PREFIXDIR  = $(prefix)
PKGDATADIR = $(datadir)/matchbox
DATADIR    = $(datadir)

AM_CFLAGS = $(GCC_FLAGS)
AM_LDFLAGS = -lmarkdown

AM_CPPFLAGS = -DDATADIR=\"$(DATADIR)\" -DPKGDATADIR=\"$(PKGDATADIR)\" -DPREFIX=\"$(PREFIXDIR)\"

bin_PROGRAMS = didiwiki

didiwiki_SOURCES = didi.c  didi.h  http.c  http.h  \
                   util.c  util.h  wiki.c  wiki.h  \
                   wikitext.h




