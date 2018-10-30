#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int myrand() {
  int randD = open("/dev/urandom", O_RDONLY);
  if(randD < 0)
    return 0;
  else {
    unsigned int *number = calloc(1, sizeof(int));
    int result = read(randD, number, sizeof number);
    if (result < 0)
      return 0;
    return *number;
  }
}


int main() {
  printf("Generating random numbers:\n");
  int myData[10], i;
  for(i = 0; i< 10; i++) {
    *(myData+ i) = myrand();
    printf("     random %d: %u\n", i, *(myData +i));
  }

  printf("\nWriting numbers to file...\n");
  int file = open("l.txt", O_WRONLY | O_CREAT);
  int result = write(file, myData, sizeof myData);
  int c = close(file);

  printf("\nReading numbers from file...\n");
  file = open("l.txt", O_RDONLY);
  int newData[10];
  result = read(file, newData, sizeof newData);
  c = close(file);

  printf("\nVerification that written values were the same:\n");
  for(i = 0; i< 10; i++) {
    printf("     random %d: %u\n", i, *(newData +i));
  }
  return 0;
}
