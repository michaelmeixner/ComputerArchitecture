# Michael Meixner, Lab 8

rproduct:
    cmpq $1, %rsi
    jle return
    pushq %rdi
    inc %rdi
    dec %rsi
    call rproduct
    imulq (%rsp), %rax
    popq
    ret
return:
    irmovq $1, %rax
    ret