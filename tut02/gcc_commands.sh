// Compilation directly into executable
gcc compile_example.c vowels.c vowels.h -o prog

// Only preprocessor step
gcc compile_example.c vowels.c vowels.h -E > preprocessor_out

// Compilation into assembly
gcc compile_example.c vowels.c vowels.h -S

// Compilation into object code
gcc compile_example.c vowels.c vowels.h -c 

// View binary machine instructions
xxd -b compile_example.o

// Remove all compilation files
rm compile_example.s compile_example.o preprocessor_out prog vowels.h.gch vowels.o vowels.s