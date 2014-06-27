using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Net.Sockets;
using System.Threading;

public class Player : MonoBehaviour {

	public Transform		origin;
	public GameObject		plan;
	public GameObject		three_dmodel;
	public GameObject 		food;
	public GameObject		linemate;
	public GameObject		deraumere;
	public GameObject 		sibur;
	public GameObject 		mendiane;
	public GameObject 		phiras;
	public GameObject 		thystame;
	public GameObject		explosion;
	public GameObject		chest;
	private GameObject		instance;
	public bool				something_to_say = false;
	public bool				winner = false;
	public string			team_win;
	public string			say;
	public int				timer;
	public bool				access = true;
	public int				bomber = 0;
	public StreamReader sr = null;
	public List<string>		read = new List<string>();
	public const float		SOUTH = 0f;
	public const float		EAST = 90f;
	public const float		NORTH = 180f;
	public const float		WEST = 270f;
	private Vector3			center_map;
	public	Thread			thread;
	public string debuger;
	// Use this for initialization
	void reader()
	{
		string str = sr.ReadLine ();
		while (str != null)
		{
			read.Add (str);
			str = sr.ReadLine ();
		}
		access = true;
	}

	void Start () {
		sr = new StreamReader(Menu.fd);
		thread = new Thread(reader);
		thread.Start();
		access = false;
	}

	void OnApplicationQuit() {
		thread.Abort();
	}

