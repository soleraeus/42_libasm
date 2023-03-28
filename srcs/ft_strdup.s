			global			ft_strdup
			extern			malloc
			extern			ft_strlen
			extern			ft_strcpy
			section			.text
			

ft_strdup:
			push			rdi
			call			ft_strlen
			mov				rdi, rax
			inc				rdi
			call			malloc WRT ..plt
			pop				rsi
			cmp				rax, 0x0
			je				end
			mov				rdi, rax
			push			rbp
			call			ft_strcpy
			pop				rbp
end:
			ret
