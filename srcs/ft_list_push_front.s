						global			ft_list_push_front
						extern			malloc
						section			.text

ft_list_push_front:
						push			rbp					; enter
						mov				rbp, rsp
						cmp				rdi, 0x0			; ret if pointer to head of list is NULL
						je				end
						push			rdi					; save list head and data on stack
						push			rsi
						mov				rdi, 16				; put 16 in first arg
						call			malloc WRT ..plt	; call malloc
						pop				rsi					; recover list head and data
						pop				rdi
						cmp				rax, 0x0			; go to end if malloc returned NULL
						je				end
						mov				rdx, [rdi]			; Put pointer to first element in rdx
						mov				[rax + 8], rdx		; New element->next = *(head of list)
						mov				[rax], rsi			; New element->data = data in arg
						mov				[rdi], qword rax	; *head = new element

end:
						pop				rbp					; leave
						ret
