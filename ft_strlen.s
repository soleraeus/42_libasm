			global		ft_strlen
			section		.text

ft_strlen:
			xor			eax, eax		; init counter at 0
loop:		
			cmp			[rdi], byte 0	; test if current char is '\0' 
			jz			end				; if yes, jump to ret
			inc			eax				; increment counter
			inc			rdi				; increment pointer to point to next char
			jmp			loop			; loop
end:
			ret
