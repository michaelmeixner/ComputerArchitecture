# Michael Meixner, Lab 8

sum:
    xorq %rax, %rax
    andq %rsi, %rsi
    jmp test
loop:
    mrmovq (%rdi), %r10
    addq %r10, %rax
    iaddq $8, %rdi
    isubq $1, %rsi
test:
    jne loop
    ret