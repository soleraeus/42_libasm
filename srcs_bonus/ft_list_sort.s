				global		ft_list_sort
				section		.text

ft_list_sort:
				push		rbp
				mov			rbp, rsp
				cmp			rdi, 0x0
				je			end
				sub			rsp, 0x18
				mov			rdx, qword [ rdi ]
				mov			[ rsp ], qword rdx
				mov			[ rsp + 0x8 ], qword rsi
loop_ext:
				mov			rdx, [ rsp ]
				cmp			rdx, 0x0
				je			end
				mov			rdi, [ rdx ]
				mov			rcx, [ rdx + 0x8 ]
				cmp			rcx, 0x0
				je			end
				mov			rsi, [ rcx ]
				mov			[ rsp + 0x10 ], qword rcx

loop_int:
				call		[ rsp + 0x8 ]
				mov			rdx, [ rsp ]
				mov			rdi, [ rdx ]
				mov			rcx, [ rsp + 0x10 ]
				mov			rsi, [ rcx ]
				cmp			eax, 0x0
				jle			loop_int_next
				mov			[ rdx ], rsi
				mov			[ rcx ], rdi 
				mov			rdi, rsi

loop_int_next:
				mov			rdx, [ rcx + 0x8]
				cmp			rdx, 0x0
				je			end_inner
				mov			rsi, [ rdx ]
				mov			[ rsp + 0x10 ], rdx
				jmp			loop_int	

end_inner:
				mov			rdx, [ rsp ]
				mov			rcx, [ rdx + 0x8 ]
				mov			[ rsp ], qword rcx
				jmp			loop_ext
end:
				leave
				ret
