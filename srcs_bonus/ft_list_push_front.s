						global			ft_list_push_front
						extern			malloc
						section			.text

ft_list_push_front:
						push			rbp
						mov				rbp, rsp
						cmp				rdi, 0x0
						je				end
						push			rdi
						push			rsi
						mov				rdi, 16
						call			malloc WRT ..plt
						pop				rsi
						pop				rdi
						cmp				rax, 0x0
						je				end
						mov				rdx, [rdi]
						mov				[rax + 8], rdx
						mov				[rax], rsi
						mov				[rdi], qword rax

end:
						pop				rbp
						ret
