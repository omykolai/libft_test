
GREEN='\033[0;32m'
RED='\033[0;31m'
NORMAL='\033[0m'

mv test_lib.c test_lib

echo
NORM=$(norminette | grep -e Error)
if [ "$NORM" != "" ]
then
	echo "${RED}NORM ERROR"
	echo
fi

mv test_lib test_lib.c

make > make.log
gcc -Wall -Wextra -Werror -o test_lib test_lib.c -L. -lft
./test_lib 0 | grep ">>"
./test_lib 1 | grep ">>"
./test_lib 2 | grep ">>"
./test_lib 3 | grep ">>"
./test_lib 4 | grep ">>"
./test_lib 5 | grep ">>"
./test_lib 6 | grep ">>"
test -f res
if [ -f res ]
then
	chmod 666 res && rm res
	echo
elif [ "$NORM" == "" ]
then
	echo "${GREEN}All tests passed!${NORMAL}"
	echo
fi
chmod 777 test_lib
rm test_lib
make fclean > make.log
rm make.log