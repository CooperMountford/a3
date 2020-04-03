#include "../disk/disk.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TO_HEX(i) (i <= 9 ? '0' + i : 'A' - 10 + i) // int to hex from stackoverflow

/* creates inodes of length 32 bytes
   4 bytes: file size (int)
   4 bytes: flags such as file type (int)
   2 bytes: block number for first 10 blocks (multiplied by 10)
   2 bytes: single indirect block
   2 bytes: double indirect block
*/
int createInode(FILE* disk, int size, int flags, int blockNum) {
   //TODO: Maybe use calloc?
   char* inode = (char*)calloc(32 * sizeof(char), 1)


   return 1;
}

int createFile() {
   return 1;
}

int deleteFile() {
   return 1;
}

int writeFile() {
   return 1;
}

int readFile() {
   return 1;
}

int findInode() {
   return 1;
}

int findBlock() {
   return 1;
}

int formatDisk() {
   return 1;
}

int checkIntegrity() {
   return 1;
}