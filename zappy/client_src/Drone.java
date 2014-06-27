
import java.nio.ByteBuffer;
import java.nio.CharBuffer;
import java.nio.charset.Charset;
import java.io.IOException;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;

class Drone
{
	private boolean		connect;
	private boolean		chef;
	private	boolean		ping = false;
	private ByteBuffer	buf = ByteBuffer.allocate(4096);
	private Charset		def = Charset.defaultCharset();
	private Charset 	cs = Charset.forName("ASCII");
	private	String		mode = "default";
	private Inventaire	inv = new Inventaire();
	private Action		action;
	private Opt			option;
	private String		team;
	private int			nb = 1;
	private	int			here = 0;
	private Lvl			lvl = new Lvl();

	Drone(String str, Opt opt)
	{
		team = str;
		option = opt;
		connect = false;
		chef = true;
	}

	boolean		isConnect()
	{

		return connect;
	}

	void		connect()
	{
		action = new Action();
		connect = true;
		action.addAction("voir");
		buf = def.encode(action.getAction());
	}

	ByteBuffer	getAction()
	{
		ByteBuffer tmp;

		tmp = buf.duplicate();
		return buf;
	}

	boolean		answer(String str) throws IOException
	{
		int here_linemate = 0;
		int here_nourriture = 0;
		int	here_deraumere = 0;
		int	here_sibur = 0;
		int	here_mendiane = 0;
		int here_phiras = 0;
		int here_thystame = 0;
		if (str.startsWith("niveau actuel"))
		{
			String str2 = str.substring(str.lastIndexOf(' ') + 1);
			if (lvl.getLvl() == Integer.parseInt(str2))
				return (false);
			lvl.lvlUp(Integer.parseInt(str2));
			if (lvl.getLvl() != 2)
				mode = "stone";
			inv.reset();
			if (chef && lvl.getLvl() == 2)
			{
				action.addAction("broadcast "+team+"+CHEF");
				action.addAction("inventaire");
				buf = def.encode(action.getAction());
				ping = true;
				return (true);
			}
			else if (chef)
			{
				here = 0;
				mode = "eat";
				action.clearAction();
				action.addAction("inventaire");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (lvl.getLvl() != 2)
				return (false);
		}
		else if (str.matches("[0-9]+"))
		{
			if (Integer.parseInt(str) > 0)
			{
				String cmd = "java -cp " + Client.class.getResource("Client.class").getPath().subSequence(0, Client.class.getResource("Client.class").getPath().lastIndexOf('/')) + " Client -n " + option.getname() + " -p " + option.getport() + " -h " + option.getdomain();
				Runtime.getRuntime().exec(cmd);
				nb++;
				if (nb > 5)
					mode = "ping";
				action.addAction("broadcast "+team+"+CHEF");
				action.addAction("broadcast "+team+"+CHEF");
				action.addAction("broadcast "+team+"+CHEF");
				action.addAction("broadcast "+team+"+CHEF");
				buf = def.encode(action.getAction());
				return (true);
			}
			else
			{
				action.addAction("fork");
				buf = def.encode(action.getAction());
				return (true);
			}
		}
		else if (str.startsWith("elevation"))
		{
			return (false);
		}
		else if(str.startsWith("message") && str.lastIndexOf('+') > 0 && str.substring(str.lastIndexOf(',') + 1, str.lastIndexOf('+')).equals(team))
		{
			String msg = str.substring(str.lastIndexOf('+') + 1);
			if (msg.equals("linemate_up"))
			{
				inv.addLin();
				return (false);
			}
			if (msg.equals("deraumere_up"))
			{
				inv.addDer();
				return (false);
			}
			if (msg.equals("sibur_up"))
			{
				inv.addSib();
				return (false);
			}
			if (msg.equals("mendiane_up"))
			{
				inv.addMen();
				return (false);
			}
			if (msg.equals("phiras_up"))
			{
				inv.addPhi();
				return (false);
			}
			if (msg.equals("thystame_up"))
			{
				inv.addThy();
				return (false);
			}
			if (msg.equals("PING") && !ping)
			{
				chef = false;
				mode = "stone";
				action.clearAction();
				action.addAction("broadcast "+team+"+PONG");
				return (false);
			}
			if (msg.equals("PONG") && chef)
			{
				nb++;
				if (nb > 5)
					mode = "stone";
				return (false);
			}
			if (msg.equals("CHEF") && !ping)
			{
				chef = false;
				return (false);
			}
			if (msg.equals("lvl_up") && !chef && mode.equals("search chef") && action.isEmpty())
			{
				int	src = Integer.parseInt(str.substring(str.lastIndexOf(' ') + 1, str.lastIndexOf(' ') + 2));
				if (src == 1 || src == 8 || src == 2)
				{
					action.addAction("avance");
					action.addAction("inventaire");
				}
				if (src == 3 || src == 4 || src == 5)
				{
					action.addAction("gauche");
					action.addAction("inventaire");
				}
				if (src == 7 || src == 6)
				{
					action.addAction("droite");
					action.addAction("inventaire");
				}
				if (src == 0)
				{
					mode = "here";
					action.addAction("broadcast "+team+"+HERE");
				}
				if (action.isLastEmpty())
				{
					buf = def.encode(action.getAction());
					return (true);
				}
				else
					return (false);
			}
			if (msg.equals("lvl_up") && !chef && mode.equals("here") && Integer.parseInt(str.substring(str.lastIndexOf(' ') + 1, str.lastIndexOf(' ') + 2)) != 0)
			{
				mode = "search chef";
				if (action.isLastEmpty())
				{
					action.addAction("inventaire");
					buf = def.encode(action.getAction());
					return (true);
				}
				else
					return (false);
			}
			if (msg.equals("HERE") && chef)
			{
				here++;
				if (here >= 5)
				{
					mode = "pose";
					action.addAction("broadcast "+team+"+pose");
					return (false);
				}
				return (false);
			}
			if (msg.equals("NOHERE") && chef)
			{
				here--;
				return (false);
			}
			if (msg.equals("pose") && !chef)
			{
				mode = "pose";
				action.clearAction();
				action.addAction("inventaire");
				return (false);
			}
			if (action.isLastEmpty())
			{
				action.addAction("inventaire");
				buf = def.encode(action.getAction());
				return (true);
			}
			else
				return (false);
		}
		else if(str.startsWith("message"))
		{
			return (false);
		}
		else if (action.getLastAction().equals("prend linemate") && str.equals("ok"))
		{
			action.addAction("broadcast "+team+"+linemate_up");
			buf = def.encode(action.getAction());
			return (true);
		}
		else if (action.getLastAction().equals("prend deraumere") && str.equals("ok"))
		{
			action.addAction("broadcast "+team+"+deraumere_up");
			buf = def.encode(action.getAction());
			return (true);
		}
		else if (action.getLastAction().equals("prend sibur") && str.equals("ok"))
		{
			action.addAction("broadcast "+team+"+sibur_up");
			buf = def.encode(action.getAction());
			return (true);
		}
		else if (action.getLastAction().equals("prend mendiane") && str.equals("ok"))
		{
			action.addAction("broadcast "+team+"+mendiane_up");
			buf = def.encode(action.getAction());
			return (true);
		}
		else if (action.getLastAction().equals("prend phiras") && str.equals("ok"))
		{
			action.addAction("broadcast "+team+"+phiras_up");
			buf = def.encode(action.getAction());
			return (true);
		}
		else if (action.getLastAction().equals("prend thystame") && str.equals("ok"))
		{
			action.addAction("broadcast "+team+"+thystame_up");
			buf = def.encode(action.getAction());
			return (true);
		}
		else if (action.getLastAction().equals("pose linemate") && chef && str.equals("ok"))
		{
			action.addAction("voir");
			buf = def.encode(action.getAction());
			return (true);
		}
		else if (action.getLastAction().equals("pose linemate") && str.equals("ok"))
		{
			action.clearAction();
			action.addAction("inventaire");
			buf = def.encode(action.getAction());
			return (true);
		}
		else if (action.getLastAction().equals("pose deraumere") && chef && str.equals("ok"))
		{
			action.addAction("voir");
			buf = def.encode(action.getAction());
			return (true);
		}
		else if (action.getLastAction().equals("pose deraumere") && str.equals("ok"))
		{
			action.clearAction();
			action.addAction("inventaire");
			buf = def.encode(action.getAction());
			return (true);
		}
		else if (action.getLastAction().equals("pose sibur") && chef && str.equals("ok"))
		{
			action.addAction("voir");
			buf = def.encode(action.getAction());
			return (true);
		}
		else if (action.getLastAction().equals("pose sibur") && str.equals("ok"))
		{
			action.clearAction();
			action.addAction("inventaire");
			buf = def.encode(action.getAction());
			return (true);
		}
		else if (action.getLastAction().equals("pose mendiane") && chef && str.equals("ok"))
		{
			action.addAction("voir");
			buf = def.encode(action.getAction());
			return (true);
		}
		else if (action.getLastAction().equals("pose mendiane") && str.equals("ok"))
		{
			action.clearAction();
			action.addAction("inventaire");
			buf = def.encode(action.getAction());
			return (true);
		}
		else if (action.getLastAction().equals("pose phiras") && chef && str.equals("ok"))
		{
			action.addAction("voir");
			buf = def.encode(action.getAction());
			return (true);
		}
		else if (action.getLastAction().equals("pose phiras") && str.equals("ok"))
		{
			action.clearAction();
			action.addAction("inventaire");
			buf = def.encode(action.getAction());
			return (true);
		}
		else if (action.getLastAction().equals("pose thystame") && chef && str.equals("ok"))
		{
			action.addAction("voir");
			buf = def.encode(action.getAction());
			return (true);
		}
		else if (action.getLastAction().equals("pose thystame") && str.equals("ok"))
		{
			action.clearAction();
			action.addAction("inventaire");
			buf = def.encode(action.getAction());
			return (true);
		}
		else if (str.equals("ok"))
		{
			if (action.isEmpty())
			{
				action.addAction("inventaire");
				buf = def.encode(action.getAction());
				return (true);
			}
			else
			{
				buf = def.encode(action.getAction());
				return (true);
			}
		}
		else if (str.startsWith("{") && action.isEmpty())
		{
			String[] tab = str.split(",");
			// case : 0
			String[] tab2 = tab[0].split(" ");
			for (String str2 : tab2)
			{
				if (str2.equals("linemate"))
					here_linemate++;
				if (str2.equals("nourriture"))
					here_nourriture++;
				if (str2.equals("deraumere"))
					here_deraumere++;
				if (str2.equals("sibur"))
					here_sibur++;
				if (str2.equals("mendiane"))
					here_mendiane++;
				if (str2.equals("phiras"))
					here_phiras++;
				if (str2.equals("thystame"))
					here_thystame++;
			}
			if (chef && mode.equals("pose") && lvl.isReady(here_linemate, here_deraumere, here_sibur, here_mendiane, here_phiras, here_thystame))
			{
				action.addAction("incantation");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (mode.equals("pose"))
			{
				action.addAction("inventaire");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (here_nourriture > 0)
			{
				action.addAction("prend nourriture");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (here_linemate > 0 && lvl.getLvl() == 1)
			{
				action.addAction("incantation");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (here_linemate > 0 && mode.equals("stone") && lvl.isNeed(inv, "linemate"))
			{
				action.addAction("prend linemate");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (here_deraumere > 0 && mode.equals("stone") && lvl.isNeed(inv, "deraumere"))
			{
				action.addAction("prend deraumere");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (here_sibur > 0 && mode.equals("stone") && lvl.isNeed(inv, "sibur"))
			{
				action.addAction("prend sibur");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (here_mendiane > 0 && mode.equals("stone") && lvl.isNeed(inv, "mendiane"))
			{
				action.addAction("prend mendiane");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (here_phiras > 0 && mode.equals("stone") && lvl.isNeed(inv, "phiras"))
			{
				action.addAction("prend phiras");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (here_thystame > 0 && mode.equals("stone") && lvl.isNeed(inv, "thystame"))
			{
				action.addAction("prend thystame");
				buf = def.encode(action.getAction());
				return (true);
			}
			// case : 2
			tab2 = tab[2].split(" ");
			for (String str2 : tab2)
			{
				if (str2.equals("linemate"))
					here_linemate++;
				if (str2.equals("nourriture") && (mode.equals("eat") || mode.equals("eat_default")))
					here_nourriture++;
				if (str2.equals("deraumere"))
					here_deraumere++;
				if (str2.equals("sibur"))
					here_sibur++;
				if (str2.equals("mendiane"))
					here_mendiane++;
				if (str2.equals("phiras"))
					here_phiras++;
				if (str2.equals("thystame"))
					here_thystame++;
			}
			if (here_nourriture > 0)
			{
				action.addAction("avance");
				action.addAction("prend nourriture");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (here_linemate > 0 && lvl.getLvl() == 1)
			{
				action.addAction("avance");
				action.addAction("incantation");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (here_linemate > 0 && mode.equals("stone") && lvl.isNeed(inv, "linemate"))
			{
				action.addAction("avance");
				action.addAction("prend linemate");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (here_deraumere > 0 && mode.equals("stone") && lvl.isNeed(inv, "deraumere"))
			{
				action.addAction("avance");
				action.addAction("prend deraumere");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (here_sibur > 0 && mode.equals("stone") && lvl.isNeed(inv, "sibur"))
			{
				action.addAction("avance");
				action.addAction("prend sibur");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (here_mendiane > 0 && mode.equals("stone") && lvl.isNeed(inv, "mendiane"))
			{
				action.addAction("avance");
				action.addAction("prend mendiane");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (here_phiras > 0 && mode.equals("stone") && lvl.isNeed(inv, "phiras"))
			{
				action.addAction("avance");
				action.addAction("prend phiras");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (here_thystame > 0 && mode.equals("stone") && lvl.isNeed(inv, "thystame"))
			{
				action.addAction("avance");
				action.addAction("prend thystame");
				buf = def.encode(action.getAction());
				return (true);
			}
			// case : 6
			if (tab.length > 6)
			{
				tab2 = tab[6].split(" ");
				for (String str2 : tab2)
				{
					if (str2.equals("linemate"))
						here_linemate++;
					if (str2.equals("nourriture") && (mode.equals("eat") || mode.equals("eat_default")))
						here_nourriture++;
					if (str2.equals("deraumere"))
						here_deraumere++;
					if (str2.equals("sibur"))
						here_sibur++;
					if (str2.equals("mendiane"))
						here_mendiane++;
					if (str2.equals("phiras"))
						here_phiras++;
					if (str2.equals("thystame"))
						here_thystame++;
				}
				if (here_nourriture > 0)
				{
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("prend nourriture");
					buf = def.encode(action.getAction());
					return (true);
				}
				if (here_linemate > 0 && lvl.getLvl() == 1)
				{
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("incantation");
					buf = def.encode(action.getAction());
					return (true);
				}
				if (here_linemate > 0 && mode.equals("stone") && lvl.isNeed(inv, "linemate"))
				{
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("prend linemate");
					buf = def.encode(action.getAction());
					return (true);
				}
				if (here_deraumere > 0 && mode.equals("stone") && lvl.isNeed(inv, "deraumere"))
				{
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("prend deraumere");
					buf = def.encode(action.getAction());
					return (true);
				}
				if (here_sibur > 0 && mode.equals("stone") && lvl.isNeed(inv, "sibur"))
				{
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("prend sibur");
					buf = def.encode(action.getAction());
					return (true);
				}
				if (here_mendiane > 0 && mode.equals("stone") && lvl.isNeed(inv, "mendiane"))
				{
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("prend mendiane");
					buf = def.encode(action.getAction());
					return (true);
				}
				if (here_phiras > 0 && mode.equals("stone") && lvl.isNeed(inv, "phiras"))
				{
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("prend phiras");
					buf = def.encode(action.getAction());
					return (true);
				}
				if (here_thystame > 0 && mode.equals("stone") && lvl.isNeed(inv, "thystame"))
				{
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("prend thystame");
					buf = def.encode(action.getAction());
					return (true);
				}
			}
			// case : 12
			if (tab.length > 12)
			{
				tab2 = tab[12].split(" ");
				for (String str2 : tab2)
				{
					if (str2.equals("linemate"))
						here_linemate++;
					if (str2.equals("nourriture") && (mode.equals("eat") || mode.equals("eat_default")))
						here_nourriture++;
					if (str2.equals("deraumere"))
						here_deraumere++;
					if (str2.equals("sibur"))
						here_sibur++;
					if (str2.equals("mendiane"))
						here_mendiane++;
					if (str2.equals("phiras"))
						here_phiras++;
					if (str2.equals("thystame"))
						here_thystame++;
				}
				if (here_nourriture > 0)
				{
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("prend nourriture");
					buf = def.encode(action.getAction());
					return (true);
				}
				if (here_linemate > 0 && lvl.getLvl() == 1)
				{
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("incantation");
					buf = def.encode(action.getAction());
					return (true);
				}
				if (here_linemate > 0 && mode.equals("stone") && lvl.isNeed(inv, "linemate"))
				{
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("prend linemate");
					buf = def.encode(action.getAction());
					return (true);
				}
				if (here_deraumere > 0 && mode.equals("stone") && lvl.isNeed(inv, "deraumere"))
				{
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("prend deraumere");
					buf = def.encode(action.getAction());
					return (true);
				}
				if (here_sibur > 0 && mode.equals("stone") && lvl.isNeed(inv, "sibur"))
				{
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("prend sibur");
					buf = def.encode(action.getAction());
					return (true);
				}
				if (here_mendiane > 0 && mode.equals("stone") && lvl.isNeed(inv, "mendiane"))
				{
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("prend mendiane");
					buf = def.encode(action.getAction());
					return (true);
				}
				if (here_phiras > 0 && mode.equals("stone") && lvl.isNeed(inv, "phiras"))
				{
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("prend phiras");
					buf = def.encode(action.getAction());
					return (true);
				}
				if (here_thystame > 0 && mode.equals("stone") && lvl.isNeed(inv, "thystame"))
				{
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("prend thystame");
					buf = def.encode(action.getAction());
					return (true);
				}
			}
			// case : 1
			tab2 = tab[1].split(" ");
			for (String str2 : tab2)
			{
				if (str2.equals("linemate"))
					here_linemate++;
				if (str2.equals("nourriture") && (mode.equals("eat") || mode.equals("eat_default")))
					here_nourriture++;
				if (str2.equals("deraumere"))
					here_deraumere++;
				if (str2.equals("sibur"))
					here_sibur++;
				if (str2.equals("mendiane"))
					here_mendiane++;
				if (str2.equals("phiras"))
					here_phiras++;
				if (str2.equals("thystame"))
					here_thystame++;
			}
			if (here_nourriture > 0)
			{
				action.addAction("avance");
				action.addAction("gauche");
				action.addAction("avance");
				action.addAction("prend nourriture");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (here_linemate > 0 && lvl.getLvl() == 1)
			{
				action.addAction("avance");
				action.addAction("gauche");
				action.addAction("avance");
				action.addAction("incantation");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (here_linemate > 0 && mode.equals("stone") && lvl.isNeed(inv, "linemate"))
			{
				action.addAction("avance");
				action.addAction("gauche");
				action.addAction("avance");
				action.addAction("prend linemate");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (here_deraumere > 0 && mode.equals("stone") && lvl.isNeed(inv, "deraumere"))
			{
				action.addAction("avance");
				action.addAction("gauche");
				action.addAction("avance");
				action.addAction("prend deraumere");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (here_sibur > 0 && mode.equals("stone") && lvl.isNeed(inv, "sibur"))
			{
				action.addAction("avance");
				action.addAction("gauche");
				action.addAction("avance");
				action.addAction("prend sibur");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (here_mendiane > 0 && mode.equals("stone") && lvl.isNeed(inv, "mendiane"))
			{
				action.addAction("avance");
				action.addAction("gauche");
				action.addAction("avance");
				action.addAction("prend mendiane");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (here_phiras > 0 && mode.equals("stone") && lvl.isNeed(inv, "phiras"))
			{
				action.addAction("avance");
				action.addAction("gauche");
				action.addAction("avance");
				action.addAction("prend phiras");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (here_thystame > 0 && mode.equals("stone") && lvl.isNeed(inv, "thystame"))
			{
				action.addAction("avance");
				action.addAction("gauche");
				action.addAction("avance");
				action.addAction("prend thystame");
				buf = def.encode(action.getAction());
				return (true);
			}
			//case : 3
			tab2 = tab[1].split(" ");
			for (String str2 : tab2)
			{
				if (str2.equals("linemate"))
					here_linemate++;
				if (str2.equals("nourriture") && (mode.equals("eat") || mode.equals("eat_default")))
					here_nourriture++;
				if (str2.equals("deraumere"))
					here_deraumere++;
				if (str2.equals("sibur"))
					here_sibur++;
				if (str2.equals("mendiane"))
					here_mendiane++;
				if (str2.equals("phiras"))
					here_phiras++;
				if (str2.equals("thystame"))
					here_thystame++;
			}
			if (here_nourriture > 0)
			{
				action.addAction("avance");
				action.addAction("droite");
				action.addAction("avance");
				action.addAction("prend nourriture");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (here_linemate > 0 && lvl.getLvl() == 1)
			{
				action.addAction("avance");
				action.addAction("droite");
				action.addAction("avance");
				action.addAction("incantation");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (here_linemate > 0 && mode.equals("stone") && lvl.isNeed(inv, "linemate"))
			{
				action.addAction("avance");
				action.addAction("droite");
				action.addAction("avance");
				action.addAction("prend linemate");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (here_deraumere > 0 && mode.equals("stone") && lvl.isNeed(inv, "deraumere"))
			{
				action.addAction("avance");
				action.addAction("droite");
				action.addAction("avance");
				action.addAction("prend deraumere");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (here_sibur > 0 && mode.equals("stone") && lvl.isNeed(inv, "sibur"))
			{
				action.addAction("avance");
				action.addAction("droite");
				action.addAction("avance");
				action.addAction("prend sibur");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (here_mendiane > 0 && mode.equals("stone") && lvl.isNeed(inv, "mendiane"))
			{
				action.addAction("avance");
				action.addAction("droite");
				action.addAction("avance");
				action.addAction("prend mendiane");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (here_phiras > 0 && mode.equals("stone") && lvl.isNeed(inv, "phiras"))
			{
				action.addAction("avance");
				action.addAction("droite");
				action.addAction("avance");
				action.addAction("prend phiras");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (here_thystame > 0 && mode.equals("stone") && lvl.isNeed(inv, "thystame"))
			{
				action.addAction("avance");
				action.addAction("droite");
				action.addAction("avance");
				action.addAction("prend thystame");
				buf = def.encode(action.getAction());
				return (true);
			}
			// case : 20
			if (tab.length > 20)
			{
				tab2 = tab[20].split(" ");
				for (String str2 : tab2)
				{
					if (str2.equals("linemate"))
						here_linemate++;
					if (str2.equals("nourriture") && (mode.equals("eat") || mode.equals("eat_default")))
						here_nourriture++;
					if (str2.equals("deraumere"))
						here_deraumere++;
					if (str2.equals("sibur"))
						here_sibur++;
					if (str2.equals("mendiane"))
						here_mendiane++;
					if (str2.equals("phiras"))
						here_phiras++;
					if (str2.equals("thystame"))
						here_thystame++;
				}
				if (here_nourriture > 0)
				{
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("prend nourriture");
					buf = def.encode(action.getAction());
					return (true);
				}
				if (here_linemate > 0 && lvl.getLvl() == 1)
				{
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("incantation");
					buf = def.encode(action.getAction());
					return (true);
				}
				if (here_linemate > 0 && mode.equals("stone") && lvl.isNeed(inv, "linemate"))
				{
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("prend linemate");
					buf = def.encode(action.getAction());
					return (true);
				}
				if (here_deraumere > 0 && mode.equals("stone") && lvl.isNeed(inv, "deraumere"))
				{
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("prend deraumere");
					buf = def.encode(action.getAction());
					return (true);
				}
				if (here_sibur > 0 && mode.equals("stone") && lvl.isNeed(inv, "sibur"))
				{
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("prend sibur");
					buf = def.encode(action.getAction());
					return (true);
				}
				if (here_mendiane > 0 && mode.equals("stone") && lvl.isNeed(inv, "mendiane"))
				{
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("prend mendiane");
					buf = def.encode(action.getAction());
					return (true);
				}
				if (here_phiras > 0 && mode.equals("stone") && lvl.isNeed(inv, "phiras"))
				{
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("prend phiras");
					buf = def.encode(action.getAction());
					return (true);
				}
				if (here_thystame > 0 && mode.equals("stone") && lvl.isNeed(inv, "thystame"))
				{
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("avance");
					action.addAction("prend thystame");
					buf = def.encode(action.getAction());
					return (true);
				}
			}
		}
		else if (str.startsWith("nourriture"))
		{
			String[] tab = str.split(",");
			String[] tab2 = tab[0].split(" ");
			String[] lin_tab = tab[1].split(" ");
			String[] der_tab = tab[2].split(" ");
			String[] sib_tab = tab[3].split(" ");
			String[] men_tab = tab[4].split(" ");
			String[] phi_tab = tab[5].split(" ");
			String[] thy_tab = tab[6].split(" ");
			if (mode.equals("pose") && Integer.parseInt(lin_tab[2]) > 0)
			{
				action.addAction("pose linemate");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (mode.equals("pose") && Integer.parseInt(der_tab[2]) > 0)
			{
				action.addAction("pose deraumere");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (mode.equals("pose") && Integer.parseInt(sib_tab[2]) > 0)
			{
				action.addAction("pose sibur");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (mode.equals("pose") && Integer.parseInt(men_tab[2]) > 0)
			{
				action.addAction("pose mendiane");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (mode.equals("pose") && Integer.parseInt(phi_tab[2]) > 0)
			{
				action.addAction("pose phiras");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (mode.equals("pose") && Integer.parseInt(thy_tab[2]) > 0)
			{
				action.addAction("pose thystame");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (mode.equals("pose") && chef)
			{
				action.addAction("voir");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (mode.equals("pose"))
			{
				action.addAction("inventaire");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (mode.equals("default") && Integer.parseInt(tab2[1]) < 10)
			{
				mode = "eat_default";
				action.clearAction();
				action.addAction("voir");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (!action.isEmpty())
			{
				buf = def.encode(action.getAction());
				return (true);
			}
			if (mode.equals("eat_default") && Integer.parseInt(tab2[1]) > 20)
			{
				mode = "default";
				action.addAction("voir");
				buf = def.encode(action.getAction());
				return (true);
			}
			if (Integer.parseInt(tab2[1]) < 10 && !mode.equals("eat_default"))
			{
				if (mode.equals("here"))
				{
					mode = "eat";
					action.clearAction();
					action.addAction("broadcast "+team+"+NOHERE");
					buf = def.encode(action.getAction());
					return (true);
				}
				if (mode.equals("appel"))
				{
					here = 0;
				}
				mode = "eat";
				action.clearAction();
				action.addAction("voir");
				buf = def.encode(action.getAction());
				return (true);
			}
			else if (mode.equals("eat") && Integer.parseInt(tab2[1]) > 20)
			{
				mode = "stone";
				action.addAction("voir");
				buf = def.encode(action.getAction());
				return (true);
			}
			else if (mode.equals("appel"))
			{
				action.addAction("broadcast "+team+"+lvl_up");
				buf = def.encode(action.getAction());
				return (true);
			}
			else if ((mode.equals("search chef") || mode.equals("here")))
			{
				action.addAction("inventaire");
				buf = def.encode(action.getAction());
				return (true);
			}
			else
			{
				action.addAction("voir");
				buf = def.encode(action.getAction());
				return (true);
			}
		}
		if (lvl.isReady(inv) && chef && nb >= 2 && mode.equals("stone"))
		{
			mode = "appel";
			action.addAction("inventaire");
			buf = def.encode(action.getAction());
			return (true);
		}
		if (lvl.getLvl() >= 2 && lvl.isReady(inv) && !chef && mode.equals("stone"))
		{
			mode = "search chef";
			action.clearAction();
			action.addAction("inventaire");
			buf = def.encode(action.getAction());
			return (true);
		}
		if (nb < 6 && chef && lvl.getLvl() == 2 && mode.equals("default"))
		{
			action.addAction("connect_nbr");
			buf = def.encode(action.getAction());
			return (true);
		}
		if (mode.equals("ping") && chef && lvl.getLvl() == 2)
		{
			nb = 1;
			action.addAction("broadcast "+team+"+PING");
			action.addAction("inventaire");
			buf = def.encode(action.getAction());
			ping = true;
			return (true);
		}
		double ran = Math.random();
		if (ran < 0.6)
		{
			action.addAction("avance");
		}
		else if (ran >= 0.6 && ran < 0.8)
		{
			action.addAction("gauche");
		}
		else
		{
			action.addAction("droite");
		}
		action.addAction("inventaire");
		buf = def.encode(action.getAction());
		return (true);
	}
}
