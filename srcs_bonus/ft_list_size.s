						global			ft_list_size
						section			.text

ft_list_size:
						xor				rax, rax

loop:
						cmp				rdi, 0x0
						je				end
						inc				rax
						mov				rdi, [rdi + 8]
						jmp				loop

end:
						ret
