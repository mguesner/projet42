
import java.util.ArrayList;
import java.io.IOException;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;

class Action
{
	private ArrayList<String>	action;
	private ArrayList<String>	last_action;
	private	boolean				first = true;

	Action()
	{
		action = new ArrayList<String>();
		last_action = new ArrayList<String>();
	}

	String	getAction()
	{
		String	tmp;
		tmp = action.get(0);
		action.remove(0);
		if (!first)
			last_action.remove(0);
		if (last_action.isEmpty())
			first = true;
		else
			first = false;
		return (tmp+"\n");
	}

	String	getLastAction()
	{
		String	tmp;
		tmp = last_action.get(0);
		return (tmp);
	}

	void	addAction(String new_action)
	{
		action.add(new_action);
		last_action.add(new_action);
	}

	void	clearAction()
	{
		action.clear();
		last_action.clear();
		first = true;
	}

	boolean	isEmpty()
	{
		return (action.isEmpty());
	}

	boolean	isLastEmpty()
	{
		return (last_action.isEmpty());
	}
}
