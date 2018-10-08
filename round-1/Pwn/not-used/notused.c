#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char * n0t_us3d = "/bin/bash";

int    call_me() {
	return system("/bin/date");
}

void function1() {
	char buf[128];
	read(STDIN_FILENO, buf, 256);
}

void function2() {
	gid_t gid = getegid();
	setresgid(gid, gid, gid);
}

int main(int argc, char** argv) {
	write(STDOUT_FILENO, "[+] Feed me more!!!\n",20);
        function1();
	function2();
	write(STDOUT_FILENO, "[+] zuv baildaa\n", 17);
}


