				global		ft_list_sort
				section		.text

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;ENTER;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
ft_list_sort:
				push		rbp							; enter
				mov			rbp, rsp
				cmp			rdi, 0x0					; check head of list is not NULL
				je			end
				sub			rsp, 0x18					; -0x18 on stack
				mov			rdx, qword [ rdi ]			; move pointer to first element in rdx
				mov			[ rsp ], qword rdx			; Put pointer to first element on stack
				mov			[ rsp + 0x8 ], qword rsi	; Put pointer to comparison function on stack

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;EXTERNAL LOOP, ITERATE OVER EACH ELEMENT;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
loop_ext:
				mov			rdx, [ rsp ]				; Put current element in rdx
				cmp			rdx, 0x0					; if pointer is NULL move to end
				je			end
				mov			rdi, [ rdx ]				; Put pointer on data of current struct in rdi
				mov			rcx, [ rdx + 0x8 ]			; Put pointer to next element in rcx
				cmp			rcx, 0x0					; if no next element move to end
				je			end
				mov			rsi, [ rcx ]				; Put data of next element in rsi
				mov			[ rsp + 0x10 ], qword rcx	; Push pointer to next element on stack

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;INNER LOOP, COMPARE CURRENT ELEMENT WITH NEXT ONES;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
loop_int:
				call		[ rsp + 0x8 ]				; call comparison function
				mov			rdx, [ rsp ]				; Recover current element
				mov			rdi, [ rdx ]				; put data of current element in rdi
				mov			rcx, [ rsp + 0x10 ]			; Recover pointer to other element
				mov			rsi, [ rcx ]				; put data of other element 
				cmp			eax, 0x0					; if ret of comparison function < 0, move to loop_int_next
				jle			loop_int_next
				mov			[ rdx ], rsi				; Put data in other element in current element
				mov			[ rcx ], rdi				; Put data of current element in other element
				mov			rdi, rsi					; Switch current data for other data

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;KEEP CURRENT ELEMENT, COMPARE WITH NEXT ONE IN THE LIST;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
loop_int_next:
				mov			rdx, [ rcx + 0x8]			; Load pointer to next on other element
				cmp			rdx, 0x0					; if null jump to end_inner
				je			end_inner
				mov			rsi, [ rdx ]				; load data in next element in rsi
				mov			[ rsp + 0x10 ], rdx			; save pointer to next on other element on stack
				jmp			loop_int					; loop

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;MOVE ON TO NEXT ELEMENT;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
end_inner:
				mov			rdx, [ rsp ]				; Put current element in rdx
				mov			rcx, [ rdx + 0x8 ]			; Put pointer to next element in rcx
				mov			[ rsp ], qword rcx			; Switch current element with next
				jmp			loop_ext					; loop
end:
				leave
				ret
