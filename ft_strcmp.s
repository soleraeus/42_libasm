			global			ft_strcmp
			section			.text

ft_strcmp:
			xor				rax,rax
loop:
			cmp				byte [ rsi ], byte 0x0
			je				end
			cmp				byte [ rdi ], byte 0x0
			je				end
			inc				rdi
			inc				rsi
end:
			mov				cl, [ rsi ]

