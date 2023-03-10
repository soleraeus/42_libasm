			global		ft_write
			extern		__errno_location
			section		.text

ft_write:
			push		rbp
			mov			rax, 0x1
			syscall
			cmp			rax, 0x0
			jl			error
			pop			rbp
			ret

error:
			mov			rdi, rax
			call		__errno_location WRT ..plt
			neg			rdi
			mov			[ rax ], rdi
			mov			rax, -0x1
			pop			rbp
			ret	
