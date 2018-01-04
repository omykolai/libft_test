GREEN='\033[0;32m'
NORMAL='\033[0m'

make > make.log
gcc -Wall -Wextra -Werror -o test_lib test_lib.c -L. -lft
echo
./test_lib 0 | grep ">>"
./test_lib 1 | grep ">>"
./test_lib 2 | grep ">>"
./test_lib 3 | grep ">>"
./test_lib 4 | grep ">>"
./test_lib 5 | grep ">>"
./test_lib 6 | grep ">>"
test -f res
[ -f res ] && chmod 666 res && rm res || echo "${GREEN}All tests passed!${NORMAL}"
echo
chmod 777 test_lib
rm test_lib
make fclean > make.log
rm make.log