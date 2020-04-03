#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define vdisk_path "../disk/vdisk"

const int BLOCK_SIZE = 512;
const int NUM_BLOCKS = 4096;
const int NUM_INODES = 4096; //***MIGHT NEED CHANGING***

// from tutorial video
void writeBlock(FILE* disk, int block, char* data) {
    fseek(disk, block * BLOCK_SIZE, SEEK_SET);
    fwrite(data, BLOCK_SIZE, 1, disk);
}
// from tutorial video
void readBlock(FILE* disk, int block, char* buff) {
    fseek(disk, block * BLOCK_SIZE, SEEK_SET);
    fread(buff, BLOCK_SIZE, 1, disk);
}

void InitLLFS() {
   FILE* disk = fopen(vdisk_path, "w+"); // destroys any existing file
   char* init = calloc(BLOCK_SIZE*NUM_BLOCKS, 1); // init to zeros
   fwrite(init, BLOCK_SIZE*NUM_BLOCKS, 1, disk);
   free(init);
   fclose(disk);

   disk = fopen(vdisk_path, "rb+");

   // init block 0 (superblock)
   // Given code doesn't work for some reason so I did it manually
   /*
   char* buffer;
   buffer = (char*) malloc(BLOCK_SIZE);
   int magic = 1337;
   int blocks = NUM_BLOCKS;
   int inodes = NUM_INODES;
   memcpy(buffer, &magic, sizeof(magic));
   memcpy(buffer + sizeof(int) * 1, &blocks, sizeof(int));
   memcpy(buffer + sizeof(int) * 2, &inodes, sizeof(int));
   writeBlock(disk, 0, buffer);
   free(buffer);
   */

   writeBlock(disk, 0, "133740964096");
   //free(buffer);

   // init block 1 (free block vector)
   char FBV[512] = {0b00000000, 0b00011111, [2 ... 511] = 0b11111111};
   writeBlock(disk, 1, FBV);

   fclose(disk);
}