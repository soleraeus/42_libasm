			global			ft_strcpy
			section			.text

ft_strcpy:
			mov				rax, rdi
loop:
			cmp				[ rsi ], byte 0x0
			je				end
			mov				cl, byte [ rsi ]
			mov				[ rdi ], cl
			inc				rdi
			inc				rsi
			jmp				loop
end:
			mov				[ rdi ], byte 0x0
			ret
