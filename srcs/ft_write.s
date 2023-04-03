			global		ft_write
			extern		__errno_location
			section		.text

ft_write:
			push		rbp								; push rbp to stack
			mov			rax, 0x1						; syscall number 1
			syscall
			pop			rbp								; restore rbp
			cmp			rax, 0x0						; check if ret < 0, if yes go to error
			jl			error
			ret

error:
			neg			rax								; get proper errno (positive)
			push		rax								; save error number on the stack
			call		__errno_location WRT ..plt		; get pointer to errno location
			pop			rdi								; put errno in rdi
			mov			[ rax ], rdi					; set errno
			mov			rax, -0x1						; set rax as -1
			ret
