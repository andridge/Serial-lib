APP_NAME = my_serial_app
BUILD_DIR = ./bin
C_FILES = ./src/*.c ./src/serial-lib/serial_port.c

APP_DEFINES:=
APP_INCLUDES:= -I./src/serial-lib
APP_LINKERS:= -L/opt/homebrew/Cellar/libserialport/0.1.1/lib -lserialport

build:
	clang $(C_FILES) -o $(BUILD_DIR)/$(APP_NAME) $(APP_INCLUDES) $(APP_LINKERS)

clean:
	rm -f $(BUILD_DIR)/$(APP_NAME)
