CXX = g++
VPATH = ../src 
CPPFLAGS = -std=c++14 -Wpedantic -Wall -Wextra -Wmissing-prototypes -Wstrict-prototypes -Wconversion -Wshadow -Wcast-qual -Wnested-externs
CPPFLAGS += -fsanitize=address -fno-omit-frame-pointer -g

OBJECTS = \
    main.o king_program.o user.o users_controller.o \
	operation.o operations_chooser.o operations_performer.o \
	message.o message_store.o

all: kingprogram

kingprogram: $(OBJECTS)
	$(CXX) $(CPPFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

-include $(OBJECTS:.o=.d)

clean:
	rm -f *.o *.d kingprogram

