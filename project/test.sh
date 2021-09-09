#!/bin/bash

NBR_TEST_DFLT=5

NBR_TEST_1=$NBR_TEST_DFLT
NBR_TEST_2=$NBR_TEST_DFLT
NBR_TEST_3=$NBR_TEST_DFLT

RESULT=""
ARG=""
TEST_ID=0

CLR_RED="\033[31m"
CLR_GREEN="\033[32m"
CLR_YELLOW="\033[33m"
CLR_BLUE="\033[34m"
CLR_BOLD="\033[1m"
CLR_DFLT="\033[0m"

new_test() {
	let TEST_ID+=1
}

title() {
	printf "\n${CLR_YELLOW}===> "

	for word in $@
	do
		printf "%s " $word
	done

	printf " <===${CLR_DFLT}\n"
}

success() {
	printf "${CLR_GREEN}[OK]${CLR_DFLT}"
}

fail() {
	printf "${CLR_RED}[KO]${CLR_DFLT}\n"
	echo $RESULT
	echo $ARG
	echo $(./push_swap $ARG)
}

check()
{
	if [ "$RESULT" == "$1" ]; then
		success
	else
		fail
		exit 1
	fi
}

set_random_arg() {
	ARG=`python3 -c "import random; \
		print(' '.join(str(i) for i in random.sample(range(-2111222333, 2111222333), $1)))"`
	# echo "$ARG"
}

ps_checker() {
	RESULT=$(./push_swap $ARG 2>&1 | ./checker $ARG 2>&1 | tail -1)
	COUNT=$(./push_swap $ARG 2>&1 | wc -l)

	printf "Test #%-2d    [%5d]    " $TEST_ID $COUNT
	check OK
	echo
}

run_random() {
	for i in $(seq $1)
	do
		new_test
		set_random_arg $2
		ps_checker
	done
}

main() {

	if [ "$1" ]; then
		NBR_TEST_1=$1
	fi

	if [ "$2" ]; then
		NBR_TEST_2=$2
	fi

	if [ "$3" ]; then
		NBR_TEST_3=$3
	fi

	title "SIMPLE VERSION"

	new_test; ARG="2 1 0"; ps_checker
	new_test; ARG="1 5 2 4 3"; ps_checker
	new_test; ARG="24 85 9 23 74"; ps_checker
	new_test; ARG="-3 5 4 3"; ps_checker
	new_test; ARG="5 4 3 2 1"; ps_checker
	new_test; ARG="2 3 1"; ps_checker

	title "SIMPLE VERSION (random 5)"
	run_random $NBR_TEST_1 5

	title "MIDDLE VERSION (random 100)"
	run_random $NBR_TEST_2 100

	title "ADVANCED VERSION (random 500)"
	run_random $NBR_TEST_3 500

	echo
}

main $1 $2 $3
