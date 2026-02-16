#include "libsha1-go.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc,char **argv){
  printf("libsha1-go version: %s\n", libsha1_go__version());
  printf("go runtime version used: %s\n", libsha1_go__version_go());
  char* dgst;
  printf("input args number:%d",argc);
if (argc>1){
  printf("sha1-file(%s): ...\n",argv[1]);
  dgst = libsha1_go__SHA1File_hexdigest(argv[1]);
  printf("sha1-file(%s):%s\n",argv[1], dgst);
} else {
  printf("sha1-file(LICENSE): ...\n");
  dgst = libsha1_go__SHA1File_hexdigest("LICENSE");
  printf("sha1-file(LICENSE):%s\n", dgst);
}

  printf("sha1-file(non-existent): ...\n");
  dgst = libsha1_go__SHA1File_hexdigest("non-existent");
  printf("sha1-file(non-existent):%s\n", dgst);
  libsha1_go__FreeResult(dgst);
  dgst = NULL; // Best practice to avoid dangling pointers
  return 0;
}