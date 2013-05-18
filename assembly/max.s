.section .data
data_items:
    .long 3, 67, 34, 22, 45, 75, 54, 34, 44, 33, 22, 11, 66, 0

.section .text
.globl _start
_start:
    # move 0 into the index register
    movl $0, %edi

    # load the first byte of data into %eax
    mov data_items(,%edi,4), %eax

    # %eax is the biggest now, %ebx is used to store the biggest
    mov %eax, %ebx

start_loop:
    # check to see if we've hit the end. Last item is 0
    cmpl $0, %eax

    # jump to loop_exit if comparison result is equal
    je loop_exit
    
    # increase the value of %edi
    incl %edi

    # load next data_item into %eax
    movl data_items(,%edi,4), %eax

    # compare value
    cmpl %ebx, %eax

    # jumo to start_loop if comparison result is less than (<)
    jle start_loop

    # then means %eax is larger than %ebx, which is the current biggest.
    movl %eax, %ebx

    jmp start_loop

loop_exit:
    # %ebx is the status code for _exit system call and
    # it already has the maximum number
    movl $1, %eax
    int $0x80
