rm *.o
rm runme
gcc -c -Wall -Wextra -Werror -g -O0 -D BUFFER_SIZE=10000000 testbonus.c get_next_line_bonus.c get_next_line_utils.c
gcc -o runme *.o
rm *.o
#file_gnl = huge_file
./runme alphabet half_marge_top
#./runme huge_line > gnl_out
#diff -q gnl_out huge_line
