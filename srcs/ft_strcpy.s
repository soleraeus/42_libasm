			global			ft_strcpy
			section			.text

ft_strcpy:
			mov				rax, rdi			; Put dest in rax (char *)
loop:
			cmp				[ rsi ], byte 0x0	; Jump to end if end of src
			je				end
			mov				cl, byte [ rsi ]	; Load current byte of src in cl
			mov				[ rdi ], cl			; Copy it at location pointed to by dest
			inc				rdi					; Increment both and loop
			inc				rsi
			jmp				loop
end:
			mov				[ rdi ], byte 0x0	; Add null-termination to copy
			ret
