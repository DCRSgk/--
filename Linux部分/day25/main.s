	.file	"main.c"
	.text
	.globl	func1
	.type	func1, @function
func1:	//func1函数
.LFB0:
	.cfi_startproc
	pushq	%rbp  //压栈
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp) //传入的数组指针
	movl	%esi, -28(%rbp) //传入的size
	movl	$0, -8(%rbp)    // cnt =0
	movl	$0, -4(%rbp)	// i=0
	jmp	.L2  //执行L2语句
.L3:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax      //cnt+=arr[i]
	movl	(%rax), %eax
	addl	%eax, -8(%rbp)		
	addl	$1, -4(%rbp)		//i++
.L2:
	movl	-4(%rbp), %eax	 //
	cmpl	-28(%rbp), %eax  //
	jl	.L3
	movl	-8(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	func1, .-func1
	.globl	func2
	.type	func2, @function
func2:	//func2函数
.LFB1:
	.cfi_startproc
	pushq	%rbp				 //压栈
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)	//传入a的值
	movl	%esi, -24(%rbp)	//传入b的值
	movl	-20(%rbp), %eax	//tmp=a
	movl	%eax, -4(%rbp)  //int tmp（给tmp指定地址
	movl	-24(%rbp), %eax	   //a = b 取出-24(%rbp)为b的值 , 将b的值给%eax
	movl	%eax, -20(%rbp)    //更新a地址里的值
	movl	-4(%rbp), %eax	   //存放在tmp地址中的值给eax
	movl	%eax, -24(%rbp)    // b = tmp  -24(%rbp)为b的值 ,将%eax的值给b
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	func2, .-func2
	.globl	func3
	.type	func3, @function
func3:	//func3函数
.LFB2:
	.cfi_startproc
	pushq	%rbp			//压栈
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)  //指针a
	movq	%rsi, -32(%rbp)  //指针b
	movq	-24(%rbp), %rax  //指针tmp
	movl	(%rax), %eax	 //(%rax)存放 %eax的值

	movl	%eax, -4(%rbp)   //交换指针
	movq	-32(%rbp), %rax  //交换值

	movl	(%rax), %edx        //交换指针
	movq	-24(%rbp), %rax		//交换值

	movl	%edx, (%rax)		//交换指针
	movq	-32(%rbp), %rax     //交换值

	movl	-4(%rbp), %edx
	movl	%edx, (%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	func3, .-func3
	.globl	main
	.type	main, @function
main:	//主函数
.LFB3:
	.cfi_startproc
	pushq	%rbp	 //压栈
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$1, -48(%rbp) //变量i的数值和地址
	movl	$3, -40(%rbp) //变量j的数值和地址
	movl	$5, -44(%rbp) //变量k的数值和地址
	movl	$1, -32(%rbp) /* 此
	movl	$2, -28(%rbp)    处
	movl	$3, -24(%rbp)    为
	movl	$4, -20(%rbp)    数
	movl	$5, -16(%rbp)    组
	movl	$6, -12(%rbp)	 arr[6] 连续储存 */
	leaq	-32(%rbp), %rax  //传地址
	movl	$6, %esi
	movq	%rax, %rdi
	call	func1  //函数调用
	movl	%eax, -36(%rbp) //-36(%rbp)为数组指针？
	movl	-48(%rbp), %eax
	movl	-40(%rbp), %edx
	movl	%edx, %esi
	movl	%eax, %edi
	call	func2  //函数调用
	leaq	-44(%rbp), %rdx //变量i的地址
	leaq	-48(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	func3  //函数调用
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L9
	call	__stack_chk_fail@PLT
.L9:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
