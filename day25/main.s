	.file	"main.c"
	.text
	.globl	func1
	.type	func1, @function
func1:	//func1����
.LFB0:
	.cfi_startproc
	pushq	%rbp  //ѹջ
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp) //���������ָ��
	movl	%esi, -28(%rbp) //�����size
	movl	$0, -8(%rbp)    // cnt =0
	movl	$0, -4(%rbp)	// i=0
	jmp	.L2  //ִ��L2���
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
func2:	//func2����
.LFB1:
	.cfi_startproc
	pushq	%rbp				 //ѹջ
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)	//����a��ֵ
	movl	%esi, -24(%rbp)	//����b��ֵ
	movl	-20(%rbp), %eax	//tmp=a
	movl	%eax, -4(%rbp)  //int tmp����tmpָ����ַ
	movl	-24(%rbp), %eax	   //a = b ȡ��-24(%rbp)Ϊb��ֵ , ��b��ֵ��%eax
	movl	%eax, -20(%rbp)    //����a��ַ���ֵ
	movl	-4(%rbp), %eax	   //�����tmp��ַ�е�ֵ��eax
	movl	%eax, -24(%rbp)    // b = tmp  -24(%rbp)Ϊb��ֵ ,��%eax��ֵ��b
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	func2, .-func2
	.globl	func3
	.type	func3, @function
func3:	//func3����
.LFB2:
	.cfi_startproc
	pushq	%rbp			//ѹջ
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)  //ָ��a
	movq	%rsi, -32(%rbp)  //ָ��b
	movq	-24(%rbp), %rax  //ָ��tmp
	movl	(%rax), %eax	 //(%rax)��� %eax��ֵ

	movl	%eax, -4(%rbp)   //����ָ��
	movq	-32(%rbp), %rax  //����ֵ

	movl	(%rax), %edx        //����ָ��
	movq	-24(%rbp), %rax		//����ֵ

	movl	%edx, (%rax)		//����ָ��
	movq	-32(%rbp), %rax     //����ֵ

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
main:	//������
.LFB3:
	.cfi_startproc
	pushq	%rbp	 //ѹջ
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$1, -48(%rbp) //����i����ֵ�͵�ַ
	movl	$3, -40(%rbp) //����j����ֵ�͵�ַ
	movl	$5, -44(%rbp) //����k����ֵ�͵�ַ
	movl	$1, -32(%rbp) /* ��
	movl	$2, -28(%rbp)    ��
	movl	$3, -24(%rbp)    Ϊ
	movl	$4, -20(%rbp)    ��
	movl	$5, -16(%rbp)    ��
	movl	$6, -12(%rbp)	 arr[6] �������� */
	leaq	-32(%rbp), %rax  //����ַ
	movl	$6, %esi
	movq	%rax, %rdi
	call	func1  //��������
	movl	%eax, -36(%rbp) //-36(%rbp)Ϊ����ָ�룿
	movl	-48(%rbp), %eax
	movl	-40(%rbp), %edx
	movl	%edx, %esi
	movl	%eax, %edi
	call	func2  //��������
	leaq	-44(%rbp), %rdx //����i�ĵ�ַ
	leaq	-48(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	func3  //��������
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
