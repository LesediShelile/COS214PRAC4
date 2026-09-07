# COS214PRAC4


 /----DOCKER---/
build:
docker build -t taskforge .
compile:
docker run --rm taskforge make
run:
docker run --rm taskforge ./taskforge

run with GDB
docker run --rm -it taskForge gdb ./taskforge

run with valgrind 
docker run --rm taskforge valgrind --leak-check=full --show-leak-kinds=all ./taskforge

