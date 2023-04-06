					global		ft_list_remove_if
					extern		free
					section		.text

ft_list_remove_if:
					enter		0x30, 0
					cmp			rdi, 0x0
					je			end
					mov			r8, [ rdi ]
					mov			[ rsp ], r8			; pointer to first element
					mov			[ rsp + 0x8 ], rsi	; data_ref
					mov			[ rsp + 0x10 ], rdx	; comp function
					mov			[ rsp + 0x18 ], rcx	; free function
					mov			[ rsp + 0x20 ], rdi	; list head
first_match:
					mov			rsi, [ rsp ]		; Load pointer to first element
					cmp			rsi, 0x0			; Check if not NULL, else go to end
					je			end
					mov			rdi, [ rsi ]		; Load value of first element as first param
					mov			rsi, [ rsp + 0x8]	; Load value of data_ref as second param
					call		[ rsp + 0x10 ]		; Call comp function
					cmp			eax, 0x0			; Check ret of comp function
					jne			main_loop			; jump to next step if data != data_ref
					mov			rsi, [ rsp ]		; Load address of first element
					mov			rdi, [ rsi ]		; Put data in first element as first argument
					call		[ rsp + 0x18 ]		; Call function to free data
					mov			rdi, [ rsp ]		; Load address of first element
					mov			r8, [ rdi + 0x8 ]	; Load value of pointer to next element in r8
					mov			r9, [ rsp + 0x20 ]	; Load pointer to list head
					mov			[ rsp ], r8			; Replace first element with next on the stack
					mov			[ r9 ], r8			; replace previous list headd with new list head
					call		free WRT ..plt		; free first element
					jmp			first_match			; Return to first_match loop

main_loop:
					mov			rsi, [ rsp ]		; Load address of current element
					mov			r8, [ rsi + 0x8 ]	; Get address of next element
					cmp			r8, 0x0				; Leave if next element is NULL (we reached the end)
					je			end
					mov			rdi, [ r8 ]			; Put data in next element as first argument
					mov			rsi, [ rsp + 0x8 ]	; Load value of data_ref as second value
					call		[ rsp + 0x10 ]		; Call comp function
					cmp			eax, 0x0			; Check ret of comp function
					je			remove_elem			; remove element if ret == 0
					mov			rsi, [ rsp ]		; Load address of previous element
					mov			r8, [ rsi + 0x8 ]	; Load address of current element
					mov			[ rsp ], r8			; replace previous element with current element
					jmp			main_loop			; iterate
					

remove_elem:
					mov			rsi, [ rsp ]		; Load address of previous element
					mov			r8, [ rsi + 0x8 ]	; Get address of current element
					mov			rdi, [ r8 ]			; Put data in current element as first argument
					call		[ rsp + 0x18 ]		; Call function to free data
					mov			rsi, [ rsp ]		; Load address of previous element
					mov			rdi, [ rsi + 0x8 ]	; Load value of pointer to next element in rdi
					mov			r8, [ rdi + 0x8 ]	; load address of next element
					mov			[ rsp + 0x28 ], r8	; save address of next element
					call		free WRT ..plt		; free current element
					mov			rsi, [ rsp ]		; Load address of previous element
					mov			r8, [ rsp + 0x28 ]	; Load saved address of next element
					mov			[ rsi + 0x8], r8	; Put address of next element in ppoint of first element
					jmp			main_loop			; Return to main loop
					
end:
					leave
					ret
