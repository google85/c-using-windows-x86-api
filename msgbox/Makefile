SRC_FILE = msgbox

include ../Makefile.include

## build: Build overrided to include manifest
.PHONY: build
build:
	mkdir -p ${BUILD_DIR} && chown 1000:1000 ${BUILD_DIR}
# 	Compile the resource (COFF format for i686)
	i686-w64-mingw32-windres -I${SRC_DIR} ${SRC_DIR}/${SRC_FILE}.rc -o ${BIN_OUT}.res --output-format=coff
# 	build with include resource in binary
	i686-w64-mingw32-gcc \
		-O2 -masm=intel \
		-fno-asynchronous-unwind-tables \
		-fno-ident \
		${SRC_DIR}/${SRC_FILE}.c \
		${BIN_OUT}.res \
		-o ${BIN_OUT}.exe \
	-lkernel32 -luser32 -mwindows
