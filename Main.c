/*
 * notepad-quick - Fast Notepad automation CLI tool
 * Copyright (C) 2026 mrla4vaboy
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NpadOpener.h"

int main(int argc, char* argv[]) {
  // Turn on ANSI escape sequence support for colors
  enable_windows_colors();

  // 1. Validate argument count
  if (argc < 2) {
    printf(RED BOLD "Error: Missing arguments.\n" RESET);
    print_help();
    return 1;
  }

  // 2. Evaluate command line flags/subcommands
  if (strcmp(argv[1], "open") == 0) {
    printf(GREEN "Opening Notepad..." RESET "\n");
    system("start notepad.exe");
  }
  else if (strcmp(argv[1], "terminate") == 0) {
    printf(YELLOW "Terminating Notepad instances..." RESET "\n");
    system("taskkill /f /im notepad.exe >nul 2>&1");
    printf(RED "All Notepad processes stopped.\n" RESET);
  }
  else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) {
    printf(BOLD CYAN "notepad-quick" RESET " version " BLUE BOLD "%s" RESET "\n", VERSION);
    printf("Copyright (C) 2026 mrla4vaboy\n");
    printf("License GPLv3+: GNU GPL version 3 or later <https://gnu.org>.\n");
    printf("This is free software: you are free to change and redistribute it.\n");
  }
  else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
    print_help();
  }
  else {
    printf(RED BOLD "Error: Unknown command '%s'" RESET "\n", argv[1]);
    print_help();
    return 1;
  }

  return 0;
}
