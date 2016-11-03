#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
  DIR * dir = opendir(".");
  struct dirent *dp;
  int size = 0;
  int error;
  struct stat *st = (struct stat *)malloc(sizeof(struct stat));
  while (dp = readdir(dir)) {
    printf("\nfile name: %s ",dp->d_name);
    if (dp->d_type == 4) {
      printf("(directory)");
    }
    error = stat(dp->d_name,st);
    size += st->st_size;
    printf("\n");
  }
  printf("The size is: %d B\n",size);
  closedir(dir);
  return 0;
}
