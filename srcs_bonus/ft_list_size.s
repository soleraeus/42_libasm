						global			ft_list_size
						section			.text

ft_list_size:
						xor				rax, rax		; zero rax

loop:
						cmp				rdi, 0x0		; if current == NULL, jump to end
						je				end
						inc				rax				; increment size (i++)
						mov				rdi, [rdi + 8]	; Move on ot next
						jmp				loop

end:
						ret
