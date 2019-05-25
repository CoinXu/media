#include <stdio.h>
#include <stdlib.h>
#include "tool.h"

/**
 * @param {string} $1 file path to open and read
 * @param {string} $2 read size
 * @return {number}
 */
int main(int argc, char *argv[]) {
	printf("argc %d", argc);

	for (int i = 0; i < argc; i++) {
		printf("argv[%d] = %s\n", i, argv[i]);
	}

	// 二进制文件存储以8 bite作为一个单位
	// 所以取char作为存储最小单元
	char *path = argv[1];
	int size = atoi(argv[2]);
	
	yuv_reader(path, size);

	return 0;
}
