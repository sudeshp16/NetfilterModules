//libxt_test
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <xtables.h>
#include <linux/netfilter/x_tables.h>
#include "libxt_test.h"


static void test_help(void)
{
	printf(" Usage : test -m test --test 1 ");
	return;
}


static void test_init(struct xt_entry_match *m)
{
	//register_match();
	return;
}

//parse
static int test_parse(int x, char **argv, int invert, unsigned int * flags,
				const void * entry, struct xt_entry_match ** match)
{

	struct Test_struct * var;


	return 0;
}


static struct xtables_match test_match = {
	.family		= NFPROTO_UNSPEC,
	.name		= "test",
	.version	= XTABLES_VERSION,
	.size		= XT_ALIGN(sizeof(struct Test_struct)),
	.userspacesize	= sizeof(struct Test_struct),
	.help		= test_help,
	.init		= test_init,
	.x6_parse	= test_parse,
	.print		= test_print,
	.save		= test_save,
	.x6_options	= test_opts,
	.xlate		= test_xlate,
};


void _init(void)
{
	xtables_register_match(&test_match);
}
