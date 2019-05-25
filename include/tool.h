#ifndef H_READ
#define H_READ

struct yuv {
	char y;
	char u;
	char v;
};
typedef struct yuv YUV;

struct rgb {
	char r;
	char g;
	char b;
};
typedef struct rgb RGB;

/**
 * 图形化yuv422p格式图像
 *
 * YUV 422P 格式，又叫做 I422，采用的是平面格式进行存储
 * 先存储所有的 Y 分量，再存储所有的 U 分量，再存储所有的 V 分量
 */
// void yuv_visualizing_422p(char *path, int width, int height, int frames);


/**
 * 图形化yuv444p格式
 * YUV 4:4:4 采样，意味着 Y、U、V 三个分量的采样比例相同
 * 因此在生成的图像里，每个像素的三个分量信息完整，都是 8 bit，也就是一个字节。
 */
// void yuv_visualizing_444p(char *path, int width, int height, int frames); 


// 读取yuv文件并输出char
void yuv_reader(char *path, int size);

// YUV编码转RGB
RGB yuv_codec_rgb(YUV yuv);
#endif
