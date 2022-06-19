	global start
	section .text
	

start:
	mov	rax, 7
	call 	fibonacci	

exit:
	mov 	rax, 0x02000001
	mov	rdi, 0
	syscall


fibonacci:
	push	rbx
	push 	rcx
	push	rdx	
	
	mov 	rdx, 2		; counter


	mov	rbx, 1		; f1
	mov	rcx, 1		; f2

loop:
	cmp	rdx, rax
	jge 	end
	
	push	rcx
	add	rcx, rbx
	pop	rbx	
	
	inc	rdx
	jmp 	loop	
	
end:
	mov	rax, rcx	

	pop	rcx
	pop	rbx
	pop	rdx

	ret	

