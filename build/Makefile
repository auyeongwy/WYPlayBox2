CC = g++-11
CFLAGS = -std=c++17 -Wall -Wextra -O3 -flto
ARCH = -march=native
#CFLAGS = -Wall -Wextra -std=c++17 -fsanitize=address -static-libasan -O3 -g3
SRC = ../src
BUILD = ../build
OBJS = $(BUILD)/WYPB_Time.o $(BUILD)/WYPB_Event.o $(BUILD)/WYPB_Event_Mgr.o $(BUILD)/WYPB_Event_0Time.o $(BUILD)/WYPB_Actor.o $(BUILD)/WYPB_World.o $(BUILD)/WYPB_PlayBox.o
TARGETLIB = $(BUILD)/lib_WYPlayBox.a
TARGETAPP = $(BUILD)/WYPlayBoxDemo


.PHONY: clean distclean object_msg

all: $(TARGETAPP)

$(TARGETAPP): $(SRC)/WYPB_Demo.cpp $(TARGETLIB)
	@echo Building demo...
	$(CC) $(CFLAGS) $(ARCH)  $(ARCH)  $(SRC)/WYPB_Demo.cpp $(TARGETLIB) -o $(TARGETAPP)

$(TARGETLIB): object_msg $(OBJS)
	@echo Building library...
	ar rcs $(TARGETLIB) $(OBJS)

$(BUILD)/WYPB_Time.o: $(SRC)/WYPB_Time.hpp $(SRC)/WYPB_Time.cpp
	$(CC) $(CFLAGS) $(ARCH)  -c $(SRC)/WYPB_Time.cpp -o $(BUILD)/WYPB_Time.o

$(BUILD)/WYPB_Event.o: $(SRC)/WYPB_EventDefs.hpp $(SRC)/WYPB_Event.hpp $(SRC)/WYPB_Event.cpp
	$(CC) $(CFLAGS) $(ARCH)  -c $(SRC)/WYPB_Event.cpp -o $(BUILD)/WYPB_Event.o

$(BUILD)/WYPB_Event_Mgr.o: $(SRC)/WYPB_EventDefs.hpp $(SRC)/WYPB_Event_Mgr.hpp $(SRC)/WYPB_Event_Mgr.cpp
	$(CC) $(CFLAGS) $(ARCH)  -c $(SRC)/WYPB_Event_Mgr.cpp -o $(BUILD)/WYPB_Event_Mgr.o

$(BUILD)/WYPB_Event_0Time.o: $(SRC)/WYPB_EventDefs.hpp $(SRC)/WYPB_Event_0Time.hpp $(SRC)/WYPB_Event_0Time.cpp
	$(CC) $(CFLAGS) $(ARCH)  -c $(SRC)/WYPB_Event_0Time.cpp -o $(BUILD)/WYPB_Event_0Time.o

$(BUILD)/WYPB_Actor.o: $(SRC)/WYPB_EventDefs.hpp $(SRC)/WYPB_Actor.hpp $(SRC)/WYPB_Actor.cpp
	$(CC) $(CFLAGS) $(ARCH)  -c $(SRC)/WYPB_Actor.cpp -o $(BUILD)/WYPB_Actor.o

$(BUILD)/WYPB_World.o: $(SRC)/WYPB_World.hpp $(SRC)/WYPB_World.cpp
	$(CC) $(CFLAGS) $(ARCH)  -c $(SRC)/WYPB_World.cpp -o $(BUILD)/WYPB_World.o

$(BUILD)/WYPB_PlayBox.o: $(SRC)/WYPB_PlayBox.hpp $(SRC)/WYPB_PlayBox.cpp
	$(CC) $(CFLAGS) $(ARCH)  -c $(SRC)/WYPB_PlayBox.cpp -o $(BUILD)/WYPB_PlayBox.o

#$(BUILD)/WYPB_EventMgr.o: $(SRC)/WYPB_EventMgr.hpp $(SRC)/WYPB_EventMgr.cpp
#	$(CC) $(CFLAGS) $(ARCH)  -c $(SRC)/WYPB_EventMgr.cpp -o $(BUILD)/WYPB_EventMgr.o

object_msg:
	@echo Building objects...

clean:
	@echo Deleting objects...
	rm -f $(BUILD)/*.o

distclean: clean
	@echo Deleting demo and library....
	rm -f $(TARGETLIB)
	rm -f $(TARGETAPP)
