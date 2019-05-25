#include <stdio.h>
#include <stdlib.h>
#include "tool.h"

void yuv_reader(char *path, int size) {
	// 二进制文件存储以8 bite作为一个单位
	// 所以取char作为存储最小单元
	printf("path: %s, size: %i", path, size);

	unsigned char *buf = malloc(sizeof(unsigned char)* size);
	FILE *fd = fopen(path, "r"); 
	size_t num = fread(buf, sizeof *buf, size, fd);
	
	for (int k = 0; k < num; k++) {
		printf("%i ", buf[k]);
	}

	putchar('\n');
	fclose(fd);
}

// RGB -> YUV
// Y = 0.299 * R + 0.587 * G + 0.114 * B
// U = -0.147 * R - 0.289 * G + 0.436 * B
// V = 0.615 * R - 0.515 * G - 0.100 * B
//
// YUV -> RGB
// R = Y + 1.14 * V
// G = Y - 0.39 * U - 0.58 * V
// B = Y + 2.03 * U

/**
 * YUV编码转RGB 
 */
RGB yuv_codec_rgb(YUV yuv) {
	RGB data;
	data.r = yuv.y + 1.14 * yuv.y;
	data.g = yuv.y - 0.39 * yuv.u - 0.58 * yuv.v;
	data.b = yuv.y + 2.03 * yuv.u;

	return data;
}



