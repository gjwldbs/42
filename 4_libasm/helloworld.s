global start


section .text

start:
    mov     rax, 0x2000004 ; syscall for write
    mov     rdi, 1 ; file handle 1 is stdout
    mov     rsi, msg ; address of string output
    mov     rdx, msg.len ;number of bytes
    syscall ; invoke operating sys to do write

    mov     rax, 0x2000001 ; syscall for exit
    mov     rdi, 0 ;exit code 0
    syscall ;invoke operating system to exit


section .data

msg:    db      "Hello, world!", 10
.len:   equ     $ - msg