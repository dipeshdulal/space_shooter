# -* Makefile *-
IDIR = includes
SDIR = sources
ODIR = objects
BDIR = bin
DDIR = data
CC = g++
CFLAGS = -Wall -g
LFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
PROG = SpaceShooter
_OBJ = main.o \
			 SDL_util.o \
			 Application.o \
			 Eventlistner.o

OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

all: $(OBJ)
	@mkdir -p --verbose $(BDIR)
	$(CC) $(CFLAGS) -I$(IDIR) -I$(BDIR) -I$(DDIR) -o $(BDIR)/$(PROG) $^ $(LFLAGS)

$(ODIR)/%.o: $(SDIR)/%.cpp
	@mkdir -p --verbose $(ODIR)
	$(CC) $(CFLAGS) -I$(IDIR) -c -o $@ $<

clean:
	rm -r -f $(ODIR) $(BDIR)
