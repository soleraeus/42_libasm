					global		ft_atoi_base
					section		.text

ft_atoi_base:
					enter		0x0, 0x0			; entering procedure
					xor			rax, rax			; Put ret to 0
					mov			r9, r9				; Init sign as 0
					cmp			rsi, 0x0			; Check base is not NULL
					je			end
					cmp			rdi, 0x0			; Check string is not null
					je			end
					xor			r8					; Init current char to 0
					mov			dl, byte [ rsi ]	; Get first character
check_base:
					cmp			dl, 0x0				; Check if reached end, if yes got to next step
					je			get_sign			
					cmp			dl, 0x2B			; Check if c == '+'
					je			end
					cmp			dl, 0x2D			; Check if c == '-'
					je			end
					cmp			dl, 0x20			; Check if c == ' '
					je			end
					cmp			dl, 0x09			; Check if c == '\t'
					je			end
					cmp			dl, 0x0A			; Check if c == '\n'	
					je			end
					cmp			dl, 0x0B			; Check if c == '\v'	
					je			end
					cmp			dl, 0x0C			; Check if c == '\f'	
					je			end
					cmp			dl, 0x0D			; Check if c == '\r'	
					je			end
					mov			rcx, r8 + 1			; Start at next char;
base_loop:
					cmp			dl, byte [ rsi + rcx ]
					je			end
					cmp			byte [ rsi + rcx ], 0x0
					je			next_base_loop
					inc			rcx
					jmp			base_loop

next_base_loop:
					inc			r8
					mov			dl, byte [ rsi + r8 ]	; Get first character
					jmp			check_base

get_sign:
					cmp			r8, 0x0				; check base is not empty
					je			end
					cmp			r8, 0x1				; check base does not have size 1
					je			end
					

end:				
					cmp			r9, 0x1	
					je			neg_ret
					leave
					ret
neg_ret:
					neg			eax
					leave
					ret
