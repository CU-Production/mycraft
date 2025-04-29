cmake_minimum_required(VERSION 3.28)
project(mycraft)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(curl
    URL https://github.com/curl/curl/releases/download/curl-8_13_0/curl-8.13.0.tar.xz
    USES_TERMINAL_DOWNLOAD TRUE # <---- This is needed only for Ninja to show download progress
)
set(BUILD_SHARED_LIBS OFF CACHE INTERNAL "shared")
set(BUILD_TESTING OFF)
set(BUILD_CURL_EXE OFF CACHE INTERNAL "" FORCE)
set(CURL_ENABLE_SSL OFF CACHE INTERNAL "" FORCE)
set(CURL_USE_LIBPSL OFF CACHE INTERNAL "" FORCE)
set(CURL_CA_PATH "none" CACHE INTERNAL "" FORCE)
set(CURL_USE_SCHANNEL OFF CACHE INTERNAL "" FORCE)
set(CURL_WINDOWS_SSPI OFF CACHE INTERNAL "" FORCE)
set(CURL_USE_OPENSSL OFF CACHE INTERNAL "" FORCE)
set(CURL_USE_SECTRANSP OFF CACHE INTERNAL "" FORCE)
set(CURL_USE_MBEDTLS OFF CACHE INTERNAL "" FORCE)
set(BUILD_EXAMPLES OFF CACHE INTERNAL "" FORCE)
FetchContent_MakeAvailable(curl)

FILE(GLOB SOURCE_FILES src/*.c)
set(MYCRAFT_SRC ${SOURCE_FILES}
        deps/lodepng/lodepng.c
        deps/noise/noise.c
        deps/sqlite/sqlite3.c
        deps/tinycthread/tinycthread.c)

if(WIN32)
    add_executable(mycraft WIN32 ${MYCRAFT_SRC})
else()
    add_executable(mycraft ${MYCRAFT_SRC})
endif()

target_include_directories(mycraft PRIVATE deps/lodepng)
target_include_directories(mycraft PRIVATE deps/noise)
target_include_directories(mycraft PRIVATE deps/sqlite)
target_include_directories(mycraft PRIVATE deps/tinycthread)
target_include_directories(mycraft PRIVATE deps/sokol)
target_include_directories(mycraft PRIVATE deps/HandmadeMath)

if(APPLE)
    target_link_libraries(mycraft PRIVATE CURL::libcurl)
endif()

if(UNIX)
    target_link_libraries(mycraft PRIVATE dl CURL::libcurl)
endif()

if(WIN32)
    target_link_libraries(mycraft PRIVATE ws2_32.lib CURL::libcurl)
endif()
