#include "tests.h"
#define BASE "0123456789ABCDEF"

void	test_atoi_base(void)
{
	int		c;

	print_test_name("ATOI_BASE");
	{
		char	nb[] = "00005A";
		char	base[] = "0123 ";

		c = ft_atoi_base(nb, base);
		if (c != 0)
		{
			print_fail();
			return;
		}
	}
	{
		char	nb[] = "00005A";
		char	base[] = "01\n23";

		c = ft_atoi_base(nb, base);
		if (c != 0)
		{
			print_fail();
			return;
		}
	}
	{
		char	nb[] = "00005A";
		char	base[] = "0\t123 ";

		c = ft_atoi_base(nb, base);
		if (c != 0)
		{
			print_fail();
			return;
		}
	}
	{
		char	nb[] = "00005A";
		char	base[] = "\r0123 ";

		c = ft_atoi_base(nb, base);
		if (c != 0)
		{
			print_fail();
			return;
		}
	}
	{
		char	nb[] = "00005A";
		char	base[] = "\v0123 ";

		c = ft_atoi_base(nb, base);
		if (c != 0)
		{
			print_fail();
			return;
		}
	}
	{
		char	nb[] = "00005A";
		char	base[] = "012\f3 ";

		c = ft_atoi_base(nb, base);
		if (c != 0)
		{
			print_fail();
			return;
		}
	}
	{
		char	nb[] = "00005A";
		char	base[] = "+0123 ";

		c = ft_atoi_base(nb, base);
		if (c != 0)
		{
			print_fail();
			return;
		}
	}
	{
		char	nb[] = "00005A";
		char	base[] = "01-23 ";

		c = ft_atoi_base(nb, base);
		if (c != 0)
		{
			print_fail();
			return;
		}
	}
	{
		char	nb[] = "00005A";
		char	base[] = "0123456178";

		c = ft_atoi_base(nb, base);
		if (c != 0)
		{
			print_fail();
			return;
		}
	}
	{
		char	nb[] = "00005A";

		c = ft_atoi_base(nb, BASE);
		if (c != 90)
		{
			print_fail();
			return;
		}
	}
	{
		char	nb[] = "\n\t      -++++++-+-00005AY";

		c = ft_atoi_base(nb, BASE);
		if (c != -90)
		{
			print_fail();
			return;
		}
	}
	{
		char	nb[] = "\n\t      -++++++-+- 00005AY";

		c = ft_atoi_base(nb, BASE);
		if (c != 0)
		{
			print_fail();
			return;
		}
	}
	{
		char	nb[] = "\n\t      -FFFF++++++-+-00005AY";

		c = ft_atoi_base(nb, BASE);
		if (c != -65535)
		{
			print_fail();
			return;
		}
	}

	print_pass();
}
