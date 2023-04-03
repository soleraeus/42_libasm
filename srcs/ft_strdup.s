			global			ft_strdup
			extern			malloc
			extern			ft_strlen
			extern			ft_strcpy
			section			.text
			

ft_strdup:
			push			rdi					; save string on stack and align stack
			call			ft_strlen			; get length of string
			mov				rdi, rax			; Put length of string as first arg
			inc				rdi					; Increment length of sting for null-termination
			call			malloc WRT ..plt	; call to malloc
			pop				rsi					; recover source string in second arf
			cmp				rax, 0x0			; check malloc did not return NULL, otherwise return
			je				end
			mov				rdi, rax			; Put address given by malloc as first arg
			push			rbp					; Push base pointer to align stack
			call			ft_strcpy			; Call strcpy
			pop				rbp					; Recover rbp
end:
			ret
