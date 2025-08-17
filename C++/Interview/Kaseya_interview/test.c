// I have to complet this code in tree in future
#include <stdio.h>
#include <stdlib.h>
#define LEN 5
struct {
    int data;
    
}file;

// Home/
// work
// file1,
// file2 

// called before using fisystem to initialize internals (if needed)
void init() {
 
}

// changes directory from current to the one named `name`
void cd(const char *name) {}

// returns list of nodes in current directory
// `entries` array of strings must be allocated in this function
// count is expected to be not nullptr and should be set to amount of entries
void ls(char **entries, int *count) {}

// creates new directory named `name` inside of current directory
void mkdir(const char *name) {}

// creates new file inside of current directory
void mkfile(const char *name, const char *contents) {}

// returns content of file named `name` in the current directory
// `contents` string must be allocated in this function
void cat(const char *name, char *contents) {}

// called after using fisystem to destory internals (if needed)
void destroy() {}

void free_string_array(char **array, int count) {
  for (int i = 0; i < count; i++) {
    free(array[i]);
  }
  free(array);
}

int main() {
  init();

  char **entries = NULL;
  int count = 0;

  mkdir("home");
  ls(entries, &count);
  // expected that entries will be { "home" };
  free_string_array(entries, count);

  cd("home");
  ls(entries, &count);
  // expected that entries will be {};
  free_string_array(entries, count);

  mkfile("work.doc", "work-related data");
  ls(entries, &count);
  // expected that entries will be { "work.doc" };
  free_string_array(entries, count);

  char *contents = NULL;
  cat("work.doc", contents);
  // expected that contents will be "work-related data";
  free(contents);

  destroy();
}