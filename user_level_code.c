/* High level code to interact with kernel I2C driver */
/* Author : Dineshkumar Subramaniam<dsubramaniam@innominds.com> */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

// path to the I2C driver
#define DEVICE_PATH "/dev/I2C_DEVICE"

#define SIZE 256

int main()
{
	int fd;
	ssize_t ret;
	char data[SIZE];

	/* Open the device file */
	fd = open(DEVICE_PATH, O_WRONLY);
	if (fd < 0)
	{
		perror("Failed to open the device file");
		return 1;
	}

	printf("Enter string within 32 characters to send to LCD display: ");
        
        /* Getting an user string */
	fgets(data, SIZE, stdin);

	// Remove the trailing newline character
	data[strcspn(data, "\n")] = '\0';  

	/* Write data to the device */
	ret = write(fd, data, strlen(data));
	if (ret < 0)
	{
		perror("Failed to write to the device");
		close(fd);
		return 1;
	}

	/* Close the device file */
	close(fd);

	return 0;
}

