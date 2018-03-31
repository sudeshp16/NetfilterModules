#include <linux/module.h>
#include <linux/ip.h>
#include <linux/skbuff.h>
#include <linux/netfilter/x_tables.h>

static struct xt_match 	Syn_xt_match;
static struct xt_mtchk_param 	Syn_xt_mtchk;
static struct xt_mtdtor_param	Syn_xt_mtdtor;

static bool SynFloodMatch(const struct sk_buff * skb,
				struct xt_action_param * xtActionParam)
{

//////////////////////////To be Wriiten//////////////////////////
}



static int SynFloodChkEntry(const struct xt_mtchk_param * mtchk)
{
	printk(KERN_ALERT "Inside %s : SynFLood Match Check", __func__);
	return 0;
}

static void SynFloodDestroy(const struct xt_mtdtor_param * mtdtor)
{

	printk(KERN_ALERT "Inside %s:SynFlood Match Destructor", __func__);
}

static int __init SynFlood_Target_init(void) 
{
	int iRet;
	static struct xt_match 	Syn_xt_match  __read_mostly ={
			.name = 	"SynFlood",
			.revision = 	0,
			.family = 	NFPROTO_IPV4,
		//	.tables =
		//      .hooks	=,
		//	.proto =
			.match = 	SynFloodMatch,
			.checkentry =	SynFloodChkEntry,
			.destroy = 	SynFloodDestroy,
			.me =		THIS_MODULE
		};
	iRet = xt_register_match(&Syn_xt_match);
	if (iRet != 0)
	{
		printk(KERN_ALERT " Inserting match target failed ");
	}

}


static void __exit SynFlood_Target_Exit(void)
{
	printk(KERN_ALERT "No Rule Exists Module Can be Removed");
	xt_unregister_match(&Syn_xt_match);
}

