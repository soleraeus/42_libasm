						global			ft_list_push_front
						section			.text

ft_list_push_front:
						cmp				rdi, 0x0
						je				end
						cmp				rsi, 0x0
						je				end
								

end:
						ret
