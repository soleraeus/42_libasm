			global			ft_strcmp
			section			.text

ft_strcmp:
			xor				rax,rax				; set rax to 0
			xor				rcx,rcx				; set rcx to 0
loop:
			mov				cl, byte [ rsi ]	; Load first byte of s2
			cmp				cl, byte 0x0		; Jump to end if end of string has been reached
			je				end
			cmp				byte [ rdi ], cl	; Compare current char at s1 with current char at s2, jump to end if different
			jne				end
			inc				rdi					; increment both strings
			inc				rsi
			jmp				loop				; move to next comparison
end:
			mov				al, byte [ rdi ]	; Put current char at s1 in al
			sub				eax, ecx			; Diff between current char at s1 and s2
			ret
