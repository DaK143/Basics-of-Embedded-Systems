CC=gcc

ROOT=..

UNITY=$(ROOT)/../unity

INC_DIR=-I$(ROOT)/../../.. -I$(UNITY) -I$(ROOT)

TEST_SRC=test_led_control.c # The test_X.c can be hidden away and only the object file is needed to compile
TEST_OBJ=test_led_control.o

SRC_FILES=$(ROOT)/led_control.c $(UNITY)/unity.c

TARGET=test

CFLAGS=-ffunction-sections \
	   -fdata-sections \
	   -std=c99 \
	   -Wall \
	   -pedantic \
	   -Os

.PHONY=$(TEST_OBJ) clean

# Rule to build the test and execute it immediately (only if obj is built beforehand)
create: $(SRC_FILES) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(INC_DIR) -o $(TARGET) $(SRC_FILES) $(TEST_OBJ)
	- ./$(TARGET)

# Rule to build the object from the test source to be able to hide it away later
obj:
	$(CC) $(CFLAGS) $(INC_DIR) -c $(TEST_SRC) -o $(TEST_OBJ)

clean:
	@rm $(TARGET)
