/*
 * notepad-quick - Fast Notepad automation CLI tool
 * Copyright (C) 2026 mrla4vaboy
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef NPAD_OPENER_H
#define NPAD_OPENER_H

#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

 // ANSI Color Escape Sequences
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

#define VERSION "1.3.0"

// Enables ANSI color parsing in the Windows console
static inline void enable_windows_colors(void) {
#ifdef _WIN32
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  if (hOut == INVALID_HANDLE_VALUE) return;
  DWORD dwMode = 0;
  if (!GetConsoleMode(hOut, &dwMode)) return;
  dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
  SetConsoleMode(hOut, dwMode);
#endif
}

// Displays the formatted help menu
static inline void print_help(void) {
  printf(BOLD CYAN "notepad-quick Custom CLI Tool" RESET " - Usage:\n");
  printf("  " GREEN "npad open" RESET "              Opens a new instance of Notepad\n");
  printf("  " RED "npad terminate" RESET "         Closes all running instances of Notepad\n");
  printf("  " YELLOW "npad -v, --version" RESET "     Displays the tool version and license info\n");
  printf("  " YELLOW "npad -h, --help" RESET "        Displays this help menu\n");
}

#endif // NPAD_OPENER_H
