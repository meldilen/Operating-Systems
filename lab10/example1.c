    #include <stdio.h>

    int main() {
        printf("Привет, мир!\n");
        return 0;
    }
    

// diana@diana-VirtualBox:~/Документы/OS/lab10$ file example1.c
// example1.c: C source, ASCII text
// diana@diana-VirtualBox:~/Документы/OS/lab10$ gcc example1.c -o example
// diana@diana-VirtualBox:~/Документы/OS/lab10$ file example
// example: ELF 64-bit LSB pie executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, BuildID[sha1]=42f021c22f83a9f4b0a53eec8f1f77d4c2ead837, for GNU/Linux 3.2.0, not stripped

// diana@diana-VirtualBox:~/Документы/OS/lab10$ file example1.c
// example1.c: C source, Unicode text, UTF-8 text
// diana@diana-VirtualBox:~/Документы/OS/lab10$ file example
// example: ELF 64-bit LSB pie executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, BuildID[sha1]=7306ee09813f4de7868af098d5ae24218c8de6fb, for GNU/Linux 3.2.0, not stripped