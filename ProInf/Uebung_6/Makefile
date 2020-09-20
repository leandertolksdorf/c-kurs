NASM=nasm
NASMFLAGS=-f elf64
CFLAGS=-std=c11 -Wall -Wextra -pedantic -O2
CPPFLAGS=-MMD -MF $*.d

program=bubblesort
obj-y=$(program).o bubblesort_wrapper.o

all: $(program)
$(program): $(obj-y)

-include *.d

# pattern rules
%: %.o
	$(CC) -o $@ $(LDFLAGS) $^ $(LDLIBS)

%.o: %.asm
	$(NASM) -g -o $@ $(NASMFLAGS) $<
%.o: %.c
	$(CC) -c -o $@ $(CPPFLAGS) $(CFLAGS) $<

%.d: ;

clean:
	@$(RM) -fv $(program) $(obj-y) $(obj-y:.o=.d)

debug: all
	@gdb -ix debug.txt -q

.SUFFIXES:
.PHONY: all clean
.PRECIOUS: $(obj-y)
