cc= gcc
OBJS= out
CFLAG= -c

$(OBJS): ui.c viml.c gifhand.so tifhand.so pnghand.so mpghand.so jpghand.so -ldl
	$(cc) -rdynamic ui.c viml.c -o $(OBJS) -ldl
	@echo "$(OBJS) generated"

gifhand.so: gifhandler.c
	$(cc) $(CFLAG) -fPIC gifhandler.c -o gifhandler.o
	$(cc) -shared -nostartfiles gifhandler.o -o gifhand.so
	@echo "gifhand.so generated"

jpghand.so: jpghandler.c
	$(cc) $(CFLAG) -fPIC jpghandler.c -o jpghandler.o
	$(cc) -shared -nostartfiles jpghandler.o -o jpghand.so
	@echo "jpghand.so generated"

pnghand.so: pnghandler.c
	$(cc) $(CFLAG) -fPIC pnghandler.c -o pnghandler.o
	$(cc) -shared -nostartfiles pnghandler.o -o pnghand.so
	@echo "pnghand.so generated"

mpghand.so: mpghandler.c	
	$(cc) $(CFLAG) -fPIC mpghandler.c -o mpghandler.o
	$(cc) -shared -nostartfiles mpghandler.o -o mpghand.so
	@echo "mpghand.so generated"

tifhand.so: tifhandler.c	
	$(cc) $(CFLAG) -fPIC tifhandler.c -o tifhandler.o
	$(cc) -shared -nostartfiles tifhandler.o -o tifhand.so
	@echo "tifhand.so generated"

clean:
	rm gifhand.so gifhandler.o jpghand.so jpghandler.o  tifhand.so tifhandler.o  mpghand.so mpghandler.o  pnghand.so pnghandler.o
