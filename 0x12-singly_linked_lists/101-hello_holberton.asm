section .data
    hello_holberton db "Hello, Holberton", 0
    format db "%s", 0
    newline db 10, 0

section .text
    extern printf

    global _start

_start:
    ; Prepare the arguments for printf
    push rsi                ; Push the pointer to the format string
    lea rsi, [hello_holberton]
    push rsi                ; Push the pointer to the hello_holberton string
    call printf             ; Call printf

    ; Cleanup the stack after the function call
    add rsp, 16

    ; Print a new line
    push rsi                ; Push the pointer to the format string
    lea rsi, [newline]
    push rsi                ; Push the pointer to the newline string
    call printf             ; Call printf

    ; Exit the program
    mov rax, 60             ; System call number for exit
    xor edi, edi            ; Exit status 0
    syscall

