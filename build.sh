#!/bin/bash

# APP NAME
EXECUTABLE_NAME="JamEngine"

# DIRECTORIES
SOURCE_DIRECTORY="./source/"
BUILD_DIRECTORY="./build/"

# COMPILE TIME ARGUMENTS
DEBUG_ARUGMENTS=("-W" "-Wall" "-Wextra")

# App CPP files in source
SOURCE_FILES="$(find ./source/ -maxdepth 3 -type f -name "*.cpp")"
VENDOR_FILES="./vendor/stb_image/stb_image.cpp ./vendor/glad.c"
LINKED_LIBRARIES="./build/SDL -Lvendor -I./build/SDL -lglad -lSDL3 -lm -lstdc++"

# todo(jack): a flag setting for printing these filenames... might not always want to see
for file in "${SOURCE_FILES[@]}"
do
  printf "Found Source File: \n$file"
done
printf "\n\n"

# todo(jack): two step compilation with object file output to build dir
# HERE

clang ${DEBUG_ARGUMENTS[@]} ${SOURCE_FILES[@]} $VENDOR_FILES -o $BUILD_DIRECTORY$EXECUTABLE_NAME -L $LINKED_LIBRARIES

printf "\n==================\n  Build Complete\n==================\n."

# todo(jack): Compile game object files
  # gcc -c ./source/main.cpp -o ./build/main.o
  # gcc -c ./source/graphics/render.cpp -o .build/render.o
  # gcc -c ./source/graphics/resource_manager.cpp -o .build/resource_manager.o
  # gcc -c ./source/graphics/shader.cpp -o .build/shader.o
  # gcc -c ./source/graphics/texture.cpp -o .build/texture.o
  # gcc -c ./source/platform/platform.cpp -o .build/platform.o
  # gcc -c ./source/platform/sdl3/platform_sdl.cpp -o .build/platform_sdl.o
  # gcc -c ./source/input/input.cpp -o .build/input.o
  # gcc -c ./vendor/stb_image/stb_image.cpp -o ../build/stb_image.o
  # gcc -c ./vendor/glad.c -o ../build/glad.o

