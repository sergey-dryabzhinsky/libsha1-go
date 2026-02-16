#include "libsha1-go.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc,char **argv){
  printf("libsha1-go version: %s\n", libsha1_go__version());
  char* dgst;
  time_t now, curt;
  long wait=60; //test 60 sec
  long ops =0;
  time(&now);
  time(&curt);
  while( (long)curt - (long)now < wait) {
    time(&curt);
    dgst = libsha1_go__SHA1_digest("123");
    libsha1_go__FreeResult(dgst);
    ops ++;
  }
  dgst = libsha1_go__SHA1_hexdigest("123");
  printf("sha1(123):%s\nOps:%ld; op/s:%6.3f\n", dgst, ops, ops/1.0/wait);
  libsha1_go__FreeResult(dgst);
  dgst = NULL; // Best practice to avoid dangling pointers
  return 0;
}