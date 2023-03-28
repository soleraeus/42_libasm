			global		ft_strlen
			section		.text

ft_strlen:
			xor			rax, rax			; init counter at 0
loop:		
			cmp			[rdi + rax], byte 0	; test if current char is '\0' 
			jz			end					; if yes, jump to ret
			inc			rax					; increment counter
			jmp			loop				; loop
end:
			ret
