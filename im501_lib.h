#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>
#include <pigpiod_if2.h>
#include <string.h>
///#include "im501_lib.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
#define SPI_MODE_0 (0|0)



 void pabort(const char *s);
 void Write_Run_Cmd(int fd);
 void Write_Start_Cmd(int fd);
 /*
 void Write_Test_Code(int fd);
 uint8_t Read_Test_data(int fd);

void Write_Test_Cmd(int fd);
*/
void Write_Iram0(int fd);
void Write_Dram0(int fd);
void Write_Dram1(int fd);

int process_pwm();
void im501_reset();
int file_Open(const char *dev);
int  ckeck_run(int fd);
