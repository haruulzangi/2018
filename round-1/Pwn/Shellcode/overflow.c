#include <stdio.h>
#include <stdlib.h>

int token = 0;

typedef void (*function_ptr)();

void function(){
    gid_t gid = getegid();
    setresgid(gid, gid, gid);
}

int main(int argc, char **argv){
    char inp[200];

    function();

    read(0, inp, 200);

    ((function_ptr)inp)();
}
