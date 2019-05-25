# $@ 目标文件名
# $< 第一个依赖文件名，如果依赖目标是以模式（即“ % “）定义的，那么” $< “将是符合模式的一系列的文件集。注意，其是一个一个取出来的。
# $^ 依赖的文件集合，比如上文的 a.c b.c 。

# 编译指令
CC           := gcc

# 目录管理
D_SOURCE     := src
D_INCLUDE    := include
D_BUILD      := build

# foreach表示遍历$(D_SOURCE)的所有子目录同时把子目录下的.c文件遍历出来
F_CFILES     := $(foreach dir, $(D_SOURCE), $(wildcard $(dir)/*.c))

# notdir表示去除目录
# patsubst foo, bar, baz 表示把baz中的foo替换为bar
# addprefix表示增加前缀
F_OFILES     = $(addprefix $(D_BUILD)/, $(patsubst %.c, %.o, $(notdir $(F_CFILES))))

# 编译目标
T_MAIN       := main

# 编译为.o文件
$(D_BUILD)/%.o: $(D_SOURCE)/%.c
	$(CC) -c -I $(D_INCLUDE) $< -o $@

# 编译.out文件
$(T_MAIN): $(F_OFILES)
	$(CC) -o $@ $^

clean:
	rm -f $(D_BUILD)/* $(T_MAIN) 

.PHONY:
	clean
