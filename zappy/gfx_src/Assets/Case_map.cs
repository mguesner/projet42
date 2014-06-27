using UnityEngine;
using System.Collections;

public class Case_map : MonoBehaviour
{

	public int food;
	public int linemate;
	public int deraumere;
	public int sibur;
	public int mendiane;
	public int phiras;
	public int thystame;
	public GameObject food_model =null;
	public GameObject linemate_model=null;
	public GameObject deraumere_model=null;
	public GameObject sibur_model=null;
	public GameObject mendiane_model=null;
	public GameObject phiras_model=null;
	public GameObject thystame_model=null;

	public int x_pos;
	public int y_pos;
	// Use this for initialization
	public Case_map (string[] contain)
	{
		this.food = int.Parse(contain[3]);
		this.x_pos = int.Parse(contain[2]);
		this.y_pos = int.Parse(contain[1]);
		this.sibur = int.Parse(contain[4]);
		this.mendiane = int.Parse(contain[5]);
		this.phiras = int.Parse(contain[6]);
		this.thystame = int.Parse(contain[7]);
	}
}
