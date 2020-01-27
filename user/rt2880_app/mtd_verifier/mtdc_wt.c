#include	<unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include	<signal.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include <stdint.h>
#include <sys/ioctl.h>
#include <sys/types.h>

#define len 128

struct erase_info_user {
	unsigned int start;
	unsigned int length;
};

struct mtd_info_user {
	unsigned char type;
	unsigned int flags;
	unsigned int size;
	unsigned int erasesize;
	unsigned int oobblock;  
	unsigned int oobsize;  
	unsigned int ecctype;
	unsigned int eccsize;
};

#define MEMGETINFO 				_IOR('M', 1, struct mtd_info_user)
#define MEMERASE 					_IOW('M', 2, struct erase_info_user)
#define MEMUNLOCK               _IOW('M', 6, struct erase_info_user)

int fd;
int flag =0;
char *mtd_d = "/dev/mtd3";

char EeBuffer0[len] = {
	0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 
	0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 
	0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 
	0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 
	0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 
	0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 
	0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 
	0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 
	0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 0x11, 0x22, 
	0x11, 0x22
};

char EeBuffer1[len] = {
	0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 
	0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44,
	0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44,
	0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44,
	0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 
	0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 
	0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 
	0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44,
	0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 
	0x44, 0x44
};
	
void mtd_erase(void){
	
	int i;
	struct mtd_info_user mtdInfo;
	struct erase_info_user mtdEraseInfo;

	fd = open(mtd_d, O_RDWR | O_SYNC);
	if(fd < 0) {
		fprintf(stderr, "Could not open mtd device: %s\n", mtd_d);
		exit(1);
	}

	if(ioctl(fd, MEMGETINFO, &mtdInfo)) {
		fprintf(stderr, "Could not get MTD device info from %s\n", mtd_d);
		close(fd);
		exit(1);
	}

	mtdEraseInfo.length = mtdInfo.erasesize;
	mtdEraseInfo.start = 0;
	
	for (mtdEraseInfo.start; mtdEraseInfo.start < mtdInfo.size; mtdEraseInfo.start += mtdInfo.erasesize) {
		ioctl(fd, MEMUNLOCK, &mtdEraseInfo);
		if(ioctl(fd, MEMERASE, &mtdEraseInfo)){
			fprintf(stderr, "Failed to erase block on %s at 0x%x\n", mtd_d, mtdEraseInfo.start);
			close(fd);
			exit(1);
		}
	}		
	close(fd);
}

void mtd_write(void){
	
	int val = 0;
	int i;
	char pbuf[len];
	
	fd = open(mtd_d, O_RDWR | O_SYNC);
	if(fd < 0) {
		printf("Could not open mtd device: %s\n",mtd_d);
		exit(1);
	}

	if(flag++ % 2 == 0)
		val = write(fd, EeBuffer0, len);
	else
		val = write(fd, EeBuffer1, len);
	
	lseek(fd,0,SEEK_SET);
	if(read(fd, pbuf, len) != len){
		printf("read() failed\n");
		close(fd);
		exit(1);
	}
	printf("mtd write val = %d  %x\n", val, pbuf[0]);
	
	close(fd);
}

int main(void)
{
	while(1){
		mtd_erase();
		mtd_write();
		sleep(1);
	}
	
	return 0;
}