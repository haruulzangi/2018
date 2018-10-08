#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int call_me() {
	return system("/bin/bash");
}

void function2() {
	char buf[128];
	read(STDIN_FILENO, buf, 256);
}

void function1() {
	gid_t gid = getegid();
	setresgid(gid, gid, gid);
}

int main(int argc, char** argv) {
	write(STDOUT_FILENO, "[+]feed me\n",12);
        function1();
	function2();
	write(STDOUT_FILENO, "[+]Zuv bailda\n", 14);
}