	void Parse_cmd(string cmd)
	{
		string [] split = cmd.Split (' ');
		if (String.Compare (split [0], "map") == 0)
		{
			plan.transform.localScale = new Vector3(int.Parse (split[1]) + 2, 1, int.Parse (split[2]) + 2);
			center_map = new Vector3(int.Parse (split[1]) / 2,0,int.Parse (split[2]) /2);
			instance = Instantiate (plan, center_map, origin.rotation) as GameObject;
		}
		else if (String.Compare (split [0], "inside") == 0)
		{
			GameObject tmp1 = GameObject.Find(split[0] +" "+ split[1]+ " " + split[2]);
			if (tmp1 == null)
			{
				GameObject go = new GameObject (split[0] +" "+ split[1]+ " " + split[2]);
				go.AddComponent<Case_map>();
				Case_map zone = go.GetComponent<Case_map>();
				zone.food = int.Parse(split[3]);
				zone.linemate = int.Parse(split[4]);
				zone.deraumere = int.Parse(split[5]);
				zone.sibur = int.Parse(split[6]);
				zone.mendiane = int.Parse(split[7]);
				zone.phiras = int.Parse(split[8]);
				zone.thystame = int.Parse(split[9]);
				zone.x_pos = int.Parse(split[1]);
				zone.y_pos = int.Parse(split[2]);
				if (zone.linemate != 0)
					zone.linemate_model = Instantiate (linemate, new Vector3(zone.x_pos + 0.2f, 0.6f, zone.y_pos), origin.rotation) as GameObject;
				if (zone.deraumere != 0)
					zone.deraumere_model = Instantiate (deraumere, new Vector3(zone.x_pos - 0.2f, 0.6f, zone.y_pos), origin.rotation) as GameObject;
				if (zone.mendiane != 0)
					zone.mendiane_model = Instantiate (mendiane, new Vector3(zone.x_pos, 0.6f, zone.y_pos + 0.2f), origin.rotation) as GameObject;
				if (zone.phiras != 0)
					zone.phiras_model = Instantiate (phiras, new Vector3(zone.x_pos, 0.6f, zone.y_pos - 0.2f), origin.rotation) as GameObject;
				if (zone.sibur != 0)
					zone.sibur_model = Instantiate (sibur, new Vector3(zone.x_pos - 0.2f, 0.6f, zone.y_pos -0.2f), origin.rotation) as GameObject;
				if (zone.thystame != 0)
					zone.thystame_model = Instantiate (thystame, new Vector3(zone.x_pos + 0.2f, 0.6f, zone.y_pos + 0.2f), origin.rotation) as GameObject;
				if (zone.food != 0)
					zone.food_model = Instantiate (food, new Vector3(zone.x_pos, 0.6f, zone.y_pos), origin.rotation) as GameObject;
			}
			else
			{
				Case_map zone = tmp1.GetComponent<Case_map>();
				zone.food = int.Parse(split[3]);
				zone.linemate = int.Parse(split[4]);
				zone.deraumere = int.Parse(split[5]);
				zone.sibur = int.Parse(split[6]);
				zone.mendiane = int.Parse(split[7]);
				zone.phiras = int.Parse(split[8]);
				zone.thystame = int.Parse(split[9]);
				if (zone.linemate == 0 && zone.linemate_model != null)
				{
					Destroy(zone.linemate_model);
					zone.linemate_model = null;
				}
				else if (zone.linemate != 0 && zone.linemate_model == null)
					zone.linemate_model = Instantiate (linemate, new Vector3(zone.x_pos + 0.1f, 0.6f, zone.y_pos), origin.rotation) as GameObject;
				if (zone.deraumere == 0 && zone.deraumere_model != null)
				{
					Destroy(zone.deraumere_model);
					zone.deraumere_model = null;
				}
				else if (zone.deraumere != 0 && zone.deraumere_model == null)
					zone.deraumere_model = Instantiate (deraumere, new Vector3(zone.x_pos + 0.1f, 0.6f, zone.y_pos - 0.2f), origin.rotation) as GameObject;
				if (zone.sibur == 0 && zone.sibur_model != null)
				{
					Destroy(zone.sibur_model);
					zone.sibur_model = null;
				}
				else if (zone.sibur != 0 && zone.sibur_model == null)
					zone.sibur_model = Instantiate (sibur, new Vector3(zone.x_pos - 0.2f, 0.6f, zone.y_pos - 0.2f), origin.rotation) as GameObject;
				if (zone.mendiane == 0 && zone.mendiane_model != null)
				{
					Destroy(zone.mendiane_model);
					zone.mendiane_model = null;
				}
				else if (zone.mendiane != 0 && zone.mendiane_model == null)
					zone.mendiane_model = Instantiate (mendiane, new Vector3(zone.x_pos - 0.2f, 0.6f, zone.y_pos), origin.rotation) as GameObject;
				if (zone.phiras == 0 && zone.phiras_model != null)
				{
					Destroy(zone.phiras_model);
					zone.phiras_model = null;
				}
				else if (zone.phiras != 0 && zone.phiras_model == null)
					zone.phiras_model = Instantiate (phiras, new Vector3(zone.x_pos - 0.2f, 0.6f, zone.y_pos+ 0.2f), origin.rotation) as GameObject;
				if (zone.thystame == 0 && zone.thystame_model != null)
				{
					Destroy(zone.thystame_model);
					zone.thystame_model = null;
				}
				else if (zone.thystame != 0 && zone.thystame_model == null)
					zone.thystame_model = Instantiate (thystame, new Vector3(zone.x_pos + 0.2f, 0.6f, zone.y_pos + 0.2f), origin.rotation) as GameObject;
				if (zone.food == 0 && zone.food_model != null)
				{
					Destroy(zone.food_model);
					zone.food_model = null;
				}
				else if (zone.food != 0 && zone.food_model == null)
					zone.food_model = Instantiate (food, new Vector3(zone.x_pos, 0.6f, zone.y_pos), origin.rotation) as GameObject;
			}
		}
		else if (String.Compare (split [0], "connect") == 0)
		{
			GameObject go = GameObject.Find(split[1] + split[6]);
			if (go == null)
			{
				go = new GameObject (split[1] + split[6]);
				go.AddComponent<Guys>();
				Guys connected = go.GetComponent<Guys>();
				connected.x_pos = int.Parse(split[2]);
				connected.y_pos = int.Parse(split[3]);
				connected.orientation = int.Parse(split[4]);
				connected.team = split[6];
				connected.level = int.Parse(split[5]);
				connected.nb = int.Parse(split[1]);
				three_dmodel.transform.position = new Vector3(connected.x_pos, 0.6f, connected.y_pos);
				connected.character = Instantiate (three_dmodel, three_dmodel.transform.position, origin.rotation) as GameObject;
				if (connected.orientation == 0)
					connected.character.transform.eulerAngles = new Vector3(10, NORTH, 0);
				else if (connected.orientation == 1)
					connected.character.transform.eulerAngles = new Vector3(10, EAST, 0);
				else if (connected.orientation == 2)
					connected.character.transform.eulerAngles = new Vector3(10, SOUTH, 0);
				else if (connected.orientation == 3)
					connected.character.transform.eulerAngles = new Vector3(10, WEST, 0);
				trigger troll = connected.character.GetComponent<trigger>();
				troll.x_pos = int.Parse(split[2]);
				troll.y_pos = int.Parse(split[3]);
				troll.orientation = int.Parse(split[4]);
				troll.team = split[6];
				troll.level = int.Parse(split[5]);
				troll.nb = int.Parse(split[1]);
				troll.Health = 1260;
				troll.deraumere = 0;
				troll.sibur = 0;
				troll.mendiane = 0;
				troll.phiras = 0;
				troll.thystame = 0;
			}
			else
			{
				Guys connected = go.GetComponent<Guys>();
				Destroy(connected.character);
				connected.x_pos = int.Parse(split[2]);
				connected.y_pos = int.Parse(split[3]);
				connected.orientation = int.Parse(split[4]);
				connected.team = split[6];
				connected.level = int.Parse(split[5]);
				connected.nb = int.Parse(split[1]);
				three_dmodel.transform.position = new Vector3(connected.x_pos, 0.6f, connected.y_pos);
				connected.character = Instantiate (three_dmodel, three_dmodel.transform.position, origin.rotation) as GameObject;
				if (connected.orientation == 0)
					connected.character.transform.eulerAngles = new Vector3(10, NORTH, 0);
				else if (connected.orientation == 1)
					connected.character.transform.eulerAngles = new Vector3(10, EAST, 0);
				else if (connected.orientation == 2)
					connected.character.transform.eulerAngles = new Vector3(10, SOUTH, 0);
				else if (connected.orientation == 3)
					connected.character.transform.eulerAngles = new Vector3(10, WEST, 0);
				trigger troll = connected.character.GetComponent<trigger>();
				troll.x_pos = int.Parse(split[2]);
				troll.y_pos = int.Parse(split[3]);
				troll.orientation = int.Parse(split[4]);
				troll.team = split[6];
				troll.level = int.Parse(split[5]);
				troll.nb = int.Parse(split[1]);
				troll.Health = 1260;
				troll.deraumere = 0;
				troll.sibur = 0;
				troll.mendiane = 0;
				troll.phiras = 0;
				troll.thystame = 0;
			}
		}
		else if (String.Compare (split [0], "move") == 0)
		{
			GameObject tmp1 = GameObject.Find(split[1] + split[5]);
			if (tmp1 != null)
			{
				Guys tmp = tmp1.GetComponent<Guys>();
				tmp.x_pos = int.Parse(split[2]);
				tmp.y_pos = int.Parse(split[3]);
				tmp.character.transform.position = new Vector3(tmp.x_pos, 0.6f, tmp.y_pos);
				if (int.Parse(split[4]) == 0)
					tmp.character.transform.eulerAngles = new Vector3(10, NORTH, 0);
				else if (int.Parse(split[4]) == 1)
					tmp.character.transform.eulerAngles = new Vector3(10, EAST, 0);
				else if (int.Parse(split[4]) == 2)
					tmp.character.transform.eulerAngles = new Vector3(10, SOUTH, 0);
				else if (int.Parse(split[4]) == 3)
					tmp.character.transform.eulerAngles = new Vector3(10, WEST, 0);
			}
		}
		else if (String.Compare (split [0], "mort") == 0)
		{
			Debug.Log(cmd);
			GameObject tmp1 = GameObject.Find(split[1] + split[2]);
			if (tmp1 != null)
			{
				Guys tmp = tmp1.GetComponent<Guys>();
				Destroy(tmp.character);
				Destroy(tmp1);
			}
			else
				Debug.Log(split[1] + split[2]);
		}
		else if (String.Compare (split [0], "inv") == 0)
		{
			GameObject tmp1 = GameObject.Find(split[1] + split[9]);
			Guys Sir = tmp1.GetComponent<Guys>();
			trigger troll = Sir.character.GetComponent<trigger>();
			troll.Health = int.Parse(split[2]);
			troll.linemate = int.Parse(split[3]);
			troll.deraumere = int.Parse(split[4]);
			troll.sibur = int.Parse(split[5]);
			troll.mendiane = int.Parse(split[6]);
			troll.phiras = int.Parse(split[7]);
			troll.thystame = int.Parse(split[8]);
		}
		else if (String.Compare (split [0], "lvl") == 0)
		{
			GameObject tmp1 = GameObject.Find(split[1] + split[3]);
			Guys Sir = tmp1.GetComponent<Guys>();
			trigger troll = Sir.character.GetComponent<trigger>();
			troll.level = int.Parse(split[2]);
		}
		else if (String.Compare (split [0], "bc") == 0)
		{
			something_to_say = true;
			say = split[1] + split[2] + " crie :" + split[3];
			timer = 10;
		}
		else if (String.Compare (split [0], "team") == 0)
		{
			team_win = "The winner is " + split[1];
			winner = true;
		}
		else if (String.Compare(split[0], "pond") == 0)
		{
			GameObject go = new GameObject (split[3] + split[4]);
			go.AddComponent<Guys>();
			Guys connected = go.GetComponent<Guys>();
			connected.x_pos = int.Parse(split[1]);
			connected.y_pos = int.Parse(split[2]);
			connected.nb = int.Parse(split[1]);
			chest.transform.position = new Vector3(connected.x_pos, 0.6f, connected.y_pos);
			connected.character = Instantiate (chest, chest.transform.position, origin.rotation) as GameObject;
		}
		else if (String.Compare(split[0], "eclo") == 0)
		{
			GameObject tmp1 = GameObject.Find(split[1] + split[2]);
			if (tmp1 != null)
			{
				Guys tmp = tmp1.GetComponent<Guys>();
			}
		}
		else
			Debug.Log(cmd);
		debuger = cmd;
	}


	void OnGUI()
	{
		if (something_to_say)
		{
			timer -= 1;
			if (timer == 0)
				something_to_say = false;
			GUI.Box(new Rect(Screen.width / 2, (Screen.height / 5) + 10, 300, 45), say);
		}
		if (winner)
		{
			GUI.Box(new Rect(Screen.width / 2, Screen.height / 2, 200, 50), team_win);
			while (bomber < 5)
			{
				GameObject damn = Instantiate (explosion, center_map, origin.rotation) as GameObject;
				Destroy(damn , 3);
				bomber++;
			}
			bomber = 0;
		}
	}
	// Update is called once per frame
	void Update ()
	{
		if (Input.GetKey(KeyCode.Escape))
		{
			Application.Quit();
		}
		if (Menu.fd.DataAvailable && access == true)
		{
			thread = new Thread(reader);
			thread.Start();
			access = false;
		}
		string i = read.FirstOrDefault();
		while (i != null)
		{
			read.Remove (i);
			Parse_cmd(i);
			i = read.FirstOrDefault();
		}
	}
}
