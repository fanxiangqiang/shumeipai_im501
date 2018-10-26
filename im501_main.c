#include "im501_lib.h"

const char *device = "/dev/spidev0.0";

int main(void)
{
	int file_fdd,pwm_fdd;//打开设备
	file_fdd=file_Open(device);
	if(file_fdd < 0)
	{
		printf("open error ,return!\r\n");
        return -1;
	}
	
	pwm_fdd=process_pwm();
	if(pwm_fdd < 0)
	{
		printf("set_clock error\r\n");
        return -1;
		
	}
	//printf("rrrrrrrr\r\n");
	 im501_reset();
	 Write_Start_Cmd(file_fdd);  
	 Write_Iram0(file_fdd);
     Write_Dram0(file_fdd);
     Write_Dram1(file_fdd);
	 Write_Run_Cmd(file_fdd);
	unsigned  char c;
	c=ckeck_run(file_fdd);
	while(1)
	{
		 c=ckeck_run(file_fdd);
		if(c ==1)
		{
			printf("im501 run  normally\r\n");
		}
		 else 
		{
			 printf("check cable and reboot \r\n");
		}			
	}
		
  
	
}
