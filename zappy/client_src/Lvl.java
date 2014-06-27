class Lvl
{
	private int		lvl = 1;
	private int		lin = 0;
	private int		der = 0;
	private int		sib = 0;
	private int		men = 0;
	private int		phi = 0;
	private int		thy = 0;


	boolean		isReady(int lin, int der, int sib, int men, int phi, int thy)
	{
//		System.out.println("need : lin ("+this.lin+"), der("+this.der+"), sib ("+this.sib+")"+", men ("+this.men+"), phi ("+this.phi+"), thy ("+this.thy+")");
//		System.out.println("case have : lin ("+lin+"), der("+der+"), sib ("+sib+")"+", men ("+men+"), phi ("+phi+"), thy ("+thy+")");
		if (this.lin <= lin && this.der <= der && this.sib <= sib && this.men <= men && this.phi <= phi && this.thy <= thy)
			return (true);
		return (false);
	}

	boolean		isReady(Inventaire inv)
	{
//		System.out.println("need : lin ("+lin+"), der("+der+"), sib ("+sib+")"+", men ("+men+"), phi ("+phi+"), thy ("+thy+")");
//		System.out.println("player have : lin ("+lin+"), der("+der+"), sib ("+sib+")"+", men ("+men+"), phi ("+phi+"), thy ("+thy+")");
		if (inv.getLin() >= lin && inv.getDer() >= der && inv.getSib() >= sib && inv.getMen() >= men && inv.getPhi() >= phi && inv.getThy() >= thy)
			return (true);
		return (false);
	}

	boolean		isNeed(Inventaire inv, String stone)
	{
		if (stone.equals("linemate"))
		{
				return (inv.getLin() < lin ? true : false);
		}
		if (stone.equals("deraumere"))
		{
				return (inv.getDer() < der ? true : false);
		}
		if (stone.equals("sibur"))
		{
				return (inv.getSib() < sib ? true : false);
		}
		if (stone.equals("mendiane"))
		{
				return (inv.getMen() < men ? true : false);
		}
		if (stone.equals("phiras"))
		{
				return (inv.getPhi() < phi ? true : false);
		}
		if (stone.equals("thystame"))
		{
				return (inv.getThy() < thy ? true : false);
		}
		return (false);
	}

	void		lvlUp(int lvl)
	{
		this.lvl = lvl;
		if (this.lvl == 2)
		{
			lin = 1;
			der = 1;
			sib = 1;
		}
		if (this.lvl == 3)
		{
			lin = 2;
			der = 0;
			sib = 1;
			phi = 2;
		}
		if (this.lvl == 4)
		{
			lin = 1;
			der = 1;
			sib = 2;
			phi = 1;
		}
		if (this.lvl == 5)
		{
			lin = 1;
			der = 1;
			sib = 2;
			men = 3;
			phi = 1;
		}
		if (this.lvl == 6)
		{
			lin = 1;
			der = 1;
			sib = 2;
			men = 3;
			phi = 1;
		}
		if (this.lvl == 7	)
		{
			lin = 2;
			der = 2;
			sib = 2;
			men = 2;
			phi = 2;
			thy = 1;
		}
	}

	int			getLvl()
	{
		return (lvl);
	}
}
