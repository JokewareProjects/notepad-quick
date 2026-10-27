# notepad-quick - GNU Make Build Automation
# Copyright (C) 2026 mrla4vaboy
# Licensed under the GNU GPL v3.0

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -O2

# Target Executable Name
TARGET = npad.exe

# Installation Directory (Windows Local AppData)
# Using ?= allows developers to override it if desired
INSTALL_DIR ?= $(LOCALAPPDATA)/notepad-quick

# Default rule: Compiles the application
all: $(TARGET)

$(TARGET): Main.c NpadOpener.h
	$(CC) $(CFLAGS) Main.c -o $(TARGET)

# Install rule: Compiles, moves the file, and configurations environment path
install: $(TARGET)
	@echo "Creating installation directory at: $(INSTALL_DIR)"
	@mkdir -p "$(INSTALL_DIR)"
	@echo "Deploying binary..."
	@mv $(TARGET) "$(INSTALL_DIR)/$(TARGET)"
	@echo "Adding notepad-quick to your User PATH environment variable..."
	@setx PATH "%PATH%;$(subst /,\\,$(INSTALL_DIR))" > nul
	@echo "--------------------------------------------------------"
	@echo "Installation successful!"
	@echo "Please restart your terminal to apply the new PATH setup."
	@echo "--------------------------------------------------------"

# Clean rule: Deletes residual build artifacts locally
clean:
	rm -f $(TARGET)

.PHONY: all install clean
