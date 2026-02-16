#include "libsha1-go.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc,char **argv){
  printf("libsha1-go version: %s\n", libsha1_go__version());
  printf("go runtime version used: %s\n", libsha1_go__version_go());
  char* dgst;
  dgst = libsha1_go__SHA1_hexdigest("123");
  printf("sha1(123):%s\n", dgst);
  libsha1_go__FreeResult(dgst);
  dgst = NULL; // Best practice to avoid dangling pointers
  return 0;
}