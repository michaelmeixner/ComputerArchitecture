// Michael Meixner
sum:
    irmovq $8, %r8 // constant 8
    irmovq $1, %r9 // constant 1
    xorq %rax, %rax
    jmp loop
loop:
    andq %rsi, %rsi // checks flags
    jz end // jumps to end if count is 0
    mrmovq (%rdi), %r11
    addq %r8, %rdi
    subq %r9, %rsi
    andq %r11, %r11
    js negative
    jmp positive
positive:
    addq %r11, %rax
    jmp loop
negative:
    subq %r11, %rax
    jmp loop
end:
    ret