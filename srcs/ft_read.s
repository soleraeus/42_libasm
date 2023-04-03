			global		ft_read
			extern		__errno_location
			section		.text

ft_read:
			push		rbp								; push rbp to 16-bit align stack before syscall
			xor			rax, rax						; put rax to zer0 (syscall for read)
			syscall
			pop			rbp								; restore rbp
			cmp			rax, 0x0						; check if ret < 0. if rax under 0 then set errno
			jl			error
			ret											; ret

error:
			neg			rax								; get proper errno (positive)
			push		rax								; save error number on the stack
			call		__errno_location WRT ..plt		; get pointer to errno location
			pop			rdi								; put errno in rdi
			mov			[ rax ], rdi					; set errno
			mov			rax, -0x1						; set rax as -1
			ret	
