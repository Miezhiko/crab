#include <dirent.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  bool cabal_found = false;

  DIR *dir = opendir(".");
  struct dirent *entry;

  while ((entry = readdir(dir)) != NULL) {
    if (entry->d_type == DT_REG) {
      if (strcmp(entry->d_name, "Cargo.toml") == 0) {
        execv("/usr/bin/cargo", argv);
      } else if (!cabal_found && strstr(entry->d_name, ".cabal")) {
        cabal_found = true;
        execv("/usr/bin/cabal", argv);
      }
    }
  }

  closedir(dir); 
  return 0;
}
