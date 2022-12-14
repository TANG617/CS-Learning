
###################################################################################################
# 编译工具链设置
PATH := ${PATH}:/your/tool_chain/path
TOOL_CHAIN = 
CC = ${TOOL_CHAIN}gcc
AR = ${TOOL_CHAIN}ar

DEBUG_BUILD ?= yes

# SHOW_COMMAND=yes，显示编译命令
ifeq (${SHOW_COMMAND}, yes)
QUIET :=
else
QUIET := @
endif

###################################################################################################
# 目录设置
# 工程根路径
PROJ_ROOT = $(abspath ../..)
# 中间文件缓存文件夹
TMP_PATH = $(abspath .)/tmp
# 当前路径
PWD_PATH = $(abspath .)

###################################################################################################
# 源文件.c
SRC := ${PROJ_ROOT}/module1/*.c
SRC += ${PROJ_ROOT}/module2/*.c
# 展开*匹配，获取所有源文件完整路径
SRC := $(wildcard ${SRC})

###################################################################################################
# 头文件路径设置
INCLUDE_PATH += /include/path1
INCLUDE_PATH += /include/path2
INCLUDE_PATH += ${PROJ_ROOT}/include/path1
INCLUDE_PATH += ${PROJ_ROOT}/include/path2

###################################################################################################
# 编译宏设定
DEFINE_SETTINGS := LINUX
DEFINE_SETTINGS += A72="A72"
DEFINE_SETTINGS += TARGET_NUM_CORES=1
DEFINE_SETTINGS += TARGET_ARCH=64
DEFINE_SETTINGS += ARCH_64
DEFINE_SETTINGS += ARM

###################################################################################################
# 库路径设置
# 静态库.a文件夹路径
STATIC_LIB_PATH := ${PROJ_ROOT}/moduleXXX1/lib
STATIC_LIB_PATH += ${PROJ_ROOT}/moduleXXX2/lib
# 动态库.so文件夹路径
DYNAMIC_LIB_PATH := ${PROJ_ROOT}/moduleXXX3/lib

###################################################################################################
# 库设置(静态库)
# STATIC_LIB += static_lib1
# STATIC_LIB += static_lib2
# STATIC_LIB += static_lib3
# STATIC_LIB += static_lib4
# 库设置(动态库)
# DYNAMIC_LIB := stdc++
# DYNAMIC_LIB += m
# DYNAMIC_LIB += rt
# DYNAMIC_LIB += pthread

###################################################################################################
# 编译选项
# CFLAGS := -fPIC -Wall -fms-extensions -Wno-write-strings -Wno-format-security
# CFLAGS += -fno-short-enums -Werror
# CFLAGS += -mlittle-endian  -Wno-format-truncation


CFLAGS = -g -Wall -Wextra -pedantic -Werror -target x86_64-apple-darwin20.3.0

###################################################################################################
# # 生成的中间文件.o
# OBJ := $(patsubst ${PROJ_ROOT}/%.c,${TMP_PATH}/%.o,${SRC})
# # 头文件存放路径设置
# INC := $(foreach path,${INCLUDE_PATH},-I${path})
# # 编译宏设置
# DEF := $(foreach macro,${DEFINE_SETTINGS},-D${macro})
# # 库设置
# LIB := -rdynamic -Wl,--cref
# LIB += $(foreach path,${DYNAMIC_LIB_PATH},"-Wl,-rpath-link=${path}")
# LIB += $(foreach path,${STATIC_LIB_PATH},-L${path})
# LIB += -Wl,-Bstatic -Wl,--start-group
# LIB += $(foreach lib,${STATIC_LIB},-l${lib})
# LIB += -Wl,--end-group
# LIB += -Wl,-Bdynamic
# LIB += $(foreach lib,${DYNAMIC_LIB},-l${lib})

# # 生成目标
# TARGET := ${PWD_PATH}/demo/demo
# # 生成目标中的详细符号信息文件
# DEP_FILE := -Wl,-Map=${TMP_PATH}/$(notdir ${TARGET}).dep

# .PHONY: all clean
# all: ${TARGET}

# ${TARGET}:${OBJ}
# 	@echo "[Linking $@]"
# 	${QUIET}${CC} ${OBJ} ${CFLAGS} ${LIB} -o $@ ${DEP_FILE} >/dev/null

# ${TMP_PATH}/%.o:${PROJ_ROOT}/%.c
# 	@echo "[Compiling $@]"
# 	@mkdir $(dir $@) -p
# 	${QUIET}${CC} -c $< -o $@ ${CFLAGS} ${DEF} ${INC} -MMD -MF $(patsubst %.o,%.dep,$@) -MT '$@'

# clean:
# 	@echo "[cleaning ${TARGET}]"
# 	${QUIET}rm -rf ${TARGET}
# 	${QUIET}rm -rf ${TMP_PATH}