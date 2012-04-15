# C++ definitions (e.g. "-Dsymbol_with_value=0xDEAD -Dsymbol_without_value")
CXX_DEFS += -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DSTM32F103VBXX

# C definitions
C_DEFS += -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DSTM32F103VBXX

# include directories
INC_DIRS += Boards/boards/f1xx
INC_DIRS += Boards/boards/f1xx/f103
INC_DIRS += $(ST_LIB)/Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/
INC_DIRS += $(ST_LIB)/Libraries/STM32F10x_StdPeriph_Driver/inc/

# source files directories
SRC_DIRS += Boards/boards/f1xx
SRC_DIRS += Boards/boards/f1xx/mediumDensity
SRC_DIRS += Boards/boards/f1xx/f103
SRC_DIRS += $(ST_LIB)/Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/
SRC_DIRS += $(ST_LIB)/Libraries/STM32F10x_StdPeriph_Driver/src/