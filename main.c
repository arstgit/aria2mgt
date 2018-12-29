#include <stdio.h>
#include <stdlib.h>
#include <endian.h>
#include <inttypes.h>

#define SLEN 99
#define MLEN 299

int main(int argc, char ** argv) {
  char * file;
  FILE * fp;
  unsigned char ch;

  file = *(argv + 1);
  if ((fp = fopen(file, "rb")) == NULL) {
    perror("open file error");
    exit(EXIT_FAILURE);
  }

  // get hash length
  uint32_t length;
  fseek(fp, 6L, SEEK_SET);
  fread(&length, 4, 1, fp);
  length = be32toh(length);

  char hash[MLEN];
  fseek(fp, 10L, SEEK_SET);
  fread(&hash, length, 1, fp);

  // get hash value
  fseek(fp, 10,  SEEK_SET);
  printf("magnet:?xt=urn:btih:");
  for(long i = 10; fread(&ch, 1, 1, fp) && i < 10 + length; fseek(fp, ++i,  SEEK_SET)) {
    printf("%02x", ch);
  }

  fclose(fp);
}
