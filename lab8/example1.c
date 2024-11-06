#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    char* message = (char*)malloc(100 * sizeof(char));
    if (message == NULL) {
        printf("Fatal\n");
        return 1;
    }
    strcpy(message, "Good morning, Heap Memory!");
    printf("Message: %s\n", message);
    while(1){
        sleep(1);
    }
    free(message);
    return 0;
}

// 55b98d6e1290: 0000 0000 0000 0000 7100 0000 0000 0000  ........q.......
// 55b98d6e12a0: 476f 6f64 206d 6f72 6e69 6e67 2c20 4865  Good morning, He
// 55b98d6e12b0: 6170 204d 656d 6f72 7921 0000 0000 0000  ap Memory!......

// Locked:                0 kB
// THPeligible:           0
// VmFlags: rd wr mr mw me ac sd 
// 55b98d6e1000-55b98d702000 rw-p 00000000 00:00 0                          [heap]
// Size:                132 kB
// KernelPageSize:        4 kB
// MMUPageSize:           4 kB