					global		ft_atoi_base
					section		.text

ft_atoi_base:
					enter		0x0, 0x0			; entering procedure
					xor			rax, rax			; Put ret to 0
					xor			r9, r9				; Init sign as 0
					cmp			rsi, 0x0			; Check base is not NULL
					je			end
					cmp			rdi, 0x0			; Check string is not null
					je			end
					xor			r8, r8					; Init current char to 0
					mov			dl, byte [ rsi ]	; Get first character
check_base:
					cmp			dl, 0x0				; Check if reached end, if yes got to next step
					je			skip_whitespaces			
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
					mov			rcx, r8				; Start at next char;
					inc			rcx
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

skip_whitespaces:
					cmp			r8, 0x0				; check base is not empty
					je			end
					cmp			r8, 0x1				; check base does not have size 1
					je			end
					xor			rcx, rcx			; put rcx to zero
inner_skip_ws:
					mov			dl, [ rdi + rcx ]	; Load current character
					cmp			dl, 0x0				; jump to end if reached end of number
					je			end
					cmp			dl, 0x20			; Check if c == ' '
					je			inc_and_skip
					cmp			dl, 0x09			; Check if c == '\t'
					je			inc_and_skip
					cmp			dl, 0x0A			; Check if c == '\n'	
					je			inc_and_skip
					cmp			dl, 0x0B			; Check if c == '\v'	
					je			inc_and_skip
					cmp			dl, 0x0C			; Check if c == '\f'	
					je			inc_and_skip
					cmp			dl, 0x0D			; Check if c == '\r'	
					je			inc_and_skip
					jmp			get_sign			; if not whitespace, move to finding sign

inc_and_skip:
					inc			rcx					; Next char
					jmp			inner_skip_ws		; skip next whitespaces
						

get_sign:
					mov			dl, [ rdi + rcx ]	; Load current character
					cmp			dl, 0x2B			; skip '+' sign
					je			skip_sign
					cmp			dl, 0x2D			; invert current sign if c == '-'
					je			invert_sign
					jmp			get_number			; move to parsing the number
					
invert_sign:
					xor			r9, 0x1				; invert sign

skip_sign:
					inc			rcx					; get to next char
					jmp			get_sign			; move to next char

get_number:	
					xor			rdx, rdx			; Put rdx to zero
					mov			dl,	[ rdi + rcx ]	; Load current char
					cmp			dl, 0x0				; Test if end of string
					je			end
					xor			r10, r10			; r10 = 0
inner_test:
					cmp			r8, r10				; Test if reached the end of base
					je			end
					cmp			dl, [ rsi + r10 ]	; Test if char is equal
					je			inc_next_char
					inc			r10					; Move to next char of the base
					jmp			inner_test

inc_next_char:
					mul			r8					; multiply current number by size of base
					add			rax, r10			; add current value	
					inc			rcx
					jmp			get_number			

end:				
					cmp			r9, 0x1	
					je			neg_ret
					leave
					ret
neg_ret:
					neg			eax
					leave
					ret
