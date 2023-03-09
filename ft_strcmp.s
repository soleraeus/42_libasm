			global			ft_strcmp
			section			.text

ft_strcmp:
			xor				rax,rax
			xor				rcx,rcx
loop:
			mov				cl, byte [ rsi ]
			cmp				cl, byte 0x0
			je				end
			cmp				byte [ rdi ], cl
			jne				end
			inc				rdi
			inc				rsi
			jmp				loop
end:
			mov				al, byte [ rdi ]
			sub				eax, ecx
			ret
