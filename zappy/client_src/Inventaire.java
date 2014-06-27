class Inventaire
{
	private int			linemate = 0;
	private	int			deraumere = 0;
	private	int			sibur = 0;
	private int			mendiane = 0;
	private int			phiras = 0;
	private	int			thystame = 0;

	int		getLin()
	{
		return (linemate);
	}

	int		getDer()
	{
		return (deraumere);
	}

	int		getSib()
	{
		return (sibur);
	}

	int		getMen()
	{
		return (mendiane);
	}

	int		getPhi()
	{
		return (phiras);
	}

	int		getThy()
	{
		return (thystame);
	}

	void	addLin()
	{
		linemate++;
	}

	void	addDer()
	{
		deraumere++;
	}

	void	addSib()
	{
		sibur++;
	}

	void	addMen()
	{
		mendiane++;
	}

	void	addPhi()
	{
		phiras++;
	}

	void	addThy()
	{
		thystame++;
	}

	void	reset()
	{
		linemate = 0;
		deraumere = 0;
		sibur = 0;
		mendiane = 0;
		phiras = 0;
		thystame = 0;
	}
}
