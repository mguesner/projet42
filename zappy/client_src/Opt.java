class Opt
{
	private int		port;
	private String	domain = "localhost";
	private String	name;

	Opt(String[] args)
	{
		int		i = 0;
		if (args.length < 4)
		{
			System.out.print("Usage: ./client -n <team> -p <port> [-h <hostname>]\n-n nom d'equipe\n-p port\n-h nom de la machine par defaut c'est le localhost\n");
			System.exit(0);
		}
		while (i < args.length)
		{
			if (args[i].startsWith("-n"))
			{
				name = args[++i];
			}
			else if (args[i].startsWith("-p") && args[++i].matches("[0-9]+"))
			{
				port = Integer.parseInt(args[i]);
			}
			else if (args[i].startsWith("-h"))
			{
				domain = args[++i];
			}
			else
			{
				System.out.print("Usage: ./client -n <team> -p <port> [-h <hostname>]\n-n nom d'equipe\n-p port\n-h nom de la machine par defaut c'est le localhost\n");
				System.exit(0);
			}
			i++;
		}
	}

	String getdomain()
	{
		return (domain);
	}

	int getport()
	{
		return (port);
	}

	String getname()
	{
		return (name);
	}
}
