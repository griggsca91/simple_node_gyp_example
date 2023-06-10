clang -shared -undefined dynamic_lookup -o libaddtwo.dylib add_two.c
clang main.c libaddtwo.dylib
./a.out
