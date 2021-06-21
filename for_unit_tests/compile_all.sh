rm *.o
rm runme
gcc -c -Wall -Wextra -Werror -g -O0 -D BUFFER_SIZE=10 testmain.c get_next_line.c get_next_line_utils.c
gcc -o runme *.o
rm *.o
#file_gnl = huge_file
./runme alphabet
#./runme huge_line > gnl_out
#diff -q gnl_out huge_line
