
cmake_minimum_required(VERSION 3.4.1)
add_library(
             pngquantandroid

             SHARED

             src/main/cpp/pngquantandroid.cpp )


set(PNGQUANT_ROOT
        src/main/cpp/pngquant
)
include_directories(AFTER
        ${PNGQUANT_ROOT}
        ${PNGQUANT_ROOT}/lib
)

set(PNGQUANT_SRC
    ${PNGQUANT_ROOT}/lodepng.c
	${PNGQUANT_ROOT}/pngquant.c
	${PNGQUANT_ROOT}/lib/blur.c
	${PNGQUANT_ROOT}/lib/kmeans.c
	${PNGQUANT_ROOT}/lib/libimagequant.c
	${PNGQUANT_ROOT}/lib/mediancut.c
	${PNGQUANT_ROOT}/lib/mempool.c
	${PNGQUANT_ROOT}/lib/nearest.c
	${PNGQUANT_ROOT}/lib/pam.c
)
add_library(pngquant
        STATIC
        ${PNGQUANT_SRC}
)


set(PNG_ROOT
        ${PNGQUANT_ROOT}/png
)

set(ZLIB_ROOT
        ${PNGQUANT_ROOT}/zlib
)

include_directories(AFTER
        ${PNG_ROOT}
        ${ZLIB_ROOT}
)

set(PNG_SRC
    ${PNG_ROOT}/png.c
    ${PNG_ROOT}/pngerror.c
    ${PNG_ROOT}/pngget.c
    ${PNG_ROOT}/pngmem.c
    ${PNG_ROOT}/pngpread.c
    ${PNG_ROOT}/pngread.c
    ${PNG_ROOT}/pngrio.c
    ${PNG_ROOT}/pngrtran.c
    ${PNG_ROOT}/pngrutil.c
    ${PNG_ROOT}/pngset.c
    ${PNG_ROOT}/pngtrans.c
    ${PNG_ROOT}/pngwio.c
    ${PNG_ROOT}/pngwrite.c
    ${PNG_ROOT}/pngwtran.c
    ${PNG_ROOT}/pngwutil.c
)


set(ZLIB_SRC
            ${ZLIB_ROOT}/adler32.c
           ${ZLIB_ROOT}/compress.c
           ${ZLIB_ROOT}/crc32.c
           ${ZLIB_ROOT}/crc32.h
           ${ZLIB_ROOT}/deflate.c
           ${ZLIB_ROOT}/deflate.h
           ${ZLIB_ROOT}/gzclose.c
           ${ZLIB_ROOT}/gzguts.h
           ${ZLIB_ROOT}/gzlib.c
           ${ZLIB_ROOT}/gzread.c
           ${ZLIB_ROOT}/gzwrite.c
           ${ZLIB_ROOT}/infback.c
           ${ZLIB_ROOT}/inffast.c
           ${ZLIB_ROOT}/inffast.h
           ${ZLIB_ROOT}/inffixed.h
           ${ZLIB_ROOT}/inflate.c
           ${ZLIB_ROOT}/inflate.h
           ${ZLIB_ROOT}/inftrees.c
           ${ZLIB_ROOT}/inftrees.h
           ${ZLIB_ROOT}/trees.c
           ${ZLIB_ROOT}/trees.h
           ${ZLIB_ROOT}/uncompr.c
           ${ZLIB_ROOT}/zconf.h
           ${ZLIB_ROOT}/zutil.c
           ${ZLIB_ROOT}/zutil.h
)

add_library(png
        STATIC
        ${PNG_SRC}
)
add_library(zlib
        STATIC
        ${ZLIB_SRC}
)

find_library(
              log-lib

              log )

target_link_libraries(
                       pngquantandroid
                       pngquant
                       ${log-lib}
                       png
                       zlib
                        )